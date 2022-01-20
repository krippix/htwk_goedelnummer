#pragma once
#include "primeNumbers.hpp"
#include <map>



class GoedelNumber{
    private:
    //variables
        //Map from chars to integers
        std::map<char,int> m_translationKey = {{'+',1},{'-',2},{'*',3},{'/',4},{'=',5},{'0',6},{'s',7},{'a',8},{'b',9},};

    public:
        GoedelNumber();
        void translateInput(std::string input);
        std::string intToSucc(std::string _Inout_updates_bytes_all_); //Converts integers to successor syntax: 1 = s0, 2 = ss0 [...]
        std::vector<int> succToVector(std::string succ_input);
        unsigned long int calculateGoedelNumber(std::vector<int> input);
        unsigned long int pow(unsigned long int, unsigned long int);
        void test(std::string);
};