﻿// CSV reader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pokemon_Team.h"
#include <cstdlib>
#include <time.h>
#include <vector>
//This works...Need to find better way hmmm
//Need to use a vector to store pokemon or a pointer
/* void generateRandom(int total) {
    std::string pkmnName;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int hp;
    int spd;
   // int pTotal = total * 2;
    //Pokemon p[pTotal];
    std::string possibleMoves[20];
    std::ifstream input;
    srand(time(NULL));
   // for (int c = 0; c < total; c++) {
    int pkmnR = (rand() % 7)+1;
    std::cout << pkmnR;
    input.open("Pokedex first 8 basic eveolutions.csv");
    if (input.is_open()) {
        std::string content;
        for (int i = 1; i <= pkmnR; i++) {
            if (i == pkmnR) {//This checks to see if we are on the right pokemon
                getline(input, content, ',');
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
                for (int j = 0; j <= 19 && getline(input, content, ','); j++) {
                    possibleMoves[j] = content;
                    //std::cout << content << " " << i; //Debug
                }
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
    }
       // p[c]= Pokemon (pkmnName, atk, def, spDef, spAtk, hp, spd);
   // }
    //Testing
   // Pokemon p1(pkmnName, atk, def, spDef,spAtk, hp, spd);
    //std::cout << p1.getName();
    input.close();
}*/
 void startBattle(Pokemon* team1, Pokemon* team2, int teamSize) {
     std::cout << "Function not implemented yet";
 }
 void generateTeams(Pokemon *team1, Pokemon *team2, int teamSize) {
     srand(time(NULL));
     int* pokemonNums = new int[teamSize*2];
     for (int i = 0; i < teamSize * 2;i++) {
         pokemonNums[i] = rand() % 7;//Make this the number of lines in the pokemon csv
         for (int j = 0; j < i; j++) {
             if (pokemonNums[i] == pokemonNums[j]) {
                 pokemonNums[i] = rand() % 7; //There may still be duplicates with this method (check later)
                 std::cout << "Duplicate detection triggered"; //Debug
             }
         }
     }
     std::ifstream input;
     input.open("Pokedex first 8 basic eveolutions.csv");
     std::string* pokemonNames = new std::string[teamSize*2];
     std::string storage;
         for (int k = 0;k < teamSize*2; k++) { //only stops when all names are filled
             for (int i = 0; i != pokemonNums[k] && getline(input,storage);i++){} //Iterates until the required line number
             getline(input, pokemonNames[k], ','); 
             std::cout << pokemonNames[k]; //Debug
         }
     int choice;
     std::cout << "Your choices are:" << std::endl;
     for (int k = 0;k < teamSize*2;k++) {
         std::cout << k+1 << pokemonNames[k] << std::endl;
     }
     int teamPickNum =1;
     int team1Mons = 0;
     int team2Mons = 0;
         while (team2Mons !=teamSize) {
             std::cout << "Team" << teamPickNum << "Choose a pokemon" <<std::endl;
             std::cin >> choice;
             if (choice < 0 || choice > teamSize*2) {
                 std::cout << "That is not a valid pokemon choice, please try again" << std::endl;
             }
             else {
                 if (teamPickNum == 1) {
                     teamPickNum = 2;
                     team1[team1Mons] = Pokemon(pokemonNames[choice - 1]);
                     team1Mons++;
                 }
                 if (teamPickNum == 2) {
                     teamPickNum = 1; 
                     team2[team2Mons] = Pokemon(pokemonNames[choice - 1]);
                     team2Mons++;
                 }
             }
         }
         std::cout << "Team successfully generated \n Press enter to continue...";
         std::cin.ignore();

 }
 void displayMenu(Pokemon *team1,Pokemon *team2,int teamSize) {
     system("CLS");
     int choice;
     std::cout << "Welcome to the Pokoman™ Battler V0.6.0 " << std::endl << "Please Choose an option:" << std::endl;
     std::cout << "[1] Start Battle(WIP)\n" << "[2]Set Up Teams(WIP) \n" << "[3]View Teams(WIP) \n" << "[4]View all Pokemon(Maybe) \n" << "[5]View all Moves(Maybe) \n" << "[0]Exit \n";
     std::cin >> choice;
     switch (choice) {
     case 1:
         if (team1[0].getName() == "" || team2[0].getName() == "") {
             std::cout << "Generate your teams first\n" << "Press enter to continue...";
             std::cin.ignore();
         }
         else
            startBattle(team1, team2, teamSize);
         break;
     case 2:
         if (team1[0].getName() != "" || team2[0].getName() != "") {
             std::cout << "Teams already generated\n" << "Press enter to continue...";
             std::cin.ignore();
         }
         else
             generateTeams(team1, team2, teamSize);
         break;
     case 3:
         std::cout << "This function is not impemented yet";
         break;
     case 4:
         std::cout << "This function is not impemented yet";
         break;
     case 5:
         std::cout << "This function is not impemented yet";
         break;
     case 0:
         system("CLS");
         std::cout << "Thanks for playing!" << std::endl;
#pragma region
         //Funny pikacu took an hour well spent
         std::cout << R"(
quu..__
 $$$b  `---.__
  "$$b        `--.                          ___.---uuudP
   `$$b           `.__.------.__     __.---'      $$$$"              .
     "$b          -'            `-.-'            $$$"              .'|
       ".                                       d$"             _.'  |
         `.   /                              ..."             .'     |
           `./                           ..::-'            _.'       |
            /                         .:::-'            .-'         .'
           :                          ::''\          _.'            |
          .' .-.             .-.           `.      .'               |
          : /'$$|           .@"$\           `.   .'              _.-'
         .'|$u$$|          |$$,$$|           |  <            _.-'
         | `:$$:'          :$$$$$:           `.  `.       .-'
         :                  `"--'             |    `-.     \
        :##.       ==             .###.       `.      `.    `\
        |##:                      :###:        |        >     >
        |#'     `..'`..'          `###'        x:      /     /
         \                                   xXX|     /    ./
          \                                xXXX'|    /   ./
          /`-.                                  `.  /   /
         :    `-  ...........,                   | /  .'
         |         ``:::::::'       .            |<    `.
         |             ```          |           x| \ `.:``.
         |                         .'    /'   xXX|  `:`M`M':.
         |    |                    ;    /:' xXXX'|  -'MMMMM:'
         `.  .'                   :    /:'       |-'MMMM.-'
          |  |                   .'   /'        .'MMM.-'
          `'`'                   :  ,'          |MMM<
            |                     `'            |tbap\
             \                                  :MM.-'
              \                 |              .''
               \.               `.            /
                /     .:::::::.. :           /
               |     .:::::::::::`.         /
               |   .:::------------\       /
              /   .''               >::'  /
              `',:                 :    .'
                                   `:.:' )" << std::endl;
#pragma endregion
         exit(0);
         break;
     }
 }
    int main() {
    //std::string name = "Squirtle";
    //Pokemon myMon(name);
    //myMon.printMoveset(); //Debug
        int teamSize; //Change the maximum team size when we get more pokemon
        std::cout << "How many pokemon on each team?(Max: 3)";
        std::cin >> teamSize;
        if (teamSize > 3 || teamSize <= 0) {
            std::cout << "Nice try. The size of each team is now 3.";
            teamSize = 3;
        }

       Pokemon* team1 = new Pokemon[teamSize];
       Pokemon* team2 = new Pokemon[teamSize];
    while (true) {
        displayMenu(team1,team2,teamSize);
    }
    delete[] team1;
    delete[] team2;
}
