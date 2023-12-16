#include <iostream>
using namespace std;
class Product{
private:
  int productID;
  string name;
  double price;
  int quantity;
public:
  Product(){}
  Product(int productID,string name,double price,int quantity){
    this->productID=productID;
    this->name=name;
    this->price=price;
    this->quantity=quantity;
  }
  int getProductId(){
    return productID;
  }
  string getName(){
    return name;
  }
  double getPrice(){
    return price;
  }
  int getQuantity(){
    return quantity;
  }
  void display(){
    cout<<"Product Id:"<<getProductId()<<endl;
    cout<<"Product Name:"<<getName()<<endl;
    cout<<"Product Price:"<<getPrice()<<endl;
    cout<<"quantity:"<<getQuantity()<<endl;
  }
};
class User{
private:
static  int UserID;
  string name;
  Product *ShoppingCart;
  int size=0;
public:
  User(){

  }
  User(string name){
      UserID++;
    this->name=name;
    ShoppingCart=new Product[100];
  }
  void AddProduct(int ProductId,string name,double price,int quantity){
    if(size<100){
      ShoppingCart[size]=Product(ProductId,name,price,quantity);
      size++;
    }
    else
    cout<<"Limit Exceed"<<endl;
  }
  void deleteProduct(int ProductId){
    for (size_t i = 0; i < size; i++) {
      if (ProductId==ShoppingCart[i].getProductId()) {
          for (size_t j = 0; j < size-1; j++) {
            ShoppingCart[j]=ShoppingCart[j+1];
          }
          size--;
          cout<<"Product Deleted"<<endl;
          return;
      }
    }
    cout<<"Product not found"<<endl;
  }
  int getUserId(){
    return UserID;
  }
  string getName(){
    return name;
  }
virtual  void display(){
    cout<<"User ID:"<<UserID<<endl;
    cout<<"User Name:"<<name<<endl;
    for (size_t i = 0; i < size; i++) {
      cout<<"Product Id:"<<ShoppingCart[i].getProductId()<<endl;
      cout<<"Product Name:"<<ShoppingCart[i].getName()<<endl;
      cout<<"Product Price:"<<ShoppingCart[i].getPrice()<<endl;
      cout<<"quantity:"<<ShoppingCart[i].getQuantity()<<endl;
    }
  }
  ~User(){
    delete [] ShoppingCart;
  }
  int getsize(){
    return size;
  }
  void setNAme(string n){
    this->name=n;
  }
};
int User::UserID=0;
class RegisteredUser:public User{
private:
  string Username;
  string Password;
public:
  RegisteredUser(){}

  RegisteredUser(string Username,string Password,string name):User(name){
    this->Username=Username;
    this->Password=Password;
  }
  void display(){
    if(getsize()==0){
      cout<<"No Order...:("<<endl;
    }
    else{
    User::display();
    cout<<"UserName:"<<Username<<endl;
  }
  }
  void setData(string n,string pass){
    this->Username=n;
    this->Password=pass;
  }
  string getUsername(){
    return Username;
  }
  string getPassword(){
    return Password;
  }
};
class Store{
private:
  Product *store;
  RegisteredUser *registered;
  int productCount=0;
  int UserCount=0;
public:
  Store(){
    store=new Product[100];
    registered=new RegisteredUser[100];
  }
  void AddProduct(int productID,string name,double price,int quantity){
    if(productCount<100){
      store[productCount]=Product(productID,name,price,quantity);
      productCount++;
      cout<<"Product added Succesfully!!"<<endl;
    }
    else
    cout<<"Limit Full"<<endl;
  }
  void Display2(){
    registered->display();
  }
  void RegisterUseR(string Username,string Password,string name){
    if (UserCount<100) {
      registered[UserCount]=RegisteredUser(Username,Password,name);
      UserCount++;
      cout<<"User Registered Succesfully"<<endl;
    }
    else
    cout<<"Limit Full"<<endl;
  }
  void DisplayUser(){
    if (UserCount==0) {
      cout<<"Please add User First:("<<endl;
      cout<<endl;
    }
    else {
    for (size_t i = 0; i < UserCount; i++) {
        cout<<"User order History....."<<endl;
      registered[i].display();
    }
  }
  }
  void Login(string UserName,string Password){
  for (size_t i = 0; i < UserCount; i++) {
    if (UserName==registered[i].getUsername()&&Password==registered[i].getPassword()) {
      cout<<"Login Successfully"<<endl;
      int ch;
      do {
          cout<<"[1] Add Product To Cart"<<endl;
          cout<<"[2] Remove Product From Cart"<<endl;
          cout<<"[0] Exit"<<endl;
          cout<<"Your Choice:"<<endl;
          cin>>ch;
          switch (ch) {
            case 1:
            if (productCount==0) {
              cout<<"Their is not Product :("<<endl;
            }
            else{
            cout<<"Product in the Store:"<<endl;
            for (size_t i = 0; i < productCount; i++) {
              store[i].display();
            }

            int id,quantity;
            double price;
            string name;
            cout<<"Enter Product Detail to Add product to cart"<<endl;
            cout<<"Enter ProductID:"<<endl;
            cin>>id;
            cout<<"Enter Product Name:"<<endl;
            cin>>name;
            cout<<"Price:"<<endl;
            cin>>price;
            cout<<"Enter Quantity:"<<endl;
            cin>>quantity;
            registered[i].AddProduct(id,name,price,quantity);
          }
          break;
          case 2:
          int id;

          cout<<"Enter Product ID to Delete Product:"<<endl;
          cin>>id;
          if (registered[i].getsize()==0) {
            cout<<"No Product in cart"<<endl;
          }
          else{
          registered[i].deleteProduct(id);
}
          break;
          }
      } while(ch!=0);

    }
    else cout<<"Incorrect Username and Password"<<endl;
  }
  if (UserCount==0) {
    cout<<"First Register an Account"<<endl;
  }
  }
  void ParticularDetail(int ProductID){
    for (size_t i = 0; i < productCount; i++) {
      if (ProductID==store[i].getProductId()) {
        store[i].display();
        return;
      }

   }
   cout<<"Product not Found.."<<endl;
   cout<<endl;
  }
  ~Store(){
    delete [] store;
    delete [] registered;
  }
};
void menu(){
  cout<<endl;
  cout<<"[1] Register Account"<<endl;
  cout<<"[2] Login"<<endl;
  cout<<"[3] Add Product"<<endl;
  cout<<"[4] display Particular Product Information"<<endl;
  cout<<"[5] Display Users Detail"<<endl;
  cout<<"[6] Display User Order History"<<endl;
  cout<<"[0] Exit "<<endl;
}
int main(int argc, char const *argv[]) {
Store *s=new Store[110];
int choice;
do{
menu();
cout<<"Your Choice:"<<endl;
cin>>choice;

if (choice==1) {

  string name;
  string username;
  string pass;
  cout<<"Enter Name:"<<endl;
  cin>>name;
  cout<<"Enter UserName:"<<endl;
  cin>>username;
  cout<<"Enter Password:"<<endl;
  cin>>pass;
  s->RegisterUseR(username,pass,name);
}
  else if (choice==2){
  string username;
  string pass;
  cout<<"Enter Username:"<<endl;
  cin>>username;
  cout<<"Enter Password:"<<endl;
  cin>>pass;
  s->Login(username,pass);
}
else if(choice==3){
  string pass="admin123";
  string pss2;
  cout<<"Only Admin Can Add Product,Enter Password:"<<endl;
  cin>>pss2;
  if (pss2==pass) {
    cout<<"Login Succesfully..."<<endl;
    int productid;
    string name;
    double price;
    int ch;
    int quantity;
    do{

    cout<<"Enter Product ID:"<<endl;
    cin>>productid;
    cout<<"Enter Product Name:"<<endl;
    cin>>name;
    cout<<"Enter Price:"<<endl;
    cin>>price;
    cout<<"Enter Product Quantity:"<<endl;
    cin>>quantity;
    s->AddProduct(productid,name,price,quantity);
    cout<<"Press 0 to Exit and 1 to Continue"<<endl;
    cin>>ch;
  }while(ch!=0);
  }
  else cout<<"Incorrect Password!!"<<endl;
}
else if(choice==4){
  int productid2;
  cout<<"Enter ProductId of to Display Product:"<<endl;
  cin>>productid2;
  s->ParticularDetail(productid2);
}
else if(choice==5){
  string pass="admin123";
  string pss2;
  cout<<"Only Admin Can See User Detail,Enter Password:"<<endl;
  cin>>pss2;
    if (pss2==pass) {
      cout<<"Login Succesfully..."<<endl;
      s->DisplayUser();
    }
    else {
      cout<<"Incorrect Password"<<endl;
    }
}
else if(choice==6){
s->Display2();
}
}while(choice!=0);
delete [ ] s;
  return 0;
}
