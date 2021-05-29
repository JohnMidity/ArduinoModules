#include "module.h"

Module* Module::_firstModule = 0;

void Module::loopAll()
{
    Module* m = Module::_firstModule;

    while (m!=0)
    {
        m->moduleLoop();
        m = m->_nextModule;
    }
}

Module* Module::addModule(Module* module)
{
    /* Add the new module at the front of the list */
    module->_nextModule = Module::_firstModule;
    Module::_firstModule = module;

    return Module::_firstModule;
}