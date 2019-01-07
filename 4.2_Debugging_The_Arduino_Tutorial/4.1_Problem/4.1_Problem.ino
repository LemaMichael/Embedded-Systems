/* 4.1 Problem */
void MyDelay(unsigned long mSecondsApx);

void setup() {
  unsigned char *portDDRB;
  portDDRB = (unsigned char *) 0x24;
  *portDDRB |= 0x20;
  
}

void loop() {
  unsigned char *portB;
  portB = (unsigned char *) 0x25;
  *portB |= 0x20;
  MyDelay(1000); // Syntax Error #1
  *portB &= 0xDF;
  MyDelay(1000); // Syntax Error #2
}

void MyDelay(unsigned long mSecondsApx) {
  volatile unsigned long i;
  unsigned long endTime = 1000 * mSecondsApx;

  for (i=0; i < endTime; i++);
}
