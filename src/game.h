#ifndef MESA_CISC187_PROJECT01_GAME_H
#define MESA_CISC187_PROJECT01_GAME_H

#include <string>
#include <vector>
#include <cstdint>
//Name : Jamie Anzai
//ID : 5550091018
  
// Function gets string from user  
std::string get_entry(const std::string);
// Function gets a value from user 
uint32_t get_value(const std::string prompt, int min, int max);
// Function prints the heap and stones 
void printEverything(const std::vector<uint32_t>); 
// Function removes stones and heap(if no stones) from the vector 
void removeStones(std::vector<uint32_t> &p , int, int);
// Function creates the vector(sets the heaps and stones) 
void createGame(std::vector<uint32_t> &p, int ,int);


#endif
