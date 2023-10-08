//Pins for the two different segments { a b c d e f g . )
int seg1Pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 0,}; 
int seg2Pins[] = {10, 11, 12, 13, A0, A1, A2, A3};

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
//Generic global variables used to store different digits
int d1, d2, num;

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
    case 6:
      d1 = 10;
      d2 = random(1,7);
      //Serial.println(dice);
      //Serial.print("Resulatet er: " + String(d1) +' '+ String(d2) + '\n');
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(100);
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(100);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(2000);
      dice = 20;
      break;
    case 20:
      num = random(1, 21);
      d1 = num / 10;
      d2 = num % 10;
      //Serial.println(dice);
      //Serial.print("Resulatet er: " + String(d1) +' '+ String(d2) + '\n');
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(100);
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(100);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(2000);
      break;
    case 100:
      num = random(0, 100);
      num = 99;
      d1 = num / 10;
      d2 = num % 10;
      //Serial.println(num);
      //Serial.println(dice);
      //Serial.print("Resulatet er: " + String(d1) +' '+ String(d2) + '\n');
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(100);
      displayDigit(10, seg1Pins);
      displayDigit(10, seg2Pins);
      delay(100);
      displayDigit(d1, seg1Pins);
      displayDigit(d2, seg2Pins);
      delay(2000);
      break;
  }

  
}

void setup(){
  //Serial.begin(9600);
  for (int i = 0; i < 8; i++)
  {
    pinMode(seg1Pins[i], OUTPUT);
    pinMode(seg2Pins[i], OUTPUT);
  }
  randomSeed(analogRead(A7));

}
/*
  Runs a random sequence of numbers on the 7-segment display
  The intent is for this to "mimic" the feeling of watching a rolling dice
*/
void randomSequence(){
  for (int i = 0; i < random(4, 10); i += 1) {
      d1 = random(10);
      d2 = random(10);
      delay(100-(i*9));
      displayDigit(d1, seg1Pins); 
      displayDigit(d2, seg2Pins);
  }
}

void loop()
{
  /*Pseudocode since I need to Check the pinout of the nano*/
  /*
  if(button1 == HIGH){
    randomSequence();
    selectDigit(6);
  }
  elif(button2 == HIGH){
    randomSequence();
    selectDigit(20);
  }
  elif(button 3 == HIGH){
    randomSequence();
    selectDigit(100);
  }
  */
}
