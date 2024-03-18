//Settings for the pokemon class
#include "Pokemon_Team.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
//Constructor functions
Pokemon::Pokemon() {
	pkmnName = "POP";
	atk = 0;
	def = 0;
	spAtk = 0;
	spDef = 0;
	hp = 0;
	spd = 0;
	/*type1 = "";
	type2 = "";*/ //These are for later
}
Pokemon::Pokemon(std::string pkmnName, int atk, int def, int spDef, int spAtk, int hp, int spd) {
	this->pkmnName =pkmnName;
	this->atk = atk;
	this->def = def;
	this->spDef = spDef;
	this->spAtk = spAtk;
	this->hp = hp;
	this ->spd = spd;
}
//doesn't work...Moved to Pokemon_Main in case this does
//it did but now memory location error
/*Pokemon::Pokemon(std::string pkmnName,int atk,int def,int spDef,int spAtk,int hp,int spd) {
	std::ifstream input;
	srand(time(NULL));
	int pkmnR = rand()%8;
	if (pkmnR == 0) {
		pkmnR = 1;
	}
	input.open("Pokedex first 8 basic eveolutions.csv");
	if (input.is_open()) {
		std::string content;
		//for (int i = 1; i <= pkmnR; i++) {
			//if (i == pkmnR) {
				while (getline(input, content, ',')) {
					std::cout << content; //Debug output
					if (content == pkmnName) { //This checks to see if we are on the right pokemon
						pkmnName = content;
						getline(input, content, ',');
						atk = stoi(content);
						getline(input, content, ',');
						def = stoi(content);
						getline(input, content, ',');
						hp = stoi(content);
						getline(input, content, ',');
						spAtk = stoi(content);
						getline(input, content, ',');
						spDef = stoi(content);
						getline(input, content, ',');
						spd = stoi(content);
						//Block of getlines above is the only way I can think of
						for (int i = 0; i < 19 && getline(input, content, ','); i++) {
							possibleMoves[i] = content;
							std::cout << content << " " << i; //Debug
						}
						break;
					}
					else {
						getline(input, content); //This moves the cursor one line down while skipping the rest of the commas
						if (input.eof()) {
							std::cout << "Pokemon not found" << std::endl;
							exit(3);
						}
					}

				}
			//}
		//}
		
		//I am going to put the random moveset generation here, because I think it makes sense
		srand(time(0));
		for (int i = 0;moveset[3] == "" || moveset[2] == "" || moveset[1] == "" || moveset[0] == ""; i++) //Keeps going until all moves are filled
		{
			int moveNumber = rand() % 20; //gives a random number
			//std::cout << "Move number:" << moveNumber <<std::endl; //Debug
			if (moveset[i % 4] == "") {
				//std::cout << i << "=>" << i % 4; //Debug
				moveset[i % 4] = possibleMoves[moveNumber];
				//std::cout << "move set to: " << possibleMoves[moveNumber] << std::endl; //Debug
			}
			if (moveset[i%4] == moveset[(i+1)%4] || moveset[i%4] == moveset[(i-1)%4] || moveset[i%4] == moveset[(i+2)%4]) { //This should hopefully not allow duplicate moves
				moveset[(i%4)] = ""; //using i and modulo should save some space and allow wraparound of numbers when looping
				//std::cout << "Duplicate move triggered" << std::endl; //Debug
			}
		} 
	}
	else {
		std::cout << "File failed to open" <<std::endl;
		input.close();
		exit(2);
	}
	input.close();
}
*/
//Setter functions
#pragma region
void Pokemon::setAtk(int atk) {
	this->atk = atk;
}
void Pokemon::setDef(int def) {
	this->def = def;
}
void Pokemon::setSpAtk(int spAtk) {
	this->spAtk = spAtk;
}
void Pokemon::setspDef(int spDef) {
	this->spDef = spDef;
}
void Pokemon::setHp(int hp) {
	this->hp = hp;
}
void Pokemon::setSpd(int spd) {
	this->spd = spd;
}
void Pokemon::setName(std::string pkmnName) {
	this->pkmnName = pkmnName;
}
/*void Pokemon::setType1(std::string type1) {
	this->type1 = type1;
}
void Pokemon::setType2(std::string type2) {
	this->type2 = type2;
}*/
#pragma endregion
//Getter functions
#pragma region
int Pokemon::getAtk() {
	return atk;
}
int Pokemon::getDef() {
	return def;
}
int Pokemon::getSpAtk() {
	return spAtk;
}
int Pokemon::getSpDef() {
	return spDef;
}
int Pokemon::getSpd() {
	return spd;
}
std::string Pokemon::getName() {
	return pkmnName;
}
/*std::string Pokemon::getType1() {
	return type1;
}
std::string Pokemon::getType2() {
	return type2;
}*/
#pragma endregion
//Misc functions
#pragma region
bool Pokemon::isKO() {
	return KO;
}
void Pokemon::setKO(bool KO_Value) {
	KO = KO_Value;
}
void Pokemon::printMoveset() {
	std::cout << pkmnName;
	for (int i = 0;i < 4;i++) {
		std::cout << std::endl << moveset[i];
	}
}
void Pokemon::printName() {
	std::cout << pkmnName;
}
#pragma endregion