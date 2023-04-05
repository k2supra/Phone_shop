#include "user.h"

// setters
void User::setName(const string &n) 
{
	name = n;
}

void User::setPassword(const string &p) 
{
	password = p;
}

void User::setIsClient(bool ic) 
{
	isClient = ic;
}

// getters
string User::getName() const
{
	return name;
}

string User::getPassword() const
{
	return password;
}

bool User::getIsClient() const
{
	return isClient;
}

// constructors
User::User() 
{
	setName("null");
	setPassword("null");
	setIsClient(false);
}
User::User(const string &n) : User()
{
	setName(n);
}
User::User(const string &n, const string &p) : User(n)
{
	setPassword(p);
}
User::User(const string &n, const string &p, bool ic) : User(n, p)
{
	setIsClient(ic);
}

// destructor
User::~User() 
{
	name.clear();
	password.clear();
	isClient = false;
}

