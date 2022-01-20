#include "primeNumbers.hpp"
#include "goedelNumber.hpp"

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

    GoedelNumber goedel;

    std::string userinput;
    std::cin >> userinput;
    goedel.translateInput(userinput);





}
