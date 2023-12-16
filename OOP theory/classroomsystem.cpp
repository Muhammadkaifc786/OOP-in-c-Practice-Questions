#include <iostream>
using namespace std;
class User{
private:
  string username;
  string password;
  string usertype;
public:
  User(){}
  User(string u,string p,string type):username(u),password(p)
  ,usertype(type){
  }

  virtual void display(){
    cout<<"User Name:"<<username<<endl;
    cout<<"Password:"<<password<<endl;
    cout<<"User type:"<<usertype<<endl;
  }
};
class Student:public User{
  int StudentId;
public:
  Student(){}
  Student(int id,string u,string p,string type)
  :User(u,p,type){
    this->StudentId=id;
  }
  void display(){
    User::display();
    cout<<"Student Id:"<<StudentId<<endl;
  }
  int getid(){
    return StudentId;
  }
  void operator <<(Student & u){
    u.display();
  }
};
class Teacher:public User{
private:
  int TeacherId;
public:
  Teacher(){}
  Teacher(int id,string u,string p,string type)
  :User(u,p,type){
    TeacherId=id;
  }
  void operator <<(Teacher & u){
    u.display();
  }
  void display(){
    User::display();
    cout<<"Teacher Id:"<<TeacherId<<endl;
  }
};
class Assign{
private:
  string AssignmnetName;
  int Assignmentno;
  string SubmissionDeadline;
  double weightage;
public:
  Assign(){}
  Assign(string n,int no,string deadline,double w)
  :AssignmnetName(n),Assignmentno(no),SubmissionDeadline(deadline),weightage(w){}
  void display(){
    cout<<"Assignment Title:"<<AssignmnetName<<endl;
    cout<<"Assignment No:"<<Assignmentno<<endl;
    cout<<"Deadline:"<<SubmissionDeadline<<endl;
    cout<<"Weightage:"<<weightage<<endl;
  }
};
class Course{
private:
  Assign *a;
  Student *s;
  string CourseCode;
  string CourseName;
  Teacher *t;
  int CourseCredits;
  int studentcount=0;
  int teachercount=0;
  int Assigncount=0;
public:
  Course(string code,string name,int credit){
    this->CourseCode=code;
    this->CourseName=name;
    this->CourseCredits=credit;
    s=new Student[100];
    t=new Teacher [100];
    a=new Assign[5];
  }
  void enrollStudent(Student &std){
    if (studentcount<100) {
      s[studentcount]=std;
      studentcount++;
    }
    else {
      cout<<"Course is Full"<<endl;
    }
  }
  void withdrawStudent(int id){
    for (size_t i = 0; i < studentcount; i++) {
      if (s[i].getid()==id) {
        s[i]=s[i+1];
        studentcount--;
        return;
      }
    }
    cout<<"Student not found"<<endl;
  }
  void setinstructor(Teacher &thr){
    if(teachercount<100){
      t[teachercount]=thr;
      teachercount++;
    }
    else{
      cout<<"No Teacher Left"<<endl;
    }
  }
  void addAssignment(string title,int no,string deadline,double weightage){
    if (Assigncount<5) {
      a[Assigncount]=Assign(title,no,deadline,weightage);
      Assigncount++;
    }
    else{
      cout<<"Can't Give More Assignmnets:"<<endl;
    }
  }
  void displayAssignment(){
    cout<<"Assignment Detail"<<endl;
    cout<<"Course Name:"<<CourseName<<endl;
    cout<<"Course Code:"<<CourseCode<<endl;
    for (size_t i = 0; i < Assigncount; i++) {
      a[i].display();
    }
  }
  void displayStudentInfo(){
    cout<<"Entrolled Student"<<endl;
    cout<<endl;
    cout<<"Course Name:"<<CourseName<<endl;
    cout<<"Course Code:"<<CourseCode<<endl;
    cout<<"Course Credit Hours:"<<CourseCredits<<endl;
    for (size_t i = 0; i < studentcount; i++) {
      s[i].display();
    }
  }
  void displayTeacherInfo(){
    cout<<"Assigned Teacher"<<endl;
    cout<<"Course Name:"<<CourseName<<endl;
    cout<<"Course Code:"<<CourseCode<<endl;
    cout<<"Course Credit Hours:"<<CourseCredits<<endl;
    for (size_t i = 0; i < teachercount; i++) {
      t[i].display();
    }
  }
  void operator <<(Course &c){
    c.displayStudentInfo();
    cout<<"-------------------"<<endl;
    c.displayTeacherInfo();
    cout<<"-------------------"<<endl;
    c.displayAssignment();
  }
  ~Course(){
    delete [] s;
    delete [] t;
    delete [] a;
  }
};
int main(int argc, char const *argv[]) {
Teacher *t =new Teacher(9301,"Kaif","123","Teacher");
Student *s=new Student(9301,"Ali","786","Student");
Course c1("CS-933","OOP",3);
c1.enrollStudent(*s);
c1.setinstructor(*t);
c1.withdrawStudent(9301);
c1.addAssignment("Operator Overloading",3,"11-12-2023",2.5);
c1 << c1;
cout<<"--------------------"<<endl;
*t << *t;
cout<<"--------------------"<<endl;
*s << *s;
delete t;
  return 0;
}
