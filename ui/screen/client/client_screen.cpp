#include "client_screen.h"
#include "../screen.h"

void ClientScreen::displayPage(vector<Phone> &phList, int startIndex, int endIndex)
{
	auto const *ph_provider = new PhoneProvider();
	for (int i = startIndex; i < endIndex && i < phList.size(); i++) {
		ph_provider->printMenuPhone(&phList[i]);
	}
	delete ph_provider;
}

void ClientScreen::menu()
{
	auto const *ph_provider = new PhoneProvider();

	vector<Phone> phdata;
	ph_provider->readPhoneData(phdata);

	int pageNum = 0;
	int possiblePages = phdata.size() / PAGE_SIZE;
	(phdata.size() % PAGE_SIZE != 0) ? possiblePages++ : possiblePages = possiblePages;
	int startIndex = pageNum * PAGE_SIZE;
	int endIndex = (pageNum + 1) * PAGE_SIZE;
	while (true) {
		cout << "\n<-------------- PAGE " << pageNum + 1 << " ---------------->\n";
		displayPage(phdata, startIndex, endIndex);
		cout << "<---                              --->\n  w                                 e  \nc - cart\nq - exit\n";
		cout << "Input action -> ";
		string action;
		cin >> action;
		std::stringstream ss1(action);
		std::stringstream ss2(action);
		int num;
		char ch;
		ss1 >> num;
		ss2 >> ch;
		if (ch == 'e' && pageNum + 1 != possiblePages) {
			pageNum++;
		}
		else if (ch == 'w' && pageNum > 0) {
			pageNum--;
		}
		else if (ch == 'q') {
			break;
		}
		if (num > 0 && num < phdata.size() + 1)
		{
			system("cls");

			Phone*curr_ph = &phdata[num - 1];

			ph_provider->printPhone(curr_ph);
			char input;
			cout << "b - buy\nq - exit\n\nInput action -> ";
			cin >> input;
			if (input == 'b')
			{
				system("cls");
				ph_provider->printPhone(curr_ph);
				cout << "\n<-------------- BUYING ---------------->\n";
				cout << "Enter your address      : ";
				string address;
				cin.ignore();
				getline(cin, address);
				cout << "Enter your full name    : ";
				string full_name;
				cin.ignore();
				getline(cin, full_name);
				cout << "Enter your phone number : ";
				int phone_number;
				cin >> phone_number;
				cout << "Enter your post office  : ";
				string post_office;
				cin.ignore();
				getline(cin, post_office);
				cout << "\nThank you for buying. Youl` be messaged when your phone arrive you ;)" << endl;
				system("pause>0");
			}
			else if (input != 'q')
			{
				cout << "Error: wrong input!\n";
				system("pause");
			}
		}
		system("cls");
		startIndex = pageNum * PAGE_SIZE;
		endIndex = (pageNum + 1) * PAGE_SIZE;
	}

	delete ph_provider;
}


