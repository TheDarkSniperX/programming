#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

struct user {
	string username;
	string password;
	string type;
	string phone;
	bool isActive = true;
};

bool validate_ph(string a) {

	string ph;
	bool check = false;
	fstream input;
	input.open("users.txt", ios::in);
	while (getline(input, ph))
	{
		if (a[0] == '7' && a[1] == '7' || a[1] == '8' || a[1] == '3' || a[1] == '1') {
			check = true;
			break;
		}
		else
		{
			check = false;
		}
	}
	if (check)
	{
		input.close();
		return 1;
	}
	else
	{
	cout << "The Number must Start with 77,78,73,71 \n";
	input.close();
	return 0;
	}

}

bool validate_u(string a) {

	string b;
	string u;
	bool check = false;
	fstream input;
	input.open("users.txt", ios::in);
	while (getline(input, u))
	{
		if (a == u) {
			check = true;
			break;
		}
		check = false;
	}
	if (check)
	{
		input.close();
		return 0;
	}
	input.close();
	return 1;
}

void add_u() { //admin only

	user a;
	fstream output;
	output.open("users.txt", ios::app);
	cout << "Enter the username to add: \n";
	getline(cin, a.username);
	if (validate_u(a.username))
	{
		cout << "Enter the password: \n";
		getline(cin, a.password);
		cout << "Enter the phone number: \n";
		getline(cin, a.phone);
		if (validate_ph(a.phone)) {
			cout << "choose the type\n1.admin\n2.employee\n";
			int x;
			cin >> x;
			cin.ignore();
			switch (x)
			{
			case 1: {
				a.type = "admin";
				break;
			}
			case 2: {
				a.type = "emplyee";
				break;
			}
			default: {
				cout << "wrong input\n";
				add_u();
			}
			}
			output << a.username << endl;
			output << a.password << endl;
			output << a.type << endl;
			output << a.phone << endl;
			output.close();
		}
		else
		{
			add_u();
		}
	}
	else
	{
		cout << "username already exists \n";
		add_u();
	}
}

int validate_login(string a) {

	string b;
	string u;
	string p;
	string t;
	bool check = false;
	fstream input;
	input.open("users.txt", ios::in);
	while (getline(input, u))
	{
		if (a == u) {
			check = true;
			break;
		}
		check = false;
	}
	if (check) {
		cout << "Enter the password: \n";
		getline(input, p);
		getline(cin, b);
		if (b == p)
		{
			getline(input, p);
			//cout << p << endl;
			if (p == "admin")
			{
				input.close();
				return 1;
			}
			else
			{
				input.close();
				return 2;
			}
		}
		else
		{
			cout << "the password is incorrect \n";
			input.close();
			return 0;
		}
	}
	else
	{
		cout << "the username doesn't exist \n";
		input.close();
		return 0;
	}

}


int login() {

	user u;
	int val = 0;
	cout << "Enter the username to login: \n";
	getline(cin, u.username);
	val = validate_login(u.username);
	if (val == 1) {
		return 1;
	}
	else if (val == 2) {
		return 2;
	}
	else if (val == 0)
	{
		return 0;
	}
	else return 0;
}


int main()
{
	add_u();
	int x;
	cout << "YOKOSU: \n1.Login \n2.About us \nchoose an option\n====================\n";
	cin >> x;
	cin.ignore();
	switch (x)
	{
	case 1: {
		int loginn = 0;
		loginn = login();
		if (loginn == 1 or loginn == 2) {
			cout << " logged in sucssessfully \n";
		}
		else
		{
			cout << " login failed \n";
		}

	}
	case 2: {


	}
	}

}
