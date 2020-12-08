#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	BankAccount a("Gleb", "Tereshkin", 100, 100, "7637905A001PB6");
	a.print();
	a.TopUpBalanceUSD(100);
	a.print();
	a.TakeOfBalanceUSD(143);
	a.print();
	a.buyUSDfromBYN(50);
	a.print();
}