#include <iostream>
#include <string>
using namespace std;

class sales {
protected:
    float salesArr[3];
public:
    void getdata() { for (int i=0;i<3;i++){ cout<<"Продажи "<<i+1<<": ";cin>>salesArr[i]; } }
    void putdata() const { for (float s: salesArr) cout<<s<<" "; cout<<endl; }
};

class publication {
protected:
    string title; float price;
public:
    void getdata(){ cout<<"Название: ";cin.ignore();getline(cin,title);cout<<"Цена: ";cin>>price; }
    void putdata()const{ cout<<title<<" - "<<price<<" руб."<<endl; }
};

class book: public publication, public sales {
    int pages;
public:
    void getdata(){ publication::getdata(); cout<<"Страниц: ";cin>>pages; sales::getdata(); }
    void putdata()const{ publication::putdata(); cout<<"Страниц: "<<pages<<endl; sales::putdata(); }
};

int main(){ book b; b.getdata(); b.putdata(); return 0; }