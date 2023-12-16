#include <iostream>
using namespace std;
class Employee{
private:
  string name;
  int id;
  double salary;
public:
  Employee(){}
  Employee(string n,int i,double s):name(n),id(i),salary(s){}
  virtual void display (){
    cout<<"Employee Name:"<<name<<endl;
    cout<<"Employee ID:"<<id<<endl;
    cout<<"Salary:"<<salary<<endl;
  }
   void operator <<(Employee &a){
    a.display();
}
void displayDetails(Employee &b){
  b.display();
}
friend Employee CompareSalaries(Employee& a,Employee& b);
Employee operator +(Employee &b){
  Employee a;
  a.salary=salary+b.salary;
  return a;
}

double getsalary(){
  return salary;
}
};
class Manager:public Employee{
private:
  int projectsManaged;
public:
  Manager(int project,string n,int i,double s)
  :Employee(n,i,s){
    this->projectsManaged=project;
  }
  void display(){
    Employee::display();
    cout<<"Project Managed:"<<projectsManaged<<endl;
  }
};
class Developer:public Employee{
private:
  string ProgrammingLanguage;
public:
  Developer(string ProgrammingLanguage,string n,int i,double s)
  :Employee(n,i,s){
    this->ProgrammingLanguage=ProgrammingLanguage;
  }
  void display(){
    Employee::display();
    cout<<"Programming Language:"<<ProgrammingLanguage<<endl;
  }
};
Employee CompareSalaries(Employee& a,Employee& b){
  if(a.salary>b.salary){
    return a;
  }
  else return b;
}
int main(int argc, char const *argv[]) {
  Employee *d=new Developer("C++","KAif",9307,100);
  *d << *d;
  Employee *s=new Manager(5,"Adil",9307,150);
  Employee res;
  res= *d+*s;
  cout<<"Salary:"<<res.getsalary()<<endl;
  Employee res2;
  res2=CompareSalaries(*d,*s);
  cout<<endl;
  res2.display();
  cout<<"Has Higer Salary";
  cout<<endl;
  cout<<endl;
  d->displayDetails(*d);
  delete d;
  delete s;
  return 0;
}
