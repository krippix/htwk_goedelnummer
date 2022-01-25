#include "goedelNumber.hpp"

//    PRIVATE   
//######################################################################

//-----functions-----

std::string GoedelNumber::formulaToSucc(std::string input){
    //Converts the integers in the provided formula to successors of the number 0
    //Example: 3 turns into sss0, 1 turns into s0

    bool wasInt = false; //keeps track of whether the last char was an integer
    std::string intBuffer; //Buffers current int "chain"
    std::string result = "";
    
    //This will iterate throug the provided input char by char
    for (unsigned int i = 0; i < input.size(); i++){

        if (std::isdigit(input[i])){ 
            
            wasInt = true;
            intBuffer += input[i];   
        }
        else {
            //if the current char has broken an int-chain, it has to be converted to the successor format
            if (wasInt){
                //Convert intBuffer and clear it
                result += intToSucc(intBuffer);
                intBuffer = ""; 
            }
            //Now the current non-int char can be appended
            result += input[i];
            
            //Mark current char as non-int for next loop
            wasInt = false; 
        }

        //If on last char, check if it was an integer, if it was it has to be converted now.
        if (i == input.size()-1 && wasInt){
            //Convert intBuffer and clear it
            result += intToSucc(intBuffer);
            intBuffer = ""; 
        }
    }
    return result;
}


std::string GoedelNumber::intToSucc(std::string intString){
    //converts string with only integers to successor format
    std::string result;

    //Converts int-string to actual int
    int integer = std::stoi(intString); 
    
    //Creates number and return string with format interger*'c'+0
    result += std::string(integer, 's') + '0';
    //result += '0';
    return result;
}


std::vector<int> GoedelNumber::succToIntChain(std::string succ_input){
    //Takes the successor formatted string and turns it into a list of integers
    std::vector<int> resultVector;

    for (unsigned int i = 0; i < succ_input.size(); i++){
        //Takes current char as input for the translation key, the key returns the assigned value of the char 
        //and puts it into the vector
        resultVector.push_back(m_translationKey[succ_input[i]]);
    }
    return resultVector;
}


void GoedelNumber::printIntChain(){
    //Simply prints m_intChain
    for (unsigned int i = 0; i < m_intChain.size(); i++){
        std::cout << m_intChain[i] << " ";
    }
    std::cout << std::endl;
}


void GoedelNumber::calculateGoedelNumber(std::vector<int> intChainInput){
    //Takes the m_IntChain vector as input and turns it into the Gödel number
    //PrimeNumbers prime;
    //prime.init();

    for (unsigned int i = 0; i < intChainInput.size(); i++){
        
        //Actual calculation
        m_goedelNumber += std::pow(m_primes->operator[](i), intChainInput[i]);
        
        //Creating String with prime^int * prime^int [...] for later visualization
        m_goedelPrimeSteps += std::to_string(m_primes->operator[](i));
        m_goedelPrimeSteps += "^";
        m_goedelPrimeSteps += std::to_string(intChainInput[i]);      
        
        if (!(i == intChainInput.size()-1)){
            m_goedelPrimeSteps += " + ";
        }
    }
    std::cout << std::endl;
}


//    PUBLIC   
//######################################################################

//-----constructor-----

GoedelNumber::GoedelNumber(PrimeNumbers* prime){
    m_primes = prime;
}

//-----functions-----

void GoedelNumber::input(std::string userinput){
    //Accepts formula and converts it into the Goedelnumber
    
    //Vector of allowed chars (excluding integers)
    std::vector<char> allowedChars {' ','+','-','*','/','=','a','b'};

    //Checking input for Illegal chars
    try{
        checkLine(userinput, allowedChars); 
    }
    catch(int errorCode){
        throw(errorCode);
    }
    //saves userinput
    m_input = userinput;
    
    //converting Integers to the successor format
    m_successorFormat = formulaToSucc(userinput);
    
    //Now the successor format can be converted to a vector of integers and printed out
    m_intChain = succToIntChain(m_successorFormat);
    
    //Now the goedel number can be calculated
    calculateGoedelNumber(m_intChain);
}


void GoedelNumber::printResults(){
    std::cout << "Successor format: " << m_successorFormat << std::endl;
    std::cout << "As integers:      "; printIntChain();
    std::cout << "Prime^int:        " << m_goedelPrimeSteps << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Result:           " << m_goedelNumber << std::endl << std::endl;
}