#define MIC_PIN 5                                        // Microphone

float micLev;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReference(EXTERNAL);
  delay(1000);
  
}

void loop() {
 int16_t micIn;
  
  micIn = analogRead(MIC_PIN);                              // Sample the microphone. Range will result in 0 to 1023.
  micLev = ((micLev * 31) + micIn) / 32;                    // Smooth it out over the last 32 samples.
  
  micIn = micIn - micLev;
  micIn = abs(micIn);

 
  Serial.println(micIn);/* Serial.print(" ");
  Serial.print(0); Serial.print(" ");
  Serial.print(100); Serial.print(" ");
  Serial.println(" ");*/
}
