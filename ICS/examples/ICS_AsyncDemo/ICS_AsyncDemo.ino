// ICS Servo sample (Asynchrotous API)

#include <ICS.h>

IcsController ICS(Serial); // Arduino UNO
//IcsController ICS(Serial1); // GR-CITRUS
IcsServo servo1;
IcsServo servo2;

void setup() {
  
  // Serial.begin(115200); // GR-CITRUS, for console monitor
  
  ICS.begin();
  servo1.attach(ICS, 0x00);
  servo2.attach(ICS, 0x01);
  
  servo1.setPosition(7500-4000);
  servo2.setPosition(7500+4000);
  
  delay(1000);
}

void loop() {
  
  int position1, position2;
  
  for(int position=-4000; position<=4000; position+=100){
    servo1.requestPosition(7500+position);
    servo2.requestPosition(7500-position);
    
    while(!ICS.isReady())
    {
        ICS.loop();
        ; // Do any other process while communicating!
    }
    
    position1 = servo1.position;
    position2 = servo2.position;
    
    // GR-CITRUS, for console monitor
    // Serial.print(position); Serial.print("\t");
    // Serial.print(position1); Serial.print("\t");
    // Serial.print(position2); Serial.print("\n");
    
    delay(100);
  }
  for(int position=-4000; position<=4000; position+=100){
    servo1.requestPosition(7500+position);
    servo2.requestPosition(7500-position);
    
    while(!ICS.isReady())
    {
        ICS.loop();
        ; // Do any other process while communicating!
    }
    
    // GR-CITRUS, for console monitor
    // Serial.print(position); Serial.print("\t");
    // Serial.print(position1); Serial.print("\t");
    // Serial.print(position2); Serial.print("\n");
    
    delay(100);
  }
}
