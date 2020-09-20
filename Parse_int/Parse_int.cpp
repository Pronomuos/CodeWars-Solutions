#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

long parse_int (std::string number) {

    const char* c_string = number.c_str();
    char del [] = {' ', '-'};
    char *token = strtok((char*) c_string, del);
    vector<string> tokens;
    while (token != nullptr) {
        tokens.emplace_back(token);
        token = strtok(nullptr, del);
    }

    int total = 0, sub_total = 0;

    for (const auto & tok : tokens) {

        if (tok == "one")
            sub_total += 1;
        else if (tok == "two")
            sub_total += 2;
        else if (tok == "three")
            sub_total += 3;
        else if (tok == "four")
            sub_total += 4;
        else if (tok == "five")
            sub_total += 5;
        else if (tok == "six")
            sub_total += 6;
        else if (tok == "seven")
            sub_total += 7;
        else if (tok == "eight")
            sub_total += 8;
        else if (tok == "nine")
            sub_total += 9;
        else if (tok == "ten")
            sub_total += 10;
        else if (tok == "eleven")
            sub_total += 11;
        else if (tok == "twelve")
            sub_total += 12;
        else if (tok == "thirteen")
            sub_total += 13;
        else if (tok == "fourteen")
            sub_total += 14;
        else if (tok == "fifteen")
            sub_total += 15;
        else if (tok == "sixteen")
            sub_total += 16;
        else if (tok == "seventeen")
            sub_total += 17;
        else if (tok == "eighteen")
            sub_total += 18;
        else if (tok == "nineteen")
            sub_total += 19;
        else if (tok == "twenty")
            sub_total += 20;
        else if (tok == "thirty")
            sub_total += 30;
        else if (tok == "forty")
            sub_total += 40;
        else if (tok == "fifty")
            sub_total += 50;
        else if (tok == "sixty")
            sub_total += 60;
        else if (tok == "seventy")
            sub_total += 70;
        else if (tok == "eighty")
            sub_total += 80;
        else if (tok == "ninety")
            sub_total += 90;
        else if (tok == "hundred")
            sub_total *= 100;
        else if (tok == "thousand") {
            sub_total *= 1000;
            total += sub_total;
            sub_total = 0;
        }
        else if (tok == "million") {
            sub_total *= 1000000;
            total += sub_total;
            sub_total = 0;
        }
    }

    total += sub_total;
    return total;
}
