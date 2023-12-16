#include <iostream>
using namespace std;
float celcius(double f){
  return 5.0/9.0*(f-32);
}
int main(int argc, char const *argv[]) {
  for (size_t i = 0; i < 20; i++) {
    cout<<"Fahrenheit: ["<<i<<"]into celcius: "<<celcius(i)<<endl;
  }
  return 0;
}
