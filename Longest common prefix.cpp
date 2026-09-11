#include<bits/stdc++.h>
using namespace std;
//Optimal approach
string commonprefix(vector<string> s){
    string result="";
    sort(s.begin(),s.end());
    string first=s[0];
    string last=s[s.size()-1];
    int minlength= min(first.size(),last.size());
    for(int i=0;i<minlength;i++){
        if(first[i]!=last[i])
            break;
        else
            result+=first[i];
    }
    return result;
}
//T.C.->O(NlogN+M)-> N is the size of input string aray and M is the minimum length of a string
//S.C.->O(M)->in worst case the string might store upto M length
int main()
{
    vector<string> s={"flower", "flow", "flight"};
    cout<<commonprefix(s);
}
