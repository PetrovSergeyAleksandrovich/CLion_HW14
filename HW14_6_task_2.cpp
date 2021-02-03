#include <iostream>
#include <string>

std::string input()
{
    std::string input_text;
    std::cout << "Input: ";
    std::getline(std::cin, input_text);
    for(int i = 0; i < input_text.length(); i++)
    {
        if(input_text.length() == 3 and (input_text[i] == 'o'
            or input_text[i] == 'x' or input_text[i] == '.') )
        {
            continue;
        }
        else
        {
            std::cout << "Incorrect. Input: ";
            std::getline(std::cin, input_text);
            i = 0;
        }
    }
    return input_text;
}

std::string  check_line(std::string tmp_str1, std::string tmp_str2, std::string tmp_str3)
{
    std::string result = "Nobody", result_player1 = "none", result_player2 ="none";
    
    if (tmp_str1 == "xxx" || tmp_str2 == "xxx" || tmp_str3 == "xxx") {
        result_player1 = "Petya won line";
    }
    if (tmp_str1 == "ooo" || tmp_str2 == "ooo" || tmp_str3 == "ooo"){
        result_player2 = "Vanya won line";
    }

    if(result_player1 == "Petya won line" && result_player2 == "Vanya won line")     return result;
    if(result_player1 == "Petya won line" && result_player2 == "none")       return result_player1;
    if(result_player1 == "none" && result_player2 == "Vanya won line")       return result_player2;
    return result;
}

std::string  check_vertical(std::string tmp_str1, std::string tmp_str2, std::string tmp_str3)
{
    std::string result = "Nobody", result_player1 = "none", result_player2 ="none";

    for(int i = 0; i < 3; i++)
    {
        if (tmp_str1[i] == 'x' && tmp_str2[i] == 'x' && tmp_str3[i]== 'x')
        {
            result_player1 = "Petya won vert";
        }
        if (tmp_str1[i] == 'o' && tmp_str2[i] == 'o' && tmp_str3[i]== 'o')
        {
            result_player2 = "Vanya won vert";
        }
    }

    if(result_player1 == "Petya won vert" && result_player2 == "Vanya won vert")     return result;
    if(result_player1 == "Petya won vert" && result_player2 == "none")       return result_player1;
    if(result_player1 == "none" && result_player2 == "Vanya won vert")       return result_player2;
    return result;
}


std::string  check_diagonal(std::string tmp_str1, std::string tmp_str2, std::string tmp_str3)
{
    std::string result = "Nobody", result_player1, result_player2;

    if (tmp_str1[0] == 'x' && tmp_str2[1] == 'x' && tmp_str3[2]== 'x')
    {
        result_player1 = "Petya won diag";
        return result_player1;
    }
    if (tmp_str1[2] == 'x' && tmp_str2[1] == 'x' && tmp_str3[0]== 'x')
    {
        result_player2 = "Petya won diag";
        return result_player2;
    }

    if (tmp_str1[0] == 'o' && tmp_str2[1] == 'o' && tmp_str3[2]== 'o')
    {
        result_player1 = "Vanya won diag";
        return result_player1;
    }
    if (tmp_str1[2] == 'o' && tmp_str2[1] == 'o' && tmp_str3[0]== 'o')
    {
        result_player2 = "Vanya won diag";
        return result_player2;
    }
    return result;
}

std::string result_check(std::string tmp_str1, std::string tmp_str2, std::string tmp_str3)
{
    std::string result = "Nobody";
    if(check_line(tmp_str1, tmp_str2, tmp_str3) != "Nobody") return check_line(tmp_str1, tmp_str2, tmp_str3);
    if(check_vertical(tmp_str1, tmp_str2, tmp_str3) != "Nobody") return check_vertical(tmp_str1, tmp_str2, tmp_str3);
    if(check_diagonal(tmp_str1, tmp_str2, tmp_str3) != "Nobody") return check_diagonal(tmp_str1, tmp_str2, tmp_str3);
    return result;
}


int main()
{
    std::string str1 = input(), str2 = input(), str3 = input();
    std::string result;
    std::cout << std::endl << str1 << "\n" << str2 << "\n" << str3 << "\n";
    result = result_check(str1, str2, str3);
    std::cout << result;
}
