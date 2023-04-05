#include "phone.h"

// setters
void PC::setId(uint64_t i)
{
	id = i;
}

void PC::setBrand(const string &b)
{
	brand = b;
}

void PC::setModel(const string &m) 
{
	model = m;
}

void PC::setColor(const string &c) 
{
	color = c;
}

void PC::setRam(int r) 
{
	ram = r;
}

void PC::setStorage(int s) 
{
	storage = s;
}

void PC::setFps(int f) 
{
	fps = f;
}

void PC::setOperatingSystem(const string &os) 
{
	operatingSystem = os;
}
void PC::setPrice(int pr)
{
	price = pr;
}

// getters
uint64_t PC::getId() const
{
	return id;
}

string PC::getBrand() const
{
	return brand;
}

string PC::getModel() const
{
	return model;
}

string PC::getColor() const
{
	return color;
}

int PC::getRam() const
{
	return ram;
}

int PC::getStorage() const
{
	return storage;
}

int PC::getFps() const
{
	return fps;
}

string PC::getOperatingSystem() const
{
	return operatingSystem;
}
int PC::getPrice() const
{
	return price;
}

// constructors
PC::PC()
{
	setId(0);
	setBrand("null");
	setModel("null");
	setColor("null");
	setRam(0);
	setStorage(0);
	setFps(0);
	setOperatingSystem("null");
	setPrice(0);
}
PC::PC(const string &b) : PC()
{
	setBrand(b);
}
PC::PC(const string &b, const string &m) : PC(b)
{
	setModel(m);
}
PC::PC(const string &b, const string &m, const string &c) : PC(b, m)
{
	setColor(c);
}
PC::PC(const string &b, const string &m, const string &c, int r) : PC(b, m, c)
{
	setRam(r);
}
PC::PC(const string &b, const string &m, const string &c, int r, int s) : PC(b, m, c, r)
{
	setStorage(s);
}
PC::PC(const string &b, const string &m, const string &c, int r, int s, int f) : PC(b, m, c, r, s)
{
	setFps(f);
}
PC::PC(const string &b, const string &m, const string &c, int r, int s, int f, const string &os) : PC(b, m, c, r, s, f)
{
	setOperatingSystem(os);
}
PC::PC(const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr) : PC(b, m, c, r, s, f, os)
{
	setPrice(pr);
}
PC::PC(uint64_t i, const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr) : PC(b, m, c, r, s, f, os, pr)
{
	setId(i);
}

// destructors
PC::~PC()
{
	id = 0;
	brand = "null";
	model = "null";
	color = "null";
	ram = 0;
	storage = 0;
	fps = 0;
	operatingSystem = "null";
	price = 0;
}

