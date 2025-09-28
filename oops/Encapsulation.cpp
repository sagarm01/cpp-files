// Learning encapsulation
// like a capsule
// it also promotes the idea of data security
// access modifiers -> Public, Private, Protected

#include <iostream>
#include <string>

using namespace std;

class SportsCar
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    // class constructor
    SportsCar(string b, string m)
    {
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0; // neutral
    };

    // class methods

    void startEngine()
    {
        isEngineOn = true;
        cout << brand << " " << model << ": Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear)
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << ": Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;
    }

    void accelerate()
    {
        if (!isEngineOn)
        {
            cout << brand << " " << model << ": Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << ": Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake()
    {
        currentSpeed -= 20;
        if (currentSpeed < 0)
            currentSpeed = 0;
        cout << brand << " " << model << ": Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine()
    {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << ": Engine turned off." << endl;
    }
};

// main method
int main()
{
    SportsCar *myCar = new SportsCar("Ford", "Mustang GT3");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    return 0;
};