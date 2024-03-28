#include <iostream>
#include <string>
using namespace std;
class Account{
    protected:
        string name;
        int acct_num;
        string acct_type;
        float balance;
    public:
        Account(string s,int num,string t):name(s),acct_num(num),acct_type(t),balance(0.00){}
        void deposit(float amount){
            balance+=amount;
            cout<<"Amount "<<amount<<" Deposited. New Balance: "<<balance<<endl;
        }
        void display(){
            cout<<"Balance: "<<balance<<endl;
        }
};
class sav_acct : public Account{
    protected:
        float interest_rate;
    public:
        sav_acct(string s,int num,float ir):Account(s,num,"Savings"),interest_rate(ir){}
        void compound_interest(){
            balance=balance*(1+interest_rate);
            cout<<"Interest Deposited. New Balance: "<<balance<<endl;
        }
        void withdrawal(float amount){
            if(balance<amount){
                cout<<"Insufficient Balance."<<endl;
            }
            else{
                balance-=amount;
                cout<<"Amount "<<amount<<" withdrawn. New balance: "<<balance<<endl;
            }
        }
};
class cur_acct : public Account{
    protected:
        float min_bal;
    public:
    cur_acct(string s,int num,float mb):Account(s,num,"Current"),min_bal(mb){}
    void check_bal(){
            if(balance<min_bal){
                balance-=230;
                cout<<"Minimum balance not met. Penalty imposed. New Balance: "<<balance<<endl;
            }
        }
};
int main() {
    sav_acct sa("Rohan",1257,0.04);
    sa.deposit(12000);
    sa.withdrawal(500);
    sa.compound_interest();
    
    cur_acct ca("Rahul",1590,700);
    ca.deposit(500);
    ca.check_bal();
    ca.display();
    return 0;
}