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
//--------------------------------------------------------------------------------------------------------
#include<unordered_map>
using namespace std;
//Better approach
vector<int> twosum(vector<int> &nums, int target){
    unordered_map<int,int> mpp;       // T.c. of unordered_map is O(1) in best & avg.case
                                    //  T.C. of a ordered map is always logN
    for(int i=0;i<nums.size();i++){
        int curr= nums[i];
        int more= target-curr;
        if(mpp.find(more) != mpp.end()){
            return {mpp[more],i};
            //or return "yes"
        }
        mpp[curr]=i;
    }
    return {-1,-1};
    //or return "No"
}
//T.C.->O(N)
//.S.C.->O(N)
