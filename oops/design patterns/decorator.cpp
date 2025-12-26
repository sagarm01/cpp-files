#include <iostream>
#include <string>

using namespace std;

class Character
{
public:
    virtual string getAbilities() = 0;
    ~Character() {}
};

class Mario : public Character
{
public:
    string getAbilities() override
    {
        return "Normal Mario";
    }
};

class CharacterDecorator: public Character
{
  protected:
  Character* character;
  public:

  CharacterDecorator(Character* c){
    this->character = c;
  }

};


// concreate decorator
class HeightUp: public CharacterDecorator{
   public:
   HeightUp(Character* c):CharacterDecorator(c){}

   string getAbilities() override {
    return character->getAbilities()+ "HIGHT UP ADDED";
   }
};



int main()
{
    Character* mario  = new Mario();
    cout<<mario->getAbilities()<<endl;

    mario = new HeightUp(mario);

    cout<<mario->getAbilities()<<endl;

    delete mario;

    return 0;

}