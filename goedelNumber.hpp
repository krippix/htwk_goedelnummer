#pragma once
#include "primeNumbers.hpp"
#include <map>

class GoedelNumber{
    private:
    //variables
        //Map from chars to integers
        std::map<char,int> m_translationKey = {{'+',1},{'-',2},{'*',3},{'/',4},{'=',5},{'0',6},{'s',7},{'a',8},{'b',9},};
        std::string m_input; //The initial userinput
        std::string m_successorFormat; //The resulting successor format formula
        std::vector<int> m_intChain; //the formula as chain of ints
        unsigned long int m_goedelNumber; //The final product, the goedel number
        PrimeNumbers* m_primes; //Pointer to prime numbers
    //functions
        //Converts formula/int to successor syntax: 1 = s0, 2 = ss0 [...]
        std::string formulaToSucc(std::string formula);
        std::string intToSucc(std::string intString);
        //Conversion of successor-format to vector of integers
        std::vector<int> succToIntChain(std::string succ_input);
        void printIntChain();

        //The final step, calculating the Gödel number
        unsigned long int calculateGoedelNumber(std::vector<int> intChainInput);
    
    public:
        //constructor
        GoedelNumber(PrimeNumbers* prime);
    //functions
        //This is where user-input gets accepted
        void input(std::string input);
};