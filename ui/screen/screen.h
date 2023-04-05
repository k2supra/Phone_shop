#pragma once
#include "../../lib/lib.h"
#include "client/client_screen.h"
#include "../../core/user/user.h"
#include "../../core/user_provider/user_provider.h"

struct Screen
{
public:
	void reg();   // register
	void login(); // login

private:
	ClientScreen *client_screen;
};
