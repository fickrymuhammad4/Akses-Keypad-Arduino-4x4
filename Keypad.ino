/* the tutorial code for 3x4 Matrix Keypad with Arduino is as
This code prints the key pressed on the keypad to the serial port*/

#include 

const byte Rows= 4; //number of rows on the keypad i.e. 4
const byte Cols= 3; //number of columns on the keypad i,e, 3

//we will definne the key map as on the key pad:

char keymap[Rows][Cols]=
{
{'1', '2', '3'},
{'4', '5', '6'},
{'7', '8', '9'},
{'*', '0', '#'}
};

//  a char array is defined as it can be seen on the above


//keypad connections to the arduino terminals is given as:

byte rPins[Rows]= {A6,A5,A4,A3}; //Rows 0 to 3
byte cPins[Cols]= {A2,A1,A0}; //Columns 0 to 2

// command for library forkeypad
//initializes an instance of the Keypad class
Keypad kpd= Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);

void setup()
{
Serial.begin(9600);  // initializing serail monitor
}

//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
void loop()
{
char keypressed = kpd.getKey();
if (keypressed != NO_KEY)
{
Serial.println(keypressed);
}
}
