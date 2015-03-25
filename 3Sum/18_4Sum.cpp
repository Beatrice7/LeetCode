class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        if(num.size() < 4) return result;
        int n = num.size();
        for(int i = 0; i < n-3; ++i){
            for(int j = i + 1; j < n-2; ++j){
                int k = j+1;
                int m = n-1;
                while(k < m){
                    int sum = num[i] + num[j] + num[k] + num[m];
                    if(sum < target) {++k;}
                    else if(sum > target) {--m;}
                    else{
                        result.push_back({num[i], num[j], num[k], num[m]});
                        ++k;
                        --m;
                        while(num[k] == num[k-1]) ++k;
                        while(num[m] == num[m+1]) --m;
                    }
                }
            
            }
        
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
        
    }
 
};
