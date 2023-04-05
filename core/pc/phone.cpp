#include "phone.h"

// setters
void Phone::setId(uint64_t i)
{
	id = i;
}

void Phone::setBrand(const string &b)
{
	brand = b;
}

void Phone::setModel(const string &m)
{
	model = m;
}

void Phone::setColor(const string &c)
{
	color = c;
}

void Phone::setRam(int r)
{
	ram = r;
}

void Phone::setStorage(int s)
{
	storage = s;
}

void Phone::setFps(int f)
{
	fps = f;
}

void Phone::setOperatingSystem(const string &os)
{
	operatingSystem = os;
}
void Phone::setPrice(int pr)
{
	price = pr;
}

// getters
uint64_t Phone::getId() const
{
	return id;
}

string Phone::getBrand() const
{
	return brand;
}

string Phone::getModel() const
{
	return model;
}

string Phone::getColor() const
{
	return color;
}

int Phone::getRam() const
{
	return ram;
}

int Phone::getStorage() const
{
	return storage;
}

int Phone::getFps() const
{
	return fps;
}

string Phone::getOperatingSystem() const
{
	return operatingSystem;
}
int Phone::getPrice() const
{
	return price;
}

// constructors
Phone::Phone()
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
Phone::Phone(const string &b) : Phone()
{
	setBrand(b);
}
Phone::Phone(const string &b, const string &m) : Phone(b)
{
	setModel(m);
}
Phone::Phone(const string &b, const string &m, const string &c) : Phone(b, m)
{
	setColor(c);
}
Phone::Phone(const string &b, const string &m, const string &c, int r) : Phone(b, m, c)
{
	setRam(r);
}
Phone::Phone(const string &b, const string &m, const string &c, int r, int s) : Phone(b, m, c, r)
{
	setStorage(s);
}
Phone::Phone(const string &b, const string &m, const string &c, int r, int s, int f) : Phone(b, m, c, r, s)
{
	setFps(f);
}
Phone::Phone(const string &b, const string &m, const string &c, int r, int s, int f, const string &os) : Phone(b, m, c, r, s, f)
{
	setOperatingSystem(os);
}
Phone::Phone(const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr) : Phone(b, m, c, r, s, f, os)
{
	setPrice(pr);
}
Phone::Phone(uint64_t i, const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr) : Phone(b, m, c, r, s, f, os, pr)
{
	setId(i);
}

// destructors
Phone::~Phone()
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

