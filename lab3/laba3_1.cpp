#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Part { public: virtual void show()=0; virtual ~Part(){} };
class Assembly: public Part {
    string name;
public:
    Assembly(string n):name(n){}
    void show() override { cout<<"Сборка: "<<name<<endl; }
};
int main(){
    vector<shared_ptr<Part>> v;
    v.push_back(make_shared<Assembly>("Двигатель"));
    v.push_back(make_shared<Assembly>("Шасси"));
    for(auto&p:v)p->show();
    return 0;
}