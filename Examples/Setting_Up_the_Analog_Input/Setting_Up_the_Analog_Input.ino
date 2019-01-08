/* Setting up the Analog Input 
 *  -> This requires a low pass filter circuit
*/
void setup() {
    Serial.begin(9600);
    
    // Setting the freq: 16 MHz / CLK(64) / TOP  = 1 Khz  ------->  (16*10^6)/64/250 = 1 kHz 
    // PWM Freq of 1kHz
    OCR0A = 250; // Top
    OCR0B = 125; // 50% Duty Cycle
    
    // Fast PWM, count up to OCROA, CLK/64, set at 0, clr at match = 125
    TCCR0A = 0X23; // (0010 0011) 00 -> Normal Port Operation, 10 -> Clear OC0B on Compare Match, 00 -> Default Read, 11 -> Fast PWM  = 111
    
    TCCR0B = 0x0B; // (0000 1011) 00 -> Operating in PWM so bits set to zero, 00 -> Default read, 1 -> Fast PWM, 011 - > CLK/64 Pre-scalar
    
    // The Port D Data Direction Register, Using Pin 5
    DDRD |= 0x20; //( 1<< 5)
    
    // Configure  ADMUX register (0x7C)
    ADMUX = 0x60; //(0110 0000); 01 -> AVCC with external capacitor at AREF pin, 1 -> Write one to ADLAR to left adjust the result, 0 -> Reserved, always read as zero,  0000 -> Single Ended input as ADC0. Digital Input is enabled if not written 1 to. ( Port C, Bit 0)
    
    // Configure ADCSRA and ADCSRB
    ADCSRA = 0xE6; // (1110 0110) 1-> ADC enabled (ON), 1->Single Conversion mode (start conversion) or if Free Running mode (first conversion), 1-> Auto Trigger enabled, 0 ->  No interrupt flag, 0 -> Default no DC Interrupt Enable, 110 -> division Factor 64
    ADCSRB = 0x00; // (0000 0000) Analog Comparator Multiplexer Enabled, Free Running mode
    
    // Configure DIDR0 to disable digital access to pin A0
    DIDR0 = 0X00;
}

// Add loop code
void loop()
{
    float aval;
    long x;
    x = millis();
    aval = abs(3 * sin(2 * 3.141592654 * x / 1000));
    OCR0B = 250 * (aval/3);
    delay(1);
    Serial.println(aval);
    
    
    // Since ADLAR=1
    unsigned short *ADCData;
    unsigned short ADCVal;
    ADCData=(unsigned short *)0x78;
    ADCVal=(*ADCData & 0xFFC0) >> 6;
    
    float fADCVal;
    fADCVal=((float)ADCVal)/1023 * 3;
    Serial.print(abs(aval));  //Original rectified sinusoid
    Serial.print(" ");
    Serial.println(fADCVal);  //Analog voltage measured from ADC
}
