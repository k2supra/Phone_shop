#pragma once
#include "../pc/phone.h"

struct PhoneProvider
{
	void printPhone(Phone const *ph) const;
	void printMenuPhone(Phone const *ph) const;
	void readPhoneData(vector<Phone> &phdata, const string &filename = "data/phonedata.csv") const;
};


