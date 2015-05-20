#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <ctype.h>
using namespace std;

int myAtoi(string str){

    if(str.length() == 0) return 0;

    string Max = "+2147483647";//pos
    string Min = "-2147483648";//neg
    int Max_len = Max.length();
    int Min_len = Min.length();

    string curInteger;
    
	int result = 0;
    /*如果这里result设置为long long型的，
      则可以直接通过比较与INT_MAX/INT_MIN的大小来确定返回指超出范围了
      就不需要两个string Max / Min
      */

	unsigned i = 0;

	for(; isspace(str[i]); str++);

    if(str[i] == '-' || str[i] == '+'){
        curInteger.push_back(str[i++]);
    }else{
        curInteger.push_back('+');
    }
    if( !isdigit(str[i]) ){
        return 0;
    }
    
    while(isdigit(str[i]) && i < str.length()){
        curInteger.push_back(str[i++]);
    }
    
    if(curInteger[0] == '+'){
        if(curInteger.length() > Max_len){
            return INT_MAX;
        }
        else if(curInteger.length() == Max_len)
        {
            if(curInteger.compare(Max) >= 0)
            {
                return INT_MAX;
            }
        }
        for(int coefIndex = 1, deg = curInteger.size()-2; coefIndex < curInteger.size(); ++coefIndex, deg--){
            result += (curInteger[coefIndex]-'0') * pow(10, deg);
        }

    }
    else{ // '-'
        cout << "in - :" << endl;
        if(curInteger.length() > Min_len){
            return INT_MIN;
        }
        else if(curInteger.length() == Min_len)
        {
            if(curInteger.compare(Min) >= 0)
            {
                return INT_MIN;
            }
        }
        for(int coefIndex = 1, deg = curInteger.size()-2; coefIndex < curInteger.size(); ++coefIndex, deg--){
            cout << curInteger[coefIndex] << " ";
            result += (curInteger[coefIndex]-'0') * pow(10, deg);
        }
        result = -result;

    }
    return result;

}


int main(int argc, const char *argv[])
{
	cout << myAtoi("-2147483647");

    return 0;
}
