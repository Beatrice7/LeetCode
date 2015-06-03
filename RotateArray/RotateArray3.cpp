#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * How to change [0,1,2,3,4,5,6] to [4,5,6,0,1,2,3] by k = 3?
 *
 * We can change by following rules: 
 *
 *     [0]->[3], [3]->[6], [6]->[2],  [2]->[5], [5]->[1], [1]->[4]
 *    
 *
 */

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    int curIndex = 0, newIndex = curIndex + k % len;
    int tmp1 = nums[curIndex], tmp2;
    int originIndex = 0;
    for(int i = 0; i < len; ++i){        
        tmp2 = nums[newIndex];
        nums[newIndex] = tmp1;
        tmp1 = tmp2;

        curIndex = newIndex;
        //newIndex = curIndex + k % len;
        //newIndex = (curIndex + k) % len;
    
        if(originIndex == curIndex){
            originIndex = ++curIndex;
            tmp1 = nums[curIndex];
        }
        newIndex = (curIndex + k) % len;//这句一定要放在if后面，当curIndex改变了，newIndex也变了
        
        
    }
}


int main(int argc, const char *argv[])
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
/*  a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
*/
    rotate(a, 2);

    for(vector<int>::iterator it = a.begin(); it != a.end(); ++it){
        cout << *it << endl;    
    }
    return 0;
}
