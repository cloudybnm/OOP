#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Transport{public:virtual void show()const=0;virtual~Transport(){};};
class Bicycle:public Transport{int gears;public:Bicycle(int g):gears(g){}void show()const override{cout<<"Велосипед: "<<gears<<" передач"<<endl;}};
class Car:public Transport{int seats;public:Car(int s):seats(s){}void show()const override{cout<<"Автомобиль: "<<seats<<" мест"<<endl;}};
class Truck:public Transport{double cap;public:Truck(double c){if(c<0)throw underflow_error("Отрицательная грузоподъемность");cap=c;}void show()const override{cout<<"Грузовик: "<<cap<<" т"<<endl;}};

template<typename T>class PtrArray{vector<T*>v;public:void add(T*p){v.push_back(p);}T*operator[](size_t i){if(i>=v.size())throw out_of_range("bad index");return v[i];}size_t size()const{return v.size();}};

int main(){
    try{
        PtrArray<Transport> a;
        Bicycle*b=new Bicycle(18);Car*c=new Car(5);Truck*t=new Truck(12.5);
        a.add(b);a.add(c);a.add(t);
        for(size_t i=0;i<a.size();i++)a[i]->show();
        delete b;delete c;delete t;
    }catch(const exception&e){cerr<<"Ошибка: "<<e.what()<<endl;}
    return 0;
}