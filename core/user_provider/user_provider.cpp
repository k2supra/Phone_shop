#include "user_provider.h"

void UserProvider::addUser(User const *user, const string &filename) const	
{
	bool nameExists = false;
	std::ifstream infile;
	infile.open(filename);
	string line;
	while (getline(infile, line))
	{
		string name_temp = line.substr(0, line.find_first_of(","));
		if (name_temp == user->getName()) 
		{
			nameExists = true;
			break;
		}
	}
	infile.close();

	if (nameExists)
	{
		cout << "Error: this username already exists!\n";
		system("pause>0");
	}
	else
	{
		std::ofstream outfile;
		outfile.open(filename, std::ios_base::app);
		outfile << user->getName() << "," << user->getPassword() << "," << 1 << "\n";
		outfile.close();
	}

}

void UserProvider::readUserData(vector<User> &userdata, const string &filename) const
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			std::stringstream ss(line);
			string name, password;
			bool isClient;
			getline(ss, name, ',');
			getline(ss, password, ',');
			ss >> isClient;
			ss.ignore();
			userdata.emplace_back(name, password, isClient);
		}
		file.close();
	}
}

bool UserProvider::userExists(User const *user, vector<User> &userdata) const
{
	auto it = std::find_if(userdata.begin(), userdata.end(), [&user](User const &u) {
		return u.getName() == user->getName() && u.getPassword() == user->getPassword() && u.getIsClient() == user->getIsClient();
	});
	return it != userdata.end();
}
