#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ISubscriber
{
public:
    ISubscriber()
    {
    }
    ~ISubscriber()
    {
    }

    virtual void update() = 0;
};

class IChannel
{
public:
    IChannel()
    {
        cout << "Constructor is called for [Ichannel]";
    }
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unsubsribe(ISubscriber *subscriber) = 0;
    virtual void notify() = 0;
    virtual ~IChannel() {}
};

class Channel : public IChannel
{
private:
    vector<ISubscriber *> subscribers;
    string name;
    string latestVideo;

public:
    Channel(const string &name)
    {
        cout << "Constructor is called for [Ichannel]";
        this->name = name;
    }

    // add a sub
    void subscribe(ISubscriber *subscriber) override
    {
        subscribers.push_back(subscriber);
    }

    // add a sub
    void unsubsribe(ISubscriber *subscriber) override
    {
        subscribers.pop_back();
    }

    void notify() override
    {
        for (auto a : subscribers)
        {
            a->update();
        }
    }

    void uploadVideo(const string &title)
    {
        latestVideo = title;
        cout << "new video uploaded";
        notify();
    }

    string getVideoData()
    {
        return latestVideo;
    }
};

class Subscriber : public ISubscriber
{
private:
    string name;
    Channel *channel;

public:
    Subscriber(const string &name, Channel *channel)
    {
        this->name = name;
        this->channel = channel;
    }

    // Called by Channel; prints notification message
    void update() override
    {
        cout << endl << "Hey " << name << "," << this->channel->getVideoData();
    }
};

int main()
{

    Channel *chan = new Channel("coder sagar");
    Subscriber *s1 = new Subscriber("s1", chan);
    Subscriber *s2 = new Subscriber("s2", chan);

    chan->subscribe(s1);
    chan->subscribe(s2);

    chan->uploadVideo("Leja ve");

    chan->unsubsribe(s2);

    chan->uploadVideo("Decorator pater video");

    return 0;
}