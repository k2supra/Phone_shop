#pragma once
#include "../pc/phone.h"

struct PCProvider
{
	void printPC(PC const *pc) const;
	void printMenuPC(PC const *pc) const;
	void readPCData(vector<PC> &pcdata, const string &filename = "data/phonedata.csv") const;
};


