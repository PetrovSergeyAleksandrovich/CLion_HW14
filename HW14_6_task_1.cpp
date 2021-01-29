#include <iostream>
#include <string>

std::string encrypt(std::string input, int N)
{
    for(int i = 0; i < input.length(); i++)
    {
//        std::cout << "before: " << int(input[i]) << std::endl;
        int tmp = input[i] + N % 25;
        if(tmp > 122) tmp = 96 + tmp % 122;
        input[i] = tmp;
//        std::cout << "after: " << int(input[i]) << std::endl;
//        std::cout << std::endl;
    }
    return input;
}

std::string decrypt(std::string input, int N)
{
    for(int i = 0; i < input.length(); i++)
    {
//        std::cout << "before: " << int(input[i]) << std::endl;
        int tmp = input[i] - N % 25;
        if(tmp < 97) tmp = 123 - 97 % tmp;
        input[i] = tmp;
//        std::cout << "after: " << int(input[i]) << std::endl;
//        std::cout << std::endl;
    }
    return input;
}

int main()
{
    int n;
    std::string str;

    std::cout << "input: ";
    std::getline(std::cin, str);

    std::cout << "\nYour input: " << str << std::endl;

    std::cout << "input encrypted number: ";
    std::cin >> n;
    str = encrypt(str, n);

    std::cout << "\nYour input encrypted: " << str << std::endl;

    std::cout << "input decrypted number: ";
    std::cin >> n;
    str = decrypt(str, n);

    std::cout << "\nYour input decrypted: " << str << std::endl;

}
