#pragma once
//Header file for the Pokemon class
#include <iostream>
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
	std::string possibleMoves[30];
	bool KO;
public:
	//class Moves; We don't need a sepreate declaration if that is the case
	//Ok, so this looks really weird, but it is NECESSARY for the array of moves to work
	class Moves {
	private:
		std::string nameMoves;
		std::string typeMoves;
		std::string categoryMoves;
		int powerMoves;
		int accuracyMoves;
		int powerPointsMoves;
		int powerPointsMovesTotal;
		float healMoves;
		int hitTimesMoves;
		bool firstMoves;
		bool critMoves;
		bool instaMoves;
		bool dodgeMoves;
		bool flinchMoves;
		bool chargeMoves;
	public:
		Pokemon::Moves();
		Pokemon::Moves(std::string nameMoves, std::string typeMoves, std::string categoryMoves, float powerMoves, int powerPointsMovesTotal,int accuracyMoves, int powerPointsMoves, float healMoves, int hitTimesMoves, bool firstMoves, bool critMoves, bool instaMoves, bool dodgeMoves, bool flinchMoves, bool chargeMoves);
		Pokemon::Moves(std::string moveName);
		void setnameMoves(std::string nameMoves);
		void settypeMoves(std::string typeMoves);
		void setcategoryMoves(std::string categoryMoves);
		void setpowerMoves(float powerMoves);
		void setaccuracyMoves(int accuracyMoves);
		void setpowerPointsMoves(int powerPointsMoves);
		void setpowerPointsTotal(int powerPointsMovesTotal);
		void sethealMoves(float healMoves);
		void sethitTimeMoves(int hitTimesMoves);
		void setfirstMoves(bool firstMoves);
		void setcritMoves(bool critMoves);
		void setinstaMoves(bool instaMoves);
		void setdodgeMoves(bool dodgeMoves);
		void setflinchMoves(bool flinchMoves);
		void setchargeMoves(bool chargeMoves);

		std::string getnameMoves();
		std::string gettypeMoves();
		std::string getcategoryMoves();
		int getpowerMoves();
		int getpowerPointMoves();
		int getpowerPointMovesTotal();
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
	//The array of moves need to be in public, unfortunately
	Pokemon::Moves moveSet[4];

	Pokemon();
	//Pokemon(std::string pkmnName, int atk, int def, int hp, int spDef, int spAtk, int spd);
	Pokemon(int pkmnNum);
	//Setter functions
	void setName(std::string pkmnName);
	void setAtk(int atk);
	void setDef(int def);
	void setSpAtk(int spAtk);
	void setspDef(int spDef);
	void setHp(int hp);
	void setSpd(int spd);
	void setmoveSet(Pokemon::Moves moveset);
	//void setType1(std::string type1);
	//void setType2(std::string type2);
	//Getter functions
	int getAtk();
	int getDef();
	int gethp();
	int getSpAtk();
	int getSpDef();
	int getSpd();
	std::string getName();
	//std::string getType1();
	//std::string getType2();
	//Misc functions
	bool isKO();
	void setKO(bool KO_Value);
	//void printMoveset(); //Debug for now
	void printName();
};
