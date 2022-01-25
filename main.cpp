#include "primeNumbers.hpp"
#include "goedelNumber.hpp"

int main(){

    //Create PrimeNumber Object
    PrimeNumbers prime; 

    //Checks if the primes.dat is valid
    try{
        prime.init();
    }
    catch (int errorCode){
        std::cout << "Exiting with error code <" << errorCode << ">" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << "####################################" << std::endl;
    std::cout << "#          Goedelnumber            #" << std::endl;
    std::cout << "####################################" << std::endl;
    std::cout << "Generates Godelnumber based on your input." << std::endl;
    std::cout << "Available prime numbers: " << prime.size() << std::endl;
    std::cout << "Allowed characters are the integers 0-9 and (comma seperated): [+, -, *, /, =, a, b] " << std::endl;

    //Creates GoedelNumber object with reference to the previously imported prime numbers
    GoedelNumber goedel(&prime);
    std::string userinput;
    
    std::cout << "Input your formula: ";
    try{
        std::cin >> userinput;
    }
    catch(...){
        std::cout << "Input failed, exiting program." << std::endl;
        return EXIT_FAILURE;
    }
    
    //Now the userinput will be passed and processed
    try{
        goedel.input(userinput);
    }
    catch(int errorCode){
        std::cout << "Exiting with error code <" << errorCode << ">" << std::endl;
        return EXIT_FAILURE;
    }

    //Print out the result
    goedel.printResults();
}
