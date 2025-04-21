#define FORCE_SENSOR_PIN A0
#define BUTTON_PIN 2
int buzzer = 5;   //declares buzzer @pin 5
int FSRanalogpin = A0; //declares the FSR @analogpin A0
int analogReading = 0;
int a = 0;
int buttonPin = 2;
int buttonState = 0; 
int h = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(FSRanalogpin,INPUT); //sets the FSR as the input
  pinMode(buzzer,OUTPUT);   //sets the buzzer as the output
  Serial.begin(9600);
}

 
void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);
  analogReading = analogRead(FSRanalogpin); //reads the FSR and store it in integer
  Serial.print("Force sensor reading = ");
  Serial.print(analogReading); // print the raw analog reading
  delay(50);
buttonState=digitalRead(buttonPin);
Serial.println("Armed?");
Serial.println(h);

if (buttonState == 1)
{
  h=1;
}

  if (analogReading < 10)       // from 0 to 9
    Serial.println(" -> no pressure");
  else if (analogReading < 200) // from 10 to 199
    Serial.println(" -> light touch");
  else if (analogReading < 500) // from 200 to 499
    Serial.println(" -> light squeeze");
  else if (analogReading < 800) // from 500 to 799
    Serial.println(" -> medium squeeze");
  else // from 800 to 1023
    Serial.println(" -> big squeeze");
    delay(100);

 
if (analogReading > 50)
{
  a=1; 
}



if ((analogReading == 0)&&(a==1)&&(h!=1))
{
  tone(buzzer, 1000);
  delay(500);
  tone(buzzer, 750);
  delay(500);

  }

  }
