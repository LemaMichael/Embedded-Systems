/* Setting up the PWM Signal

1. PWM frequency of 1kHz (should be within 1Hz) and duty cycle proportional to “aval”
2. Fast PWM Mode
3. PWM Output on Arduino pin 5
 Recall arduino has 16 kHz default
 Use "Tools" -> "Serial Plotter" to view the sinusoid generated
*/

void setup() {
    Serial.begin(9600);
    
    // PWM Freq of 1kHz
    OCR0A = 250; // Top
    OCR0B = 125; // 50% Duty Cycle
    
    // Fast PWM, count up to OCROA, CLK/64, set at 0, clr at match = 125
    TCCR0A = 0X23; // (0010 0011) 00 -> Normal Port Operation, 10 -> Clear OC0B on Compare Match, 00 -> Default Read, 11 -> Fast PWM  = 111
    
    TCCR0B = 0x0B; // (0000 1011) 00 -> Operating in PWM so bits set to zero, 00 -> Default read, 1 -> Fast PWM, 011 - > CLK/64 Pre-scalar
    
    // The Port D Data Direction Register, Using Pin 5
    DDRD |= 0x20; //( 1<< 5)
    
}

// Add loop code
void loop()
{
    float aval;
    long x;
    x = millis();
    aval = abs(3 * sin(2 * 3.141592654 * x / 1000));
    delay(1);
    Serial.println(aval);
}
