#pragma once
#include "../../../lib/lib.h"
#include "../../../core/pc/phone.h"
#include "../../../core/pc_provider/phone_provider.h"

struct ClientScreen
{
public:
	void displayPage(vector<PC> &pcList, int startIndex, int endIndex);
	void menu();

private:
	int PAGE_SIZE = 5;
};
