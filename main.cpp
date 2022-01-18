#include "primeNumbers.hpp"

int main(){

    //Attempts to create prime object, containing the primes imported from "primes.dat"
    try{
        PrimeNumbers prime;
    }
    catch (int customerror){
        std::cout << "Exiting with error code <" << customerror << ">" << std::endl;
        return EXIT_FAILURE;
    }
    
}