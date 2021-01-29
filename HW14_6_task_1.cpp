#include <iostream>
#include <string>

std::string encrypt(std::string input, int N)
{
    for(int i = 0; i < input.length(); i++)
    {
        int tmp = input[i] + N % 25;
        if(tmp > 122) tmp = 96 + tmp % 122;
        input[i] = tmp;
    }
    return input;
}

std::string decrypt(std::string input, int N)
{
    for(int i = 0; i < input.length(); i++)
    {
        int tmp = input[i] - N % 25;
        if(tmp < 97) tmp = 123 - 97 % tmp;
        input[i] = tmp;
    }
    return input;
}

int main()
{
    int n;
    std::string str;

    std::cout << "input: ";
    std::getline(std::cin, str);

    std::cout << "input encrypted number: ";
    std::cin >> n;
    str = encrypt(str, n);
    std::cout << "\nencrypted: " << str << std::endl;
    std::cout << std::endl;

    std::cout << "input decrypted number: ";
    std::cin >> n;
    str = decrypt(str, n);
    std::cout << "\ndecrypted: " << str << std::endl;
    std::cout << std::endl;

}
