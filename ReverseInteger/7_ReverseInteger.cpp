class Solution {
    public:
    int reverse(int x){
            //这里要用long long型；只用long是不够的；
            //因为有符号的long的范围不够
            long long result = 0;
            long long tmp_x = x;
            int neg = 0;
        
            if (tmp_x < 0){
                        neg = 1;
                        tmp_x = -tmp_x;
                    }
        
            while (tmp_x){
                        int digit = tmp_x % 10;
                        result = (result * 10 + digit);
                        tmp_x /= 10;
                    }
        
            if (result > INT_MAX) return 0;
        
            return neg == 0 ? (int)result : -(int)result;
        }

};
