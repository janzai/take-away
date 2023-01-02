#include <game.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
//Name : Jamie Anzai
//ID : 5550091018

std::string get_entry(const std::string prompt){
  
  std::string x;
  std::string y;
  std::cout << prompt;
  
  std::cin >> x;

  if(x.empty() == true){
    std::cout << prompt;
    std::cin >> x; 
  }
  y = x.substr(0,x.find(" "));
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return y;

}

uint32_t get_value(const std::string prompt, int min, int max){

  uint32_t x;

  std::cout << prompt;

  std::cin >> x;
  while(std::cin.fail()){
    std::cout << "ERROR - PLEASE ENTER VALID ENTRY: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> x;
      }
  while(x < min || x > max){
    std::cout << "Please enter a valid entry\n";
    std::cin >> x;
  }
  
  return x;
}

void printEverything(const std::vector<uint32_t> p){
  for(int i = 0; i < p.size(); i++){
      std::cout << "Heap " << i+1 << "[" << p[i] << "]: ";
        for(int j = 0; j < p[i]; j++){
          std::cout << "*";
        }
        std::cout << "\n";
  }
  std::cout << "\n";

}
void removeStones(std::vector<uint32_t> &p , int heap , int stones){
    p[heap] = p[heap] - stones;
    if(p[heap] == 0){
      p.erase(p.begin() + heap);
    }

}
void createGame(std::vector<uint32_t> &p , int heap, int stones){
  srand((int) time(nullptr)); 
  if(stones == 0 && heap == 0){
    int max = (rand() % 10) + 1;
    for(int i = 0; i < max; i++){
      p.push_back((rand() % 20) + 1);
    }
  }
  else if(stones != 0 && heap == 0){
    int max = (rand() % 10) + 1;
      for(int i = 0; i < max; i++){
        p.push_back(stones);
      }
  }
  else if(stones == 0 && heap != 0){
    for(int i = 0; i < heap; i++){
      p.push_back((rand() % 20) + 1);
    }
  }
  else{
      for(int i = 0; i < heap; i++){
        p.push_back(stones);
      }
    }
 
}
