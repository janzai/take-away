#include "options.h"
#include <string>
#include <cstring>
#include <iostream>

// Name : Jamie Anzai
// ID : 5550091018

std::string mesa::usage(const char* y ){

  std::string i = y; 
  std::string x = "Usage: " + i + " [-h] [-c] [-p # piles] [-s # stones]\n";
  return x;
}

std::string mesa::help(const char* x){
  std::string y = mesa::usage(x);

  y += "\nOptions:\n\t -h Show this text.\n\t -c Make player two the computer. Default == false.\n\t -p Manually set the starting number of piles in the game.\n\t -s Manually set the starting number of stones in each pile.\n\n\tMax values for piles: 10\n\tMax values for stones: 20\n\tMin values for piles and stones: 1\n";
  return y;
}


mesa::option mesa::get_options(int x, char** y){

  mesa::option options;
  
  for(int i = 1; i < x; i++){
    
    if(strcmp(y[i] , "-h") == 0){
         std::cout << mesa::help(y[0]);
          exit(0);
     } 
     if(strcmp(y[i] , "-p") == 0){
       i++;
      if(i < x){

      }else {
        options.valid = false;
        std::cout << "Invalid parameter, initializing randomly generated game\n";
        return options;      
      }
      if(std::atoi(y[i]) > 0 && std::atoi(y[i]) < 10){
       options.piles = std::atoi(y[i]);
          options.valid = true;
        }else{
          options.valid = false;
        }
     }
     if(strcmp(y[i] , "-c") == 0){
      options.valid = true;
      options.has_ai = true;
     }
     if(strcmp(y[i] , "-s") == 0){
       i++;
      if(i < x){

      }else{
        options.valid = false;
        std::cout << "Invalid parameter, initializing randomly generated game\n";
        return options;
      }
      if(std::atoi(y[i]) > 0 && std::atoi(y[i]) < 20){
        options.stones = std::atoi(y[i]);
        options.valid = true;
      }else{
        options.valid = false;
      }
     }
  }
  return options;
}


/*
    if(strcmp(y[1] , "-h") == 0){
      std::cout<<mesa::help(y[0]);
      options.valid = false;
    return options;
    exit(0);

  }

  if(strcmp(y[1] , "-p") == 0){
    if(x == 2){
      options.valid = false;
      return options;
    }
    if(std::atoi(y[2]) > 0 && std::atoi(y[2]) < 100){
    options.piles = std::atoi(y[2]);
    options.valid = true;
    }
    else{
      options.valid = false;
    }
    return options;
  
  }

  if(strcmp(y[1] , "-c") == 0){
    options.valid = true;
    options.has_ai = true;
    return options;
  }
  if(strcmp(y[1] , "-s") == 0){
    if(x == 2){
    options.valid = false;
    return options;
    }
    if(std::atoi(y[2]) <= 0 || std::atoi(y[2]) >= 100){
    options.valid = false;
    return options;
      }
        options.stones = std::atoi(y[2]);
        options.valid = true;

    
    
    return options;
  }
  return options;

}
*/
