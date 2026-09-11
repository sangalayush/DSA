#include<bits/stdc++.h>
using namespace std;
//Optimal approach
string largestoddno(string s){
    int end=-1;
    for(int i=s.length()-1;i>=0;i--){
        if((s[i]-'0')%2==1){
            end=i;
            break;
        }
    }
    int i=0;
    while(i<s.length() && s[i]=='0'){
        i++;
    }
    return s.substr(i,end-i+1);
}
//T.C.->O(N)
//S.C.->O(1)
int main()
{
    string s="06567";
    cout<<largestoddno(s);
}
