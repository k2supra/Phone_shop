#include "screen.h"

User *current_user;

void Screen::reg()
{
	system("cls");
	cout << "<----------- REGISTRATION ----------->\n";
	string name, password;
	cout << "Input name\n-> ";
	cin >> name;
	cout << "Input password\n-> ";
	cin >> password;
	auto *user = new User(name, password, true);
	auto *user_provider = new UserProvider();
	user_provider->addUser(user);

	delete user;
	delete user_provider;
	system("cls");
}

void Screen::login()
{
	cout << "<--------------- LOGIN --------------->\n";
	int isRegistered;
	cout << "Are you registered? (1 - yes; 0 - no)\n-> ";
	cin >> isRegistered;

	if (!isRegistered)
	{
		reg();
		cout << "<--------------- LOGIN --------------->\n";
	}
	else if (isRegistered != 1)
	{
		cout << "Error: wrong input!\n";
		return;
	}

	int isClient;
	cout << "Input type of account\n1 - Client\n-> ";
	cin >> isClient;

	if (isClient != 0 && isClient != 1)
	{
		cout << "Error: wrong input!\n";
		return;
	}

	string name;
	cout << "Input name\n-> ";
	cin >> name;
	string password;
	cout << "Input password\n-> ";
	cin >> password;

	vector<User> userdata;
	current_user = new User(name, password, isClient);
	auto *user_provider = new UserProvider();
	user_provider->readUserData(userdata);

	if (!user_provider->userExists(current_user, userdata))
	{
		cout << "Error: there is no such user or your input is wrong!\n";
		return;
	}

	delete user_provider;
	system("cls");
	if (isClient)
	{
		client_screen = new ClientScreen();
		client_screen->menu();
	}
	else if (!isClient)
	{
		cout << "NULL" << endl;
	}
}

