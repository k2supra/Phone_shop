#pragma once
#include "../../lib/lib.h"

struct Phone
{
public:
	// setters
	void setId(uint64_t i);
	void setBrand(const string &b);
	void setModel(const string &m);
	void setColor(const string &c);
	void setRam(int r);
	void setStorage(int s);
	void setFps(int f);
	void setOperatingSystem(const string &os);
	void setPrice(int pr);

	// getters
	uint64_t getId() const;
	string getBrand() const;
	string getModel() const;
	string getColor() const;
	int getRam() const;
	int getStorage() const;
	int getFps() const;
	string getOperatingSystem() const;
	int getPrice() const;

	// constructors
	Phone();
	explicit Phone(const string &b);
	Phone(const string &b, const string &m);
	Phone(const string &b, const string &m, const string &c);
	Phone(const string &b, const string &m, const string &c, int r);
	Phone(const string &b, const string &m, const string &c, int r, int s);
	Phone(const string &b, const string &m, const string &c, int r, int s, int f);
	Phone(const string &b, const string &m, const string &c, int r, int s, int f, const string &os);
	Phone(const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr);
	Phone(uint64_t i, const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr);

	// destructors
	~Phone();

private:
	uint64_t id;
	string brand;
	string model;
	string color;
	int ram;
	int storage;
	int fps;
	string operatingSystem;
	int price;
};
