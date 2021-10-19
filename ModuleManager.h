#ifndef MAX_MODULES
#define MAX_MODULES 50
#endif

#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H

#include <Arduino.h>
#include "Module.h"

#define MODULE_FAIL_INIT 1000

class ModuleManager{
  public:
    ModuleManager();
    void run();
    int add_module(void (*module_func)(void), unsigned long delay);
    void enable(int module_index);
    void disable(int module_index);
    
  private:
    Module* modules[MAX_MODULES];
    int module_count;
  
};

#endif
