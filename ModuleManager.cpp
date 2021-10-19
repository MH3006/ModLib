#include "ModuleManager.h"


ModuleManager::ModuleManager(){
  module_count = 0;
}

void ModuleManager::run(){
  for(int i = 0; i < MAX_MODULES; i++){
    if(modules[i] != NULL){
      modules[i]->run();
    }
  }
}

int ModuleManager::add_module(void(*module_func)(void), unsigned long delay){
  if(module_count > MAX_MODULES) return MODULE_FAIL_INIT;

  modules[module_count] = new Module(module_func, delay);
  return module_count++;
}

void ModuleManager::enable(int module_index){
  modules[module_index]->enable();
}

void ModuleManager::disable(int module_index){
  modules[module_index]->disable();
}
