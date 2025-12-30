#include <iostream>
#include <string>

using namespace std;


class IReports {
    public:
    virtual string getJsonData()  = 0;
};

class XMLProvider {
    public:
    XMLProvider(){}
    ~XMLProvider(){}
    string getXMLData(){
        cout<<"XML DATA"<<endl;
        return "THIS DATA IS IN XML FORMAT";
    }
};

class XMLAdapter : public IReports {
   private:
   XMLProvider* xmlProvider;
   public:
   XMLAdapter(){
    xmlProvider = new XMLProvider();
   }
   ~XMLAdapter(){
    delete xmlProvider;
   }
   string getJsonData () override {
      string xml = xmlProvider->getXMLData();
      return xml+"This is json now after conversion";
   }
};

int main(){
   IReports* jsonGiver = new XMLAdapter();
   cout<<jsonGiver->getJsonData();
}