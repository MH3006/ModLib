# ModLib
A library for Arduino to implement a time based module structure for non-blocking programs. Based on the code structure taught in the DMU Embedded Systems modules.

The library is broken down into a few files and classes.

## Module Class
The Module.cpp and Module.h files contain the Module class. The Module class takes a pointer to a function and a delay in milliseconds. Running the "run" method within the loop function of the main arduino code will cause the function to run at regular intervals based on the delay set. The "disable" method will stop the function from being executed when the run method is called. The "enable" method re-enables the module and allows the function to run at regular intervals again when the run function is called. 

The function reference by the pointer passed to the class must return nothing/void and have no/void parameters. The delay is passed as 32-bit unsigned integer with a maximum delay of approximately 4.3 billion seconds (or 49.7 days).

## ModuleManager class
The ModuleManager.cpp and ModuleManager.h files contain the ModuleManager class. This class is used to manage multiple modules to keep the code simple and easy to read. The ModuleManager class takes no arguments when initialised. 

The "add_module" method takes a pointer to a function and a delay in milliseconds and creates a module which is stored in an array within the module. This method returns an integer code which represents the module and is used to address the specific module from the module manager. The function corresponding to the pointer must follow the same rules as required by the module.

The "disable" method takes a integer value corresponding to the code for a specific module. This function will disable the module specificied and stop it from running until it is re-enabled. 

The "enable" method similarly takes a integer code for a specific module and enables the module, allowing it to continue running.

The "run" method will run all the modules created by the manager. This method need to be run in the loop function of your arduino code to ensure the timings function correctly.

The maximum number of modules per module manager is managed by a macro named "MAX_MODULES". This is set to 50 by default, but can be changed by redefining the "MAX_MODULES" macro in the main arduino code. 

## ModLib.h File
The ModLib.h file will include the Module and ModuleManager code and means that only one header has to be included for the library to function.

## Drawbacks
The timing of the modules only works if the run time of each module function is shorter than the shortest delay, otherwise the software will be stalled by the operation of the current code. 

There is also no way of setting the priority of modules. Meaning that if two modules reach their interval at the same time, the conflict is not resolved intentionally in the code. However, each module is run based on the order in which they were added to the manager, meaning that if two modules are scheduled to run at the same time then the module which was added to the manager the earliest will be run first. This can be used a very basic form or priority setting. 

# Notes
This library was put together over a weekend as a fun project and has not been thoroughly tested or made efficient and is likely not that useful or revolutionary to most people. There will likely not be many updates or fixes to this code, however anyone is welcome to modify and improve upon it. This is also the first github repository I have created so apologies if anything is wrong. Please feel free to provide any feedback on the code or repository although I can't guarentee I will see it. 
