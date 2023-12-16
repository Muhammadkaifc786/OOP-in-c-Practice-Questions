#include <iostream>
using namespace std;
class timeType{
private:
  int hour;
  int min;
  int sec;
public:
  timeType()  {
    hour=0;
    min=0;
    sec=0;
  }
  timeType(int hour,int min,int sec){
    this->hour=hour;
    this->min=min;
    this->sec=sec;
  }
  void display(){
    min=min+sec/60;
    sec=sec%60;
    hour=hour+min/60;
    min=min%60;
    cout<<hour<<":"<<min<<":"<<sec<<endl;
  }
  timeType operator +(timeType &other){
    timeType result;
    result.hour=hour+other.hour;
    result.min=min+other.min;
    result.sec=sec+other.sec;
    return result;
  }
  void operator ++(int){
    sec++;
  }
  void operator ++(){
    ++sec;
  }
  void operator --(int){
    sec--;
  }
  void operator --(){
    --sec;
  }
};
int main(int argc, char const *argv[]) {
  timeType t1(12,45,20),t2(3,19,20),t3;
  t3=t1+t2;
  t3.display();
  t3--;
  --t3;
  t3++;
  ++t3;
  t3.display();
  return 0;
}
