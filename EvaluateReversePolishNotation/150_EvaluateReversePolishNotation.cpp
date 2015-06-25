#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isOperator(const string &op){
    return op.size()==1 && string("+-*/").find(op) != string::npos;
}

int evalRPN(vector<string>& tokens) {
    stack<string> s;
    for(int i = 0; i < tokens.size(); ++i){
        if(!isOperator(tokens[i])){
            s.push(tokens[i]);
        }else{ //warning: 注意a,b的顺序
            int b = stoi(s.top());
            s.pop();
            int a = stoi(s.top());
            s.pop();
            if(tokens[i][0] == '+') a += b;
            else if(tokens[i][0] == '-') a -= b;
            else if(tokens[i][0] == '*') a *= b;
            else                         a /= b;
            s.push(to_string(a));
        }
    }
    return stoi(s.top());
}


int main(int argc, const char *argv[])
{
    vector<string> v;
    v.push_back("0");
    v.push_back("3");
    v.push_back("/");
    cout << evalRPN(v);

    return 0;
}
