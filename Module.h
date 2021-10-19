#ifndef MODULE_H
#define MODULE_H

#include <Arduino.h>

class Module{
  public:
    Module(void (*module_func)(void), unsigned long module_delay);
    void run();
    void enable();
    void disable();
  private:
    void (*func)(void);
    unsigned long delay;
    unsigned long previous_time;
    bool do_step;
    bool enabled;
};

#endif
