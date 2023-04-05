#pragma once
#include "../../../lib/lib.h"
#include "../../../core/pc/pc.h"
#include "../../../core/pc_provider/pc_provider.h"

struct AdminScreen
{
public:
	void displayPage(vector<PC>& pcList, int startIndex, int endIndex);
	void menu();

private:
	int PAGE_SIZE = 5;
};
