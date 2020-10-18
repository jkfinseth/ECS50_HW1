#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

std::string changeToTwo(int input_10) {
    
    std::string output;
    int quotient = input_10;
    int remainder;
    char buf;
    int max = 27;

    // Make sure input is not 0
    if (quotient != 0) {
        
        while (quotient != 0) {
            // Obtain remainder of quotient/new_base 
            remainder = quotient % 2;
            
            // Determine the appropriate character
            buf = '0' + remainder;
            
            // Add character to the output and update the maximum characters
            output += buf;
            max--;
            
            // Update the quotient
            quotient = quotient / 2;
        }
    }
    
    // Check to make sure there are 27 characters in the input. If not, fill the rest with 0's.
    while (max != 0) {
        output += '0';
        max--;
    }
    
    // Reverse the string in order to get the characters in the correct order
    std::reverse(output.begin(), output.end());
    return output;
}

char binaryToLetter(std::string binary) {
    
    char result;
    int i;
    
    // Determine if letter is upper or lower case
    if (binary[0] == '1') {
        result = 'A';
    } else {
        result = 'a';
    }
    
    // Continue to go back until a letter is determined
    for (i = 26; i>1; i--) {
        if (binary[i] == '1') {
            return result;
        } else {
            result++;
        }
    }
}

int main (int argc, char *argv[]) {
    
    int x;
    int input;
    std::string binary;
    char letter;
    std::string result;
    
    // Take each number in the input, convert it to binary, and determine the letter. Add the letter to a string
    for (x = 1; x < argc; x++) {
        std::istringstream ss(argv[x]);
        ss >> input;
        binary = changeToTwo(input);
        letter = binaryToLetter(binary);
        result += letter;
    }
    
    // Print the word stored in the string
    std::cout << "You entered the word: " << result << std::endl;
    return 0;
}
