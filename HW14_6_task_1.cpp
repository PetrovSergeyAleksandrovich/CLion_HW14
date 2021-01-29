#include <iostream>
#include <string>

std::string encrypt(std::string input, int N)
{
    for(int i = 0; i < input.length(); i++)
    {
        if( input[i] < 97 or input[i] > 122) continue;
        input[i] += N % 25;
        if(input[i] > 122) input[i] = 96 + input[i] % 122;
    }
    return input;
}

std::string decrypt(std::string input, int N)
{
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] < 97 or input[i] > 122) continue;
        input[i] -= N % 25;
        if(input[i] < 97) input[i] = 123 - 97 % input[i];
    }
    return input;
}

int main()
{
    int n;
    std::string str;

    std::cout << "input: ";
    std::getline(std::cin, str);
    std::cout << std::endl;

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
