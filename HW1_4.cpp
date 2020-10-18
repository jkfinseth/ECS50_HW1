#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

// Class to represent the upper triangular matrix
class upper_triangular_matrix {
  public:
    
    // Variables
    int size;
    std::vector<int> contents;
    
    // Constructors
    upper_triangular_matrix(std::string dimension, std::string contents);
    upper_triangular_matrix();
    
    // Functions
    void matrix_print();
};

upper_triangular_matrix::upper_triangular_matrix(std::string dimension, std::string content) {
    
    int x;
    int y = 0;
    int buf;
    std::string substr = "";
    
    // Scan in info for dimension
    for (x=0; x<dimension.length(); x++) {
        if (dimension[x+1] == ' ') {
            substr = dimension.substr(y,x-y+1);
            std::stringstream stoi(substr);
            stoi >> buf;
            size = buf;
        }
    }
    
    // Scan in info for the contents of the matrix
    for (x=0; x<content.length(); x++) {
        if (content[x+1] == ' ') {
            substr = content.substr(y,x-y+1);
            std::stringstream stoi(substr);
            stoi >> buf;
            contents.insert (contents.end(), buf);
            x++;
            y = x+1;
        }
    }
    
}

upper_triangular_matrix::upper_triangular_matrix () {}

void upper_triangular_matrix::matrix_print() {
    int x;
    int items = 0;
    
    // Determine the number of items contained in the matrix
    for (x = size; x > 0; x--) {
        items += x;
    }
    
    // Iterate over each item, printing them as it goes.
    for (x = 0; x < items; x++) {
        if (x != items - 1) {
            std::cout << contents[x] << " ";
        } else {
            std::cout << contents[x] << std::endl;
        }
    }
}

upper_triangular_matrix crossProduct (std::vector<int> A, std::vector<int> B, int size) {
    
    upper_triangular_matrix C;
    C.size = size;
    int items = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int o = 0;
    int buf = 0;

    // Determine number of items
    for (int i = size; i > 0; i--) {
        items += i;
    }

    for (int i=0; i<items; i++) {

        if (l == 0) {

            // Current square is a diagonal, equal to diagonal*diagonal
            buf = A[i] * B[i];
        } else {

            // Current square is not a diagonal, needs l+1 calculations.
            for (m=0; m<l+1; m++) {
                
                o = 0;
                
                //Determine the gap needed to go down one row each time.
                for (int p = 0; p < m; p++) {
                    o += (size - n + p);
                }
                buf += (A[k+m] * B[i+o]);
                n++;
            }
        }

        // Add the result to the vector and reset buf
        C.contents.insert(C.contents.end(), buf);
        buf = 0;

        // Update variables kjln if end of a row is reached, or ln if the end is not reached
        if (i == k+(size - (j+1))) {
            k += (size - j);
            j++;
            l = 0;
            n = j;
        } else {
            l++;
            n = j;
        }

    }
    
    return C;
}

int main(int argc, char *argv[]) {
    
    
    std::ifstream input;
    std::string line_contents = "";
    std::vector<std::string> vector_storage;
    
    // Open the first file
    input.open(argv[1]);
    
    // Store contents and close the file
    while (getline(input, line_contents)) {
        if (line_contents.length() != 0) {
            vector_storage.insert(vector_storage.end(), line_contents);
        }
    }
    input.close();
    
    // Open the second file
    input.open(argv[2]);
    
    // Store contents and close the file
    while (getline(input, line_contents)) {
        if (line_contents.length() != 0) {
            vector_storage.insert(vector_storage.end(), line_contents);
        }
    }
    input.close();
    
    // From the stored information from the files, create two vectors, A and B
    upper_triangular_matrix A(vector_storage[0], vector_storage[1]);
    upper_triangular_matrix B(vector_storage[2], vector_storage[3]);
    
    // Calculate the cross product and store result in C. Then print C
    upper_triangular_matrix C = crossProduct(A.contents, B.contents, A.size);
    C.matrix_print();
    return 0;
}
