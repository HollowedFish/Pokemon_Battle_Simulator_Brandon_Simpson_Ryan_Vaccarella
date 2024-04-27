//Settings for the pokemon class
#include "Pokemon_Team.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
//Constructor functions
Pokemon::Pokemon() {
	pkmnName = "";
	atk = 0;
	def = 0;
	spAtk = 0;
	spDef = 0;
	hp = 0;
	spd = 0;
	/*type1 = "";
	type2 = "";*/ //These are for later
}
//This only needs to have the name as input, for simplicity
Pokemon::Pokemon(int pkmnNum) {
	std::ifstream input;
	std::string* usableMoves = new std::string[547];
	std::string storage;
	input.open("PokemonMoves.csv");
	for (int i = 0; i < 547;i++) {
		getline(input, storage, ',');
		usableMoves[i] = storage;
		getline(input, storage);
	} // Adds all usable moves to an array
	input.close();
	input.open("PokemonGens1-3.csv");
	if (input.is_open()) {
		std::string content;
		for (int i = 1; i <= pkmnNum; i++) {
			if (i == pkmnNum) {//This checks to see if we are on the right pokemon
				getline(input, content, ',');
				pkmnName = content;
				//std::cout << content << ":"; //debug
				getline(input, content, ',');
				hp = stoi(content);
				getline(input, content, ',');
				atk = stoi(content);
				getline(input, content, ',');
				def = stoi(content);
				getline(input, content, ',');
				spAtk = stoi(content);
				getline(input, content, ',');
				spDef = stoi(content);
				getline(input, content, ',');
				spd = stoi(content);
				//Block of getlines above is the only way I can think of
				bool moveIsPossible = false;
				int possibleMovesNum = 0;
				for (int j = 0; j < 30; j++) {
					moveIsPossible = false; //Forgetting to reset this made this way harder than it needed to be
					getline(input, content, ',');
					possibleMoves[j] = content;
					//std::cout << possibleMoves[j] << std::endl; //Debug
					for (int k = 0; k < 547;k++) {
						//std::cout <<  possibleMoves[j] << "Vs. " << usableMoves[k] << std::endl; //Debug
						if (possibleMoves[j] == usableMoves[k]) {
							moveIsPossible = true;
							//std::cout << " Move is possible:" << possibleMoves[j] << std::endl; //Debug
							possibleMovesNum++;
						}
							//std::cout << "success"; //Debug
					}//Makes sure all moves entered into possiblemoves are usable
					//std::cout << content << " " << i; //Debug
					if (moveIsPossible == false) {
						//std::cout << " Move is NOT possible:" << possibleMoves[j] << std::endl; //Debug
						possibleMoves[j] = "";
					}
					if (possibleMovesNum < 4) {//Makes sure to always generate a valid pokemon moveset
						possibleMoves[16] = "Tackle";
							possibleMoves[17] = "Quick Attack";
							possibleMoves[18] = "Scratch";
							possibleMoves[19] = "Double Hit";
					}
				}
				input.close();
			}
			else {
				getline(input, content); //This moves the cursor one line down while skipping the rest of the commas
				if (input.eof()) {
					std::cout << "Pokemon not found" << std::endl;
					input.close();
					exit(3);
				}
			}
		}

		//Random moveset name generation
		std::string movesetS[4];
		for (int i = 0;movesetS[3] == "" || movesetS[2] == "" || movesetS[1] == "" || movesetS[0] == ""; i++) //Keeps going until all moves are filled
		{
			int moveNumber = rand() % 30;
			//std::cout << "Move number:" << moveNumber <<std::endl; //Debug
			if (movesetS[i % 4] == "") {
				//std::cout << i << "=>" << i % 4; //Debug
				movesetS[i % 4] = possibleMoves[moveNumber];
				//std::cout << "move set to: " << possibleMoves[moveNumber] << std::endl; //Debug
			}
			if (movesetS[i % 4] == movesetS[(i + 1) % 4] || movesetS[i % 4] == movesetS[(i - 1) % 4] || movesetS[i % 4] == movesetS[(i + 2) % 4]) { //This should hopefully not allow duplicate moves
				movesetS[(i % 4)] = ""; //using i and modulo should save some space and allow wraparound of numbers when looping
				//std::cout << "Duplicate move triggered" << std::endl; //Debug
			}
		}
		input.close();
		//Now that the names of the moves are all generated: time to set up the actual move data
		for (int k = 0; k < 4;k++) {
			Pokemon::moveSet[k] = Pokemon::Moves(movesetS[k]);
			//std::cout << moveSet[k].getnameMoves() << " vs. " << movesetS[k] << std::endl; //Debug
		}
	}
	delete[] usableMoves;
}
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
int Pokemon::gethp() {
	return hp;
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
/*void Pokemon::printMoveset() {
	std::cout << pkmnName;
	for (int i = 0;i < 4;i++) {
		std::cout << std::endl << moveset[i];
	}
}*/
void Pokemon::printName() {
	std::cout << pkmnName;
}
#pragma endregion

//Setting for the Moves Class:
//Constructors
#pragma region
Pokemon::Moves::Moves() {
	nameMoves = "";
	typeMoves = "";
	categoryMoves = "";
	powerMoves = 0.0;
	accuracyMoves = 0;
	powerPointsMoves = 0;
	powerPointsMovesTotal =0;
	healMoves = 0;
	hitTimesMoves = 0;
	firstMoves = false;
	critMoves = false;
	instaMoves = false;
	dodgeMoves = false;
	flinchMoves = false;
	chargeMoves = false;
}
Pokemon::Moves::Moves(std::string moveName) {
	//std::cout << moveName << " "; //Debug
	std::ifstream input;
	input.open("PokemonMoves.csv");
	if (input.is_open()) {
		std::string content;
		for (int i = 0; i < 547;i++) {
			getline(input, content, ','); //Gets the name of the move at the line the cursor is on
			//std::cout << content << " "; //Debug
			if (content == moveName) { //If the cursor is on the right line
				//Massive block of getlines to read all values needed
				nameMoves = moveName; //Sets the move name
				//std::cout << content; //Debug
				getline(input, content, ',');
				//std::cout << content << " "; //Debug
				typeMoves = content;
				getline(input, content, ',');
				//std::cout << content << " "; //Debug
				categoryMoves = content;
				getline(input, content, ',');
				//std::cout << content << " "; //Debug
				powerMoves = stoi(content);
				getline(input, content, ',');
				//std::cout << content << " "; //Debug
				accuracyMoves = stoi(content);
				getline(input, content, ',');
				//std::cout << content << " "; //Debug
				powerPointsMoves = stoi(content);
				getline(input, content, ',');
				//std::cout << content << " "; //Debug
				healMoves = stof(content);
				getline(input, content, ',');
				//std::cout << content << " "; //Debug
				hitTimesMoves = stoi(content);
				getline(input, content, ',');
				if (content == "TRUE") {
					firstMoves = true;
				} //Don't need to check for false
				getline(input, content, ',');
				if (content == "TRUE") {
					critMoves = true;
				}
				getline(input, content, ',');
				if (content == "TRUE") {
					instaMoves = true;
				}
				getline(input, content, ',');
				if (content == "TRUE") {
					dodgeMoves = true;
				}
				getline(input, content, ',');
				flinchMoves;
				if (content == "TRUE") {
					flinchMoves = true;
				}
				getline(input, content, ',');
				if (content == "TRUE") {
					chargeMoves = true;
				}
				//std::cout << std::endl; //Debug
			}
			else {
				getline(input, content); //Moves to the next line
				if (input.eof() && categoryMoves == "") { //This single and comparison cost me so much time
					std::cout << "Pokemon Move not found" << std::endl;
					input.close();
					exit(4);
				}
			}
		}
	}
	else
		std::cout << "File failed bro";
}
#pragma endregion
//Setters
#pragma region
void Pokemon::Moves::setnameMoves(std::string nameMoves) {
	nameMoves = nameMoves;
}
void Pokemon::Moves::settypeMoves(std::string typeMoves) {
	typeMoves = typeMoves;
}
void Pokemon::Moves::setcategoryMoves(std::string categoryMoves) {
	this->categoryMoves = categoryMoves;
}
void Pokemon::Moves::setpowerMoves(float powerMoves) {
	this->powerMoves = powerMoves;
}
void Pokemon::Moves::setaccuracyMoves(int accuracyMoves) {
	this->accuracyMoves = accuracyMoves;
}
void Pokemon::Moves::setpowerPointsMoves(int powerPointsMoves) {
	this->powerPointsMoves = powerPointsMoves;
}
void Pokemon::Moves::setpowerPointsTotal(int powerPointsMovesTotal) {
	this-> powerPointsMovesTotal= powerPointsMoves;
}
void Pokemon::Moves::sethealMoves(float healMoves) {
	this->healMoves = healMoves;
}
void Pokemon::Moves::sethitTimeMoves(int hitTimesMoves) {
	this->hitTimesMoves = hitTimesMoves;
}
void Pokemon::Moves::setfirstMoves(bool firstMoves) {
	this->firstMoves = firstMoves;
}
void Pokemon::Moves::setcritMoves(bool critMoves) {
	this->critMoves = critMoves;
}
void Pokemon::Moves::setinstaMoves(bool instaMoves) {
	this->instaMoves = instaMoves;
}
void Pokemon::Moves::setdodgeMoves(bool dodgeMoves) {
	this->dodgeMoves = dodgeMoves;
}
void Pokemon::Moves::setflinchMoves(bool flinchMoves) {
	this->flinchMoves = flinchMoves;
}
void Pokemon::Moves::setchargeMoves(bool chargeMoves) {
	this->chargeMoves = chargeMoves;
}
#pragma endregion
//Getters
#pragma region
std::string Pokemon::Moves::getnameMoves() {
	return nameMoves;
}
std::string Pokemon::Moves::gettypeMoves() {
	return typeMoves;
}
std::string Pokemon::Moves::getcategoryMoves() {
	return categoryMoves;
}
int Pokemon::Moves::getpowerPointMoves() {
	return powerPointsMoves;
}
int Pokemon::Moves::getpowerPointMovesTotal() {
	return powerPointsMovesTotal;
}
int Pokemon::Moves::getpowerMoves() {
	return powerMoves;
}
int Pokemon::Moves::getaccuracyMoves() {
	return accuracyMoves;
}
float Pokemon::Moves::gethealMoves() {
	return healMoves;
}
int Pokemon::Moves::gethitTimesMoves() {
	return hitTimesMoves;
}
bool Pokemon::Moves::getfirstMoves() {
	return firstMoves;
}
bool Pokemon::Moves::getcritMoves() {
	return critMoves;
}
bool Pokemon::Moves::getinstaMoves() {
	return instaMoves;
}
bool Pokemon::Moves::getdodgeMoves() {
	return dodgeMoves;
}
bool Pokemon::Moves::getflinchMoves() {
	return flinchMoves;
}
bool Pokemon::Moves::getchargeMoves() {
	return chargeMoves;
}
#pragma endregion

