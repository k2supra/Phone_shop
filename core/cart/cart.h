#pragma once
#include "../../lib/lib.h"
#include "../pc/pc.h"
#include "../pc_provider/pc_provider.h"

struct Cart
{
public:
	void addPC(PC *pc);						// add PC to cart
	void removePC(uint64_t i);				// remove PC from cart
	void printCartPCs() const;				// print cart's PCs
	void buy(PC const *pc);					// buy certain thing
	void cart();							// main cart function

private:
	vector<PC*> cartdata;
};

