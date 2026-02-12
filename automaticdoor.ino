#include <Stepper.h>
#include "iftachs.h"

Iftachs myIftach(4,7); //obejct, trig, echo

void setup() {
  myIftach.begin();
}

void loop() {
  float d = myIftach.getDistance();
  Serial.print("Distance: ");
  Serial.println(d);
  Serial.println(" cm");
delay(500);

 if (d > 0 && d <= 50){
  myIftach.drive_stepper();
 }
}


