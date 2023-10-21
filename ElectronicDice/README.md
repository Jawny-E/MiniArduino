# Dice Roller on two 7-segment displays

For yall nerds out there who might also need some soldering practice. The finished product consists of an Arduino Nano, two Common Anode 7-segment displays, a button to initialise rolling, a potentiometer to choose dice and a whole load of resistors and wires! 

## About the project
This is a small personal project I made as a gift for a friend who plays D&D.
The goal was originally to create it with ATTiny and bit-shift registers as I wanted
more experience with different components and make it a compact product. But, after not
finding the components I wanted, I ended up trying to create it on the Arduino Nano instead. Rant over, here are the highlights of the project (imo)
* Uses Arduino Nano to control two 7-segment displays
* The function is to roll different dice(d6, d20 and d100) dependent on the state of a potentiometer
* Has some light animation to imitate the dice rolling
* Function based design to be easily expanded or changed :D
## Code
The full Arduino Code can be found in this directiory, but here are some comments:
- The code is not made to be perfect! It uses delays and has repeating segments, this is mostly because I found it readable when I made it
- The code has some functions that are dependent on each other, yeah this is unfortunate af. I hope however that the names and descriptions are enough to figure out what does what. 
- If you want to use the project the main "changeables" are at the top of the code
## Wire Diagram of Project
<img width="597" alt="Skjermbilde 2023-10-19 212329" src="https://github.com/Jawny-E/MiniArduino/assets/94108006/427684be-fb3e-4035-9e72-9959f49fa675">

## Project Prototype
![20231019_212527](https://github.com/Jawny-E/MiniArduino/assets/94108006/70ea31c4-ab10-4fcb-9d3b-34751d1955e2)

## Finished product
![20231021_160449](https://github.com/Jawny-E/MiniArduino/assets/94108006/27d9f909-4059-4229-bf62-2fb11283dba1)


## Use this project for yourself
Feel free to steal or change anything about it! I personally found it to be quite a cool hobby project
