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
    }
    return maxlen;
}
int main()
{
    vector<int> nums={2,3,2,1,3,1,1,1,1,5,6};
    int k=6;
    cout<<longestsubarray(nums,k);
    return 0;
}
