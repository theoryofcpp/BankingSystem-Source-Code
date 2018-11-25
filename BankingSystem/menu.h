#pragma once
#ifndef MENU.H

#include <iostream>
#include <fstream>
#include <cctype>
#include "Account.h"

void write_account();	// function to write record in binary file
void display_sp(int);		// function to display account details
void modify_acount(int);	// function to update record files
void delete_acount(int);	// function to delete account
void display_all();			// function to display all account
void deposit_withdraw(int, int); // function to deposit/ withdraw amount
void intro();		// introductory screen funciton

#endif // !MENU.H