void MyDelay(unsigned long mSecondsApx);

void setup() {
    unsigned char *portDDRB;
    portDDRB = (unsigned char *) 0x24; //DDRB – The Port B Data Direction Register
    *portDDRB |= 0x20; // 0010 0000 // PB5 -> PIN 13 as OUPUT Pin all else are input Pins
}


void loop() {
    unsigned char *portB;
    portB = (unsigned char *) 0x25; //PORTB – The Port B Data Register
    *portB |= 0x20;  //0010 0000 -> PORTB5 (on) -> Port Pin is driven high (one)
    MyDelay(1000); // 1 Second delay
    *portB &= 0xDF;// 0xDF = 1101 1111 -> Result =  0000 0000 -> PORTB5 (off) -> Port Pin is driven low (zero)
    MyDelay(1000);
    
    // Blink twice
    *portB |= 0x20;  //on
    MyDelay(100); //delay
    *portB &= 0xDF; //off
    MyDelay(50);
    *portB |= 0x20; //ON
    MyDelay(100);
    *portB &= 0xDF;
    MyDelay(1000);
    
    // Blink 3 times
    *portB |= 0x20;  //on
    MyDelay(100); //delay
    *portB &= 0xDF; //off
    MyDelay(50);
    *portB |= 0x20; //ON
    MyDelay(100);
    *portB &= 0xDF;
    MyDelay(50);
    *portB |= 0x20; //ON
    MyDelay(100);
    *portB &= 0xDF;
    MyDelay(1000);
    
    
}

void MyDelay(unsigned long mSecondsApx) {
    volatile unsigned long i;
    unsigned long endTime = 1000 * mSecondsApx;
    for (i = 0; i < endTime; i++);
}
