#ifndef MODULE_H
#define MODULE_H

class Module
{
    private:
        static Module* _firstModule;
        Module* _nextModule;

    public:
        static Module* addModule(Module* module);
        static void loopAll();
        
        virtual void moduleLoop()=0;
};

#endif