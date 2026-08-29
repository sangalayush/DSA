#include <iostream>
#include<vector>
using namespace std;
//brute-force approach
int longestsubarray(vector<int> &nums,int k){
    int sum=0, maxlen=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            sum+= nums[j];
            if(sum==k)
                maxlen=max(maxlen,j-i+1);
        }
        sum=0;
    }
    return maxlen;
}
//T.C.->O(N*N)
//S.C.->O(1)
