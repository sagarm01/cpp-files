// using this code lets learn abstraction
// abstraction hides all the unnecssary methods and variables from user which the user does not need to know
#include <iostream>
#include <string>

using namespace std;

// virtual means just declaring and not defiing, whosover extends it needs to define it

// abstract class cannot be directly intancetiated,
class Car
{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;

    // class destructor
    virtual ~Car()
    {
    }
};

class SportsCar : public Car
{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

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
    Car *myCar = new SportsCar("Ford", "Mustang GT3");

    // i am simply calling its method without understanding how internally it is working
    // equilvalent to PUSH TO START BUTTION
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    return 0;
};
