﻿// Pokemon Battler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Made by Brandon Simpson and Ryan Vaccarella
#include <iostream>
#include "Pokemon_Team.h"
#include <cstdlib>
#include <time.h>
//Got tired lines 60-66 contain the ensenece for how it should go need to filter it to nested classes to work
//This works...Need to find better way hmmm
//Need to use a vector to store pokemon or a pointer
void winscreen() {
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
    exit(1);

}
int damageCalculator(Pokemon Active,int p1Atk, int moveAtk, int t2Def,int Activemon) {
    int damage;
    int randomNumber=rand()%100+85;
    damage = ((((2*100/7)*p1Atk*moveAtk/t2Def)/50)+2)*randomNumber/100;
    std::cout << Active.getName() << " Took " << damage;
    Activemon -= damage;
    return Activemon;
}
bool checkFaint(Pokemon Active,int hp) {
    bool ko = false;
    if (hp<= 0) {
        std::cout << Active.getName() << " fainted!";
        ko = true;
    }
    return ko;
}
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
 void startBattle(Pokemon* team1, Pokemon* team2,/*Pokemon::Moves* moveSet,*/ int teamSize) { //Ok, here we go on the main bit
     Pokemon t1Active; //Creates the objects for the active pokemon
     Pokemon t2Active; //Maybe make into pointers for direct value editing?
     std::string p1;//Player names
     std::string p2;
     int ActiveMonNum1;
     int ActiveMonNum2;//Storage so you can actually change the stored pokemon's values (for hp and KO)
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
     t1Active = team1[0];
     ActiveMonNum1=t1Active.gethp();
             t2Active = team2[0];
             ActiveMonNum2 = t2Active.gethp();

     /*std::cout << "Starting active pokemon are: " << T1Active.getName() << " " << T2Active.getName(); //Debug
     std::cin.get(); //Debug
     std::cin.ignore();//Debug */

     //Actual battle loop time, here we go!
     //std::cout << "" << "" << std::endl;//Some sort of battle start message goes here?
     bool p1Win = false;
     bool p2Win = false;
     int turnNumP1 = 0;
     int turnNumP2 = 0;
     int dmg = 0;
     int movedmg = 0;
     int def = 0;
     int count1 = 1;
     int count2 = 1;
     std::string typeAtk1,typeAtk2;
     while (p1Win == false && p2Win == false) {
         
         if (turnNumP1 <= turnNumP2) {
             //Like the snakes and ladders game from last year

             if (checkFaint(t1Active,ActiveMonNum1)==true) {//MOVE SOMEHWERE ELSE, THIS IS JUST A TEMPORARY PLACE TO PUT THIS
                 std::cout << " is fainted" << std::endl;
                 std::cout<<"Swaping Pokemon"<<std::endl;
                 count1++;
                 if (count1 > teamSize) {
                     std::cout << "YOUR OUT OF POKEMON " << p1;
                     std::cout << "You Win!" << p2;
                     winscreen();
                 }
                 else if(count1<=teamSize){
                 t1Active = team1[count1];
                 ActiveMonNum1 = t1Active.gethp();
                 }
             }
             else
             {
                 std::cout << std::endl;
             }
             turnNumP1++;
             int choice = 0;
             system("CLS");
             std::cout << "--------------------------------------------------\n";
             std::cout << "It is turn " << turnNumP1 << " What action do you want " << t1Active.getName() << " to take " << p1 << " ? \n";
             std::cout << "--------------------------------------------------\n";
             std::cout << "Health:" << ActiveMonNum1 << std::endl << "Moves:" << std::endl;

             for (int i = 0; i < 4; i++) {
                 std::cout << i + 1 << "." << t1Active.moveSet[i].getnameMoves() << " " << t1Active.moveSet[i].getpowerPointMoves() << std::endl;
             }
             std::cin >> choice;
             if (choice > 4 || choice <= 0) {
                 while (choice <= 0 || choice > 4) {
                     std::cout << "Invalid input please reenter:";
                     std::cin >> choice;
                     std::cin.ignore();
                 }
             }
             std::cout << t1Active.moveSet[choice - 1].getpowerMoves();//Debug
             movedmg = t1Active.moveSet[choice - 1].getpowerMoves();
             typeAtk1 = t1Active.moveSet[choice - 1].getcategoryMoves();
             if (typeAtk1 == "Physical") {
                 dmg = t1Active.getAtk();
                 def = t2Active.getDef();
             }
             else {
                 dmg = t1Active.getSpAtk();
                 def = t2Active.getDef();
            }
         }
         ActiveMonNum2=damageCalculator(t2Active,dmg,movedmg,def,ActiveMonNum2);
         if (turnNumP1 > turnNumP2) {
             turnNumP2++;
             int choice = 0;
             if (checkFaint(t2Active,ActiveMonNum2)==true) {
                 std::cout << " is fainted" << std::endl;
                 std::cout << "sending out next pokemon";
                 std::cout << " is fainted" << std::endl;
                 std::cout << "Swaping Pokemon" << std::endl;
                 count2++;
                 if (count2 > teamSize) {
                     std::cout << "NO POKEMON LEFT" << p2;
                     std::cout << "You Win!" << p1;
                     winscreen();
                 }
                 else if (count2 <= teamSize) {
                     t2Active = team2[count2];
                     ActiveMonNum2 = t2Active.gethp();
                 }
             }
             else
             {
                 std::cout << std::endl;
             }
             std::cout << "It is turn " << turnNumP2 << " What action do you want " << t2Active.getName() << " to take " << p2 << "?\n";
             std::cout << "Health" << ActiveMonNum2 << std::endl;
             for (int i = 0; i < 4; i++) {
                 std::cout << i + 1 << "." << t2Active.moveSet[i].getnameMoves() << " " << t2Active.moveSet[i].getpowerPointMoves() << ": " << t2Active.moveSet[i].getpowerPointMovesTotal() << std::endl;
             }
             std::cin >> choice;
             if (choice > 4 || choice <= 0) {
                 while (choice <= 0 || choice > 4) {
                     std::cout << "Invalid input please reenter:";
                     std::cin >> choice;
                     std::cin.ignore();
                 }
             }
             movedmg = t2Active.moveSet[choice - 1].getpowerMoves();
             typeAtk2 = t2Active.moveSet[choice - 1].getcategoryMoves();

             if (typeAtk2 == "Physical") {
                 dmg = t2Active.getAtk();
                 def = t1Active.getDef();
             }
             else {
                 dmg = t2Active.getSpAtk();
                 def = t1Active.getDef();
             }
         }
        ActiveMonNum1= damageCalculator(t1Active, dmg, movedmg, def,ActiveMonNum1);
     }
     exit(1);
 }
 void generateTeams(Pokemon* team1, Pokemon* team2,/*Pokemon::Moves* moveSet,*/ int teamSize, std::string* tMoves) {
     srand(time(NULL));
     //std::ifstream input;
     /*std::ifstream moves;
     int atk;
     int def;
     int spAtk;
     int spDef;
     int hp;
     int spd;
     std::string potentialMoves[30];
     std::string possibleMoves[30];*/
     std::string pkmnName;
     int pkmnR;
     std::string content;
     for (int c = 0; c < teamSize; c++) {
         //input.open("PokemonGens1-3.csv");
         pkmnR = (rand() % 387) + 1;
         if (pkmnR == 1) {
             pkmnR = 2; //This makes sure that we don't make a pokemon with the header line
             //Wasn't necessary before because the other csv didn't have one
         }
         //std::cout << pkmnR; //Debug
         //std::cout << pkmnR<< " 1\n"; //Debug
         //if (input.is_open()) {
             //for (int i = 1; i <= pkmnR; i++) {
                 //if (i == pkmnR) {//This checks to see if we are on the right pokemon
                     /*getline(input, content, ',');
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
                     spd = stoi(content);*/
                     //This will sort it for every other one
                     //team1[c] = Pokemon(pkmnName, atk, def, hp, spAtk, spDef, spd); //Swapped constructor functions
                     team1[c] = Pokemon(pkmnR);
                     /*for (int j = 0; j <= 19; j++) {
                         getline(input, content, ',');
                         potentialMoves[j] = content;
                          for (int a = 0; a <= 546; a++) {
                              if (tMoves[a] == potentialMoves[j]) {
                                  possibleMoves[j] = potentialMoves[j];
                                  std::cout << possibleMoves[j];
                               }
                        }

                     }*/ //It's kinda funny to have one line of code buried in a mess of comments

                     //input.close();
                 //}
                 /*else {
                     getline(input, content); //This moves the cursor one line down while skipping the rest of the commas
                     if (input.eof()) {
                         std::cout << "Pokemon not found" << std::endl;
                         input.close();
                         exit(3);
                     }
                 }*/
             //}
         //}
     }

     for (int c = 0; c < teamSize; c++) { //Makes team 2 by copying the process of team 1, may or may not be duplicate mons
         pkmnR = (rand() % 387) + 1;
         if (pkmnR == 1) {
             pkmnR = 2; //This makes sure that we don't make a pokemon with the header line
             //Wasn't necessary before because the other csv didn't have one
         }
         //std::cout << pkmnR; //Debug
         //std::cout << pkmnR<< " 2\n"; //Debug
         team2[c] = Pokemon(pkmnR);
         //std::cout << team2[c].getName(); //Debug
     }
 }
 void displayPokemonAvailable(Pokemon*team2) {
     std::ifstream input;
     input.open("PokemonGens1-3.csv");
     std::string content;
     int count = 0;
     if (input.is_open()) {
         while (getline(input, content)) {
             count++;
             if (count == 0)
                 std::cout << std::endl;
             else if (count == 387)
                 break;
             else {
                 getline(input, content, ',');
                 std::cout << count << "." << content << std::endl;
                 getline(input, content, ',');
             }
         }
     }
     else if (!input.is_open())
         std::cout << "Could not find file specified";
     input.close();
 }
 
 void displayMenu(Pokemon *team1,Pokemon *team2,/*Pokemon::Moves* moveSet,*/ int teamSize, std::string* tMoves) {
     system("CLS");
     std::string enter;
     int choice;
     std::cout << "Welcome to the Pokoman™ Battler V0.6.0 " << std::endl << "Please Choose an option:" << std::endl;
     std::cout << "[1] Start Battle(WIP)\n" << "[2]Generate Pokemon teams(WIP) and moves \n" << "[3]View Teams \n" << "[4]View all Pokemon \n" << "[5]View all Moves possible \n" << "[0]Exit \n";
     std::cin >> choice;
     switch (choice) {
     case 1:
         if (team1[0].getName() == "" || team2[0].getName() == "") {
             std::cout << "Generate your teams first\n" << "Press enter to continue...";
             std::cin.get();
             std::cin.ignore();
         }
         else
            startBattle(team1, team2,/* moveSet,*/ teamSize);
         break;
     case 2:
         if (team1[0].getName() != "" || team2[0].getName() != "") {
             std::cout << "Teams already generated" <<std::endl << "Press enter to continue...";
             std::cin.get();
             std::cin.ignore(); //Both of these are needed for this to work
         }
         else {
             generateTeams(team1, team2,/*moveSet,*/ teamSize, tMoves);
             std::cout << "Teams Generated successfully!" << std::endl << "Press Enter to Continue...";
             std::cin.get();
             std::cin.ignore();
         }
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
         displayPokemonAvailable(team2);
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
         winscreen();

         //All deletes need to go here
         delete[] team1;
         delete[] team2;
         delete[] tMoves;
         exit(0);
         break;
     default:
         std::cout << "invalid input" <<std::endl << "Press enter to continue";
     }
     displayMenu(team1, team2,/*moveSet,*/ teamSize, tMoves); //Calls itself for an infinite loop
 }
    int main() {
    //std::string name = "Squirtle";
    //Pokemon myMon(name);
    //myMon.printMoveset(); //Debug
        int teamSize; //NOTE: Change the maximum team size when we get more pokemon
     
        std::cout << "How many pokemon on each team?(Max: 6)";
        std::cin >> teamSize;
        if (teamSize > 6 || teamSize <= 0) {
            std::cout << "Nice try. The size of each team is now 6." << std::endl << "Press Enter to Continue...";
            std::cin.get();
            std::cin.ignore();
            teamSize = 6;
        }
       Pokemon* team1 = new Pokemon[teamSize];
       Pokemon* team2 = new Pokemon[teamSize];
       //Pokemon::Moves* moveSet= new Pokemon::Moves[4];
       //Creates 4 moves per class
       std::string* tMoves = new std::string[547]; //Creates an array for moves of size 547
       std::ifstream moves;
       moves.open("PokemonMoves.csv");
       std::string content;
       if (moves.is_open()) {
           for (int i = 0; i < 547; i++) { //Stores all move names sequentially in an array
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
    //delete[] moveSet;
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