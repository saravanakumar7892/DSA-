#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Function to check if the equation holds true
bool checkEquation(const std::unordered_map<char, int>& mapping) {
    int apple = mapping.at('A') * 10000 + mapping.at('P') * 1000 + mapping.at('P') * 100 + mapping.at('L') * 10 + mapping.at('E');
    int lemon = mapping.at('L') * 10000 + mapping.at('E') * 1000 + mapping.at('M') * 100 + mapping.at('O') * 10 + mapping.at('N');
    int banana = mapping.at('B') * 100000 + mapping.at('A') * 10000 + mapping.at('N') * 1000 + mapping.at('A') * 100 + mapping.at('N') * 10 + mapping.at('A');

    return apple + lemon == banana;
}

// Function to solve the equation using brute-force
void solveEquation() {
    std::unordered_map<char, int> mapping;
    std::vector<char> letters = {'A', 'P', 'L', 'E', 'M', 'O', 'N', 'B'};

    // Iterate over all possible combinations of digits
    std::vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        for (size_t i = 0; i < letters.size(); ++i) {
            mapping[letters[i]] = digits[i];
        }

        // Check if 'A', 'L', and 'B' have valid (non-zero) leading digits
        if (mapping['A'] != 0 && mapping['L'] != 0 && mapping['B'] != 0 &&
            checkEquation(mapping)) {

            // Print the solution
            std::cout << "A = " << mapping['A'] << std::endl;
            std::cout << "P = " << mapping['P'] << std::endl;
            std::cout << "L = " << mapping['L'] << std::endl;
            std::cout << "E = " << mapping['E'] << std::endl;
            std::cout << "M = " << mapping['M'] << std::endl;
            std::cout << "O = " << mapping['O'] << std::endl;
            std::cout << "N = " << mapping['N'] << std::endl;
            std::cout << "B = " << mapping['B'] << std::endl;
            return;
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
}

int main() {
    solveEquation();
    return 0;
}