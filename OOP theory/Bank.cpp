#include <iostream>
using namespace std;
class Account{
private:
  int id;
  string name;
  double balance;
public:
  Account(){
  }
  Account(int i,string n,double b):id(i),name(n),balance(b){
  }
  double getBal(){
    return balance;
  }
  void display(){
    cout<<"Account Holder Id:"<<id<<endl;
    cout<<"Account Holder Name:"<<name<<endl;
    cout<<"Balance:"<<balance<<endl;
  }
  void withdaw(double amount){
    if (amount>balance||amount<0) {
      cout<<"Insuffient Balance"<<endl;
    }
    else{
      balance-=amount;
      cout<<"Withdraw Succefully"<<endl;
    }
  }
  string getname(){
    return name;
  }
  friend void operator > (Account &a,Account &b);
  void operator <<(Account &s){
    s.display();
  }
  void deposit(double amount){
    if (amount<0) {
    cout<<"Invalid Amount"<<endl;
    }
    else{
      balance+=amount;
    }
  }
  friend void transferfunds(Account &to,Account &from,double amount);

};
class Bank{
private:
  Account *acc;
  int size=0;
public:
  Bank(){
    acc=new Account[100];
  }
  void addAccount(Account &r){
    if(size<100){
      acc[size]=r;
      size++;
    }

    else{
      cout<<"Limit Exceed"<<endl;
    }
  }
  void displayAllAcounts(){
    for (size_t i = 0; i < size; i++) {
      acc[i].display();
    }
  }
  ~Bank(){
    delete [] acc;
  }
};
void transferfunds(Account &from,Account &to,double amount){
  if (amount>0) {
    from.balance-=amount;
    to.balance+=amount;
  }
  else{
    cout<<"Invalid Account"<<endl;
  }
}
 void operator > (Account &a,Account &b){
  if(a.getBal()>b.getBal()){
    cout<<a.name<<" Has greater Balance than "<<b.name;
  }
  else{

    cout<<b.name<<" Has greater Balance than "<<a.name;

  }
}
int main(int argc, char const *argv[]) {
Account a1(9307,"Kaif",10000);
Account a2(9301,"Ali",500);
Bank b1;
b1.addAccount(a1);
b1.addAccount(a2);
a1.display();
a2.display();
transferfunds(a1,a2,500);
cout<<endl;
a1.display();
a2.display();
cout<<endl;
b1.displayAllAcounts();
cout<<endl;
a1>a2;
  return 0;
}
