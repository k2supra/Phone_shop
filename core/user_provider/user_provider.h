#pragma once

#include "../../lib/lib.h"
#include "../user/user.h"

	struct UserProvider
	{
		void addUser(User const *user, const string &filename = "data/userdata.csv") const;
		void readUserData(vector<User> &userdata, const string &filename = "data/userdata.csv") const;
		bool userExists(User const *user, vector<User> &userdata) const;
	};

