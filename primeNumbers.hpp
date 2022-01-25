#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

class PrimeNumbers{
    private:
    //variables
        std::vector<unsigned long> m_primeNumbers;
        
    //functions
        /**
         * @brief Checks if "primes.dat" exists and calls import and validation of prime numbers.
         */
        void importPrimeNumbers();

        /**
         * @brief Converts given String to int and appends them to the vector m_primeNumbers
         * 
         * @param current_line String to convert
         */
        void convertLine(std::string current_line); 
    
    public:
    //operator
        /**
         * @brief allows to access prime number by index
         * 
         * @param index 
         * @return unsigned long int prime number
         */
        unsigned long int operator[](unsigned long int index);

    //functions
        /**
         * @brief imports prime numbers, throws error on failure
         * This function is not part of a constructor, because it would be limited to the scope of the try block it's in
         */
        void init();

    //getter
        /**
         * @brief returns size() of the prime number vector in the object
         * 
         * @return int amount of primes
         */
        int size();
};

/**
 * @brief Checks input line for allowed chars, throws error if illegal char is found
 * 
 * This function checks a provided line for a set of chars you can define. Integers can be allowed by using the intAllowed parameter.
 * 
 * @param line string to check
 * @param allowedChars vector of chars you want to allow
 * @param intAllowed default=true, if false, integers are not allowed
 */
void checkLine(std::string line, std::vector<char> allowedChars, bool intAllowed = true);