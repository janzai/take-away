#include <computer_player.h>
#include <game.h>
#include <options.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdint>
#include <ctime>
#include <cctype>
// Name : Jamie Anzai
// ID : 5550091018

int main(int argc, char*argv[]) {

  std::string firstPlayer = "";
  std::string secondPlayer = "";

  mesa::option options;

  options = mesa::get_options(argc, argv);

  std::vector<uint32_t> p;
   
  std::string playAgain = "";

  do{
      

    createGame(p , options.piles , options.stones);
    if(options.has_ai == false){
    firstPlayer = get_entry("First Player: ");
    secondPlayer = get_entry("Second Player: ");
    std::cout << "Player 1: " << firstPlayer << std::endl;
    std::cout << "Player 2: " << secondPlayer << std::endl;
    }
    if(options.has_ai == true){
      firstPlayer = get_entry("Human player name: ");
      secondPlayer = "ROBOT"; 
    }
    printEverything(p);

    uint32_t heap = 0;
    int counter = 0;
    while(true){
      
      int32_t stones = 0;

      
        std::cout << firstPlayer << "'s turn" << std::endl;

        heap = (get_value("Which heap? ",1, p.size())) - 1;
        stones = get_value("How many stones? ", 0 , p[heap] );

        std::cout << "Player 1: " << firstPlayer << std::endl;
        std::cout << "Player 2: " << secondPlayer << std::endl;

        removeStones(p,heap,stones);


        if(p.size()==0){
          counter = 1; 
          break;
        }
        printEverything(p); 
  

        if(options.has_ai == false){
        std::cout << secondPlayer <<"'s turn" << std::endl;
        heap = get_value("Which heap? " , 1 , p.size()) - 1;
        

        stones = get_value("How many stones? " , 0 , p[heap]);
        
        std::cout << "Player 1: " << firstPlayer << std::endl;
        std::cout << "Player 2: " << secondPlayer << std::endl;
        }
        else if(options.has_ai == true){
          std::cout << secondPlayer << "'s turn" << std::endl;
          evaluate(p);
          heap = choose_heap();
          stones = how_many();
          std::cout << secondPlayer << " removed " << stones << " stones from heap " << heap+1 << ".\n";
        }

        removeStones(p,heap,stones);
        if(p.size()==0){
          break;
        }
        printEverything(p);
    }
      if(counter == 1){
        std::cout << firstPlayer << " wins!!" << std::endl;
      }else {
        std::cout << secondPlayer << " wins!!" << std::endl;
      } 
        playAgain = get_entry("Play another game? [Y/N]");
        while(playAgain != "y" && playAgain != "n" && playAgain != "Y" && playAgain != "N"){
            playAgain = get_entry("Please type either Y or N");
        } 
    }while(playAgain == "Y" || playAgain == "y"); 
  //}
  return 0;
}
