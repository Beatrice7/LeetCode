/********************************************************************************** 
* 
* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
* compute how much water it is able to trap after raining. 
* 
* For example, 
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*   
*     ^                                             
*     |                                             
*   3 |                       +--+                  
*     |                       |  |                  
*   2 |          +--+xxxxxxxxx|  +--+xx+--+         
*     |          |  |xxxxxxxxx|  |  |xx|  |         
*   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+      
*     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |      
*   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
*       0  1   0  2  1   0  1  3  2  1  2  1        
* 
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
* 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*               
**********************************************************************************/

class Solution {
public:
	int trap(int A[], int n){
		int p1 = 0, p2 = 0, units = 0;
		//列首为0的元素过滤掉
		while(A[p1] == 0 && p2 != n) ++p1, p2 = p1 + 1;

		while(p1 < n){
		    //直到A[i]>A[p1]或者队列结束为止
		    while(A[p2] <= A[p1] && p2 != n) ++p2;
		    if(p2 == n){
		        int par = p1 + 1;
		        int tmpMax = searchMax(par, n, A);//这里par的值会改变
		        for(int j = p1 + 1; j < par; ++j){
		            units +=  (tmpMax - A[j]);
		        }
		        p1 = par;
		    }else{
		        for(int j = p1 + 1; j < p2; ++j){
		            units +=  (A[p1] - A[j]);
		        }
		        p1 = p2;
		    }
		    p2 = p1 + 1;
		}
		return units;
	}

    int searchMax(int &par, int len, int A[]){
	    int max = 0;
	    for(int i = par; i < len; ++i)
	        if(A[i] > max) max = A[i], par = i;
	    return max;
	}
};
