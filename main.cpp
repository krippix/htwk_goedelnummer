#include "primeNumbers.hpp"

int main(){
    
    PrimeNumbers prime; //Create PrimeNumber Object
    
    
    
    //Attempts to create prime object, containing the primes imported from "primes.dat"
    try{
        prime.init();
    }
    catch (int errorCode){
        std::cout << "Exiting with error code <" << errorCode << ">" << std::endl;
        return EXIT_FAILURE;
    }
    for (int i = 0; i < prime.size(); i++){
        std::cout << prime[i] << std::endl;
    }
}