int hallsensor = 2;                // Hall sensor at pin 2

volatile byte counter;

unsigned int rpm;

unsigned long passedtime;

void isr()

 {

   //Each rotation, this interrupt function is run twice, so take that into consideration for

   //calculating RPM

   //Update count

      counter++;

 }
void setup()

 {Serial.begin(9600);

   //Intiates Serial communications

   attachInterrupt(0, isr, RISING); //Interrupts are called on Rise of Input

   pinMode(hallsensor, INPUT); //Sets hallsensor as input

   counter = 0;

   rpm = 0;

   passedtime = 0; //Initialise the values

 }
 void loop()
 {
   delay(999); //Update RPM every second, used 999 cause it takes about a millisecond to do the calculations

detachInterrupt(0); //Don't process interrupts during calculations

rpm = 60*1000*counter/(millis() - passedtime);

counter= 0;

Serial.print("RPM=");

Serial.println(rpm); //Print out result to monitor

attachInterrupt(0, isr, RISING); //Restart the interrupt processing
  }
