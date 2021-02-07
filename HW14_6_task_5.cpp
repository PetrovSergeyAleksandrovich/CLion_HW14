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

std::string conversion(std::string x)
{
    std::string tmp;

    if(x[0] == '-') tmp.push_back('0');
    else tmp.push_back('1');



    for(int i = 0; x[i] != '\0';)
    {
        if(x[i] == '0' || x[i] == '-')
        {
            i++;
            continue;
        }
        else
        {
            for(int j = i; x[j] != '.'; j++)
            {
                tmp.push_back(x[j]);
                i++;
            }
        }

        if(x[i] == '.')
        {
            for(int j = i; x[j] != '\0'; j++)
            {
                tmp.push_back(x[j]);
                i++;
            }
        }
    }

    return tmp;
}

std::string comparison(std::string x, std::string y)
{
    std::string result = "Equal";

    //check if equal
    if(x == y) return result;

    //check for any zeros
    bool IsX = false;
    bool IsY = false;
    for(int i = 1; x[i] != '\0'; i++)
    {
        if(x[i] == '.') continue;
        if(x[i] != '0') IsX = true;
    }
    for(int i = 1; y[i] != '\0'; i++)
    {
        if(y[i] == '.') continue;
        if(y[i] != '0') IsY = true;
    }
    if(!IsX && !IsY) return result;

    //check sign
    if(x[0] > y[0]) { result = "More"; return result;}
    if(x[0] < y[0]) { result = "Less"; return result;}

    //check if both positive
    if(x[0] == '1'){
        for(int i = 1; ; i++)
        {
            if(x[i] == y[i]) continue;

            if(x[i] > y[i]) { result = "More"; return result;}
            if(x[i] < y[i]) { result = "Less"; return result;}

            if(x[i] >= '0' && x[i] <= '9' && y[i] == '\0') { result = "More"; return result;}
            if(x[i] == '\0' && y[i] >= '0' && y[i] <= '9') { result = "Less"; return result;}
        }
    }

    //check if both negative
    if(x[0] == '0'){
        for(int i = 1; ; i++)
        {
            if(x[i] == y[i]) continue;

            if(x[i] < y[i]) { result = "More"; return result;}
            if(x[i] > y[i]) { result = "Less"; return result;}

            if(x[i] >= '0' && x[i] <= '9' && y[i] == '\0') { result = "Less"; return result;}
            if(x[i] == '\0' && y[i] >= '0' && y[i] <= '9') { result = "More"; return result;}
        }
    }
}


int main()
{
    std::string x = input();
    std::string y = input();
    x = conversion(x);
    y = conversion(y);

    std::cout << comparison(x, y);

    return 0;
}
