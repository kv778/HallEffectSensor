int led = 13;                            // define LED Interface
int SENSOR = 10;                        // define the Hall magnetic sensor interface
int val;                               // define numeric variables val
 
void setup ()
{
  pinMode (led, OUTPUT);            // define LED as output interface
  pinMode (SENSOR, INPUT);         // define the Hall magnetic sensor line as input
}
 
void loop ()
{
  val = digitalRead (SENSOR);     // read sensor line
  if (val == HIGH)               // when the Hall sensor detects a magnetic field, Arduino LED lights up
  {
    digitalWrite (led, HIGH);
  }
  else
  {
    digitalWrite (led, LOW);
  }
}
