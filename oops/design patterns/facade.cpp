#include <iostream>
#include <string>


using namespace std;

class PowerSupply {
    public:
    void supplyPower(){
        cout<<"Power supply is on"<<endl;
    }
};


class CoolingSystem {
    public:
    void startCooler(){
        cout<<"Cooling process started"<<endl;
    }
};

class CPU {
    public:
    void startCPU(){
        cout<<"CPU started"<<endl;
    }
};


class Memory{
     public:
    void initmemory(){
        cout<<"memory initialied"<<endl;
    }
};


class BIOS{
    public:
    void bootSystem(CPU c, Memory m){
        cout<<"BIOS IS HAPPENING";
        c.startCPU();
        m.initmemory();
    }
};


class ComputerFacade {
    private:
    PowerSupply p;
    CoolingSystem cs;
    CPU cpu;
    Memory m;
    BIOS b;

    public:

    void startComputer(){
         cout<<"Starting computer";
         p.supplyPower();
         cs.startCooler();
         b.bootSystem(cpu,m);
         cout<<"Computer started successfully";

    }

};


int main(){
   ComputerFacade computer;
   computer.startComputer();

   return 0;
}