int SENSOR = A3; // define the Hall magnetic sensor interface
float val; // define numeric variable val
float rval;
 
void setup ()
{
   Serial.begin(9600);
   pinMode (SENSOR, INPUT);  // define the Hall magnetic sensor line as input
}
 
void loop ()
{
   val = analogRead (SENSOR); // read analog data from sensor
   if(val>500)
    {
      Serial.println("NULL");
    }
   else
   {
     rval = ((val/100)-1.5);
     Serial.print(rval);
     Serial.print(" cm");
     Serial.println();
   }
}
