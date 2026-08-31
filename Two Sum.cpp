#include <iostream>
#include<vector>
using namespace std;
//Brute-force approach
vector<int> twosum(vector<int> &nums, int target){
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target)
                return {i,j};
                //Or we can return YES
        }
    }
    return {-1,-1};
    //Or we can return NO
}
//T.C.->O(N*N)
//.S.C.->O(1)
