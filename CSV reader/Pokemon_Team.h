#pragma once
//Header file for the Pokemon class
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
	/*std::string type1;
	std::string type2;*/
	bool KO;
	std::string possibleMoves[20]; //A container for the move names (string for now but could be the moves class which will be added later?)

	//create an array for moves somewhere

public:
	Pokemon();
	Pokemon(std::string pkmn);
	//Setter functions
	void setAtk(int atk);
	void setDef(int def);
	void setSpAtk(int spDef);
	void setHp(int hp);
	void setSpd(int spd);
	void setName(std::string name);
	void setType1(std::string type1);
	void setType2(std::string type2);
	//Getter functions
	int getAtk();
	int getDef();
	int getSpAtk();
	int getSpDef();
	int getSpd();
	std::string getName();
	std::string getType1();
	std::string getType2();
	//Misc functions
	bool isKO();
	void setKO(bool KO_Value);
};
