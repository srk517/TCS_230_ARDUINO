const int s0 = 8;
const int s1 = 9;
const int s2 = 10;
const int s3 = 11;
const int out = 12;
//int yel=0;
// LED pins connected to Arduino
int redLed = 2;
int greenLed = 3;
int blueLed = 4;
// Variables
int red = 0;
int green = 0;
int blue = 0;
int yellow=0;
void color()
{
digitalWrite(s2, LOW);
digitalWrite(s3, LOW);
digitalWrite(s1,LOW);
digitalWrite(s0,LOW);
//count OUT, pRed, RED 
red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
digitalWrite(s3, HIGH);
//count OUT, pBLUE, BLUE
blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
digitalWrite(s2, HIGH);
//count OUT, pGreen, GREEN
green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
//digitalWrite(s1,HIGH);
yellow = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

}
void setup()
{
Serial.begin(9600);
pinMode(s0, OUTPUT);
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
pinMode(s3, OUTPUT);
pinMode(out, INPUT);
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(blueLed, OUTPUT);
digitalWrite(s0, HIGH);
digitalWrite(s1, HIGH);
}
void loop()
{
color();
Serial.print("R Intensity:");
Serial.print(red, DEC);
Serial.print(" G Intensity: ");
Serial.print(green, DEC);
Serial.print(" B Intensity : ");
Serial.print(blue, DEC);
Serial.print(" Y Intensity : ");
Serial.print(yellow,DEC);

//Serial.println();
if (red < blue && red < green && red < 20)
{
Serial.println(" - (Red Color)");
digitalWrite(redLed, HIGH); // Turn RED LED ON
digitalWrite(greenLed, LOW);
digitalWrite(blueLed, LOW);
}
else if (blue < red && blue < green)
{
Serial.println(" - (Blue Color)");
digitalWrite(redLed, LOW);
digitalWrite(greenLed, LOW);
digitalWrite(blueLed, HIGH); // Turn BLUE LED ON
}
else if (green < red && green < blue)
{
Serial.println(" - (Green Color)");
digitalWrite(redLed, LOW);
digitalWrite(greenLed, HIGH); // Turn GREEN LED ON
digitalWrite(blueLed, LOW);
}
else
{
Serial.println(" - (Yellow Color)");
digitalWrite(redLed, HIGH);
digitalWrite(greenLed, HIGH);
digitalWrite(blueLed, LOW); // Turn BLUE LED ON
}
///delay(500);
//yellow
for(int i=0;i<255;i++)

{
  digitalWrite(redLed, i);
  delay(5);
}
for(int i=0;i<255;i++)
{
digitalWrite(greenLed, i);
delay(5);
}
digitalWrite(blueLed, LOW);
}
