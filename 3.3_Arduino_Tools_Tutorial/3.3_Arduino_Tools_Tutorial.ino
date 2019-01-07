
void MyDelay(unsigned long mSecondsApx); 


void setup() {
  unsigned char *portDDRB;
  portDDRB = (unsigned char *) 0x24; // The Port B Data Direction Register
  *portDDRB |= 0x20; /// DDB5 is an output pin
}

void loop() {
  unsigned char *portB;
  portB = (unsigned char *) 0x25; //The Port B Data Register

  *portB |= 0x20; // Port pin is driven high 
  MyDelay(1000);
  *portB &= 0xDF; // All ports pins are driven low
  MyDelay(1000);

}

void MyDelay(unsigned long mSecondsApx) {
  volatile unsigned long i;
  unsigned long endTime = 1000 * mSecondsApx;
  for (i = 0; i < endTime; i++);
}
