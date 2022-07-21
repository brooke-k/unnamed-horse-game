/**
 * @file dilutedCoat.hpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 20/Jul/2022
 *
 */

#include "./baseCoat.hpp"
#include <string>
#include <iostream>

class DilutionCoat
{
private:
    BaseCoat base;
    bool *dilutions;
    string coatName;

public:
    
    DilutionCoat(int baseGeneDec, int diluteDec){

	string tempGene = to_string(diluteDec);
	dilutions = new bool[8]
	for(i = 0; i<tempGene.length, i<8; i++){
	    if(tempGene[i] == '0'){
	     	dilutions[i] = false;
	    }else
		dilutions[i] = true;
	    }
	
    }
  
};
