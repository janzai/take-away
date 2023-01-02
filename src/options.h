#ifndef MESA_CISC187_PROJECT01_CHANGE_H
#define MESA_CISC187_PROJECT01_CHANGE_H

#include <string>


// Namie : Jamie Anzai
// ID : 5550091018



namespace mesa{
  
  struct option{

  bool valid = true;
  bool has_ai = false;
  uint32_t piles = 0;
  uint32_t stones = 0;

  };
  // Functions prints out how to play  
  std::string usage(const char*); 
  std::string help(const char*); 
  // Function returns the options
  option get_options(int, char**);





}





#endif
