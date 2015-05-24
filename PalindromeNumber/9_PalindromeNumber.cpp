#include <iostream>
#include <string>
#include <vector>
using namespace std;
int reverse(int x);

bool isPalindrome(int x) {
    return (x>=0 && x == reverse(x));  
}

int reverse(int x) {
    int y=0;

    int n;
    while( x!=0 ){
        n = x%10;
        y = y*10 + n;
        cout << y << endl;
        x /= 10;
    }
    return y;//这里就算y超过了int的范围也无所谓，因为返回的结果肯定与x不等
}


/********************************************************/
bool my_isPalindrome(int x) {
    if(x < 0) return false;
    long long reverseInteger = 0;
    int origin = x;
    while(x){
        int cur = x % 10;
        x /= 10;
        reverseInteger = reverseInteger * 10 + cur;
        if(reverseInteger > INT_MAX){
            return false;
        }
    }
    if(reverseInteger == origin) return true;
    else return false;
}

int main(int argc, const char *argv[])
{
    isPalindrome(2147483647);
    return 0;
}
