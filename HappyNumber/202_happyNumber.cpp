#include <iostream>
#include <set>
#include <map>
using namespace std;
int toSum(int, map<int, int>);

bool isHappy(int n){
    map<int, int> squares;
    for(int i = 0; i < 10; ++i){
        squares[i] = i*i;
    }

    set<int> haveshown;
    int sum = n;
    while(sum != 1){
            sum = toSum(sum, squares);
    //        cout << "sum" <<  sum <<endl;
            if(haveshown.find(sum) != haveshown.end()){
                return false;
            }else{
                haveshown.insert(sum);
            }
    }
    
    return true;

}

int toSum(int n, map<int, int> squares){
    int sum = 0;
    while(n){
        sum += squares[n % 10];
        n /= 10;
    }
    return sum;
}




int main(int argc, const char *argv[])
{
    cout << isHappy(3);

    return 0;
}
