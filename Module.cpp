#include "Module.h"

Module::Module(void (*module_func)(void), unsigned long module_delay){
  func = module_func;
  delay = module_delay;
  previous_time = millis();
  do_step = false;
  enabled = false;
}

void Module::enable(){
  enabled = true;
  
}

void Module::disable(){
  enabled = false;
}

void Module::run(){
  if(!enabled) return;

  unsigned long current_time = millis();
  if((long)(current_time - previous_time) > delay){
    previous_time = current_time;
    do_step = true;
  }else do_step = false;

  if(do_step){
    (*func)();
  }
}
