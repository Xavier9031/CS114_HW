#include <iostream>

using namespace std;
class Account {
	protected:
		double balance;
		double interestRate;
	public:
		Account(double  _b = 0.0, double _i = 0.0){
			balance = _b;
			interestRate = _i;
		}
		void credit(double _c = 0.0){
			balance += _c;
		}
		bool debit(double _d = 0.0){
			if(_d > balance){
				cout << "Debit amount exceeded account balance." << endl;
				return false;
			}
			balance -= _d;
			return true;
		}
		double getBalance(){return balance;}
		double calculateInterest(){
			double interest = balance*interestRate;
			balance += interest;
			return interest;
		};
		void print(){
			
		}
		
};

class SavingAccount: public Account{
	private:
		double transactFee;
	public:
		SavingAccount(double _b = 0.0, double _i = 0.0, double _tw = 3.0){
			balance = _b;
			interestRate = _i;
			transactFee = _tw;
		};
		bool debit(double _d = 0.0){
			bool temp = Account::debit(_d);
			if(temp)balance -= transactFee;
		}
		void print(){
			cout << "SavingAccount account:" << endl;
			cout << "    Balance: " << balance << endl;
			cout << "    Interest rate: " << interestRate << endl;
			cout << "    Transaction fee of withdraw: " << transactFee << endl;
		}
		friend class CheckingAccount;
		
};

class CheckingAccount: public Account{
	private:
		double transactFeeW;
		double transactFeeD;
	public:
		CheckingAccount(double _b = 0.0, double _i = 0.0, double _tw = 3.0, double _td = 2.0){
			balance = _b;
			interestRate = _i;
			transactFeeW = _tw;
			transactFeeD = _td;
		}
		bool debit(double _d = 0.0){
			bool temp = Account::debit(_d);
			if(temp)balance -= transactFeeW;
		}
		void credit(double _c  = 0.0){
			Account::credit(_c);
			balance -= transactFeeD;
		}
		void print(){
			cout << "CheckingAccount account:" << endl;
			cout << "    Balance: " << balance << endl;
			cout << "    Interest rate: " << interestRate << endl;
			cout << "    Transaction fee of withdraw: " << transactFeeW << endl;
			cout << "    Transaction fee of deposition: " << transactFeeD << endl;
		};
		friend class SavingAccount;
};
bool SavingToChecking(SavingAccount& _s, CheckingAccount& _c, const double _t){
	if(_s.getBalance() < _t){
		cout << "Transfer transaction fails." << endl;
		return false;
	}else{
		_s.debit(_t);
		_c.credit(_t);
		return true;
	}
	
}
bool CheckingToSaving(CheckingAccount& _c, SavingAccount& _s, const double _t){
	if(_c.getBalance() < _t){
		cout << "Transfer transaction fails." << endl;
		return false;
	}else{
		_c.debit(_t);
		_s.credit(_t);
		return true;
	}
}


double money , rate;
int main()
{
    cin >> money >> rate;
    cout << "Create a saving account." << endl;
    SavingAccount sAcnt(money, rate);
    sAcnt.print();
    sAcnt.debit(50.0);
    cout << "    New balance after withdrawing $50 from the saving account:" << sAcnt.getBalance() <<endl;
    sAcnt.credit(150.0);
    cout << "    New balance after depositing $150 to the saving account:" << sAcnt.getBalance() << endl;
    sAcnt.print();
    cout << "    Interest of the saving account:" << sAcnt.calculateInterest()<<endl;
    cout << "    New balance after adding interest:" <<sAcnt.getBalance()<<endl;
    cout << "    Withdrawing 800 from the saving account:" << endl;
    sAcnt.debit(800);

    cin >> money >> rate;
    cout << "\nCreate a checking account." <<endl;
    CheckingAccount cAcnt(money, rate);
    cAcnt.print();
    cAcnt.debit(200.0);
    cout <<" New balance after withdrawing $200 from the checking account:" << cAcnt.getBalance() << endl;
    cAcnt.credit(150.0);
    cout << " New balance after depositing $150 to the checking account:" << cAcnt.getBalance() << endl;

    cout << endl;
    cAcnt.print();
    sAcnt.print();

    cout << "\nAfter transfer $600 from cAcnt to sAcnt:" <<endl;
    CheckingToSaving(cAcnt,sAcnt,600.0);
    cout << "New balance of cAcnt:"<<cAcnt.getBalance()<<" New balance of sAcnt " <<sAcnt.getBalance() << endl;
    cout << "\nAfter transfer $800 from sAcnt to sAcnt" <<endl;
    SavingToChecking(sAcnt,cAcnt,800.0);
    cout << "New balance of cAcnt:"<<cAcnt.getBalance()<<" New balance of sAcnt " <<sAcnt.getBalance() << endl;
    CheckingToSaving(cAcnt,sAcnt,50.0);
    cout << "\nAfter transfer $50 from cAcnt to sAcnt" <<endl;
    cout << "New balance of cAcnt:"<<cAcnt.getBalance()<<" New balance of sAcnt " <<sAcnt.getBalance() << endl;
    SavingToChecking(sAcnt,cAcnt,50.0);
    cout << "\nAfter transfer $50 from sAcnt to cAcnt" <<endl;
    cout << "New balance of cAcnt:"<<cAcnt.getBalance()<<" New balance of sAcnt " <<sAcnt.getBalance() << endl;
}
