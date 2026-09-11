#include<bits/stdc++.h>
using namespace std;
//brut-force approach
int maximumsubarraysum(vector<int> nums){
    int maxi= INT_MIN;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=nums[k];
            }
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
//T.C.->O(N^3)
//S.C.->O(1)
//---------------------------------------------------------------
//Better approach
int maximumsubarraysum(vector<int> nums){
    int maxi= INT_MIN;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+= nums[j];
            maxi= max(sum,maxi);
        }
    }
    return maxi;
}
//T.C.->O(N^2)
//S.C.->O(1)
//----------------------------------------------------------------

int main()
{
    vector<int> nums={-2, -3, -7, -2, -10, -4};
    cout<<maximumsubarraysum(nums);
}
