#include "cart.h"

void Cart::addPC(PC *pc)
{
	cartdata.push_back(pc);
}

void Cart::removePC(uint64_t i)
{
	auto search{ std::ranges::find_if(cartdata,
		[i](PC const *pc)
		{
			return pc->getId() == i;
		}
	) };
	if (search == cartdata.end())
	{
		cout << "Error: there is no such element\n";
		system("pause>0");
	}
	else
	{
		cartdata.erase(search);
	}
}

void Cart::printCartPCs() const
{
	auto const *pc_provider = new PCProvider();
	for (int i = 0; i < cartdata.size(); i++)
	{
		pc_provider->printMenuPC(cartdata[i]);
	}
	delete pc_provider;
}

void Cart::buy(PC const *pc)
{
	string fullName;
	cout << "Input full name of the reciever\n-> ";
	cin.ignore(1, '\n');
	getline(cin, fullName);
	string phoneNumber;
	cout << "Input phone number of the reciever\n-> ";
	cin.ignore(1, '\n');
	getline(cin, phoneNumber);
	string city;
	cout << "Input the place where you want to recieve your package\n-> ";
	cin.ignore(1, '\n');
	getline(cin, city);
	int deliveryMethod;
	cout << "Input how do you want to get your package (1 - delivery, 0 - pickup)\n-> ";
	cin >> deliveryMethod;
	int paymentMethod;
	cout << "Input how do you want to pay for the package (1 - cash, 0 - credit card)\n-> ";
	cin >> paymentMethod;

	auto *pc_provider = new PCProvider();
	pc_provider->printPC(pc);
	cout << "Your total will be:\n";
	cout << '\t' << pc->getPrice() << "$\n";

	int isPurchasing;
	cout << "Input 1 to complete your purchase\n-> ";
	cin >> isPurchasing;
	if (isPurchasing == 1)
	{
		cout << "Thank you for using our services! You'll get message when your PC will arrive to closest post office.\n";
		system("pause>0");
		removePC(pc->getId());
	}
	else
	{
		return;
	}
}

void Cart::cart()
{
	auto const *pc_provider = new PCProvider();

	while (true) {
		cout << "\n<-------------- CART ---------------->\n";
		printCartPCs();
		cout << "<------------------------------------>\nb - buy\nr - remove\nq - exit\n";
		cout << "\nInput action -> ";
		char ch;
		cin >> ch;
		if (ch == 'b')
		{
			int index;
			cout << "Input index of PC you want to buy\n-> ";
			cin >> index;

			auto search{ std::find_if(cartdata.begin(), cartdata.end(),
				[index](PC const *pc)
				{
					return pc->getId() == index;
				}
			)};
			if (search != cartdata.end())
			{
				buy(*search);
			}
			else
			{
				cout << "Error: there is no such element\n";
				system("pause>0");
			}
		}
		else if (ch == 'r')
		{
			int index;
			cout << "Input index of the object -> ";
			cin >> index;
			removePC(index);
		}
		else if (ch == 'q') {
			break;
		}
		system("cls");
	}

	delete pc_provider;

}

