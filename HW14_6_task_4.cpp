#include <iostream>
#include <string>

std::string input()
{
    std::string ip;
    std::cout << "Input IP: ";
    std::cin >> ip;
    std::cout << std::endl << "Your input: " << ip << std::endl;
    return ip;
}

std::string check_symbols(std::string ip)
{
    std::string output = "YES";
    int  check = 0;
    for(int i = 0; i < ip.length(); i++)
    {
        if(ip[i] == '.') continue;
        if(ip[i] >= '0' && ip[i] <= '9') continue;
        check++;
    }
    if(check)
    {
        output = "check_symbols";
        return output;
    }
    return output;
}

std::string check_dots(std::string ip)
{
    std::string output = "YES";

    for(int i = 0; i < ip.length()-1; i++)
    {
        if(ip[i] == '.' && ip[i+1] == '.')
        {
            output = "check_dots";
            return output;
        }
    }

    if(ip[ip.length()-1] == '.')
    {
        output = "check_dots";
        return output;
    }

    int dots = 0;
    for(int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == '.') dots++;
    }
    if(dots != 3)
    {
        output = "check_dots";
        return output;
    }

    return output;
}

std::string check_zeros(std::string ip)
{
    std::string output = "YES";
    for(int i = 0; i < ip.length()-2; i++)
    {
        if(ip[i] == '1' && ip[i+1] == '0' && ip[i+2] == '0') continue;
        if(ip[i] == '2' && ip[i+1] == '0' && ip[i+2] == '0') continue;

        if(ip[i] == '0' && ip[i+1] == '0')
        {
            output = "check_zeros";
            return output;
        }

        if(ip[i] == '.' && ip[i+1] == '0' && ip[i+2] == '0')
        {
            output = "check_zeros";
            return output;
        }

        if( ip[i] == '.' && ip[i+1] == '0' && ip[i+2] >= '1' && ip[i+2] <= '9')
        {
            output = "check_zeros";
            return output;
        }
    }
    return output;
}

std::string check_digits(std::string ip)
{
    std::string output = "YES";
    std::string tmp;
    for(int i = 0; i < ip.length(); i++)
    {
        if(ip[i] != '.')
        {
            tmp.push_back(ip[i]);
        }
        else
        {
            if(std::stoi(tmp) > 255)
            {
                output = "check_digits";
                return output;
            }
            else
            {
               tmp.clear();
            }
        }
    }

    return output;
}


int main()
{
    std::string output;
    std::string ip = input();

    output = check_symbols(ip);
    if(output == "check_symbols"){ std::cout << std::endl << output; return 0; }

    output = check_dots(ip);
    if(output == "check_dots"){ std::cout << std::endl << output; return 0; }

    output = check_zeros(ip);
    if(output == "check_zeros"){ std::cout << std::endl << output; return 0; }

    output = check_digits(ip);
    if(output == "check_digits"){ std::cout << std::endl << output; return 0; }

    std::cout << output;

    return 0;
}

