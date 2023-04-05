#include "client_screen.h"
#include "../screen.h"

void ClientScreen::displayPage(vector<PC> &pcList, int startIndex, int endIndex)
{
	auto const *pc_provider = new PCProvider();
	for (int i = startIndex; i < endIndex && i < pcList.size(); i++) {
		pc_provider->printMenuPC(&pcList[i]);
	}
	delete pc_provider;
}

void ClientScreen::menu()
{
	auto const *pc_provider = new PCProvider();

	vector<PC> pcdata;
	pc_provider->readPCData(pcdata);

	int pageNum = 0;
	int possiblePages = pcdata.size() / PAGE_SIZE;
	(pcdata.size() % PAGE_SIZE != 0) ? possiblePages++ : possiblePages = possiblePages;
	int startIndex = pageNum * PAGE_SIZE;
	int endIndex = (pageNum + 1) * PAGE_SIZE;
	while (true) {
		cout << "\n<-------------- PAGE " << pageNum + 1 << " ---------------->\n";
		displayPage(pcdata, startIndex, endIndex);
		cout << "<---                              --->\n  w                                 e  \nc - cart\nq - exit\n";
		cout << "Input action -> ";
		string action;
		cin >> action;
		std::stringstream ss1(action);
		std::stringstream ss2(action); // tried to do it with one ss, but it didn't work
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
		if (num > 0 && num < pcdata.size() + 1)
		{
			system("cls");

			PC *curr_pc = &pcdata[num - 1];

			pc_provider->printPC(curr_pc);
			char input;
			cout << "b - buy\nq - exit\n\nInput action -> ";
			cin >> input;
			if (input == 'b')
			{
				system("cls");
				pc_provider->printPC(curr_pc);
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

	delete pc_provider;
}


