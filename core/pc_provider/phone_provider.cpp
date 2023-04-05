#include "phone_provider.h"

void PhoneProvider::printPhone(Phone const *ph) const
{
	cout << "Brand            : " << ph->getBrand() << '\n';
	cout << "Model            : " << ph->getModel() << '\n';
	cout << "Color            : " << ph->getColor() << '\n';
	cout << "RAM              : " << ph->getRam() << '\n';
	cout << "Storage          : " << ph->getStorage() << '\n';
	cout << "FPS              : " << ph->getFps() << '\n';
	cout << "Operating system : " << ph->getOperatingSystem() << '\n';
	cout << "Price            : " << ph->getPrice() << "$\n\n";
}


void PhoneProvider::printMenuPhone(Phone const *ph) const
{
	cout << '#' << ph->getId() << ' ' << ph->getBrand() << ' ' << ph->getModel() << '\n';
	cout << "\tFPS     : " << ph->getFps() << '\n';
	cout << "\tStorage : " << ph->getStorage() << '\n';
	cout << "\tRAM     : " << ph->getRam() << '\n';
	cout << ph->getPrice() << "$\n";
}

void PhoneProvider::readPhoneData(vector<Phone> &phdata, const string &filename) const
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		string line;
		int i = 1;
		while (getline(file, line))
		{
			std::stringstream ss(line);
			string brand, model, color, operatingSystem;
			int ram, storage, price, fps;
			getline(ss, brand, ',');
			getline(ss, model, ',');
			getline(ss, color, ',');
			ss >> ram;
			ss.ignore();
			ss >> storage;
			ss.ignore();
			ss >> fps;
			ss.ignore();
			getline(ss, operatingSystem, ',');
			ss >> price;
			ss.ignore();
			phdata.emplace_back(i, brand, model, color, ram, storage, fps, operatingSystem, price);
			i++;
		}
		file.close();
	}
}


