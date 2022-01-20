#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

void checkLine(std::string& line, std::vector<char> allowedChars); //checks line for illegal characters

class PrimeNumbers{
    private:
        
        //variables
        std::vector<unsigned long> m_primeNumbers;
        
        //functions
        void importPrimeNumbers();
        void convertLine(std::string current_line); //converts String to Integers and adds them to m_primeNumbers
    public:
        //operator
        unsigned long int operator[](unsigned long int index);

        //functions
        void init(); //Starts import of Prime numbers

        //getter
        int size(); //returns amount of prime numbers

};