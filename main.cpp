#include <iostream>
#include <string>

int main() {

    std::string text = "-.123";
    double x = 5;

    std::cout << std::stof(text) + x;

    return 0;
}
