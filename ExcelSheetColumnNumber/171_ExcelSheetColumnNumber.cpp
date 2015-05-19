#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int titleToNumber(string s)
{
    int sum = 0;
    int len = s.length();
    for(size_t i = 0; i < len; ++i)
    {
        int number = s.at(i) - 'A' + 1;
        sum += number * pow(26, len-i-1);
    }
    return sum;
}


int main(int argc, const char *argv[])
{
    cout << titleToNumber("AB");
    return 0;
}
