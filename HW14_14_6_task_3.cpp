#include <iostream>
#include <string>

std::string input()
{
    std::string email;
    std::cout << "Input email: ";
    std::cin >> email;
    std::cout << std::endl << "Your input: " << email << std::endl;
    return email;
}


std::string check_dots(std::string email)
{
    std::string output = "YES";
    for(int i = 0; i < email.length()-1; i++)
    {
        if(email[i] == '.' && email[i+1] == '.')
        {
            output = "check_dots";
            return output;
        }
    }
    return output;
}


std::string check_dogs(std::string email)
{
    std::string output = "YES";
    for(int i = 0; i < email.length()-1; i++)
    {
        if(email[i] == '@' && email[i+1] == '@')
        {
            output = "check_dogs";
            return output;
        }
    }

    for(int i = 0, dogs = 0; i < email.length(); i++)
    {
        if(email[i] == '@')
        {
            dogs++;
            if (dogs == 2 || dogs == 0)
            {
                output = "check_dogs";
                return output;
            }

        }
    }

    return output;
}


std::string check_1part_length(std::string email)
{
    std::string output = "YES";
    for(int i = 0, symbols = 0; i < email.length(); i++)
    {
        if(email[i] != '@')
        {
            symbols++;
            if(symbols > 64)
            {
                output = "check_1part_length";
                return output;
            }
        }
    }
    return output;
}


std::string check_symbols(std::string email)
{
    std::string output = "YES";
    for(int i = 0; i < email.length(); i++)
    {
        if(
        (email[i] > 96 && email[i] < 123) || (email[i] > 64 && email[i] < 91) || (email[i] > 47 && email[i] < 58)
        || email[i] == '!' || email[i] == '#' || email[i] == '$' || email[i] == '%' || email[i] == '&'
        || email[i] == 39  || email[i] == '*' || email[i] == '+' || email[i] == '-' || email[i] == '/'
        || email[i] == '=' || email[i] == '?' || email[i] == '^' || email[i] == '_' || email[i] == 96
        || email[i] == '{' || email[i] == '|' || email[i] == '}' || email[i] == '~' || email[i] == '@'
        || email[i] == '.')
        {
            continue;
        }
        else
        {
            output = "check_symbols";
            return output;
        }
    }
    return output;
}


std::string check_2part_single_symbol(std::string email)
{
    std::string output = "YES";
    for(int i = 0; i < email.length(); i++)
    {
        if(email[i] == '@')
        {
            for(int j = i+1; j < email.length(); j++)
            {
                if(email[j] == '_')
                {
                    output = "check_2part_single_symbol";
                    return output;
                }
            }
        }
    }
    return output;
}


int main()
{
    std::string output;
    std::string email = input();

    output = check_dots(email);
    if(output == "check_dots"){ std::cout << std::endl << output; return 0; }

    output = check_dogs(email);
    if(output == "check_dogs"){ std::cout << std::endl << output; return 0; }

    output = check_1part_length(email);
    if(output == "check_1part_length"){ std::cout << std::endl << output; return 0; }

    output = check_symbols(email);
    if(output == "check_symbols"){ std::cout << std::endl << output; return 0; }

    output = check_2part_single_symbol(email);
    if(output == "check_2part_single_symbol"){ std::cout << std::endl << output; return 0; }

    std::cout << output;

    return 0;
}
