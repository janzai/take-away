#ifndef MESA_CISC187_PROJECT01_COMPUTER_PLAYER_H
#define MESA_CISC187_PROJECT01_COMPUTER_PLAYER_H

#include <vector>
#include <cstdint>
// Name : Jamie Anzai
// ID : 5550091018

// Function returns the amount of stones the computer player will remove 
int how_many();
// Function decides returns the heap to take from 
int choose_heap();
// Function calculates the nimsum (who wins) and uses binary XOR operator to find the winning play 
void evaluate(std::vector<uint32_t>); 





#endif
