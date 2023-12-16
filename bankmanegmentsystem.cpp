#include <iostream>
#include <string>
using namespace std;

//______________________________________________________________________________
class Information {
private:
    string name;
    string address;
    string cnic;
    string mobile_no;
public:
    Information(){}
    Information(string name, string address, string cnic, string mobile_no) {
        this->name = name;
        this->address = address;
        this->cnic = cnic;
        this->mobile_no = mobile_no;
    }

    void setName(string name)
	 { this->name = name;
	 }

    void setAddress(string address)
	 { this->address = address;
	 }

	void setCnic(string cnic)
	 { this->cnic = cnic;
	 }

	void setMobileNo(string mobile_no)
	 { this->mobile_no = mobile_no; }

	string getName() const
	 { return name; }

	string getAddress() const
	 { return address; }

	string getCnic() const
	 { return cnic; }

	string getMobileNo() const
	 { return mobile_no; }

	friend ostream& operator<<(ostream& os, const Information& info);

	friend istream& operator>>(istream& in, Information& info);

};

ostream& operator<<(ostream& os, const Information& info) {
    os << "Name: " << info.getName() << endl
       << "Address: " << info.getAddress() << endl
       << "CNIC: " << info.getCnic() << endl
       << "Mobile No: " << info.getMobileNo() << endl;
    return os;
}

istream& operator>>(istream& in, Information& info) {
    cout << "Enter name: ";
    getchar();
    getline(in>>ws, info.name);

    cout << "Enter address: ";

    getline(in>>ws, info.address);

    cout << "Enter CNIC: ";
    getline(in>>ws, info.cnic);

    cout << "Enter mobile number: ";

    getline(in>>ws, info.mobile_no);

    return in;
}

//_______________________________________________________________
class Account {
private:
    string id;
    double balance;
    Information info;

public:
	Account(){
		string id="";
		balance=0;
	}
    Account(string id, double balance, Information info) {
        this->id = id;
        this->balance = balance;
        this->info = info;
    }

    void setId(string id) {
        this->id = id;
    }

    string getId() const {
        return id;
    }

    void setBalance(double balance) {

		if(balance<0)
    	cout<<"invalid input."<<endl;

    	else
        this->balance = balance;
    }

    double getBalance() const {

		return balance;
    }

    void setInfo(Information info) {

		this->info = info;
    }

    Information getInfo() const {

		return info;
    }

    virtual void deposit(double amount) {

		balance += amount;
        cout << "Deposited " << amount << " into account " << id << endl;
    }

    virtual void withdraw(double amount) {

		if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " from account " << id << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }

    void checkBalance() const {

		cout << "Account " << id << " has balance of " << balance << endl;
    }

    friend void transfer_balance(Account& from, Account& to, double amount);

    friend ostream& operator<<(ostream& os, const Account& account);

    friend istream& operator>>(istream& is, Account& account);

};

void transfer_balance(Account& from, Account& to, double amount) {
    if (from.balance - amount < 0) {
        cout << "Transfer failed. ";
    } else {
        from.balance -= amount;
        to.balance += amount;
        cout << amount << " transferred from";
    }
}

ostream& operator<<(ostream& os, const Account& account) {
    os << "Account id" << account.id << "\n"
       << "Account Information" << account.info << "\n"
       << "Balance: " << account.balance << "\n";
    return os;
}

istream& operator>>(istream& is, Account& account) {
    cout << "Enter account id "<<endl;
    is >> account.id;
    cout << "Enter info "<<endl;
    is >> account.info;
    cout << "Enter balance: "<<endl;
    is >> account.balance;
    return is;
}

//_____________________________________________________________

class CurrentAccount : public Account {
public:
	CurrentAccount(){}
    CurrentAccount(string id, double balance, Information info) : Account(id, balance, info) {}

    void withdraw(double amount) {
        double balance = getBalance();
        if (balance >= amount && amount<=50000) {
            setBalance(balance - amount);
            cout << "Withdrawal of " << amount << " made successfully" << endl;
        } else {
            cout << "Insufficient balance for withdrawal" << endl;
        }
    }
};

//_________________________________________________________________
class SavingAccount : public Account {

private:

    static double interestRate; // interest rate in percentage

public:
    SavingAccount()
    {

    }
    SavingAccount(string id, double balance, Information info, double rate) : Account(id, balance, info) {
	//addInterest();
	}

    void deposit(double amount) {
        setBalance(getBalance() + amount);
        cout << "Deposit of " << amount << " made successfully" << endl;
    }
    void withdraw(double amount)
    {
        double balance = getBalance();
        if (balance >= amount && amount<=20000) {
            setBalance(balance - amount);
            cout << "Withdrawal of " << amount << " made successfully" << endl;
        }
		else {
            cout << "Insufficient balance for withdrawal" << endl;
        }
    }

    void addInterest() {
        double balance = getBalance();
        double interest = balance * (interestRate/100.0);
        setBalance(balance + interest);
        cout << "Interest of " << interest << " added to account balance" << endl;
    }
};
  double SavingAccount::interestRate=0.5;
//_______________________________________________________________________

class Bank {
private:
    Account* accounts;
    int size;
public:
    Bank() {
        size = 0;
        accounts = nullptr;
    }

    ~Bank() {
        delete[] accounts;
    }

    void addAccount(Account* newAccount) {
        if (size == 0) {
            accounts = new Account[1];
            accounts[0] = *newAccount;
        } else {
            Account* newAccounts = new Account[size + 1];
            for (int i = 0; i < size; i++) {
                newAccounts[i] = accounts[i];
            }
            newAccounts[size] = *newAccount;
            delete[] accounts;
            accounts = newAccounts;
        }

        size++;
        cout << "Account added successfully" << endl;
    }

    void deleteAccount(string id) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (accounts[i].getId() == id) {
                found = true;
                for (int j = i; j < size - 1; j++) {
                    accounts[j] = accounts[j+1];
                }
                size--;
                break;
            }
        }
        if (found) {
            Account* newAccounts = new Account[size];
            for (int i = 0; i < size; i++) {
                newAccounts[i] = accounts[i];
            }
            delete[] accounts;
            accounts = newAccounts;
            cout << "Account deleted successfully" << endl;
        } else {
            cout << "Account not found" << endl;
        }
    }

    Account* Found(string id)
    {cout<<"done"<<endl;
        bool found=false;
        for (int i = 0; i < size; i++) {
            if (accounts[i].getId() == id)
               {
                return &accounts[i];}
                else
                {cout<<"Not found"<<endl;
                return nullptr;}
        }}

    void modifyAccount(string id) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (accounts[i].getId() == id) {
                // Found the account
                found = true;
                cout << "Enter new balance: ";
                double balance;
                cin >> balance;
                accounts[i].setBalance(balance);
                cout << "Account modified successfully" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found" << endl;
        }
    }

   void showAllAccounts() const {
        if (size > 0) {
            for (int i = 0; i < size; i++) {
                cout << "Account " << i+1 << ":" << endl;
                cout << "ID: " << accounts[i].getId() << endl;
                cout << "Balance: " << accounts[i].getBalance() << endl;
                Information info = accounts[i].getInfo();
                cout << "Name: " << info.getName() << endl;
                cout << "Address: " << info.getAddress() << endl;
                cout << "CNIC: " << info.getCnic() << endl;
                cout << "Mobile No: " << info.getMobileNo() << endl;
                cout << endl;
            }
        } else {
            cout << "No accounts found" << endl;
        }
    }
    //withdraw and deposit test
    void withdrawAmount(string id,int amount)
    {
        bool accountFound = false;
        for (int i = 0; i < size; i++) {
            if (accounts[i].getId() == id) {
                // Found the account
                accountFound = true;
                accounts[i].withdraw(amount);
                cout<<"Amount withdraw is successfull"<<endl;
                break;
            }
        }
        if (!accountFound) {
            cout << "Account not found" << endl;
        }
    }
    void depositAmount(string id,int amount)
   {
        bool found = false;
        for (int i = 0; i <size; i++) {
            if (accounts[i].getId() ==id) {
                // Found the account
                found = true;
                accounts[i].deposit(amount);
                cout<<"Amount deposited successfully"<<endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found" << endl;
        }
    }
};

//__________________________________________________________________________

class BillPayment {
private:
    Account* account;
public:
    BillPayment() {}
    BillPayment(Account* account) {
        this->account = account;
    }



    void payBill(string billType, double amount) {
        double balance = account->getBalance();
        if (balance >= amount) {
            account->setBalance(balance - amount);
            cout << "Bill payment of " << amount << " made successfully for " << billType << endl;
        } else {
            cout << "Insufficient balance for bill payment" << endl;
        }
    }
};

//__________________________________________________________________________
class Loan {
private:
    Account* account;
public:
    Loan() {}
    Loan(Account* account) {
        this->account = account;
    }
    void payLoan(double amount) {
        double balance = account->getBalance();
        if (balance >= amount) {
            account->setBalance(balance - amount);
            cout << "Loan payment " << amount << " returned successfully" << endl;
        } else {
            cout << "Insufficient balance for loan" << endl;
        }
    }
    void getLoan(double amount) {
        account->setBalance(account->getBalance() + amount);
        cout << "Loan of " << amount << " obtained successfully"<< endl;
    }
};

//________________________________________________________________________
int main()
{int choice;



    Information is;
    Information ic;
    SavingAccount as;
    CurrentAccount ac;
        Bank bank;
do{

    cout<<"--------Menu-------"<<endl;
    cout<<"1-Add Account"<<endl;
    cout<<"2-Delete Account"<<endl;
    cout<<"3-Modify Account "<<endl;
    cout<<"4-Show all accounts"<<endl;
    cout<<"5-Deposit Amount"<<endl;
    cout<<"6-Withdraw Amount"<<endl;
    cout<<"7-Transfer Money"<<endl;
    cout<<"8-Bill Payment"<<endl;
    cout<<"9-Loan"<<endl;
    cout<<"10-Exit"<<endl;
     cin>>choice;

    if(choice==1)
    {
        int choice_Account_Type;
        cout<<"Do you want to create:\n1-Saving Account\n2-Current Account"<<endl;
        cin>>choice_Account_Type;
        if(choice_Account_Type==1)
        {

            cin>>as;
           as.addInterest();
		   bank.addAccount(&as);
        }
        else if(choice_Account_Type==2)
        {
        	cin>>ac;
            bank.addAccount(&ac);
        }
    }
    else if(choice==2)
    {
        string id;

    cout<<"Enter account ID that is to be deleted"<<endl;
    cin>>id;
    bank.deleteAccount(id);
    }

    else if(choice==3)
    {
    string id;
        cout<<"Enter account ID that is to be modified"<<endl;
        cin>>id;
        bank.modifyAccount(id);
    }
    else if(choice==4)
    {
   bank.showAllAccounts();
    }
    else if(choice==5)
    {
        cout<<"Enter Acccount Number"<<endl;
        string id;
        cin>>id;
        int amount;
        cout<<"Enter amount to be deposited"<<endl;
        cin>>amount;
        bank.depositAmount(id,amount);
       }

    else if(choice==6)
    {
        cout<<"Enter Acccount Number"<<endl;
        string id;
        cin>>id;
        int amount;
        cout<<"Enter amount to withdraw"<<endl;
        cin>>amount;
        bank.withdrawAmount(id,amount);

    }

   else if(choice==7)
{
     string id1,id2;
     cout<<"Enter id for account by which money will be transfered"<<endl;
     cin>>id1;
    cout<<"Enter id for account to which money will be transfered"<<endl;
     cin>>id2;


     Account*a1=bank.Found(id1);
     if(a1!=nullptr)
     cout<<"found 1"<<endl;
     Account*a2=bank.Found(id2);
     if(a2!=nullptr)
        cout<<"found 2"<<endl;


     /*if(a1!=nullptr)
     {
        cout<<id1<<" Account is found"<<endl;
        if(a2!=nullptr)
        {
        cout<<id2<<" Account is found"<<endl;
        double amount;
        cout<<"Enter amount to be transfered"<<endl;
        cin>>amount;
        transfer_balance(*a1,*a2,amount);}
     }
     else
     cout<<"Transfer not successful"<<endl;*/
}
    else if(choice==8)
    {
         string id;
        cout<<"Enter id"<<endl;
        cin>>id;
        Account*a=bank.Found(id);

		if(a!=nullptr)
        {
            string billType;
            double amount;
            cout<<"Enter Bill Type"<<endl;
            cin>>billType;
            cout<<"Enter amount to be payed"<<endl;
            cin>>amount;
            BillPayment b(a);
            b.payBill(billType,amount);
        }

        else
        cout<<"Account not found"<<endl;
    }

	 else if(choice==9)
     {
        int loan_choice;
        string id;
        cout<<"Enter account id"<<endl;
        cin>>id;
        cout<<"1-Pay Loan\n2-Get Loan"<<endl;
        cin>>loan_choice;
        Account*a=bank.Found(id);
        if(a!=nullptr)
        {
            if(loan_choice==1)
            {
                int amount;
                cout<<"Enter loan amount"<<endl;
                cin>>amount;
                Loan l(a);
                l.payLoan(amount);
            }
            else if(loan_choice==2)
            {
                int amount;
                cout<<"Enter loan amount"<<endl;
                cin>>amount;
                Loan l(a);
                l.getLoan(amount);
            }
            else
            cout<<"Invalid Input"<<endl;
        }
     }

       else if(choice==10)
       break;

    else if(choice!=1 ||choice!=2||choice!=3||choice!=4||choice!=5||choice!=6||choice!=7||choice!=8)
    {cout<<"Invalid input \nEnter again"<<endl;
    cin>>choice;}

}while(choice!=10);
return 0;
}
