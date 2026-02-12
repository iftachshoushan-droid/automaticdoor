#ifndef IFTACHS_H
#define IFTACHS_H

#include <Arduino.h>

class Iftachs {
  public:
    Iftachs(int trigPin, int echoPin);
    void begin();
    float getDistance();
    void drive_stepper();

  private:
    int _trig;
    int _echo;

    static const byte step_pin  = 3;
    static const byte dir_pin   = 6;
    static const byte step2_pin = 2;
    static const byte dir2_pin  = 5;

    static const int steps = 920;
};

#endif
