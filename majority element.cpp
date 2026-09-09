#include <iostream>
#include<vector>
using namespace std;
//brute-force approach
int majorityelement(vector<int> nums){
    for(int i=0;i<nums.size();i++){
        int cnt=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]==nums[j]){
                cnt++;
            }
        }
        if(cnt>nums.size()/2)
            return nums[i];
    }
    return -1;
}

int main()
{
    vector<int> nums={2,2,1,5,5,1,5,5,2,5,5,5};
    cout<<majorityelement(nums);
    return 0;
}
