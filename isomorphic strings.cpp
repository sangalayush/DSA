#include <iostream>
#include<vector>
using namespace std;
bool isomorphic(string s, string t){
    //declare two arrays to store the characters which have previously occured
     int m1[256]={0}, m2[256]={0};
    for(int i=0;i<s.size();i++){
        if(m1[s[i]]!=m2[t[i]])
            return false;
        m1[s[i]]=i+1;
        m2[t[i]]=i+1;
    }
    return true;
}
//T.C.->O(N)
//S.C.->O(1)->constant sized two arrays of 256 size used  
int main()
{
   
    string s="paper", t="title";
    if(isomorphic(s,t))
        cout<<"yes isomorphic"<<endl;
    else
        cout<<"not isomorphic"<<endl;
    return 0;
}
