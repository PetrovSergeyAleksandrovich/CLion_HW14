#include <iostream>
#include <string>

int main()
{
    std::string str1, str2, str3;

    std::cout << "1st line: ";
    std::cout << std::endl;
    std::getline(std::cin, str1);
    std::cout << std::endl;

    std::cout << "2st line: ";
    std::getline(std::cin, str2);
    std::cout << std::endl;

    std::cout << "3st line: ";
    std::getline(std::cin, str3);
    std::cout << std::endl;

    std::cout << str1 << "\n" << str2 << "\n" << str3 << "\n";

    
}
