/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */

#include <OneWire.h>

// Based on the OneWire library example
//1 GPIO สามารถต่อได้สูงสุด 8 ตัว และต้องเป็น Digital Port เท่านั้นไม่สามารถใช้กับ ADC Port ได้
OneWire ds(23);  //data wire connected to GPIO35

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte i;
  byte addr[8];
  
  if (!ds.search(addr)) {
    Serial.println(" No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
  Serial.print(" ROM =");
  for (i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }
}
