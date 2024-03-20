﻿// Pokemon Battler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Made by Brandon Simpson and Ryan Vaccarella
#include <iostream>
#include "Pokemon_Team.h"
#include <cstdlib>
#include <time.h>
#include <vector>
//Got tired lines 60-66 contain the ensenece for how it should go need to filter it to nested classes to work
//This works...Need to find better way hmmm
//Need to use a vector to store pokemon or a pointer
void viewMoves(std::string*pMoves) {
    system("CLS");
    for (int i = 0; i <= 546; i++) {
        std::cout <<i+1<<". "<< pMoves[i] << std::endl;
        if (i == 249) { //Rudimentary page system so it actually displays all moves properly
            std::cout << "Page 1/2" << std::endl << "Press enter to move to next page when ready...";
            std::cin.get();
            std::cin.ignore();
            system("CLS");
        }
        if (i == 546) {
            std::cout << "Page 2/2" << std::endl << "Press enter to continue...";
        }
    }
}
 void startBattle(Pokemon* team1, Pokemon* team2, int teamSize) { //Ok, here we go on the main bit
     Pokemon t1Active; //Creates the objects for the active pokemon
     Pokemon t2Active;
     std::string p1;//Player names
     std::string p2;
     system("CLS"); //Clears screen
     std::cout << "Enter the name for player 1:" << std::endl;
     std::cin.ignore(); //This needs to be here otherwise it skips
     std::getline(std::cin, p1);
     std::cout << "Enter the name for player 2:" << std::endl;
     std::getline(std::cin, p2);
     system("CLS");
     std::cout << "Trainer " << p1 << " challenges Trainer " << p2 << " to a Battle!" << std::endl;
     std::cout << "Press Enter to continue...";
     std::cin.get();
     std::cin.ignore();
     //1st team initial pokemon choosing
     while (t1Active.getName() == "") {
         system("CLS");
         std::cout << "Trainer " << p1 << ": Choose who to send out first!\n";
         std::cout << "--------------------------------------------------\n"; //<--Copy paste this for formatting consistency later
         for (int i = 0; i < teamSize; i++) {
             std::cout << i + 1 << ". " << team1[i].getName() << std::endl;
         }
         int choice = 0;
         std::cout << "Please enter the number of the pokemon:";
         std::cin >> choice;
         //std::cout << choice; //Debug
         if (choice >= 1 && choice <= teamSize) { //Makes the active pokemon the chosen pokemon + Input validation
             t1Active = team1[choice - 1];
         }
         else {
             std::cout << "Invalid selection" << std::endl << "Try again";
             std::cin.ignore();
         }
     }
     //2nd team initial pokemon choosing
     while (t2Active.getName() == "") {
         system("CLS");
         std::cout << "Trainer " << p2 << ": Choose who to send out first!\n";
         std::cout << "--------------------------------------------------\n"; //<--Copy paste this for formatting consistency later
         for (int i = 0; i < teamSize; i++) {
             std::cout << i + 1 << ". " << team2[i].getName() << std::endl;
         }
         int choice = 0;
         std::cout << "Please enter the number of the pokemon:";
         std::cin >> choice;
         //std::cout << choice; //Debug
         if (choice >= 1 && choice <= teamSize) { //Makes the active pokemon the chosen pokemon + Input validation
             t2Active = team2[choice - 1];
         }
         else {
             std::cout << "Invalid selection" << std::endl << "Try again";
             std::cin.ignore();
         }
     }
     /*std::cout << "Starting active pokemon are: " << T1Active.getName() << " " << T2Active.getName(); //Debug
     std::cin.get(); //Debug
     std::cin.ignore();//Debug */

     //Actual battle loop time, here we go!
     std::cout << "" << "" << std::endl;
     bool p1Win = false;
     bool p2Win = false;
     while (p1Win == false && p2Win == false) {
         //Come back to this later
     }
 }
 void generateTeams(Pokemon* team1, Pokemon* team2, int teamSize,std::string *tMoves) {
     std::ifstream input;
     std::ifstream moves;
     std::string pkmnName;
     int atk;
     int def;
     int spAtk;
     int spDef;
     int hp;
     int spd;
     int pkmnR;
     std::string potentialMoves[30];
     std::string possibleMoves[30];
     std::string content;
    srand(time(0));
      for (int c = 0; c < teamSize; c++) {
          input.open("Pokedex first 8 basic eveolutions.csv");
     int pkmnR = rand() % 7+1;
    //std::cout << pkmnR; //Debug
     if (input.is_open()) {
             for (int i = 1; i <= pkmnR; i++) {
                 if (i == pkmnR) {//This checks to see if we are on the right pokemon
                     getline(input, content, ',');
                     pkmnName = content;
                     getline(input, content, ',');
                     hp = stoi(content);
                     getline(input, content, ',');
                     atk = stoi(content);
                     getline(input, content, ',');
                     def= stoi(content);
                     getline(input, content, ',');
                     spAtk= stoi(content);
                     getline(input, content, ',');
                     spDef = stoi(content);
                     getline(input, content, ',');
                     spd = stoi(content);
                     //This will sort it for every other one
                    team1[c] = Pokemon(pkmnName, atk, def, hp, spAtk, spDef, spd);
                     //Block of getlines above is the only way I can think of
                     for (int j = 0; j <= 19; j++) {
                         getline(input, content,',');
                         potentialMoves[j] = content;
                        /* for (int a = 0; a <= 546; a++) {
                             if (tMoves[a] == potentialMoves[j]) {
                                 possibleMoves[j] = potentialMoves[j];
                                 std::cout << possibleMoves[j];
                              }
                         }*/
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
         }
     }
      for (int c = 0; c < teamSize; c++) { //Makes team 2 by copying the process of team 1, may or may not be duplicate mons
          input.open("Pokedex first 8 basic eveolutions.csv");
          pkmnR = rand() % 7 + 1;
          //std::cout << pkmnR; //Debug
          if (input.is_open()) {
              std::string content;
              for (int i = 1; i <= pkmnR; i++) {
                  if (i == pkmnR) {//This checks to see if we are on the right pokemon
                      getline(input, content, ',');
                      pkmnName = content;
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
                      //This will sort it for every other one
                      team2[c] = Pokemon(pkmnName, atk, def, hp, spAtk, spDef, spd);
                      //Block of getlines above is the only way I can think of
                      for (int j = 0; j <= 19 && getline(input, content, ','); j++) {
                          possibleMoves[j] = content;
                          //std::cout << content << " " << i; //Debug
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
          }
      }
 }
 void displayMenu(Pokemon *team1,Pokemon *team2,int teamSize,std::string *tMoves) {
     system("CLS");
     std::string enter;
     int choice;
     std::cout << "Welcome to the Pokoman™ Battler V0.6.0 " << std::endl << "Please Choose an option:" << std::endl;
     std::cout << "[1] Start Battle(WIP)\n" << "[2]Generate Pokemon teams(WIP) and moves \n" << "[3]View Teams \n" << "[4]View all Pokemon(WIP) \n" << "[5]View all Moves possible \n" << "[0]Exit \n";
     std::cin >> choice;
     switch (choice) {
     case 1:
         if (team1[0].getName() == "" || team2[0].getName() == "") {
             std::cout << "Generate your teams first\n" << "Press enter to continue...";
             std::cin.get();
             std::cin.ignore();
         }
         else
            startBattle(team1, team2, teamSize);
         break;
     case 2:
         if (team1[0].getName() != "" || team2[0].getName() != "") {
             std::cout << "Teams already generated" <<std::endl << "Press enter to continue...";
             std::cin.get();
             std::cin.ignore(); //Both of these are needed for this to work
         }
         else
             generateTeams(team1, team2, teamSize,tMoves);
         std::cout << "Teams Generated successfully!" << std::endl << "Press Enter to Continue...";
         std::cin.get();
         std::cin.ignore();
         break;
     case 3:
         if (team1[0].getName() != "" || team2[0].getName() != "") {
             std::cout << "On team 1 we have..." << std::endl;
             for (int i = 0; i < teamSize; i++) {
                 std::cout << i + 1 << ". " << team1[i].getName() << std::endl;
             }
             std::cout << "On team 2 we have.." << std::endl;
             for (int i = 0; i < teamSize; i++) {
                 std::cout << i + 1 << ". " << team2[i].getName() << std::endl;
             }
             std::cout << "\n Press Enter to Continue...";
             std::cin.get();  
             std::cin.ignore();
         }
         else {
             std::cout << "You still need to generate your teams! Go catch em!";
             std::cin.get();
             std::cin.ignore();
         }
         break;
     case 4:
         std::cout << "This function is not impemented yet";
         std::cin.get();
         std::cin.ignore();
         break;
     case 5:
         viewMoves(tMoves);
         //std::cin.get(); //Maybe don't need this this one time?
         std::cin.ignore();
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
         //All deletes need to go here
         delete[] team1;
         delete[] team2;
         delete[] tMoves;
         exit(0);
         break;
     default:
         std::cout << "invalid input" <<std::endl << "Press enter to continue";
     }
     displayMenu(team1, team2, teamSize,tMoves); //Calls itself for an infinite loop
 }
    int main() {
    //std::string name = "Squirtle";
    //Pokemon myMon(name);
    //myMon.printMoveset(); //Debug
        int teamSize; //NOTE: Change the maximum team size when we get more pokemon
     
        std::cout << "How many pokemon on each team?(Max: 3)";
        std::cin >> teamSize;
        if (teamSize > 3 || teamSize <= 0) {
            std::cout << "Nice try. The size of each team is now 3." << std::endl << "Press Enter to Continue...";
            std::cin.get();
            std::cin.ignore();
            teamSize = 3;
        }

       Pokemon* team1 = new Pokemon[teamSize];
       Pokemon* team2 = new Pokemon[teamSize];
       std::string* tMoves = new std::string[547]; //Creates an array for moves of size 547
       std::ifstream moves;
       moves.open("PokemonMoves - Sheet1.csv");
       std::string content;
       if (moves.is_open()) {
           for (int i = 0; i <= 546; i++) { //Stores all move names sequentially in an array
               getline(moves, content, ',');
               tMoves[i] = content;
               getline(moves, content); //Iterates to the next line
           }
       }
       moves.close();
        displayMenu(team1,team2,teamSize,tMoves); //Start game loop
    //The below will never actually run
    delete[] team1;
    delete[] team2;
    delete[] tMoves;
}
    /*srand(time(NULL));
   int* pokemonNums = new int[teamSize*2];
   for (int i = 0; i < teamSize * 2;i++) {
       pokemonNums[i] = rand() % 7;//Make this the number of lines in the pokemon csv
       std::cout << pokemonNums[i];
       //std::cin.get();
       //std::cin.ignore();
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
       for (int k = 0;pokemonNames[(teamSize*2)-1] == ""; k++) { //only stops when all names are filled
           for (int i = 0; i != pokemonNums[k];i++) { getline(input, storage); } //Iterates until the required line number
           getline(input, pokemonNames[k], ',');
           std::cout << pokemonNames[k]; //Debug
       }
   int choice;
   std::cout << "Your choices are:" << std::endl;
   for (int k = 0;k < teamSize*2;k++) {
       std::cout << k+1 << " " << pokemonNames[k]  << std::endl;
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
       std::cin.get();
       std::cin.ignore();
       */ //Come back to this later
       //Temporary hardcoding teams
       /*std::ifstream input;
       input.open("Pokedex first 8 basic eveolutions.csv");
       for (int i = 0; i < teamSize;i++) {
           //getline(input, team1[i], ',');
       }
       }*/
       /* void generateRandom(int total) {

       //Testing
      // Pokemon p1(pkmnName, atk, def, spDef,spAtk, hp, spd);
       //std::cout << p1.getName();
       input.close();
   }*/