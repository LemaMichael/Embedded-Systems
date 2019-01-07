/* Polling is the simple process of continuously reading the value of the input pins 
 *  and comparing the current value with the previous-read value to determine if 
 *  an external signal event has occured. 
 */
#define BIT0_MASK 0x01 // 0000 0001

unsigned char *portDDRB;
unsigned char *portDataB;
unsigned char *portPinB;

void setup() {
  Serial.begin(9600);
  portDDRB = (unsigned char *) 0x24;
  portDataB = (unsigned char *) 0x25;
  portPinB = (unsigned char *) 0x23;

  // Make bit 0 of PORT B an input with an internal pull-up resistor enabled.
  *portDDRB = (*portDDRB) & (~BIT0_MASK); // configure bit 0 as an input
  *portDataB = (*portDataB) | BIT0_MASK; // turn on the bit 0 pull-up
  
}

void loop() {
  unsigned char previousSample;
  unsigned char currentSample;
  
  currentSample = (*portPinB) & BIT0_MASK; // Only interested in bit 0
  if (currentSample != previousSample) {
    Serial.println("A change has occured! We should do something...");
  }
  
  // Store the current sample as the next previous sample
  previousSample = currentSample;
}
