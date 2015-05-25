#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int majorityElement(vector<int> &nums){
    map<int, int> m;
    for(auto &item: nums){
        if(++m[item] > int(nums.size() / 2)) 
            return item;
    }
    return 0;
}

vector<int> &split(const string &s, char delim, vector<int> &elems){
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)){
        elems.push_back(atoi(item.c_str()));
    }
    return elems;
}

int main(int argc, const char *argv[])
{
    vector<int> a;
    string array = "3,3,4";
    split(array, ',', a);
    cout << majorityElement(a);
    return 0;
}
