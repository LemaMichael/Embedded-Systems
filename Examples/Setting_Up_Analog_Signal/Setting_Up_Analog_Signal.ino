/* Use "Tools" -> "Serial Plotter" to view the sinusoid generated  */
void setup() {
    Serial.begin(9600);
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
