#include<iostream>
#include<string>
using namespace std;

class Account
{

private:
    string HOLDER_NAME;
    char TYPE;
    long ACC_NUM;
    int balance;//Will be assigning the account number from this static DataMember

public:
    static long ACCOUNT_NUM_QUEUE; 
    static int transactionCount;
    Account(string name, char type);
    Account();

    void setBalance(int balance){
        this->balance = balance;
    }
    int getBalance() {
        return this->balance;
    }
    string getName() {
        return this->HOLDER_NAME;
    }
    char getType() {
        return this->TYPE;
    }
    long getAccNum() {
        return this->ACC_NUM;
    }
    void setAccNum(long n) {
        this->ACC_NUM = n;
    }
    void deposit(int amount){
        setBalance(this->balance + amount);
        transactionCount++;
    }
    int withdraw(int amount){
        if (this->balance - amount >= 0)
        {
            transactionCount++;
            setBalance(this->balance - amount);
            return amount;
        }
        else
            return -1;   
    }
};

Account::Account(string name, char type)
{
    this->HOLDER_NAME = name;
    this->TYPE = type;
    this->balance = 0;
    this->ACC_NUM = ACCOUNT_NUM_QUEUE;
    ACCOUNT_NUM_QUEUE+=10;
}
Account::Account() {
    setAccNum(0);
}

int Account::transactionCount = 0;
long Account::ACCOUNT_NUM_QUEUE = 10010010;

int main()
{   
    Account account_list[100];//Array of accounts for multiple accounts
    
    int choice,menuChoice,listSize=0,selectedIndex = -1;
    bool flag,menuFlag = true;
    do{
        flag = true;
        cout<<"Press 1 to Create new account"<<endl;
        if(listSize>0)
            cout<<"Press 2 to enter account number and login"<<endl;
        cout<<"Press 9 exit"<<endl<<"Enter Choice: ";
        cin>>menuChoice;
        switch(menuChoice)
        {  
            case 1:
            {
                string name;
                char type;
                cout<<"Enter acccount name: ";
                cin>>name;
                cout<<"Enter account type[S->Savings|C->Current] :";
                cin>>type;
                Account account = Account(name, type);
                account_list[listSize] = account;
                selectedIndex = listSize;
                listSize++;
                cout<<"Your generated account number is : "<<account.getAccNum()<<endl;
                break;
            }
            case 2:
            {
                if (listSize == 0)
                {
                    cout<<"Wrong Choice"<<endl;
                    break;
                }
                long enteredNum;
                cout<<"Enter account number: ";
                cin>>enteredNum;
                for (int i = 0; i < listSize; i++)
                {
                    int num = account_list[i].getAccNum();
                    if ( num == 0)
                    {
                        selectedIndex = -1;
                        break;
                    }
                    else if (num == enteredNum)
                    {
                        selectedIndex = i;
                        break;
                    }
                    else
                    {
                        selectedIndex = -1;
                    }    
                }
                break;    
            }
            case 9:
            {
                cout<<"Total Transactions: "<<account_list[0].transactionCount<<endl;
                cout<<"Good Bye"<<endl;
                menuFlag = false;
                break;
            }
            default:
            {
                cout<<"Wrong Choice"<<endl;

            }
        }
        Account account = account_list[selectedIndex];
        while (flag)
        {
            if (selectedIndex == -1 || !menuFlag)
            {
                if (menuFlag)
                    cout<<"No Account Selected/Present"<<endl;
                break;
            }
            
            cout<<"Press 1 to Deposit"<<endl<<"Press 2 to Withdraw"<<endl<<"Press 3 to Show Balance"<<endl<<"Press 4 to show account details"<<endl<<"Press 9 to exit"<<endl<<"Enter Choice: ";
            cin>>choice;
            int amount = 0; //A default value not necessary
            switch (choice)
            {
            case 1:
            {
                cout<<"Enter amount: ";
                cin>>amount;
                account.deposit(amount);
                cout<<"Thank You!!"<<endl;
                break;
            }
            case 2:
            {
                cout<<"Enter amount: ";
                cin>>amount;
                int result = account.withdraw(amount);
                if (result >= 0)
                {
                    cout<<"Withdrew: "<<result<<endl;
                    int left = account.getBalance();
                    cout<<"Balance Left: "<<left<<endl;
                }
                else
                    cout<<"You don't have sufficient balance to make this transaction"<<endl;
                break;
            }
            case 3:
            {
                int balance = account.getBalance();
                cout<<"Balance: "<<balance<<endl;
                break;
            }
            case 4:
            {
                string Name, Type;
                Name = account.getName();
                Type = (account.getType()=='S')?"Savings":"Current";
                long accNum = account.getAccNum();
                int balance = account.getBalance();
                cout<<"Name: "<<Name<<endl<<"Type: "<<Type<<endl<<"Account Number: "<<accNum<<endl<<"Balance: "<<balance<<endl;
                break;
            }
            case 9:
            {
                flag = false;
                break;
            }
            
            default:{
                cout<<"Wrong Choice!!"<<endl;
                break;
                }
            }
        }
        if(selectedIndex >= 0)
            account_list[selectedIndex] = account;
        cout<<"Total Transactions: "<<account_list[0].transactionCount<<endl;
    }while (menuFlag);
    

    return 0;
}