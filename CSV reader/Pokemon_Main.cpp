// CSV reader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pokemon_Team.h"
#include <cstdlib>
#include <time.h>
#include <vector>
//This works...Need to find better way
void generateRandom() {
    std::string pkmnName = "POP";
    int atk = 0;
    int def = 0;
    int spAtk = 0;
    int spDef = 0;
    int hp = 0;
    int spd = 0;
    std::string possibleMoves[20];
    std::ifstream input;
    srand(time(NULL));
    int pkmnR = rand() % 7;
    if (pkmnR == 0) {
        pkmnR = 1;
    }
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
                getline(input, content, '\r');
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
            exit(3);
           }
         }
        }
    }
}
    int main() {
    //std::string name = "Squirtle";
    //Pokemon myMon(name);
    //myMon.printMoveset(); //Debug
    int choice;
    while (true) {
        system("CLS");
        generateRandom();
        std::cout << "Welcome to the Pokoman™ Battler V0.5.1 " << std::endl << "Please Choose an option:" << std::endl;
        std::cout << "[1] Start Battle(WIP)\n" << "[2]Set Up Teams(WIP) \n" << "[3]View Teams(WIP) \n" << "[4]TBD \n" << "[5]TBD \n" << "[0]Exit \n";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "This function is not impemented yet";
            break;
        case 2:
            std::cout << "This function is not impemented yet";
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
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
