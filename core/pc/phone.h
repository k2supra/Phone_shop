#pragma once
#include "../../lib/lib.h"

struct PC
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
	PC();
	explicit PC(const string &b);
	PC(const string &b, const string &m);
	PC(const string &b, const string &m, const string &c);
	PC(const string &b, const string &m, const string &c, int r);
	PC(const string &b, const string &m, const string &c, int r, int s);
	PC(const string &b, const string &m, const string &c, int r, int s, int f);
	PC(const string &b, const string &m, const string &c, int r, int s, int f, const string &os);
	PC(const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr);
	PC(uint64_t i, const string &b, const string &m, const string &c, int r, int s, int f, const string &os, int pr);

	// destructors
	~PC();

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
