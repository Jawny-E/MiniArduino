//Pins for the two different segments { a b c d e f g . )
int seg1Pins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 
int seg2Pins[] = {10, 11, 12, 13, A0, A1, A2, A3};

int button = A5;
int potMeter = A6;

//Generic global variables used to store different digits
int d1, d2, num;

//Truth table for the display, for common Cathode 7-segment
byte segCode[11][8] = {
  //  a  b  c  d  e  f  g  .
  { 0, 0, 0, 0, 0, 0, 1, 1},  // 0
  { 1, 0, 0, 1, 1, 1, 1, 1},  // 1
  { 0, 0, 1, 0, 0, 1, 0, 1},  // 2
  { 0, 0, 0, 0, 1, 1, 0, 1},  // 3
  { 1, 0, 0, 1, 1, 0, 0, 1},  // 4
  { 0, 1, 0, 0, 1, 0, 0, 1},  // 5
  { 0, 1, 0, 0, 0, 0, 0, 1},  // 6
  { 0, 0, 0, 1, 1, 1, 1, 1},  // 7
  { 0, 0, 0, 0, 0, 0, 0, 1},  // 8
  { 0, 0, 0, 0, 1, 0, 0, 1},  // 9
  { 1, 1, 1, 1, 1, 1, 1, 1}   // BLANK
};

/*
  This function does the actual work of setting the pins
  It takes in the wanted digit and Pin-array to be given new values
*/
void displayDigit(int digit, int Pins[]){
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(Pins[i], segCode[digit][i]);
  }
}

/*
  This function is responsible for finding the result of the dicethrow
  and then assigning values to the two displays, and adding a small blink-effect
  to show that this is the definate result :)
  It uses switch-case logic so its easier to add different types of dice,
  change the logic, and do different troubleshooting
*/
void selectDigit(int dice){
    switch(dice){
    case 0:
      d1 = 10;
      d2 = random(1,7);
      //Serial.println(dice);
      Serial.print("Resulatet er: " + String(d1) +' '+ String(d2) + '\n');
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(400);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(300);
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(300);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(2000);
      dice = 20;
      break;
    case 1:
      num = random(1, 21);
      d1 = num / 10;
      d2 = num % 10;
      //Serial.println(dice);
      Serial.print("Resulatet er: " + String(d1) +' '+ String(d2) + '\n');
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(300);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(300);
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(300);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(2000);
      break;
    case 2:
      num = random(0, 100);
      d1 = num / 10;
      d2 = num % 10;
      //Serial.println(num);
      //Serial.println(dice);
      Serial.print("Resulatet er: " + String(d1) +' '+ String(d2) + '\n');
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(300);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(300);
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(300);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(2000);
      break;
  }

  
}
/*
  Runs a random sequence of numbers on the 7-segment display
  The intent is for this to "mimic" the feeling of watching a rolling dice
*/
void randomSequence(){
  for (int i = 0; i < random(10, 20); i += 1) {
      d1 = random(10);
      d2 = random(10);
      delay(50+(20*i));
      displayDigit(d1, seg1Pins); 
      displayDigit(d2, seg2Pins);
  }
}
/*
  This function is responsible for choosing which dice to
  roll dependent on the state of the potentiometer
*/
int potentiMeter(){
  int meas = 0;
  int value = analogRead(potMeter);
  if (value > 700){
    meas = 2;
  }
  else if (value >350) {
    meas = 1;
  }
  Serial.println(meas);
  return meas;
}

void setup(){
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(potMeter, INPUT);

  for (int i = 0; i < 8; i++)
  {
    pinMode(seg1Pins[i], OUTPUT);
    pinMode(seg2Pins[i], OUTPUT);
  }
}

void loop()
{
  if(digitalRead(button) == HIGH){
    randomSequence();
    selectDigit(potentiMeter());
  }
}
