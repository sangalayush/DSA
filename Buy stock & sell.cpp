#include <iostream>
#include<vector>
using namespace std;
//brute-force
int buysellstock(vector<int> nums){
    int maxprofit=0, profit=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            profit= nums[j]-nums[i];
            maxprofit= max(maxprofit,profit);
        }
    }
    return maxprofit;
}
//T.C.->O(N*N)
//S.C.->O(1)
//----------------------------------------------------------------
//optimal
int buysellstock(vector<int> nums){
    int mini=nums[0], maxprofit=0, profit=0;
    for(int i=1;i<nums.size();i++){
        profit= nums[i]-mini;
        maxprofit= max(maxprofit, profit);
        mini= min(mini,nums[i]);
    }
    return maxprofit;
}
//T.C.->O(N)
//S.C.->O(1)
int main()
{
    vector<int> nums={7,1,5,3,6,4};
    cout<<buysellstock(nums);
    return 0;
}
