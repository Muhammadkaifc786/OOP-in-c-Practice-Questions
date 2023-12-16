#include <iostream>
#include <string>
using namespace std;

class User{
private:
  string username;
  string password;
  int userid;
  string fullname;
  User *s;
  int friendcout=0;
public:
  User(){}
  User (string u,string p,int id,string fname){
    this->username=u;
    this->password=p;
    this->userid=id;
    this->fullname=fname;
    s=new User[100];
  }
  void addfriend(User &u){
    if(friendcout<100){
      s[friendcout]=u;
      friendcout++;
    }
    else{
      cout<<"Friend List is Full :("<<endl;
    }
  }
  int getuserid(){
    return userid;
  }
  void removefriend(int id){
    for (size_t i = 0; i < friendcout; i++) {
      if (id==getuserid()) {
        s[i]=s[i+1];
        friendcout--;
        return;
      }
    }
    cout<<"Friend not found!!"<<endl;
  }
  string getusername(){
    return fullname;
  }
  void displayUserprofile(){
    for (size_t i = 0; i < friendcout; i++) {
    s[i].display() ;
    }
  }

  void display(){
    cout<<"Full name:"<<fullname<<endl;
    cout<<"User id:"<<userid<<endl;
    // cout<<"UserName:"<<username<<endl;
    // cout<<"PAssword:"<<password<<endl;
  }
};
class Post{
private:
  int postid;
  User *liked;
  string content;
  int likecount=0;
  Post *p;
  int postcount=0;
  User *cu;
  int cucount=0;
public:
  Post(){

  }
  Post(int postid,string content){
    this->postid=postid;
    this->content=content;
    liked=new User[100];
    p=new Post[100];
    cu=new User[100];
  }
  void createPost(User &u,int id,string content){
    if (postcount<100) {
        p[postcount]=Post(id,content);
        postcount++;
        cu[cucount]=u;
        cucount++;
    }
    else {
      cout<<"Limit Exceed"<<endl;
    }
  }
  void displayPost(){
    for (size_t i = 0; i < cucount; i++) {
      cu[i].display();
    }
    for (size_t i = 0; i < postcount; i++) {
      p[i].displayPostDetail();
    }
  }
  void addlike(User &u,int id){
    for (size_t i = 0; i < likecount; i++) {
      if (liked[i].getuserid() == u.getuserid()) {
        cout<<"Error User Already liked!!"<<endl;
        return;
      }
    }
    if (likecount<1000) {
      liked[likecount]=u;
      for (size_t i = 0; i < postcount; i++) {
        if (p[i].getpostid()==id) {
          p[i].likecount++;
          break;
        }

      }

      cout<<u.getusername()<<" Has liked the Post"<<endl;
      likecount++;
    }
    else {
      cout<<"Maximum like are reached"<<endl;
    }
  }

  int getlikecount(){
    return likecount;
  }
  void displaylike(){
    for (size_t i = 0; i < likecount; i++) {
      liked[i].display();
    }
  }
void displayPostDetail(){
  cout<<"Post id:"<<postid<<endl;
  cout<<"Content:"<<content<<endl;
  cout<<"Total likes:"<<getlikecount()<<endl;
}
int getpostid(){
  return postid;
}
};
class Comment{
private:
  string content;
  int commentid;
  User *u;
  Comment *c;
  int commentcount=0;
  int count=0;
public:
  Comment(){

  }
  Comment(int id,string content){
    this->commentid=id;
    this->content=content;
    u=new User[1000];
    c=new Comment[1000];
  }
  void display2(){
    cout<<"Comment:"<<content<<endl;
  }
  void setcontent(string content){
    this->content=content;
  }
void AddComment(User &t){

  for (size_t i = 0; i < count; i++) {
    if (u[i].getuserid()== t.getuserid()) {
      cout<<"User has Already Commented!"<<endl;
      return;
    }
  }
    if (count<1000) {
      u[count]=t;
      string cnt;

      // cout<<"--Enter Comment:"<<endl;
      // cin.ignore();
      // getline(cin,cnt);
      cnt=" Nice post";
      c[commentcount].setcontent(cnt);
      cout<<"Comment added"<<endl;
      count++;
    }
    else {
      cout<<"Comment limit is full"<<endl;
    }
  }

void displayComment(){
  for (size_t i = 0; i < count; i++) {
    u[i].display();
    c[i].display2();
  }
}
};
int main(int argc, char const *argv[]) {
User u1("kaif.cpp","@@123",123,"M.Kaif");
// u1.display();
User u2("Adil.cpp","@@786",786,"M.Adil");
// u1.addfriend(u2);
// cout<<"-----------------"<<endl;
// u1.displayUserprofile();
Post p1(9,"sunset");
p1.createPost(u2,9,"Sunset");

p1.addlike(u2,9);

p1.displayPost();








Comment c1(1,"nice");
c1.AddComment(u1);
c1.AddComment(u2);
c1.displayComment();
  return 0;
}
