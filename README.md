# ArduinoModules
Starter kit for better organized Arduino code. Intended for medium-size projects, for example when you connect a few sensors and motors. Instead of having all code in one INO file, we propose to use "ArduinoModules".
This is a cooperative scheduler.

## How to start
### 1. Create a Module
An empty Module looks like this:
```
/* file: myModule.h */
#include "module.h"

class myModule : public Module
{
private:
  /* Add your private variables and functions here */;

public:
  /* Add your public variables and functions here */;
  myModule(int anInt);
  void moduleLoop();
};
```

```
/* file: myModule.cpp */
#include "myModule.h"

myModule::myModule(int anInt)
{
  /* Constructor, add you initialization code here */;
}

void myModule::moduleLoop()
{
  /* ADD YOUR REPEATED CODE HERE */
}
```
### 2. Install the module
Add your module to your INO sketch like this:
```
#include "module.h"
#include "myModule.h"

void setup() {
    Module m = Module::addModule(new myModule(3));
}

void loop() {
    Module::loopAll();
}
```

### 3. Module setup procedure
Your setup and initialization code should go in the constructor of the module.

### 4. Repeated calls
Instead of becoming idle, the processor will call the ```moduleLoop()``` function of all installed modules. 
Note that this is a cooperative scheduler, so the next module will only be called after the current module ends its ```moduleLoop```. 
To keep your system responsive, the loop function should be relatively short. 
