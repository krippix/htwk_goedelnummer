#pragma once
#include "primeNumbers.hpp"
#include <map>

/**
 * @brief Handles calculation of goedelnumber and saves each step
 * 
 */
class GoedelNumber{
    private:
    //variables
        //Map from chars to integers
        std::map<char,int> m_translationKey = {{'+',1},{'-',2},{'*',3},{'/',4},{'=',5},{'0',6},{'s',7},{'a',8},{'b',9},};
        
        //Pointer to prime number
        PrimeNumbers* m_primes; 
        
        //The initial userinput
        std::string m_input; 
        
        //The resulting successor format formula (1 = s0, 2 = ss0)
        std::string m_successorFormat; 
        
        //the formula as chain of integers (translated with m_translationKey)
        std::vector<int> m_intChain;

        //Contains depiction with prime^int * prime^int [...]
        std::string m_goedelPrimeSteps = "";

        //The final product, the goedel number
        unsigned long long int m_goedelNumber = 0; 
        
    //functions        
        /**
         * @brief Converts formula to successor syntax:
         * e.g. "1+a=2" will turn into "s0+a=ss0"
         * @param formula 
         * @return std::string in successor format
         */
        std::string formulaToSucc(std::string formula);

        /**
         * @brief Converts String of ints to successor syntax: 1 = s0, 2 = ss0 [...]
         * This is supposed to be called by formulaToSucc(), wich provides a string containing integers
         * @param intString String that only contains strings
         * @return std::string string in successor format
         */
        std::string intToSucc(std::string intString);

        /**
         * @brief Conversion of successor-format to vector of integers
         * Takes the whole successor-formatted formula and converts it to a list of integers based on the map m_translationKey
         * @param succ_input formula in successor format
         * @return std::vector<int> 
         */
        std::vector<int> succToIntChain(std::string succ_input);
        
        /**
         * @brief prints out m_intChain
         * 
         */
        void printIntChain();

        /**
         * @brief Calculates the goedel number based on the provided int vector
         * The calculation steps will also be saved in m_goedelPrimeSteps for later printing
         * @param intChainInput vector of integers
         */
        void calculateGoedelNumber(std::vector<int> intChainInput);
    
    public:
    //constructor
        /**
         * @brief Construct a new Goedel Number object
         * 
         * @param prime requires pointer to previously created PrimeNumbers object
         */
        GoedelNumber(PrimeNumbers* prime);

    //functions
        /**
         * @brief Accepts string and attempts to convert it to goedel number
         * 
         * @param input formula to be converted
         */
        void input(std::string input);

        /**
         * @brief prints out the goedel number and it's calculation steps.
         * 
         */
        void printResults(); //Prints out the steps taken to calculate the number
};