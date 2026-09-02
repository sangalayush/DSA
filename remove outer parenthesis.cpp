#include <iostream>
#include<string>
using namespace std;
string removeparenthesis(string &s, string &result){
    int cnt=0;
    for(char ch:s){
        if(ch == '('){
            if(cnt>0)   
                result+= ch;
            cnt++;
        }
        else{
            cnt--;
            if(cnt>0)
                result+= ch;
        }
    }
    return result;
}
//T.C.->O(N)
//S.C.->O(1)  result is used to return the the output
int main()
{
    string s="((()))";
    string result="";
    cout<<removeparenthesis(s,result);
    return 0;
}
