//Finn Stalter
//CIS 1202 5T1
// 7/30/23

#include <iostream>
#include <stdexcept>

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw std::invalid_argument("InvalidCharacterException: start is not a letter");
    }

    char result = start + offset;

    if (!isalpha(result) || (islower(start) && isupper(result)) || (isupper(start) && islower(result))) {
        throw std::invalid_argument("InvalidRangeException: invalid offset or upper-lower case transition");
    }

    return result;
}

int main() {
    try {
        char start = 'a';
        int offset = 1;
        char result = character(start, offset);
        std::cout << "Character at offset " << offset << " from " << start << " is: " << result << std::endl;

        start = 'a';
        offset = -1;
        result = character(start, offset);
        std::cout << "Character at offset " << offset << " from " << start << " is: " << result << std::endl;

        start = 'Z';
        offset = -1;
        result = character(start, offset);
        std::cout << "Character at offset " << offset << " from " << start << " is: " << result << std::endl;

        start = '?';
        offset = 5;
        result = character(start, offset);
        std::cout << "Character at offset " << offset << " from " << start << " is: " << result << std::endl;

        start = 'A';
        offset = 32;
        result = character(start, offset);
        std::cout << "Character at offset " << offset << " from " << start << " is: " << result << std::endl;
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
