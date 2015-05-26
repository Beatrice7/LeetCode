#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countAndSay(int n) {
    string res = "1";
    if(n == 1) return res;

    string cur;
    for(int i = 1; i < n; ++i){
        cur = res;
        res.clear();
        for(int j = 0; j < cur.size(); ){
            int count = 1;
            char tmp = cur[j];
            while(++j < cur.size() && cur[j-1] == cur[j]) {
                count++;
            }
            res += count + '0';
            res += tmp;
        }
    }
    return res;
}

int main(){
	cout << countAndSay(2) << endl;
	return 0;
}


