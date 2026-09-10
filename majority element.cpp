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
//T.C.->O(N*N)
//S.C.->O(1)
//------------------------------------------------------------------------
#include<unordered_map>
using namespace std;
//Better approach
int majorityelement(vector<int> nums){
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;             //store all the elements in mpp
                                    // number->feq
                                    //key->value
    }
    //now check through the map the maximum element
    for(auto it:mpp){
        if(it.second>nums.size()/2){
            return it.first;
        }
    }
    return -1;
}
//T.C.->O(N)
//S.C.->O(N)
//--------------------------------------------------------------------------
//Optiaml  approach->using moore's voting algorithm
int majorityelement(vector<int> nums){
    int cnt=0, ele=0;
    for(int i=0;i<nums.size();i++){
        if(cnt==0){
            cnt=1;
            ele=nums[i];
        }
        else if(nums[i]==ele){
            cnt++;
        }
        else
            cnt--;
    }
    //check if it is actually the majorityelement
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==ele)
            count++;
    }
    if(count>nums.size()/2)
        return ele;
    return -1;
}
//T.C.->O(N)
//S.C.->O(1)
int main()
{
    vector<int> nums={2,2,1,5,5,1,5,5,2,5,5,5};
    cout<<majorityelement(nums);
    return 0;
}
