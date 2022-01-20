#include "primeNumbers.hpp"

//    PRIVATE   
//######################################################################

//-----functions-----

void PrimeNumbers::importPrimeNumbers(){
    //Import of prime number file and error handling
    std::vector<char> allowedChars {' ',',','0','1','2','3','4','5','6','7','8','9'}; //allowed chars in input

    std::ifstream primesDat; //Initialize data object

    //Attempts to open "primes.dat"
    primesDat.open("primes.dat", std::ifstream::in);
    
    //Checking if primes.dat was successfully opened
    if (!primesDat.is_open()){
        std::cout << "Failed to open \"primes.dat\", please make sure the file exists and has read permissions." << std::endl;
        throw (404);
    }
    
    //Read each line of the file and add the resulting integers to the m_primeNumbers vector
    std::string current_line; //Buffer for current line
    int lineNumber = 1;

    while (primesDat){
        std::getline (primesDat, current_line);

        try{
            checkLine(current_line, allowedChars); //Checks for illegal chars
        }
        catch (int errorCode){            
            //Adds line that causes failure and throws again
            std::cout << "Please check your primes.dat" << " Line: " << lineNumber << std::endl;          
            throw (errorCode);
        }

        //Now that the current line has been checked, it can be added to the vector
        convertLine(current_line);

        lineNumber++; //Increment line number, will be used in case an error happens.
    }
    primesDat.close(); //IMPORTANT
}

void PrimeNumbers::convertLine(std::string line){
    //converts given line into integer and adds it to the m_primeNumbers vector

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
                m_primeNumbers.push_back(std::stoi(buffer)); //This is where the actual conversion to in happens
                buffer = "";
                break;
            case ' ':
                break;
            default:
                buffer += line[i]; //writes current char into buffer
                break;
        }
    }
}


//    PUBLIC   
//######################################################################



void PrimeNumbers::init(){
    //initializes PrimeNumber Object, imports files..
    //This is not in the constructor because it can fail and I want to handle errors
    
    try{
        importPrimeNumbers();
    }
    catch (int errorCode){
        throw (errorCode);
    }
    
    std::cout << "Successfully loaded " << size() << " prime numbers!" << std::endl;
}

//operator
unsigned long int PrimeNumbers::operator[](unsigned long int index){
    //Operator for easier calling of the numbers
    
    if (index >= m_primeNumbers.size()){
        std::cout << "[ERROR] Index out of Range, there are only " << m_primeNumbers.size() << " Numbers available!" << std::endl;
        throw (416);
    }
    return m_primeNumbers[index];
}





//getter
int PrimeNumbers::size(){
    return m_primeNumbers.size();
}

//setter




void checkLine(std::string line, std::vector<char> allowedChars, bool intAllowed) {
    //Takes 2+1 inputs. A string, custom allowed chars (can be empty), and a bool if integers are allowed (t/f) (default=true)
    //Throws error if a char was not legal
    bool charIsLegal;//Used to determine if curren char was allowed 

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