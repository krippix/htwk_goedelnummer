#include "primeNumbers.hpp"
#include "goedelNumber.hpp"

int main(){
    
    PrimeNumbers prime; //Create PrimeNumber Object
    
    //Tests if primes.dat can be read
    try{
        prime.init();
    }
    catch (int errorCode){
        std::cout << "Exiting with error code <" << errorCode << ">" << std::endl;
        return EXIT_FAILURE;
    }

    GoedelNumber goedel;

    std::string userinput;
    std::cout << "Input your formula: ";
    std::cin >> userinput;
    goedel.input(userinput);
}
