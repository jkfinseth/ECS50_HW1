#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int changeToTen (int base, std::string input) {
    
    int i = input.length();
    int buf_num;
    int buf_power;
    char buf_char;
    int total = 0;
    
    for (i; i>0; i--) {
        buf_power = std::pow(base, i-1);
        buf_char = input[input.length() - i];
        if (48<=int(buf_char) && int(buf_char) <= 57) {
            buf_num = int(buf_char) - 48;
        } else if (65<=int(buf_char) && int(buf_char) <= 90) {
            buf_num = int(buf_char) - 55;
        }
        total += buf_power * buf_num;
    }
    return total;
}

std::string changeFromTen (int new_base, int input_10) {
    
    std::string output;
    int quotient = input_10;
    int remainder;
    char buf;

    // Make sure input is not 0
    if (quotient != 0) {
        
        while (quotient != 0) {
            // Obtain remainder of quotient/new_base 
            remainder = quotient % new_base;
            
            // Determine the appropriate character
            if (remainder < 10) {
                buf = '0' + remainder;
            } else {
                buf = 'A' + remainder - 10;
            }
            
            // Add character to the output
            output += buf;
            
            // Update the quotient
            quotient = quotient / new_base;
        }
    } else {
        // If the input is 0, the output is also 0
        output += '0';
    }
    
    // Reverse the string in order to get the characters in the correct order
    std::reverse(output.begin(), output.end());
    return output;
}

int main () {
    int base;
    int new_base;
    int buf;
    std::string input;
    std::string output;
    
    // Request a base for the original number to be in
    std::cout << "Please enter the number's base: ";
    // Store input in an int base
    std::cin >> base;
    
    // Request a value in base base
    std::cout << "Please enter the number: ";
    // Store input in a str input
    std::cin >> input;
    
    // Request new base for the input
    std::cout << "Please enter the new base: ";
    // Store input in an int new_base
    std::cin >> new_base;
    
    // Convert input from base base to base 10
    buf = changeToTen (base, input);
    
    // Convert buf from base 10 to base new_base
    output = changeFromTen (new_base, buf);
    
    // Output solution
    std::cout << input << " base " << base << " is " << output << " base " << new_base << std::endl;
}
