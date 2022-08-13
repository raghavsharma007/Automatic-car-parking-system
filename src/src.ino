// This software was used to create a model for an automated automobile parking solution.

from xml.etree.ElementInclude import include

#include <LiquidCrystal.h>
LiquidCrystal lcd(3,4,5,8,9,10);
// setting detector to 0
int detector=0;

long Interval(int prompt,int par2)
{
  // setting prompt pin to output
  pinMode(prompt,OUTPUT);
  // writing LOW for pin prompt
  digitalWrite(prompt,LOW);
  // delay of 5 microseconds
  delayMicroseconds(5);
  // writing HIGH for pin prompt
  digitalWrite(prompt,HIGH);
  // writing LOW for pin prompt
  delayMicroseconds(8);
  // writing LOW for pin prompt
  digitalWrite(prompt,LOW);
  // setting par2 pin to input
  pinMode(par2,INPUT);
  // return of reading HIGH on pin par2
  return pulseIn(par2,HIGH);
}

void setup()
{
  // setting pin 0 to output
  pinMode(0,OUTPUT);
  // setting pin 2 to output
  pinMode(2,OUTPUT);
  // setting pin 5 to output
  pinMode(5,OUTPUT);
  // setting pin 7 to output
  pinMode(7,OUTPUT);
  // setting pin 9 to output
  pinMode(9,OUTPUT);
  // setting the diamensions of the LCD
  lcd.begin(15,1);
  Serial.begin(9600);
}

void loop()
{
  detector=0.01543*Interval(9,8);
  // console output detector
  Serial.println(detector);
  // adding delay
  delay(25);
  // checking if detector is less than 10
  if(detector<10)
  {
    // writing HIGH for pin 6
    digitalWrite(6,HIGH);
    // writing analog 150 for pin A3
    analogWrite(A3,150);
    // writing HIGH for pin 1
    digitalWrite(1,HIGH);
    // writing LOW for pin 3
    digitalWrite(3,LOW);
    // writing LOW for pin 8
    digitalWrite(8,LOW);
    // set the cursor
    lcd.setCursor(0,1);
    // lcd output
    lcd.print("Hurdle detected");
    // set the cursor
    lcd.setCursor(0,0);
    // lcd output
    lcd.print("Move the car aside");
  }
  else
  {
    // writing LOW for pin 6
    digitalWrite(6,LOW);
    // writing HIGH for pin 7
    digitalWrite(7,HIGH);
    // writing HIGH for pin 3
    digitalWrite(3,HIGH);
    // writing analog 0 for pin A5
    analogWrite(A5,0);
    // writing LOW for pin 8
    digitalWrite(8,LOW);
    // set the cursor
    lcd.setCursor(0,1);
    // lcd output
    lcd.print("Moving the car is allowed");
    // set the cursor
    lcd.setCursor(0,0);
    // lcd output
    lcd.print("Car is in reverse");
  }
}
