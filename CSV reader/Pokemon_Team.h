//Header file for the Pokemon class
#pragma once
#include <string>
#include <fstream>
//Functions are in camel case
class Pokemon {
private:
	int atk;
	int def;
	int spAtk;
	int spDef;
	int hp;
	int spd;
	std::string name;
	std::string type1;
	std::string type2;

	//create an array for moves somewhere

public:
	Pokemon() {}
	Pokemon(std::string pkmn){}
	void setAtk(int atk){}
	void setDef(int def){}
	void setSpAtk(int spDef){}


};
