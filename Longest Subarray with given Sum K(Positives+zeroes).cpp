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
//-----------------------------------------------------------------------------------
//Optimal approach
int longestsubarray(vector<int> &nums,int k){
    int sum=0, maxlen=0;
    int left=0, right=0;
    while(right<nums.size()){
        sum+=nums[right];
        if(sum==k)
            maxlen= max(maxlen,right-left+1);
        while(left<right && sum>k){
            sum-= nums[left];
            left++;
        }
        right++;
    }
    return maxlen;
}
//T.C.->O(N+N)  -> bcs the first while loop will run till N times & the 
                // inner while loop will almost run N times 
//S.C.->O(1)
int main(){
    vector<int> nums={2,3,1,1,1,1,2,5,4};
    int k=6;
    cout<<longestsubarray(nums,k);
    return 0;
}
