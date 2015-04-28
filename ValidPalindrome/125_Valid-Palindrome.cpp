/********************************************************************************** 
* 
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*
* 回文
* 
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
* 
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
* 
* For the purpose of this problem, we define empty string as valid palindrome.
* 
*               
**********************************************************************************/

/*transform函数
* isalnum
* prev 
tolower 不在std命名空间下*/

class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower); //一定要加::tolower这是why？
        auto left = s.begin();
        auto right = std::prev(s.end());
        while(left < right){
            if( !(std::isalnum(*left)) ) left++;
            else if( !(std::isalnum(*right)) ) right--;
            else if(*right != *left) return false;
            else left++, right--;
        }
        return true;
    }
};