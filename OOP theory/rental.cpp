#include <iostream>
using namespace std;
class Vehicle{
protected:
  int vehicleID;
  string model;
  double rate;
  string availability;
public:
  Vehicle(int id,string m,double rate,string a){
    this->vehicleID=id;
    this->model=m;
    this->rate=rate;
    this->availability=a;
  }
  virtual double CalculateRentalrate(int)=0;
  void isAvailable(){
    if (availability=="Available") {
      cout<<"Yes car is Available"<<endl;
    }
    else{
      cout<<"Vehicle is not Available for rent"<<endl;
    }
  }

  void Rent(){
    if (availability=="Available") {
      availability="Rented";
      cout<<"Car rented!"<<endl;
    }
    else{
      cout<<"Vehicle is not Available for rent"<<endl;
    }
  }
  void Return(){

    availability="Available";
    cout<<"Car Return!!"<<endl;

  }
  double getrate(){
    return rate;
  }
  void setrate(double r){
    this->rate=r;
  }
  void operator <<(Vehicle &v){
    v.display();
  }
  void operator >>(Vehicle &b){
    cout<<"Enter Vehicle ID:";
    cin>>b.vehicleID;
    cout<<"Model :"<<endl;
    cin>>b.model;
    cout<<"Rate"<<endl;
    cin>>b.rate;
    cout<<"Availability:"<<endl;
    cin>>b.availability;
  }
  virtual void display(){
    cout<<"Vehicle Id:"<<vehicleID<<endl;
    cout<<"Model:"<<model<<endl;
    cout<<"Rental Rate:"<<rate<<endl;
    cout<<"Availability:"<<availability<<endl;
  }
};
class Car:public Vehicle{
private:
  string name;
public:
  Car(string name,int id,string m,double rate,string a)
  :Vehicle(id,m,rate,a){
    this->name=name;
  }
  double  CalculateRentalrate(int hours){
      double r;
      r=getrate()*hours;
      return r;
  }
  void display(){
    cout<<"Car Type:"<<name<<endl;
    Vehicle::display();
  }
  void setName(string n){
    this->name=n;
  }
};
class Bike:public Vehicle{
private:
  string name;
public:
  Bike(string n,int id,string m,double rate,string a)
  :Vehicle(id,m,rate,a){
    this->name=n;
  }
  void setName(string n){
    this->name=n;
  }
  double  CalculateRentalrate(int hours){
      double r;
      r=getrate()*hours;
      return r;
  }
  void display(){
    cout<<"Bike Type:"<<name<<endl;
    Vehicle::display();
  }
};
class Truck:public Vehicle{
private:
  string Trucktype;
public:
  Truck(string type,int id,string m,double rate,string a)
  :Vehicle(id,m,rate,a){
    this->Trucktype=type;
  }
  void setName(string n){
    this->Trucktype=n;
  }
  double  CalculateRentalrate(int hours){
      double r;
      r=getrate()*hours;
      return r;
  }
  void display(){
    cout<<"Truck Type:"<<Trucktype<<endl;
    Vehicle::display();
  }
};
int main(int argc, char const *argv[]) {
  Vehicle *c=new Car("Audi",9307,"A3",100,"Available");
  Vehicle *b=new Bike("Honda",9301,"CD",50,"Available");
  Vehicle *t=new Truck("Mercedes",9300,"M3",500,"Available");

    c->Rent();

    c->isAvailable();
    cout<<"---------------"<<endl;
    *c<<*c;
    cout<<"---------------"<<endl;
    cout<<"Total Rent:"<<c->CalculateRentalrate(3);
    delete c;
    delete b;
    delete t;
  return 0;
}
