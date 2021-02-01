#include <iostream>
#include <string>

std::string input()
{
    std::string output = "false";
    while(output == "false")
    {
        std::string n;
        bool answer = true;
        int digit = 0;
        int dot = 0;
        int minus = 0;

        std::cout << "\n\nType the number > ";
        std::cin >> n;

        //Counting the content of the string
        for(int i = 0; i < n.length(); i++){
            if (n[i] >= '0' && n[i] <= '9') digit += 1;
            if (n[i] == '-') minus += 1;
            if (n[i] == '.') dot += 1;
        }

        //Check if INPUT is OK
        if (minus>1 || dot>1) answer = false;
        else if (minus == 1 && n[0] != '-') answer = false;
        else if (digit == 0) answer = false;
        
        //Print the answer
        if(answer) output = n;
        else{
            std::cout << "ERROR";
        }
    }
    return output;
}


int main()
{
    std::string n1 = input(), n2 = input();

    if(stof(n1) > stof(n2)) std::cout << "More";
    if(stof(n1) < stof(n2)) std::cout << "Less";
    if(stof(n1) == stof(n2)) std::cout << "Equal";

    return 0;
}
