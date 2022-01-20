#include "goedelNumber.hpp"

GoedelNumber::GoedelNumber(){

    //Initialize translation key for later use
    std::map<char,int> m_translationKey = {
            {'+',1},
            {'-',2},
            {'*',3},
            {'/',4},
            {'=',5},
            {'0',6},
            {'s',7},
            {'a',8},
            {'b',9},
        };

}


int GoedelNumber::translateInput(std::string input){
    //Takes String as input and returns Goedel Number as output
    std::vector<char> allowedChars {' ','0','1','2','3','4','5','6','7','8','9','+','-','*','/','=','a','b'};
    std::string result = "";

    if (input.size() == 0){
        std::cout << "Your input is empty! Please try again." << std::endl;
    }

    //checks if input contains illegal chars
    try{
        checkLine(input, allowedChars); 
    }
    catch(int errorCode){
        throw(errorCode);
    }

    //Integers are convertet to the n*s+0 format
    result = intToSucc(input);
    std::cout << "Successor result: " << result << std::endl;

    //Now the successor format can be converted to a vector of integers
    std::vector<int> resultVec = succToVector(result);
    
    std::cout << "Integer result: " << result << std::endl;
    for (int i = 0; i < resultVec.size(); i++){
       std::cout << resultVec.size() << " ";
    }
    std::cout << std::endl;

    std::cout << "Final result: " << calculateGoedelNumber(resultVec);


}


std::string GoedelNumber::intToSucc(std::string input){
    //convert integers to ss0 etc.
    //Example: 1 = s0, 2 = ss0
    std::string result = "";
    std::string testing = "test";
    bool wasInt = false; //keeps track of whether the last char was an integer
    std::string intBuffer; //keeps track of ints until non-int char
    std::cout << testing << std::endl;
    for (int i = 0; i < input.size(); i++){
        if (input[i] >= 48 || input[i] <= 57){ //Checks if current iteration is an int
            wasInt = true;
            intBuffer += input[i];
        }
        else { //Current input isn't an integer
            //Appends 's' for each integer intBuffer is after 0
            if (wasInt){
                int temp_int = std::stoi(intBuffer); //Converts intbuffer into actual int type
                
                //append temp_int times c
                for (int j = 0; j <= temp_int; j++){
                    result += 's';
                }
                result += '0';
                intBuffer = ""; //Reset intbuffer for next loop
            }

            //Every char that is not an int will just be appended
            result += input[i];
            

            wasInt = false; //Reset wasInt for next loop
        }
    }
}


std::vector<int> GoedelNumber::succToVector(std::string succ_input){
    //Takes the successor formatted string and turns it into a list of integers
    
    std::vector<int> resultVector;

    for (int i = 0; i < succ_input.size(); i++){
        //Takes current char as input for the translation key, the key returns the assigned value of the char 
        //and puts it into the vector
        resultVector.push_back(m_translationKey[succ_input[i]]);
    }

    return resultVector;
}


unsigned long int GoedelNumber::calculateGoedelNumber(std::vector<int> input){
    //The last step: Now we will use prime numbers as base and take it to the power of the previously translated integer
    unsigned long int final_result;

    PrimeNumbers prime;


    for (int i = 0; i < input.size(); i++){
        final_result += pow(prime[i],input[i]);
    }

    return final_result;
}

unsigned long int GoedelNumber::pow(unsigned long int a, unsigned long int b){
    //Takes 1st input to the power of the second input
    unsigned long int result = a;
    
    for (int i = 0; i < b; i++){
        result *= a;
    }

    return result;
}