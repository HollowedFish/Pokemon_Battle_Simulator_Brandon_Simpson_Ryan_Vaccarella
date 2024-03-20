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
	std::string pkmnName;
	/*std::string type1;
	std::string type2;*/
	bool KO;
	std::string possibleMoves[20]; //A container for the move names (string for now but could be the moves class which will be added later?)
	std::string moveset[4];
	//create an array for moves somewhere

public:
	Pokemon();
	Pokemon(std::string pkmnName, int atk, int def, int hp, int spDef, int spAtk, int spd);
	//Pokemon(std::string pkmnName);
	//Setter functions
	void setName(std::string pkmnName);
	void setAtk(int atk);
	void setDef(int def);
	void setSpAtk(int spAtk);
	void setspDef(int spDef);
	void setHp(int hp);
	void setSpd(int spd);
	//void setType1(std::string type1);
	//void setType2(std::string type2);
	//Getter functions
	int getAtk();
	int getDef();
	int getSpAtk();
	int getSpDef();
	int getSpd();
	std::string getName();
	//std::string getType1();
	//std::string getType2();
	//Misc functions
	bool isKO();
	void setKO(bool KO_Value);
	void printMoveset();
	void printName();
};
class Moves {
private:
	std::string nameMoves;
	std::string typeMoves;
	std::string categoryMoves;
	float powerMoves;
	int accuracyMoves;
	int powerPointsMoves;
	float healMoves;
	int hitTimesMoves;
	bool firstMoves;
	bool critMoves;
	bool instaMoves;
	bool dodgeMoves;
	bool flinchMoves;
	bool chargeMoves;
public:
	Moves();
	Moves(std::string nameMoves, std::string typeMoves, std::string categoryMoves, float powerMoves, int accuracyMoves, int powerPointsMoves, float healMoves, int hitTimesMoves, bool firstMoves,bool critMoves,bool instaMoves,bool dodgeMoves, bool flinchMoves, bool chargeMoves);

	void setNameMoves(std::string nameMoves);
	void setTypeMoves(std::string typeMoves);
	void setcategoryMoves(std::string categoryMoves);
	void setpowerMoves(float powerMoves);
	void setaccuracyMoves(int accuracyMoves);
	void setpowerPointsMoves(int powerPointsMoves);
	void sethealMoves(float healMoves);
	void sethitTimeMoves(int hitTimesMoves);
	void setfirstMoves(bool firstMoves);
	void setcritMoves(bool critMoves);
	void setinstaMoves(bool instaMoves);
	void setdodgeMoves(bool dodgeMoves);
	void setflinchMoves(bool flinchMoves);
	void setchargeMoves(bool chargeMoves);

	std::string getNameMoves();
	std::string getTypeMoves();
	std::string getcategoryMoves();
	float getpowerMoves();
	int getaccuracyMoves();
	float gethealMoves();
	int gethitTimesMoves();
	bool getfirstMoves();
	bool getcritMoves();
	bool getinstaMoves();
	bool getdodgeMoves();
	bool getflinchMoves();
	bool getchargeMoves();
	
};
