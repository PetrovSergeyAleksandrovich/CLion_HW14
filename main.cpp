#include <iostream>
#include <string>

int main() {

    std::string x = "10000000.001";
    std::string y = "10000000.002";


    std::cout << stold(x) - stold(y) ;


    return 0;
}
