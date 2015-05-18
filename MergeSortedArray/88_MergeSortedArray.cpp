class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();
        nums1.assign(p1, p1+m);
        nums2.assign(p2, p2+n);
      
        while(p1 != nums1.end() && p2 != nums2.end()){
            if(*p1 <= *p2) p1++;
            else{
                p1= nums1.insert(p1, *p2);
                p1++;
                p2++;
            } 
        }
    
        if(p1 == nums1.end()){
            while( p2!=nums2.end() ) nums1.push_back(*p2), p2++;
        }
        return;
   
    }
};


    
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ia = m-1, ib = n-1, icur = m+n-1;
        while(ia >=0 && ib >= 0){
            nums1[icur--] = nums1[ia] > nums2[ib] ? nums1[ia--] : nums2[ib--];
        }
        while(ib >= 0){
            nums1[icur--] = nums2[ib--];
        }
        return;
    }
};
