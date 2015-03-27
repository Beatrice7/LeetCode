/***************************************
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*****************************************/

class Solution {
public:   
    /*暴力方法超时
    string getPermutation(int n, int k) {
        vector<int> v;
        for(int i = 1; i <= n; ++i){
            v.push_back(i);
        }
        while(--k){
            next_permutation(v.begin(), v.end());   
        }
        string s = "";
        for(auto it = v.begin(); it < v.end(); ++it) s+=(*it+'0');
        return s;
    }
    */
    
    /*暴力方法超时
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; ++i)
            s[i] += i+1;
        for (int i = 0; i < k-1; ++i)
            next_permutation(s.begin(), s.end());
        return s;
    }*/
    
    string getPermutation(int n, int k) {
        string s;
        if(n == 1) return s += (n+'0');
        vector<int> seq;
        for(int i = 1; i <= n; ++i){
            seq.push_back(i);
        }
        int size = seq.size();
        int an , kn;
        /*编码从0开始的，所以别忘了减1
        比如seq[1,2,3,4]，
        如果k=6, 那么第一个数的编码应该为5/(3!) => 0,也就是第一位为seq[0] = 1
        如果忘了k--， 那么求出的第一个数的编码为6/(3!) => 1, 则变为seq[1] = 2，得出的结果就错了!
        */
        k--; 
        for(int j = 1; j < size; ++j){
            kn = k / factorial(size-j);
            an = k % factorial(size-j);
            s += seq[kn] + '0';
            seq.erase(seq.begin() + kn);
            k = an;
        }
        //直接将最后字符加入队尾，减少一次循环
        s += seq[0] + '0';
        return s;
        
    }
    
private:
    int factorial(int n){
        int result = 1;
        for(int i = 1; i <= n; ++i){
            result *= i;
        }
        return result;
    }
    
    

};




