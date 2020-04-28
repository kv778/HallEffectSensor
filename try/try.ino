int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3
int Led = 13;                    // outside leads to ground and +5V
int val = 0;        // variable to store the value read

void setup() 
{
  pinMode(Led, OUTPUT);
  Serial.begin(9600);           //  setup serial
}

void loop() 
{
  val = analogRead(analogPin);
  if(val>=900)
  {
    digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW); 
  }
  Serial.println(val);          // debug value
}
