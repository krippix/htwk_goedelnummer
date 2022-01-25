#include "primeNumbers.hpp"
#include "goedelNumber.hpp"

int main(){
    
    PrimeNumbers prime; //Create PrimeNumber Object
    
    //Checks if the primes.dat is valid
    try{
        prime.init();
    }
    catch (int errorCode){
        std::cout << "Exiting with error code <" << errorCode << ">" << std::endl;
        return EXIT_FAILURE;
    }

    //Creates GoedelNumber object with reference to the previously importet prime numbers
    GoedelNumber goedel(&prime);

    std::string userinput;
    std::cout << "Input your formula: ";
    std::cin >> userinput;
    goedel.input(userinput);
}
