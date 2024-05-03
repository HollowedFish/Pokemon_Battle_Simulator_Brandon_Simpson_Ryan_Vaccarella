// Pokemon Battler.cpp : This file contains the 'main' function. Program execution begins and ends here.
//Made by Brandon Simpson and Ryan Vaccarella
#include <iostream>
#include <string> //Funny thing, this line wasn't here until WELL after it should have been (5/3/2024)
#include "Pokemon_Team.h"
#include "Items.h"
#include <cstdlib>
#include <time.h>
#include <iterator>
#include <vector>
//This works...Need to find better way hmmm
//Need to use a vector to store pokemon or a pointerasdf
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
    std::cin.ignore();
    exit(1);

}
float SameTypeAttackBonus (Pokemon * Attacker, int u_choice) {
    if (Attacker->getType1() == Attacker->moveSet[u_choice-1].gettypeMoves()) {
        return 1.5;
    }
    else if (Attacker->getType2() == Attacker->moveSet[u_choice-1].gettypeMoves()) {
        return 1.5;
    }
    else
    return 1;
}
float WeaknessorResistance(Pokemon* Attacker, Pokemon* Defender, int u_choice) {
    std::string attackingMoveType = Attacker->moveSet[u_choice - 1].gettypeMoves();
    std::string defendingType[2] = { Defender->getType1(),Defender->getType2() };
    float effectiveness = 1;
    int count = 1;
    if (defendingType[1] != "") {
        count = 2;
    }
    for (int i = 0; i < count; i++) {
        if (attackingMoveType == "Normal") {
            if (defendingType[i] == "Rock" || defendingType[i] == "Steel"){
                effectiveness /= 2;
            }
            else if (defendingType[i] == "Ghost" || defendingType[i + 1] == "Ghost") {
                effectiveness = 0;
                return effectiveness;
            }

        }
        else if (attackingMoveType == "Psychic") {
         
            if (defendingType[i] == "Fighting" || defendingType[i] == "Poison") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Psychic" || defendingType[i] == "Steel") {
                effectiveness /= 2;
            }
            else if (defendingType[i] == "Dark" || defendingType[i + 1] == "Dark") {
                effectiveness = 0;
                return effectiveness;
            }
        }
        else if (attackingMoveType == "Grass") {
            if (defendingType[i] == "Water" || defendingType[i] == "Ground" || defendingType[i] == "Rock") {
                effectiveness *= 2;
            }
            else if (defendingType[i]=="Fire"|| defendingType[i]=="Grass"||defendingType[i]=="Poison"||defendingType[i]=="Flying"||defendingType[i]=="Bug"||defendingType[i]=="Dragon"||defendingType[i]=="Steel") {
                effectiveness /= 2;
            }
        }
        else if (attackingMoveType == "Fighting") {
            if (defendingType[i] == "Normal" || defendingType[i] == "Ice" || defendingType[i] == "Rock" || defendingType[i] == "Dark" || defendingType[i] == "Steel") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Poison" || defendingType[i] == "Flying" || defendingType[i] == "Psychic" || defendingType[i] == "Bug" || defendingType[i] == "Fairy") {
                effectiveness /= 2;
            }
            else if (defendingType[i] == "Ghost" || defendingType[i + 1] == "Ghost") {
                effectiveness = 0;
                return effectiveness;
            }
        }
        else if (attackingMoveType == "Water") {
            if (defendingType[i] == "Fire" || defendingType[i] == "Ground" || defendingType[i] == "Rock") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Water" || defendingType[i] == "Grass" || defendingType[i] == "Dragon") {
                effectiveness /= 2;
            }
        }
        else if (attackingMoveType == "Dark") {
            if (defendingType[i] == "Psychic" || defendingType[i] == "Ghost") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Fighting" || defendingType[i] == "Dark" || defendingType[i] == "Fairy") {
                effectiveness /= 2;
            }
        }
        else if (attackingMoveType == "Electric") {  
            if (defendingType[i] == "Water" || defendingType[i] == "Flying") {
                effectiveness *=2;
            }
            else if (defendingType[i] == "Electric" || defendingType[i] == "Grass" || defendingType[i] == "Dragon") {
                effectiveness /=2;
            }
            else if (defendingType[i] == "Ground" || defendingType[i + 1] == "Ground") {
                effectiveness = 0;
                return 0;
            }
        }
        else if (attackingMoveType == "Fire") {
            if (defendingType[i] == "Grass" || defendingType[i] == "Ice" || defendingType[i] == "Bug" || defendingType[i] == "Steel") {
                effectiveness *=2;
            }
            else if (defendingType[i] == "Fire" || defendingType[i] == "Water" || defendingType[i] == "Rock" || defendingType[i] == "Dragon") {
                effectiveness /=2;
            }
        }
        else if (attackingMoveType == "Steel") {
            if (defendingType[i] == "Ice" || defendingType[i] == "Rock" || defendingType[i] == "Fairy") {
                effectiveness *=2;
            }
            else if (defendingType[i] == "Fire" || defendingType[i] == "Water" || defendingType[i] == "Electric" || defendingType[i] == "Steel") {
                effectiveness /=2;
            }
        }
        else if (attackingMoveType == "Poison") {
            if (defendingType[i] == "Grass" || defendingType[i] == "Fairy") {
                effectiveness *=2;
            }
            else if (defendingType[i] == "Poison" || defendingType[i] == "Ground" || defendingType[i] == "Rock" || defendingType[i] == "Ghost") {
                effectiveness /=2;
            }
            else if (defendingType[i] == "Steel" || defendingType[i + 1] == "Steel") {
                effectiveness = 0;
                return 0;
            }
        }
        else if (attackingMoveType == "Bug") {
            if (defendingType[i] == "Grass" || defendingType[i] == "Psychic" ||defendingType[i]=="Dark")  {
                effectiveness *=2;
            }
            else if (defendingType[i] == "Fire" || defendingType[i] == "Fighting" || defendingType[i] == "Poison" || defendingType[i] == "Flying" || defendingType[i] == "Ghost" || defendingType[i] == "Steel" || defendingType[i] == "Fairy") {
                effectiveness /=2;
            }
        }
        else if (attackingMoveType == "Fairy") {
            if (defendingType[i] == "Fighting" || defendingType[i] == "Dragon" || defendingType[i] == "Dark") {
            effectiveness *=2;
            }
            else if (defendingType[i] == "Fire" || defendingType[i] == "Poison" || defendingType[i] == "Steel") {
                effectiveness /=2;
            }
        }
        else if (attackingMoveType == "Ghost") {
            if (defendingType[i] == "Psychic" || defendingType[i] == "Ghost") {
            effectiveness *= 2;
            }
            else if (defendingType[i] == "Dark") {
                effectiveness /= 2;
            }
            else if (defendingType[i] == "Normal" || defendingType[i + 1] == "Normal") {
              effectiveness = 0;
              return 0;
            }
        }
        else if (attackingMoveType == "Ice") {
            if (defendingType[i] == "Grass" || defendingType[i] == "Ground" || defendingType[i] == "Flying" || defendingType[i] == "Dragon") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Fire" || defendingType[i] == "Water" || defendingType[i] == "Ice" || defendingType[i] == "Steel") {
                effectiveness /= 2;
            }
        }
        else if (attackingMoveType == "Dragon") {
            if (defendingType[i] == "Dragon") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Steel") {
                effectiveness /= 2;
            }
            else if (defendingType[i] == "Fairy" || defendingType[i + 1] == "Fairy") {
                effectiveness = 0;
                return effectiveness;
            }
        }
        else if (attackingMoveType == "Ground") {
            if (defendingType[i] == "Fire" || defendingType[i] == "Electric" || defendingType[i] == "Poison" || defendingType[i] == "Rock" || defendingType[i] == "Steel") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Grass" || defendingType[i] == "Bug") {
                effectiveness /= 2;
            }
            else if (defendingType[i] == "Flying" || defendingType[i + 1] == "Flying") {
                effectiveness = 0;
                return effectiveness;
            }
        }
        else if (attackingMoveType == "Flying") {
            if (defendingType[i] == "Grass" || defendingType[i] == "Fighting" || defendingType[i] == "Bug") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Electric" || defendingType[i] == "Rock" || defendingType[i] == "Steel") {
                effectiveness /= 2;
            }
        }
        else if (attackingMoveType == "Rock") {
            if (defendingType[i] == "Fire" || defendingType[i] == "Ice" || defendingType[i] == "Flying" || defendingType[i] == "Bug") {
                effectiveness *= 2;
            }
            else if (defendingType[i] == "Fighting" || defendingType[i] == "Ground" || defendingType[i] == "Steel") {
                effectiveness /= 2;
            }
        }
    }
    return effectiveness;
}
void damageCalculator(Pokemon* Attacker,Pokemon*Defender,int u_choice) {
    //std::cout << Attacker->moveSet[u_choice].getpowerMoves();//Debug
    system("CLS");
    std::cout << Attacker->getName()<<" Used "<<Attacker->moveSet[u_choice - 1].getnameMoves();
    std::cin.ignore();
    std::cin.get();
    system("CLS");
    int movedmg = Attacker->moveSet[u_choice - 1].getpowerMoves();
    std::string categoryAtk = Attacker->moveSet[u_choice - 1].getcategoryMoves();
    int aDmg;
    int dDef;
    int damage;
    int randomNumber = rand() % 15+85+rand()%2;
    if (categoryAtk == "Physical") {
        aDmg = Attacker->getAtk();
        dDef = Defender->getDef();
    }
    else {
        aDmg = Attacker->getSpAtk();
        dDef = Defender->getDef();
    }
    // Actual damage calculator = ((((2 * Level / 5 + 2) * AttackStat * AttackPower / DefenseStat) / 50) + 2) * STAB * Weakness / Resistance * RandomNumber / 100
    damage = (((((2 * 100 / 7) * aDmg * movedmg / dDef) / 50) + 2) * SameTypeAttackBonus(Attacker,u_choice)*WeaknessorResistance(Attacker,Defender,u_choice)*randomNumber) / 100;
    std::cout << Defender->getName() << " Took " << damage<<" damage";
    std::cin.ignore();
    std::cin.get();
    Defender->setHp(Defender->getHp() - damage);
}
void swapPokemon() {
    std::cout << "You don't have anymore Pokemon!" << std::endl;
    std::cin.ignore();
}
bool bag(Pokemon* team, item* itemBag, bool bagSuccess,int teamSize) {
    int emptyBagSlots = 0;
    int choice1 = 0;
    int choice2 = 0;
    std::string choiceS;
    for (int i = 0; i < 7; i++) { //This assumes that there are 7 bag slots, CHANGE THIS IF WE ADD MORE ITEMS
        if (itemBag[i].getQuantity() == 0) { emptyBagSlots++; }
        //It actually doens't matter that this treats them all like base items, because quantity is inherent to item
        //I will need to do some dynamic cast black magic later though
    }
    if (emptyBagSlots == 7) {
        std::cout << "You are out of items!" << std::endl;
        std::cout << "Press enter to go back to the menu...";
        std::cin.ignore();
        return false;
    }
    std::cout << "Choose which item you want to use:" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << i+1 << ". " << itemBag[i].getName() << " X " << itemBag[i].getQuantity() << std::endl;
        std::cout << "  -" << itemBag[i].getDescription() << std::endl;
    }
    std::cout << "0. Exit Menu" <<std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cin >> choice1;
    switch (choice1){//This is an astoudingly terrible solution, not scalable in the slightest, but whatever
    case 0:
        return false;
        break;
    case 1://potions
    case 2:
    case 3:
        std::cout << "Choose which pokemon you want to use this item on:" << std::endl;
        for (int i = 0; i < teamSize; i++) {//Had to import teamSize just for this
            std::cout << i+1 << ". " << team[i].getName() << std::endl;
        }
        std::cout << "--------------------------\n";
        std::cin >> choice2;
        if (potion* I = dynamic_cast<potion*>(&itemBag[choice1 - 1])) {//Yikes
            I->use(&team[choice2 - 1]); //Dear god this is cursed
        }
        bagSuccess = true;
        std::cin.ignore();
        break;
    case 4://ethers
    case 5:
        std::cout << "Choose which pokemon you want to use this item on:";
        for (int i = 0; i < teamSize; i++) {//Had to import teamSize just for this
            std::cout << i << ". " << team[i].getName();
        }
        std::cout << "--------------------------\n";
        std::cin >> choice2;
        if (ether* I = dynamic_cast<ether*>(&itemBag[choice1 - 1])) {//Yikes
            I->use(&team[choice2 - 1]); //Dear god this is cursed
        }
        bagSuccess = true;
        std::cin.ignore();
        break;
    case 6://revives
    case 7:
        std::cout << "Choose which pokemon you want to use this item on:";
        for (int i = 0; i < teamSize; i++) {//Had to import teamSize just for this
            std::cout << i << ". " << team[i].getName();
        }
        std::cout << "--------------------------\n";
        std::cin >> choice2;
        if (revive* I = dynamic_cast<revive*>(&itemBag[choice1 - 1])) {//Yikes
            I->use(&team[choice2 - 1]); //Dear god this is cursed
        }
        bagSuccess = true;
        std::cin.ignore();
        break;
    default:
        std::cout << "Invalid choice, try again.";
        bool storage = bag(team, itemBag, bagSuccess, teamSize);
        break;
    }
    return bagSuccess;
}
void fightMoves(Pokemon*Attacker,Pokemon*Defender){
    system("CLS");
    int u_choice;
    int powerPointsTotal[4];
    int powerPointsLeft[4];
    int bug = -1;
    while (bug == -1) {
        std::cout << "What would you like " << Attacker->getName() << " To attack with?" << std::endl;
        for (int i = 0; i <= 3; i++) {
            powerPointsLeft[i] = Attacker->moveSet[i].getpowerPointMoves();
            powerPointsTotal[i] = Attacker->moveSet[i].getpowerPointMovesTotal();
            std::cout << i + 1 << ". " << Attacker->moveSet[i].getnameMoves() << " PP " <<powerPointsLeft[i] <<" / "<<powerPointsTotal[i]<< " Type "<<Attacker->moveSet[i].gettypeMoves()<<std::endl;
        }
        std::cin >> u_choice;
        switch (u_choice) {
        case 1:
            if (powerPointsLeft[0] == 0) {
                std::cout << " No power Points left!!";
                bug--;
            }
            else {
                Attacker->moveSet[0].setpowerPointsMoves(powerPointsLeft[0] - 1);
                damageCalculator(Attacker, Defender, u_choice);
            }
        break;
        case 2:
            if (powerPointsLeft[1] == 0) {
                std::cout << " No power Points left!!";
                bug--;
            }
            else {
                Attacker->moveSet[1].setpowerPointsMoves(powerPointsLeft[1] - 1); 
                damageCalculator(Attacker, Defender, u_choice);
            }
        break;
        case 3:
            if (powerPointsLeft[2] == 0) {
                std::cout << " No power Points left!!";
                bug--;
            }
            else {
                Attacker->moveSet[2].setpowerPointsMoves(powerPointsLeft[2] - 1);
                damageCalculator(Attacker, Defender, u_choice);
            }
        break;
        case 4:
            if (powerPointsLeft[3] == 0) {
                std::cout << " No power Points left!!";
                bug--;
            }
            else {
                Attacker->moveSet[3].setpowerPointsMoves(powerPointsLeft[3] - 1);
                damageCalculator(Attacker, Defender, u_choice);
            }
        break;
        default:
            std::cout << "Invalid input press enter to repick" << std::endl;
            std::cin.get();
            std::cin.ignore();
            bug--;
        }
       
        bug++;
    }

}
void battleMenu(Pokemon*attackingTeam,Pokemon*Attacker,item*itemBag,Pokemon*Defender,std::string playerName,int teamSize) {
    system("CLS");
    bool bagSuccess = false;
    int choice = 0;
    int u_choice = 0;
    while (choice == 0) {
        std::cout << Attacker->getName() << " Has " << Attacker->getHp() << " / " << Attacker->getMaxHP()<<std::endl;
        std::cout << "1.Fight" << std::endl << "2.Bag(WIP)" << std::endl << "3.Swap current Pokemon(WIP)" << std::endl <<"4.Run "<<std::endl<<"Enter number here : ";
        std::cin >> u_choice;
        switch (u_choice) {
        case 1:
            //fight
            fightMoves(Attacker,Defender);
            break;
        case 2:
            //bag
            if (bag(attackingTeam, itemBag, bagSuccess,teamSize) == false) {
                choice--;
            }
            break;
        case 3:
            swapPokemon();
            break;
        case 4:
            //run
            std::cout << "You can't run from a pokemon battle!( Press enter to continue):";
            std::cin.ignore();
            std::cin.get();
            choice--;
            break;
        default:
            std::cout << "Invalid input try again";
            std::cin.ignore();
            std::cin.get();
            choice--;
        }
        system("CLS");
        choice++;
    }
}

bool checkFaint(Pokemon* Active,std::string  trainer,std::string trainer_2) {
     int hp= Active->getHp();
    bool ko = false;
    if (hp<= 0) {
        
        std::cout << Active->getName() << " fainted!";
        std::cout << trainer_2 << " You are out of Pokemon" << std::endl;
        std::cout << trainer << " You Win!"<<std::endl;
        winscreen();
    }
    return ko;
}
void viewMoves() {
    system("CLS");
    std::string content;
    std::ifstream output;
    std::vector < std::string> moves = {};
    
    output.open("PokemonMoves.csv");
    if (output.is_open()) {
        /*for (int i = 0; i <= 546; i++) {
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
        }*/
        while (std::getline(output, content, ',')) {
            moves.push_back(content);
            std::getline(output, content);
        }
        std::vector<std::string> ::iterator it = moves.begin();
       for (int i = 1; it < moves.end(); it++, i++) {
            std::cout << i << ". " << *it << std::endl;
            if (i %100 ==0) {
                if (i == 100) {
                    std::cin.ignore();
               }
                std::cout << "Please press enter to continue";
                std::cin.get();
                system("CLS");
            }
        }
        std::cout << "Press enter to continue";
        while (!moves.empty()) {
            moves.pop_back();
        }
        it = moves.begin();
    }
    else if (!output.is_open()) {
        std::cout << "Operation failed" << std::endl << "Press enter to continue";
        std::cin.get();
        std::cin.ignore();
    }
    output.close();
}
void startBattle(Pokemon* team1,item* bag1, Pokemon* team2,item* bag2, int teamSize) {
    Pokemon* t1Active; //Active pokemon pointers
    Pokemon* t2Active;
    std::string p1;//Player names
    std::string p2;
    //int ActiveMonNum1;
    //int ActiveMonNum2;//Storage so you can actually change the stored pokemon's values (for hp and KO)
    //Stolen for HP values lol
    system("CLS"); //Clears screen
    std::cout << "Enter the name for player 1:" << std::endl;
    std::cin.ignore(); //This needs to be here otherwise it skips
    std::getline(std::cin, p1); //<--I have no idea what is going on here, I will just continue coding, and I will hope you know
    std::cout << "Enter the name for player 2:" << std::endl;
    std::getline(std::cin, p2);
    system("CLS");
    std::cout << "Trainer " << p1 << " challenges Trainer " << p2 << " to a Battle!" << std::endl;
    std::cout << "Press Enter to continue...";
    std::cin.get();
    std::cin.ignore();
    //1st team initial pokemon choosing
    t1Active = &team1[0];
    t2Active = &team2[0];

/*std::cout << "Starting active pokemon are: " << T1Active.getName() << " " << T2Active.getName(); //Debug
std::cin.get(); //Debug
std::cin.ignore();//Debug */

//Actual battle loop time, here we go!
    bool p1Win = false;
    bool p2Win = false;
    int turnNumP1 = 0;
    int turnNumP2 = 0;
    int count1 = 1;
    int count2 = 1;
    std::string typeAtk1, typeAtk2;
    while (p1Win == false && p2Win == false) {

        if (turnNumP1 <= turnNumP2) {
            //Like the snakes and ladders game from last year

            if (checkFaint(t1Active,p1,p2)){
                std::cout << " is fainted" << std::endl;
                std::cout << "Swapping Pokemon" << std::endl;
                count1++;
                if (count1 > teamSize) {
                    std::cout << "YOU'RE OUT OF POKEMON " << p1;
                    std::cout << "You Win!\n" << p2;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore();
                    winscreen();

                }
                else if (count1 <= teamSize) {
                    t1Active = &team1[count1];
                    //ActiveMonNum1 = t1Active->getHp();
                }
            }
            else
            {
                battleMenu(team1,t1Active, bag1, t2Active, p1,teamSize);
                checkFaint(t1Active, p1, p2);
            }
            turnNumP1++;
            int choice = 0;
            system("CLS");
        }
        if (turnNumP1 > turnNumP2) {
            turnNumP2++;
            int choice = 0;
            if (checkFaint(t2Active,p2,p1)) {
                std::cout << " is fainted" << std::endl;
                std::cout << "sending out next pokemon";
                std::cout << " is fainted" << std::endl;
                std::cout << "Swapping Pokemon" << std::endl;
                count2++;
                if (count2 > teamSize) {
                    std::cout << "NO POKEMON LEFT" << p2;
                    std::cout << "You Win!" << p1 << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore();
                    winscreen();
                }
                else if (count2 <= teamSize) {
                    t2Active = &team2[count2];
                    //ActiveMonNum2 = t2Active->getHp();
                }
            }
            else
            {
                battleMenu(team2,t2Active,bag2, t1Active, p2,teamSize);
                checkFaint(t1Active, p2, p1);
            }

        }
    }
}
 void generateTeams(Pokemon* team1, Pokemon* team2, int teamSize) {
     srand(time(NULL));
     std::string pkmnName;
     int pkmnR;
     std::string content;
     for (int c = 0; c < teamSize; c++) {
         pkmnR = (rand() % 387) + 1;
         if (pkmnR == 1) {
             pkmnR = 2; //This makes sure that we don't make a pokemon with the header line
             //Wasn't necessary before because the other csv didn't have one
         }
         team1[c] = Pokemon(pkmnR);
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
 void displayPokemonAvailable() {
     std::ifstream output;
     output.open("PokemonGens1-3.csv");
     std::string content;
     if (output.is_open()) {
         std::vector<std::string> pokemonAvailable = {};
         while (std::getline(output, content,',')) {
             pokemonAvailable.push_back(content);
             std::getline(output, content);
             }
         std::vector<std::string>::iterator it = pokemonAvailable.begin();
         for (int i = 1; it < pokemonAvailable.end(); i++, it++) {
             std::cout << i << ". " << *it << std::endl;
             if (i % 100 == 0) {
                 if (i == 100) {
                     std::cin.ignore();
                 }
                 std::cout << "Press enter to continue";
                 std::cin.get();
                 system("CLS");
             }
         }
         std::cout << "Press enter to continue";
         while (!pokemonAvailable.empty()) {
             pokemonAvailable.pop_back();
         }
         it = pokemonAvailable.begin();
     }
     else if (!output.is_open()) {
         std::cout << "Could not find file specified";
     }
     output.close();
 }
 
 void displayMenu(Pokemon *team1,item* bag1,Pokemon *team2,item* bag2, int teamSize) {
     system("CLS");
     std::string enter;
     int choice;
     std::cout << "Welcome to the Pokoman™ Battler V0.6.0 " << std::endl << "Please Choose an option:" << std::endl;
     std::cout << "[1] Start Battle\n" << "[2]Generate Pokemon teams and moves \n" << "[3]View Teams \n" << "[4]View all Pokemon \n" << "[5]View all Moves possible \n" << "[0]Exit \n";
     std::cin >> choice;

     switch (choice) {
     case 1:
         if (team1[0].getName() == "" || team2[0].getName() == "") {
             std::cout << "Generate your teams first\n" << "Press enter to continue...";
             std::cin.get();
             std::cin.ignore();
         }
         else
            startBattle(team1,bag1, team2,bag2, teamSize);
         break;
     case 2:
         if (team1[0].getName() != "" || team2[0].getName() != "") {
             std::cout << "Teams already generated" <<std::endl << "Press enter to continue...";
             std::cin.get();
             std::cin.ignore(); //Both of these are needed for this to work
         }
         else {
             generateTeams(team1, team2, teamSize);
             std::cout << "Teams Generated successfully!" << std::endl << "Press Enter to Continue...";
             std::cin.get();
             std::cin.ignore();
         }
         break;
     case 3:
         if (team1[0].getName() != "" || team2[0].getName() != "") {
             std::cout << "On team 1 we have..." << std::endl;
             for (int i = 0; i < teamSize; i++) {
                 std::cout << i + 1 << ". " << team1[i].getName()<<" They are " << team1[i].getType1() << " " << team1[i].getType2()<<" type(s)";
                 std::cout<<std::endl;
             }
             std::cout << "On team 2 we have.." << std::endl;
             for (int i = 0; i < teamSize; i++) {
                 std::cout << i + 1 << ". " << team2[i].getName() << " They are " << team2[i].getType1() << " " << team2[i].getType2() << " type(s)";
                 std::cout << std::endl;
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
         displayPokemonAvailable();
         std::cin.get();
         std::cin.ignore();
         break;
     case 5:
         viewMoves();
         //std::cin.get(); //Maybe don't need this this one time?
         std::cin.ignore();
         break;
     case 0:
         system("CLS");
         winscreen();
         delete[] team1;
         delete[] bag1;
         delete[] team2;
         delete[] bag2;
         exit(0);
         break;
     default:
         std::cout << "invalid input" <<std::endl << "Press enter to continue";
     }
     displayMenu(team1,bag1, team2,bag2, teamSize); //Calls itself for an infinite loop
 }
    int main() {
        int teamSize;
     
        std::cout << "How many pokemon on each team?(Max: 6)";
        std::cin >> teamSize;
        if (teamSize > 6 || teamSize <= 0) {
            std::cout << "Nice try. The size of each team is now 6." << std::endl << "Press Enter to Continue...";
            std::cin.get();
            std::cin.ignore();
            teamSize = 6;
        }
       Pokemon* team1 = new Pokemon[teamSize];
       item* bag1 = new item[7]{//I chose not to include regular potions, because on level 100's it wouldn't do anything bu waste a move
           potion("Super Potion","Heals pokemon by 50 HP.",5,50),
           potion("Hyper Potion","Heals pokemon by 200 HP.",2,200),
           potion("Max Potion", "Heals one poekmon to full hp",2,9001), //ITS OVER 9000
           ether("Ether","Restores 10 PP to one move.",5,10),
           ether("Max Ether","Restores all PP to one move.",2,100),
           revive("Revive","Removes faint from one pokemon and restores them to 50% hp.",2,0.5),
           revive("Max revive","Removes faint from one pokemon and restores them to 100% HP",1,1)
       };
       Pokemon* team2 = new Pokemon[teamSize];
       item* bag2 = new item[7]{//I chose not to include regular potions, because on level 100's it wouldn't do anything bu waste a move
           potion("Super Potion","Heals pokemon by 50 HP.",5,50),
           potion("Hyper Potion","Heals pokemon by 200 HP.",2,200),
           potion("Max Potion", "Heals one poekmon to full hp",2,9001), //ITS OVER 9000
           ether("Ether","Restores 10 PP to one move.",5,10),
           ether("Max Ether","Restores all PP to one move.",2,100),
           revive("Revive","Removes faint from one pokemon and restores them to 50% hp.",2,0.5),
           revive("Max revive","Removes faint from one pokemon and restores them to 100% HP",1,1) 
       }; //I chose to hardcode the bags because it was way easier than randomizing it
        displayMenu(team1,bag1,team2,bag2,teamSize); //Start game loop
    //The below will never actually run
    delete[] team1;
    delete[] team2;
    //delete[] moveSet;
}