
/**
 * void setLEDs(unsigned int)
 * Sets the specified number of LEDs to ON.
 * e.g. if degree = 7, all seven LEDs turn on.
 *      if degree = 4, the first 4 LEDs turn on.
 *      if degree = 0, all LEDs go off.
 * If degree is greater than 7, turns on all LEDs.
 * The first LED is on Pin 9, the second on Pin 8, etc., the last on Pin 3.
 * Assumes that the pin modes of Pins 3-9 are set to OUTPUT.
 */
void setLEDs(unsigned int degree)
{
  switch(degree)
  {
    case 1:
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    break;
    case 2:
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    break;
    case 3:
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    break;
    case 4:
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    break;
    case 5:
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    break;
    case 6:
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    break;
    case 7:
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    break;
    default:
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
}



void setup()
{
  // begin the serial communication between the computer
  // and the Arduino with transfer rate = 9600 bits/second
  Serial.begin(9600);

  // set the modes of all the general purpose I/O pins we're using
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}


// This is the global variable that represents the voltage of the
// analog pin A0.
double readVal;

// It's good practice to not hard-code values. 
// Here, we set the analog pin number to 0. (See below)
byte A_PIN = 0;

void loop()
{
  readVal = analogRead(A_PIN);
  
  Serial.print("Read A0 as: ");
  Serial.print(readVal);
  Serial.print("\n\n");

  if(readVal < 100)
    setLEDs(7);
  else if(readVal < 120)
    setLEDs(6);
  else if(readVal < 145)
    setLEDs(5);
  else if(readVal < 180)
    setLEDs(4);
  else if(readVal < 220)
    setLEDs(3);
  else if(readVal < 280)
    setLEDs(2);
  else if(readVal < 360)
    setLEDs(1);
  else
    setLEDs(0);
}


