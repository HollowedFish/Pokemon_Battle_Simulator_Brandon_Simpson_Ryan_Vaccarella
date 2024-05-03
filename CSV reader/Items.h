#pragma once
#include <iostream>
#include <string>
#include "Pokemon_Team.h"

class item {
protected:
	std::string name = "";
	std::string description = "";
	int quantity = 0;
public:
	item(std::string name, std::string description, int quantity);
	std::string getName();
	std::string getDescription();
	int getQuantity();
	void setName(std::string name);
	void setDescription(std::string description);
	void setQuantity(int quantity);
	virtual void use();
	virtual void printItem();
};

class potion :public item {
private:
	int healVal = 0;
public:
	potion(std::string name, std::string description, int quantity, int healVal);
	int getHealVal();
	void setHealVal(int healVal);
	void use(Pokemon* pokemon);
	void printItem();
};

class ether :public item {
private:
	int PP_RestoreVal = 0;
public:
	ether(std::string name, std::string description, int quantity, int PP_RestoreVal);
	int getPPRV();
	void setPPRV(int PP_RestoreVal);// You can make the abbreviation longer if you want
	void use(Pokemon* pokemon);
	void printItem();
};

class revive :public item {
private:
	float resHealPercent = 0.0; //Percent will be formatted as such: 50% = 0.5, 100% = 1.0, 25% = 0.25, etc.
public:
	revive(std::string name, std::string description, int quantity, float resHealPercent);
	float getResHealPercent();
	void setResHealPercent(float resHealPercent);
	void use(Pokemon* pokemon);
	void printItem();
};