#include <iostream>
#include <string>

std::string encrypt(std::string input, int N)
{
    if(N > 0){
        for(int i = 0; i < input.length(); i++)
        {
            if( input[i] < 'a' or input[i] > 'z') continue;
            input[i] += N % 26;
            if(input[i] > 'z') input[i] = '`' + input[i] % 'z';
        }
        return input;
    }
    if(N < 0)
    {
        N *= -1;
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] < 'a' or input[i] > 'z') continue;
            input[i] -= N % 26;
            if(input[i] < 'a') input[i] = '{' - 'a' % input[i];
        }
        return input;
    }

}

int main()
{
    int n;
    std::string str;

    std::cout << "input: ";
    std::getline(std::cin, str);
    std::cout << std::endl;

    std::cout << "input encrypted number (positive value): ";
    std::cin >> n;
    str = encrypt(str, n);
    std::cout << "\nencrypted: " << str << std::endl;
    std::cout << std::endl;

    std::cout << "input decrypted number (negative value): ";
    std::cin >> n;
    str = encrypt(str, n);
    std::cout << "\ndecrypted: " << str << std::endl;
    std::cout << std::endl;

}
