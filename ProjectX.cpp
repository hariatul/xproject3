#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <cstdlib>

using namespace std;

string user;
string pass;

int LoginCheck(string user, string pass)
{
	ifstream file;
	string username, password;
	int n = 0;
	file.open("login.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> username >> password;
			n++;
			if (user == username && pass == password)
				return n;
		}
	}
	else
	{
		cout << "file not open" << endl;
	}
	return 0;
}


int main()
{
	int loginattempts = 0;
	ifstream userfile;
	userfile.open("login.txt");
	string userset, passset;
	while (LoginCheck(user, pass) == 0)
	{
		loginattempts++;
		cout << "Username: ";
		cin >> user;
		cout << "Password: ";
		cin >> pass;
		if (LoginCheck(user, pass) != 0)
		{
			cout << "Welcome " << user << "." << endl;
		}
		else
		{
			cout << "Invalid username/password combination" << endl;
		}
	}
	userfile.close();
}