#include "Items.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

//Item class
#pragma region
//Getters for Item class
std::string item::getName() { return name; }
std::string item::getDescription() { return description; }
int item::getQuantity() { return quantity; }
//setters for Item class
void item::setName(std::string name) { this->name = name; }
void item::setDescription(std::string description) { this->description = description; }
void item::setQuantity(int quantity) { this->quantity = quantity; }
void item::use() { std::cout << "Used an undefined item \n This shouldn't happen."; }
void item::printItem() { std::cout << " Base Item print function used. \n This shouldn't happen."; }
#pragma endregion

//Potion class
#pragma region
int potion::getHealVal(){return healVal; }
void potion::setHealVal(int healVal) { this->healVal = healVal; }
void potion::use() {

}
void potion::printItem(){}
#pragma endregion

//Ether class
#pragma region
int ether::getPPRV() { return PP_RestoreVal; }
void ether::setPPRV(int PP_RestoreVal) { this->PP_RestoreVal = PP_RestoreVal; }
void ether::use() {

}
void ether::printItem(){}
#pragma endregion

//revive class
#pragma region
float revive::getResHealPercent() { return resHealPercent; }
void revive::setResHealPercent(float resHealPercent) { this->resHealPercent = resHealPercent; }
void revive::use() {

}
void revive::printItem(){}
#pragma endregion