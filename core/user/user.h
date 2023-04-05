#pragma once

#include "../../lib/lib.h"

struct User
{
public:

	// setters
	void setName(const string &n);
	void setPassword(const string &p);
	void setIsClient(bool ic);

	// getters
	string getName() const;
	string getPassword() const;
	bool getIsClient() const;

	// constructors
	User();
	explicit User(const string &n);
	User(const string &n, const string &p);
	User(const string &n, const string &p, bool ic);
	
	// destructor
	~User();

private:
	string name;
	string password;
	bool isClient;
};

extern User *current_user;

