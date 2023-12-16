#include <iostream>
#include <ctime>
using namespace std;
string cointoss(){

  int randomNumber = rand() % 2 + 1;
  if (randomNumber==1) {
    return "Head";
  }
  else if(randomNumber==2){
    return "Tail";

  }
}
int main(int argc, char const *argv[]) {
  srand(time(0));
  int time,result;
  cout<<"How many time do you want to toss the coin?";
  cin>>time;
  for (size_t i = 0; i < time; i++) {
    cout<<"Toss ["<<i+1<<"] :"<<cointoss()<<endl;
  }

  return 0;
}
