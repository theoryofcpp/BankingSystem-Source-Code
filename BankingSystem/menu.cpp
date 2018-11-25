#include "pch.h"
#include "menu.h"
#include <iostream>
#include <fstream>

using namespace std;

// function to write in file
void write_account() {
	Account ac;
	ofstream outFile;
	outFile.open("account.txt", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	outFile.close();
}

// function to read specific record from file
void display_sp(int n) {
	Account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile) {
		cout << "File could not be Open !!\n";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
		return;
	}
	cout << "\nBalance Details\n";

	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
		if (ac.retacno() == n) {
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag = false) {
		cout << "\nIncorrect Account Number";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
	}
}

// function to update Account
void modify_acount(int n) {
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);

	if (!File) {
		cout << "\nFile could not be Open !!\n";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
		return;
	}
	while (!File.eof() && found == false) {
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if (ac.retacno() == n) {
			ac.show_account();
			cout << "\nEnter the New Details of Account: \n";
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(Account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout << "\n\n\tRecord UPDATED!!!";
			cout << "\n\nPress ENTER to return to the Main Menu.\n";
			found = true;
		}
	}
	File.close();
	if (found == false) {
		cout << "\nRecord Not Found";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
	}
}

// function to delete account
void delete_acount(int n) {
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile) {
		cout << "File could not be Open !!\n";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
		return;
	}
	outFile.open("temp.txt", ios::binary);
	inFile.seekg(0, ios::beg);

	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
		if (ac.retacno() != n) {
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.txt");
	rename("temp.txt", "account.txt");
	cout << "\n\n\tRECORD DELETED";
	cout << "\n\nPress ENTER to return to the Main Menu.\n";
}

// function to display all accounts
void display_all() {
	Account ac;
	ifstream inFile;
	inFile.open("account.txt", ios::binary);
	if (!inFile) {
		cout << "File could not be Open !!\n";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "========================================================\n";
	cout << "A/C no.		NAME			TYPE		BALANCE\n";
	cout << "========================================================\n";
	while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
		ac.report();
	}
	inFile.close();
	cout << "\n\nPress ENTER to return to the Main Menu.\n";
}

// function to deposit and withdraw amounts
void deposit_withdraw(int n, int option) {
	int amt;
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.txt", ios::binary | ios::in | ios::out);
	if (!File) {
		cout << "File could not be Open !!\n";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
		return;
	}
	while (!File.eof() && found == false) {
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if (ac.retacno() == n) {
			ac.show_account();
			if (option == 1) {
				cout << "\n\n\tTo DEPOSIT Amount";
				cout << "\n\nEnter the Amount to be Deposited: ";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2) {
				cout << "\n\n\tTo WITHDRAW Amount";
				cout << "\n\nEnter the Amount to be Withdraw: ";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C')) {
					cout << "Insufficient Balance\n";
				}
				else {
					ac.draw(amt);
				}
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout << "\n\n\tRecord Updated";
			cout << "\n\nPress ENTER to return to the Main Menu.\n";
			found = true;
		}
	}
	File.close();
	if (found == false) {
		cout << "\n\nRecord Not Found";
		cout << "\n\nPress ENTER to return to the Main Menu.\n";
	}
}

// function to show introduction
void intro() {
	cout << "\n\n\n\tWELCOME To";
	cout << "\n\n\tFAKE BANK SYSTEM";
	cout << "\n\n\tPlease press Enter to Proceed\n";
	cin.get();
}
