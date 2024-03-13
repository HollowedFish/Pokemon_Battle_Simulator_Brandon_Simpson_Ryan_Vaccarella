//Settings for the pokemon class
#include "Pokemon_Team.h"
#include <string>
#include <fstream>
#include <iostream>
//Constructor functions
Pokemon::Pokemon() {
	atk = 0;
	def = 0;
	spAtk = 0;
	spDef = 0;
	hp = 0;
	spd = 0;
	type1 = "";
	type2 = "";
}
Pokemon::Pokemon(std::string pkmn) {
	//This will be blank for now
}
//Setter functions
#pragma region
void Pokemon::setAtk(int atk) {
	this->atk = atk;
}
void Pokemon::setDef(int def) {
	this->def = def;
}
void Pokemon::setSpAtk(int spDef) {
	this->spAtk = spAtk;
}
void Pokemon::setHp(int hp) {
	this->hp = hp;
}
void Pokemon::setSpd(int spd) {
	this->spd = spd;
}
void Pokemon::setName(std::string name) {
	this->name = name;
}
void Pokemon::setType1(std::string type1) {
	this->type1 = type1;
}
void Pokemon::setType2(std::string type2) {
	this->type2 = type2;
}
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
	return name;
}
std::string Pokemon::getType1() {
	return type1;
}
std::string Pokemon::getType2() {
	return type2;
}
#pragma endregion
//Misc functions
#pragma region
bool Pokemon::isKO() {
	return KO;
}
void Pokemon::setKO(bool KO_Value) {
	KO = KO_Value;
}
#pragma endregion