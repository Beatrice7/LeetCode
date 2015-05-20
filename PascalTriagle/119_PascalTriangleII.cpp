#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex){
    //improve edition
    vector<int> curIndexRow;
    curIndexRow.resize(rowIndex + 1, 1);

    for(int i = 0; i < rowIndex + 1; ++i)
    {
        //curIndexRow[0] = curIndexRow[i] = 1;    
        for(int j = i-1; j > 0; --j){
            curIndexRow[j] = curIndexRow[j - 1]  + curIndexRow[j];
        }
    }
    return curIndexRow;
}

int main(int argc, const char *argv[])
{
    vector<int> m;
    m = getRow(3);
    
    for(auto &item: m){
            cout << item;
    }
    
    return 0;
}
