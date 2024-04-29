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
void potion::use(Pokemon* pokemon) {
	pokemon->setHp(pokemon->getHp() + healVal);
}
void potion::printItem(){}
#pragma endregion

//Ether class
#pragma region
int ether::getPPRV() { return PP_RestoreVal; }
void ether::setPPRV(int PP_RestoreVal) { this->PP_RestoreVal = PP_RestoreVal; }
void ether::use(Pokemon* pokemon) {
	int choice = 0;
	system("CLR");
	std::cout << "Please choose which move to use the ether on:\n";
	std::cout << "1." << pokemon->moveSet[0].getnameMoves() << pokemon->moveSet[0].getpowerPointMoves() << "/" << pokemon->moveSet[0].getpowerPointMovesTotal() << std::endl;
	std::cout << "2." << pokemon->moveSet[1].getnameMoves() << pokemon->moveSet[1].getpowerPointMoves() << "/" << pokemon->moveSet[1].getpowerPointMovesTotal() << std::endl;
	std::cout << "3." << pokemon->moveSet[2].getnameMoves() << pokemon->moveSet[2].getpowerPointMoves() << "/" << pokemon->moveSet[2].getpowerPointMovesTotal() << std::endl;
	std::cout << "4." << pokemon->moveSet[3].getnameMoves() << pokemon->moveSet[3].getpowerPointMoves() << "/" << pokemon->moveSet[3].getpowerPointMovesTotal() << std::endl;
	std::cin >> choice;
	std::cin.ignore();
	pokemon->moveSet[choice - 1].setpowerPointsMoves(pokemon->moveSet[choice - 1].getpowerPointMoves() + PP_RestoreVal);
	if (pokemon->moveSet[choice - 1].getpowerPointMoves() > pokemon->moveSet[choice - 1].getpowerPointMovesTotal()) {
		pokemon->moveSet[choice - 1].setpowerPointsMoves(pokemon->moveSet[choice - 1].getpowerPointMovesTotal());
	}
	std::cout << "New PP Total is " << pokemon->moveSet[choice - 1].getpowerPointMoves() << "/" << pokemon->moveSet[choice - 1].getpowerPointMovesTotal();
	std::cout << "Press enter to continue...";
	std::cin.ignore();
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