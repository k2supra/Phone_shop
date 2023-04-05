#include "phone_provider.h"

void PCProvider::printPC(PC const *pc) const
{
	cout << "Brand            : " << pc->getBrand() << '\n';
	cout << "Model            : " << pc->getModel() << '\n';
	cout << "Color            : " << pc->getColor() << '\n';
	cout << "RAM              : " << pc->getRam() << '\n';
	cout << "Storage          : " << pc->getStorage() << '\n';
	cout << "FPS              : " << pc->getFps() << '\n';
	cout << "Operating system : " << pc->getOperatingSystem() << '\n';
	cout << "Price            : " << pc->getPrice() << "$\n\n";
}


void PCProvider::printMenuPC(PC const *pc) const
{
	cout << '#' << pc->getId() << ' ' << pc->getBrand() << ' ' << pc->getModel() << '\n'; // add index
	cout << "\tFPS     : " << pc->getFps() << '\n';
	cout << "\tStorage : " << pc->getStorage() << '\n';
	cout << "\tRAM     : " << pc->getRam() << '\n';
	cout << pc->getPrice() << "$\n";
}

void PCProvider::readPCData(vector<PC> &pcdata, const string &filename) const
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
			pcdata.emplace_back(i, brand, model, color, ram, storage, fps, operatingSystem, price);
			i++;
		}
		file.close();
	}
}


