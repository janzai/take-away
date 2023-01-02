#include "computer_player.h"
#include <vector>
#include <cstdint>

// Name : Jamie Anzai
// ID : 5550091018
namespace {
int chosenHeap = 0;
int stones = 0;
}

void evaluate(std::vector<uint32_t> p){   
  int nimSum = p[0];
  for(int i = 1; i < p.size();i++){
    nimSum = nimSum ^ p[i];
  }

    if(nimSum != 0){
      for(int i = 0;i < p.size();i++){
        
        if((p[i] ^ nimSum) < p[i]){
          chosenHeap = i;
          stones = p[i]-(p[i]^nimSum);
        
        }
      }
    }else{
      chosenHeap = 0;
      stones = 1;
    }

}


int how_many(){
  return stones;
}
int choose_heap(){
  return chosenHeap;
}

