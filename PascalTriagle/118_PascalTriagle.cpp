#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows){
    vector<vector<int> > PascalTriangle;
    vector<int> tmpvec;
    if(numRows >= 1) {
        vector<int> tmpvec;
        tmpvec.push_back(1);
        PascalTriangle.push_back(tmpvec);
    }if(numRows >= 2) {
        vector<int> tmpvec;
        tmpvec.push_back(1);
        tmpvec.push_back(1);
        PascalTriangle.push_back(tmpvec);
    }
    if(numRows >= 3) {
        for(int i = 3; i <= numRows; ++i){
            vector<int> tmp;
            tmp.push_back(1);
            for(int j = 0; j < i-2; ++j){
                tmp.push_back(PascalTriangle[i-2][j] + PascalTriangle[i-2][j+1]);
            }
            tmp.push_back(1);
            PascalTriangle.push_back(tmp);
        }
    }

    return PascalTriangle;
}

int main(int argc, const char *argv[])
{
    vector< vector<int> > m;
    m = generate(2);
    
    for(auto &item: m){
            for(auto &it: item){
                    cout << it << " ";
            }
            cout << endl;
    }
    
    return 0;
}
