// Polymorphism allows objects of different types to be treated as objects of a common base type.
#include <iostream>
using namespace std;
class Shape{
  friend void operator > (Shape& ,Shape &);
public:
  virtual double calArea()=0;
  virtual void display()=0;

    virtual ~Shape(){
    cout<<"Shape Destructor"<<endl;
  }
};
class Circle :public Shape{
private:
  double radius;
  double area;
public:
  Circle(double r):radius(r){}
  double calArea(){
    area=3.14*(radius*radius);
    return area;
  }
  void display(){
    cout<<"Circle Area is :"<<area<<endl;
  }
  double getarea(){
    return area;
  }
  ~Circle(){
    cout<<"Circle Destructor"<<endl;
  }
};
class Rectangle:public Shape{
private:
  double width;
  double height;
  double area;
public:
  Rectangle(double w,double h):width(w),height(h){}
  double calArea(){
    area=width*height;
    return area;
  }
  double getarea(){
    return area;
  }
  void display(){
    cout<<"Rectangle Area is :"<<area<<endl;
  }
  ~Rectangle(){
    cout<<"Rectangle Destructor"<<endl;
  }
};
class Triangle:public Shape{
private:
  double base;
  double height;
  double area;
public:
  Triangle(double b,double h):base(b),height(h){}
  double calArea(){
    area=0.5*(base*height);
    return area;
  }
  double getarea(){
    return area;
  }
  void display(){
    cout<<"Triangle Area is :"<<area<<endl;
  }
  ~Triangle(){
    cout<<"Triangle Destructor"<<endl;
  }
};
void operator >(Shape& s,Shape&r){
  if(s.calArea() > r.calArea()){
    s.display();
    cout<<" has Greater Area than ";
    r.display();
  }
  else{
    r.display();
    cout<<" has Greater Area than ";
    s.display();
  }
}
int main(int argc, char const *argv[]) {
Shape *s=new Circle(5);
Shape *r=new Rectangle(4,6);
Shape *t=new Triangle(3,7);
*s> *r;
cout<<endl;
delete t;
delete r;
delete s;
  return 0;
}
