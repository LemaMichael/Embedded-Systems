/* 4.2 Problem */
void NewDelay(unsigned char mSecondsApx);

void setup() {
  unsigned char *portDDRB;
  portDDRB = (unsigned char *) 0x24;
  *portDDRB |= 0x20;
  
}

void loop() {
  unsigned char *portB;
  portB = (unsigned char *) 0x25;
  *portB |= 0x20;
  NewDelay(100); 
  *portB &= 0xDF;
  NewDelay(100); 
}

void NewDelay(unsigned char mSecondsApx) {
  volatile unsigned long i; // Change #1 
  unsigned long endTime = 1000 * (long) mSecondsApx; // Change #2

  for (i=0; i < endTime; i++);
}
