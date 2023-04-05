#include "lib/lib.h"
#include "core/pc/phone.h"
#include "ui/screen/screen.h"
#include "core/pc_provider/phone_provider.h"

int main()
{
	auto *screen = new Screen();
	screen->login();

	return 0;
}