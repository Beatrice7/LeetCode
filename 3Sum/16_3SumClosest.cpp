class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        auto last = num.end();
        int dis = INT_MAX;
        int result;
        for(auto i = num.begin(); i < prev(last, 2); ++i){
            auto j = next(i);
            auto k = last-1;
            
            while(j < k){
                int sum = *i + *j + *k;
                int tmp;
                if(sum > target) --k;
                else if(sum < target) ++j;
                else return target;
                
                if(dis > abs(target-sum)){
                        result = sum;
                        dis = abs(target-sum);
                    }   
            }
            
        }
        return result;
    }
};
