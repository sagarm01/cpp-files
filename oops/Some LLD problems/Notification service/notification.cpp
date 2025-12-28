#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

// Notification
// Notifcation object is decoratable -> Can have multiple things can look like diff things

using namespace std;

class INotification
{
public:
    virtual string getContent()  = 0;
    virtual ~INotification() {}
};

class SimpleNotification : public INotification
{
private:
    string text;

public:
    SimpleNotification(const  string &text)
    {
        this->text = text;
    }

    string getContent()  override
    {
        return text;
    }
};

// is a and has a relationship with INoticiaiton required to decorate it
class INotificationDecorator : public INotification
{
protected:
    INotification *notification;

public:
    INotificationDecorator(INotification *notifObject)
    {
        notification = notifObject;
    }
};

class WithTimestampNotication : public INotificationDecorator
{
public:
    WithTimestampNotication(INotification *notifObject) : INotificationDecorator(notifObject) {}
    string getContent ()  override
    {
        return notification->getContent() + "Timestamp Added";
    }
};

class WithSignatureNotification : public INotificationDecorator
{
public:
    WithSignatureNotification(INotification *sign) : INotificationDecorator(sign) {}
    string getContent()  override
    {
        return notification->getContent() + "Signature Added";
    }
};

// Observer pattern implementation for notification engine

class IObserver
{
public:
    virtual void update() = 0;
    virtual ~IObserver() {}
};

class IObservable
{

public:
    virtual void add(IObserver* obs) = 0;
    virtual void remove(IObserver* obs) = 0;
    virtual void notify() = 0;
};



class ConcreteObservable : public IObservable
{
private:
    vector<IObserver *> list;
    INotification *currentNotification;

public:
    ConcreteObservable()
    {
        currentNotification = nullptr;
    }

    void add(IObserver *obs)
    {
        list.push_back(obs);
    }
    void remove(IObserver *obs)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (*it == obs)
            {
                list.erase(it);
                break; // Remove only first occurrence
            }
        }
    }

    void notify()
    {
        for (auto a : list)
        {
            a->update();
        }
    }

    void setNotification(INotification *notification)
    {
        if (currentNotification != nullptr)
        {
            delete currentNotification;
        }
        currentNotification = notification;
        notify();
    }

    INotification *getNotification()
    {
        return currentNotification;
    }

    string getNotificationContent()
    {
        return currentNotification->getContent();
    }

    ~ConcreteObservable()
    {
        if (currentNotification != NULL)
        {
            delete currentNotification;
        }
    }
};



// each has its on observable

class Logger : public IObserver
{
private:
    ConcreteObservable *notificationObservable;

public:
    Logger(ConcreteObservable *a)
    {
        notificationObservable = a;
    }
    virtual void update()
    {
        cout << "Nofication logged" << notificationObservable->getNotificationContent();
    };
};



// Strategy pattern to implement notification engine

class INotificationStrategy {
    public:
    virtual void sendNotification(string content) = 0;
};

class EmailStrat : public INotificationStrategy{
    private:
    string emailId;
    public:
    EmailStrat(const string& e){
        this->emailId = e;
    }
    void sendNotification(string content){
        cout<<"SENT AN EMAIL NOTIFICATION to "<<emailId;
    }
};

class SMSStrat : public INotificationStrategy{
    private:
    string phone;
    public:
     SMSStrat(const string& e){
        this->phone = e;
    }
    void sendNotification(string content){
        cout<<"SENT SMS NOTIFICATION to "<<phone;
    }
};


class NotificationEngine : public IObserver
{
private:
    ConcreteObservable *notificationObservable;
    vector<INotificationStrategy*> notifStrats;

public:
    NotificationEngine(ConcreteObservable *a)
    {
        notificationObservable = a;
    }

    void addNewStrat(INotificationStrategy* stat){
        this->notifStrats.push_back(stat);
    }


    void update()
    {
        for(auto a:notifStrats){
            a->sendNotification(notificationObservable->getNotificationContent());
        }
    };
};


// FINALLY OUR MAIN SERVICE WHICH HANDLED EVERYTHING
// keeps tract of notifications

// Singleton class
// Singleton class
class NotificationService {
private:
    ConcreteObservable* observable;
    static NotificationService* instance;
    vector<INotification*> notifications;

    NotificationService() {
        // private ructor
        observable = new ConcreteObservable();
    }

public:
    static NotificationService* getInstance() {
        if(instance == nullptr) {
            instance = new NotificationService();
        }
        return instance;
    }

    // Expose the observable so observers can attach.
    ConcreteObservable* getObservable() {
        return observable;
    }

    // Creates a new Notification and notifies observers.
    void sendNotification(INotification* notification) {
        notifications.push_back(notification); // history
        observable->setNotification(notification);
    }

    ~NotificationService() {
        delete observable;
    }
};

NotificationService* NotificationService::instance = nullptr;





int main() {
    // Create NotificationService.
    NotificationService* notificationService = NotificationService::getInstance();

    // Get Observable
    ConcreteObservable* notificationObservable = notificationService->getObservable();
   
    // Create Logger Observer
    Logger* logger = new Logger(notificationObservable);

    // Create NotificationEngine observers.
    NotificationEngine* notificationEngine = new NotificationEngine(notificationObservable);

    notificationEngine->addNewStrat(new EmailStrat("random.person@gmail.com"));
    notificationEngine->addNewStrat(new SMSStrat("+91 9876543210"));

    // Attach these observers.
    notificationObservable->add(logger);
    notificationObservable->add(notificationEngine);

    // Create a notification with decorators.
    INotification* notification = new SimpleNotification("Your order has been shipped!");
    notification = new WithTimestampNotication(notification);
    notification = new WithSignatureNotification(notification);
    
    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}