#include <iostream>

using namespace std;
class Account {
	private:
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
			cout << "    Balance: " << balance << endl;
			cout << "    Interest rate: " << interestRate << endl;
		}
		
};
class CheckingAccount;

class SavingAccount: public Account{
	private:
		double transactFee;
	public:
		SavingAccount(double _b = 0.0, double _i = 0.0, double _tw = 3.0):Account(_b,_i){
			transactFee = _tw;
		};
		bool debit(double _d = 0.0){
      		_d += transactFee;
			bool temp = Account::debit(_d);
      return true;
		}
		void print(){
			cout << "SavingAccount account:" << endl;
			Account::print();
			cout << "    Transaction fee of withdraw: " << transactFee << endl;
		}
		// friend class CheckingAccount;
    friend bool SavingToChecking(SavingAccount& , CheckingAccount& , const double );
    friend bool CheckingToSaving(CheckingAccount& , SavingAccount& , const double );
    
		
};

class CheckingAccount: public Account{
	private:
		double transactFeeW;
		double transactFeeD;
	public:
		CheckingAccount(double _b = 0.0, double _i = 0.0, double _tw = 3.0, double _td = 2.0):Account(_b,_i){
			transactFeeW = _tw;
			transactFeeD = _td;
		}
		bool debit(double _d = 0.0){
      _d += transactFeeW;
			bool temp = Account::debit(_d);
      return true;
		}
		void credit(double _c  = 0.0){
      _c -= transactFeeD;
			Account::credit(_c);
		}
		void print(){
			cout << "CheckingAccount account:" << endl;
			Account::print();
			cout << "    Transaction fee of withdraw: " << transactFeeW << endl;
			cout << "    Transaction fee of deposition: " << transactFeeD << endl;
		};
		// friend class SavingAccount;
    friend bool SavingToChecking(SavingAccount& , CheckingAccount& , const double );
    friend bool CheckingToSaving(CheckingAccount& , SavingAccount& , const double );
};
bool SavingToChecking(SavingAccount& _s, CheckingAccount& _c, const double _t){
	if(_s.getBalance() < _t){
		cout << "Transfer transaction fails." << endl;
		return false;
	}else{
    double _d = _t;
		 _d += _s.transactFee;
		_s.Account::debit(_d);

    _d = _t;
		_d += _c.transactFeeW;
		_c.Account::debit(_d);
		return true;
	}
	
}
bool CheckingToSaving(CheckingAccount& _c, SavingAccount& _s, const double _t){
	if(_c.getBalance() < _t){
		cout << "Transfer transaction fails." << endl;
		return false;
	}else{
    double _d = _t;
		_d += _c.transactFeeW;
		_c.Account::debit(_d);
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
