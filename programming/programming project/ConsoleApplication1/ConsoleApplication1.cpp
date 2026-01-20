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
	}
	if (check) {
		cout << "Enter the password: \n";
		getline(input, p);
		getline(cin, b);
		if (b == p)
		{
			getline(input, p);
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

bool validate_ph(string a) {

	if (a[0] == '7' && (a[1] == '7' || a[1] == '8' || a[1] == '3' || a[1] == '1')) {
		return 1;
	}
	else
	{
		cout << "The Number must Start with 77,78,73,71 \n";
		return 0;
	}

}

bool validate_u(string a) {

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

void remove_u() {

	user a;
	string b;
	string c;
	string d;
	fstream output;
	fstream input;
	fstream outputback;
	fstream inputback;
	fstream record;
	record.open("record.txt", ios::app);
	output.open("userst.txt", ios::out);
	input.open("users.txt", ios::in);
	cout << "enter the user you want to delete\n";
	getline(cin, c);
	while (getline(input, b))
	{
		if (c != b) {
			output << b << endl;
		}
		else
		{
			record << "admin " << "removed this user\n";
			record << b << endl;
			getline(input, d);
			record << d << endl;
			getline(input, d);
			record << d << endl;
			getline(input, d);
			record << d << endl << "======================\n";
		}
	}
	record.close();
	output.close();
	input.close();
	outputback.open("userst.txt", ios::in);
	inputback.open("users.txt", ios::out);
	while (getline(outputback, b))
	{
		inputback << b << endl;
	}
}

int login() {

	user a;
	int val = 0;
	cout << "Enter the username to login: \n";
	getline(cin, a.username);
	val = validate_login(a.username);
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

void del() {

	fstream dele;
	dele.open("userst.txt", ios::out);
	dele.open("users.txt", ios::out);
	dele.close();

}

int main()
{
l:
	int x;
	x = login();
	cout << "YOKOSU: \n1.Login \n2.About us \nchoose an option\n====================\n";
	switch (x)
	{
	case 1: {

		cout << "1.add a user \n2.remove a user \n3.activate a user \n4.deactivate a user \n5.view all users \n6.view a user by type \n7.count the users \n8.system statistics\n";
		cout << "choose an option\n";
		int c;
		cin >> c;
		cin.ignore();
		switch (c)
		{
		case 1: {
			add_u();
		}
		case 2: {
			remove_u();
		}
		case 3: {

		}
		case 4: {

		}
		case 5: {

		}
		case 6: {

		}
		default: {

			break;
		}
		}
	}
	case 2: {



	}
	default: {

		cout << "login failed\n";
		goto l;
	}
	}
}
