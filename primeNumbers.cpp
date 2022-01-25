#include "primeNumbers.hpp"

//    PRIVATE   
//######################################################################

//-----functions-----

void PrimeNumbers::importPrimeNumbers(){
    //allowed chars in input
    std::vector<char> allowedChars {' ',','}; 

    //Initialize data object
    std::ifstream primesDat; 

    //Attempts to open "primes.dat"
    primesDat.open("primes.dat", std::ifstream::in);
    
    //Checking if primes.dat was successfully opened
    if (!primesDat.is_open()){
        std::cout << "Failed to open \"primes.dat\", please make sure the file exists and has read permissions." << std::endl;
        throw (404);
    }
    
    //Read each line of the file and add the resulting integers to the m_primeNumbers vector
    std::string current_line;
    int lineNumber = 1;

    while (primesDat){
        std::getline (primesDat, current_line);

        try{
            checkLine(current_line, allowedChars);
        }
        catch (int errorCode){            
            //Adds line that causes failure and throws again
            std::cout << "Please check your primes.dat" << " Line: " << lineNumber << std::endl;          
            throw (errorCode);
        }

        //Now that the current line has been checked, it can be added to the vector
        convertLine(current_line);
        lineNumber++;
    }
    primesDat.close();
}


void PrimeNumbers::convertLine(std::string line){

    std::string buffer = "";

    //Do nothing if string is empty
    if (line.size() == 0){
        return;
    }

    //Iterates through provided lines and converts them into a string
    //uses ',' as seperator and ignores spaces
    for (unsigned int i = 0; i < line.size(); i++){
        switch (line[i]){
            case ',': 
                m_primeNumbers.push_back(std::stoi(buffer));
                buffer = "";
                break;
            case ' ':
                break;
            default:
                buffer += line[i];
                break;
        }
    }
}


//    PUBLIC   
//######################################################################
void PrimeNumbers::init(){
    
    try{
        importPrimeNumbers();
    }
    catch (int errorCode){
        throw (errorCode);
    }
}


//-----operators-----

unsigned long int PrimeNumbers::operator[](unsigned long int index){
    
    if (index >= m_primeNumbers.size()){
        std::cout << "[ERROR] Index out of Range, there are only " << m_primeNumbers.size() << " Numbers available!" << std::endl;
        throw (416);
    }
    return m_primeNumbers[index];
}


//-----getter-----

int PrimeNumbers::size(){
    return m_primeNumbers.size();
}


//-----setter-----

void checkLine(std::string line, std::vector<char> allowedChars, bool intAllowed) {

    //Used to determine if current char was allowed 
    bool charIsLegal;

    //There are two cases now: Integers with chars and only the given chars
    for (unsigned int i = 0; i < line.size(); i++){ //iterates through line
        charIsLegal = false;

        //If current char ist not a digit -> Check if it contains allowed chars
        if (!(std::isdigit(line[i])) || !intAllowed){
            //Iterates through allowed chars
            for (unsigned int j = 0; j < allowedChars.size(); j++){ 
                if (line[i] == allowedChars[j]){
                    charIsLegal = true;
                }
            }
        }
        else {
            charIsLegal = true;
        }
        
        //If no legal char was found, charIsLegal will be false:
        if (!charIsLegal){
            std::cout << "[ERROR] Illegal Character found: " << line[i] << std::endl;
            throw (422);
        }
    }
    return;
}