// Read the file line by line.
// For each line, find the first and last number.
// Concatenate these numbers to form a new number.
// Sum all these new numbers to get a final total.

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main() { // initialize main
    std::ifstream file("list.txt"); // input file stream (ifstream)
    std::string line; // Strings are objects that represent sequences of characters.
    long long totalSum = 0; // long data type is integer or double

    if (file.is_open()) { //if statement determinging if file is open
        while (getline(file, line)) { //getline() read a line from a stream into a string
            std::string firstNum = "", lastNum = "";
            bool foundFirst = false;

            // Find the first and last number
            for (char ch : line) {
                if (isdigit(ch)) {
                    if (!foundFirst) {
                        firstNum = ch;
                        foundFirst = true;
                    }
                    lastNum = ch;
                }
            }

            if (!firstNum.empty() && !lastNum.empty()) {
                // Concatenate and add to total
                totalSum += std::stoll(firstNum + lastNum);
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
        return 1;
    }

    std::cout << "Total Sum: " << totalSum << std::endl;
    return 0;
}
