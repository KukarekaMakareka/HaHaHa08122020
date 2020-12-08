#include <iostream>
#include <string>
#include <fstream>
#include "BankAccount.h"
using namespace std;

BankAccount::BankAccount() {
	Name = "";
	Surname = "";
	balanceUSD = 0;
	balanceBYN = 0;
	ID = "";
}

BankAccount::BankAccount(string fname, string fsurname, unsigned int fbalanceUSD, unsigned int fbalanceBYN, string fid) {
	Name = fname;
	Surname = fsurname;
	balanceUSD = fbalanceUSD;
	balanceBYN = fbalanceBYN;
	ID = fid;
}

void BankAccount::setName(string fname) { Name = fname; }
void BankAccount::setSurname(string fsurname) { Surname = fsurname; }
void BankAccount::setBalanceUSD(unsigned int fbalance) { balanceUSD = fbalance; }
void BankAccount::setBalanceBYN(unsigned int fbalance) { balanceBYN = fbalance; }
void BankAccount::setID(string fid) { ID = fid; }

string BankAccount::getName(string) { return Name; }
string BankAccount::getSurName(string) { return Surname; }
unsigned int BankAccount::getBalanceUSD(unsigned int) { return balanceUSD; }
unsigned int BankAccount::getBalanceBYN(unsigned int) { return balanceBYN; }
string BankAccount::getID(string) { return ID; }

void BankAccount::print() {
	cout << Surname << ' ' << Name << ' ' << "ID: " << ID << endl << "Balance: " 
		<< balanceUSD << " USD, " << balanceBYN << " BYN" << endl << endl;

}

void BankAccount::TopUpBalanceUSD(unsigned int fbalance) {
	cout << "Add " << fbalance << "$" << endl;
	balanceUSD += fbalance;
}

void BankAccount::TopUpBalanceBYN(unsigned int fbalance) {
	cout << "Add " << fbalance << "$" << endl;
	balanceBYN += fbalance;
}

void BankAccount::TakeOfBalanceUSD(unsigned int fbalance) {
	if (fbalance < balanceUSD) {
		cout << "Filmed " << fbalance << " USD" << endl;
		balanceUSD -= fbalance;
	}
	else
		cout << "Error: insufficient funds USD" << endl;
}
void BankAccount::TakeOfBalanceBYN(unsigned int fbalance) {
	if (fbalance < balanceBYN) {
		cout << "Filmed " << fbalance << " BYN" << endl;
		balanceBYN -= fbalance;
	}
	else
		cout << "Error: insufficient funds BYN" << endl;
}

void BankAccount::buyUSDfromBYN(unsigned int fUSD)
{
	ifstream inputFile;
	inputFile.open("courses.txt");
	if (inputFile.is_open())
	{
		string str;
		inputFile >> str;
		int USDtoBYN = stoi(str);
		int amountToTakeOfBYN = fUSD * USDtoBYN;
		if (amountToTakeOfBYN < balanceBYN)
		{
			this->TakeOfBalanceBYN(amountToTakeOfBYN);
			this->TopUpBalanceUSD(fUSD);
		}
		else
		{
			cout << "Error: insufficient funds BYN" << endl;
		}
	}
	else
	{
		cout << "Error, can't open the file" << endl;
	}
}