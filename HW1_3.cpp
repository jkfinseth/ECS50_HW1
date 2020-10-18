#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

std::string changeToTwo(int input_10) {
    
    std::string output;
    int quotient = input_10;
    int remainder;
    char buf;

    // Make sure input is not 0
    if (quotient != 0) {
        
        while (quotient != 0) {
            // Obtain remainder of quotient/new_base 
            remainder = quotient % 2;
            
            // Determine the appropriate character
            buf = '0' + remainder;
            
            // Add character to the output
            output += buf;
            
            // Update the quotient
            quotient = quotient / 2;
        }
    } else {
        // If the input is 0, the output is also 0
        output += '0';
    }
    
    // Reverse the string in order to get the characters in the correct order
    std::reverse(output.begin(), output.end());
    return output;
}

std::string convertDecimalToTwo(float input_10) {

    std::string output;
    // Used as counter to go through negative powers of 2 (1/2, 1/4, 1/8, etc.)
    int i = -1;
    // Used to store only the decimal without the 
    float decimal = input_10 - (int)input_10;

    // Continue while there is more to convert
    while (decimal > 0) {
        
        // Check if bit should be a 1 or a 0
        if (decimal >= std::pow(2,i)) {
            output += '1';
            decimal -= std::pow(2,i);
        } else {
            output += '0';
        }

        // Decrease counter
        i--;
    }

    return output;
}

std::string itos(int input) {

    std::stringstream os;
    std::string output;

    os << input;
    output = os.str();

    return output;
}

int main() {

    float input;
    int len;
    std::string power = "E";
    std::string solution;
    
    // Request value
    std::cout << "Please enter a float: ";
    std::cin >> input;
    
    // Change input to binary and store in solution
    solution = changeToTwo((int)input);
    
    // Calculate correct power
    len = solution.length() - 1;
    
    // Insert . in second slot
    solution.insert(1,".");
    
    // Convert the decimal and add it to the solution string
    solution += convertDecimalToTwo(input);
    
    // Update power to include the correct power and add it to solution
    power += itos(len);
    solution += power;
    
    // Output solution
    std::cout << solution << std::endl;
    
    return 0;
}
