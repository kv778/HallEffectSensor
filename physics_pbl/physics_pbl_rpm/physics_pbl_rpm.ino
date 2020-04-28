int LED = 13;
int SENSOR = 2;
int val;
volatile byte ctr;
int rpm;
unsigned long passedtime;

void isr()
{
  ctr++;
}

void setup() 
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(SENSOR), isr, RISING); 
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);

  ctr = 0;
  rpm = 0;
  passedtime = 0;
}

void loop() 
{
   delay(3000);
   detachInterrupt(0); //Interrupts are disabled
   rpm = (60*1000*ctr)/(millis() - passedtime);
   passedtime = millis();
   ctr = 0; 
   Serial.print("RPM = ");
   Serial.println(rpm); 
   attachInterrupt(0, isr, RISING);   
}
