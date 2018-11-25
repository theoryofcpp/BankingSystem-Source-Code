#include "pch.h"
#include <iostream>
#include <iomanip>		// parametric manipulators
#include "Account.h"

using namespace std;

void Account::create_account() {
	cout << "\nEnter the Account No. ";
	cin >> acno;
	cout << "\nEnter the Name of Account Holder: ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nEnter the Type of the Account (C/S): ";
	cin >> type;
	type = toupper(type);	// transform it to UPPERCASE
	cout << "\nEnter the Initial Amount (Minimum 500 for Saving and 1000 for Current): ";
	cin >> deposit;
	cout << "\n\nYour Account has been Successfully Created";
}

void Account::show_account() const {
	cout << "\nEnter the Account No. " << acno;
	cout << "\nAccount Holder Name: " << name;
	cout << "\nType of Account: " << type;
	cout << "\nBalance Amount: " << deposit;
}

void Account::modify() {
	cout << "\nEnter the Account No. " << acno;
	cout << "\nUpdate Account Holder Name: ";
	cin.ignore();
	cin.getline(name, 50);
}

void Account::dep(int x) { deposit += x; }
void Account::draw(int x) { deposit -= x; }

void Account::report() const {
	cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

int Account::retacno() const { return acno; }
int Account::retdeposit() const { return deposit; }
char Account::rettype() const { return type; }