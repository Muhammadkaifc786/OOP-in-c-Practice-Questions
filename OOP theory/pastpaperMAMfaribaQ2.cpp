#include <iostream>
#include <string>
using namespace std;

class Post{
private:
  string title;
  string description;
public:
  Post(){

  }
  Post(string title,string description){
    this->title=title;
    this->description=description;
  }
  void settitle(string t){
    title=t;
  }
  void setDescription(string d){
    description=d;
  }
  string gettitle(){
    return title;
  }
  string getdescription(){
    return description;
  }
  void display(){
    cout<<"Post Title:"<<gettitle()<<endl;
    cout<<"Post Description:"<<getdescription()<<endl;
  }
};
class UserAccount{
private:
  string username;
  string password;
  Post *p;
  int size=0;
public:
  UserAccount(){}
  UserAccount(string username,string password){
    this->username=username;
    this->password=password;
    p=new Post[100];
  }
  virtual void display(){
    cout<<"UserName:"<<username<<endl;
    cout<<"Password:"<<password<<endl;
  }
  void AddPost(string title,string description){
      if(size<100){
        p[size]=Post(title,description);
        size++;
        cout<<"Post Uploaded...."<<endl;
      }
      else {
        cout<<"Limit Exceed..."<<endl;
      }
  }
  void ViewAllPost(){
    if(size==0){
      cout<<"You don't Have Uploaded any Post :("<<endl;
    }
    else{
    for (size_t i = 0; i < size; i++) {
      p[i].display();
    }
  }
  }
  ~UserAccount(){
    delete [] p;
  }
};
class PersonalAccount:public UserAccount{
private:
  string Gender;
public:
  PersonalAccount(){}
  PersonalAccount(string Gender,string Username,string Password)
  :UserAccount(Username,Password){
    this->Gender=Gender;
  }
  void display(){
    UserAccount::display();
    cout<<"Gender:"<<Gender<<endl;
  }

};
class Bussiness:public UserAccount{
private:
  double revenue;
public:
  Bussiness(){}
  Bussiness(double revenue,string username,string password)
  :UserAccount(username,password){
    this->revenue=revenue;
  }
  void display(){
    UserAccount::display();
    cout<<"Revenue:"<<revenue<<endl;
  }
};
int main(int argc, char const *argv[]) {
  UserAccount *ptr1;

  UserAccount *ptr2;
  int ch;
  cout<<"Which Type of Account you want ot create?"<<endl;
  cout<<"[1] Personal Account"<<endl;
  cout<<"[2] Bussiness Account"<<endl;
  cin>>ch;
  if (ch==1) {
    string username;
    string password;
    string gender;
    cout<<"Enter Your UserName:"<<endl;
    cin>>username;
    cout<<"Enter Password:"<<endl;
    cin>>password;
    cout<<"Enter Your Gender:"<<endl;
    cin>>gender;
    PersonalAccount p(gender,username,password);
    ptr1=&p;
    string title;
    string description;
    cout<<"lets Create some Post Now"<<endl;
    cout<<"Enter Title:"<<endl;
    cin>>title;
    cin.ignore();
    cout<<"Enter Description:"<<endl;
    getline(cin,description);
    ptr1->AddPost(title,description);
    do {
      int ch;
      cout<<"Do You Want to Add another Post?"<<endl;
      cout<<"[1] Yes"<<endl;
      cout<<"[2] No"<<endl;
      cin>>ch;
      if (ch==1) {
        string title;
        string description;
        cout<<"lets Create some Post Now"<<endl;
        cout<<"Enter Title:"<<endl;
        cin>>title;
        cin.ignore();
        cout<<"Enter Description:"<<endl;
        getline(cin,description);
        ptr1->AddPost(title,description);
      }
    else if(ch==2){
      break;
    }
  } while(1);
  ptr1->display();
  cout<<endl;
  ptr1->ViewAllPost();
  }
  else if (ch==2) {
    string username;
    string password;
    double revenue;
    cout<<"Enter Your UserName:"<<endl;
    cin>>username;
    cout<<"Enter Password:"<<endl;
    cin>>password;
    cout<<"Enter Your Revenue:"<<endl;
    cin>>revenue;
    Bussiness b(revenue,username,password);
    ptr2=&b;
    string title;
    string description;
    cout<<"lets Create some Post Now"<<endl;
    cout<<"Enter Title:"<<endl;
    cin>>title;
    cin.ignore();
    cout<<"Enter Description:"<<endl;
    getline(cin,description);
    ptr2->AddPost(title,description);
    do {
      int ch;
      cout<<"Do You Want to Add another Post?"<<endl;
      cout<<"[1] Yes"<<endl;
      cout<<"[2] No"<<endl;
      cin>>ch;
      if (ch==1) {
        string title;
        string description;
        cout<<"lets Create some Post Now"<<endl;
        cout<<"Enter Title:"<<endl;
        cin>>title;
        cin.ignore();
        cout<<"Enter Description:"<<endl;
        getline(cin,description);
        ptr2->AddPost(title,description);
      }
      else if (ch==2) {
      break;
      }
    else{
      cout<<"Enter Correct Option"<<endl;
    }
  }while(1);
  ptr2->display();
  cout<<endl;
  ptr2->ViewAllPost();
  }
  return 0;
}
