#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
using namespace std;

class Base{ public: virtual void action(){cout<<"Base"<<endl;} virtual ~Base(){} };
class Derived: public Base{ public: void action() override{cout<<"Derived"<<endl;} };

int main(){
    srand(time(0)); vector<shared_ptr<Base>> v;
    for(int i=0;i<10;i++) v.push_back((rand()%2)?make_shared<Base>():make_shared<Derived>());
    for(auto&p:v)p->action();
    return 0;
}