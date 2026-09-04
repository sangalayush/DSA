#include <iostream>
#include<vector>
using namespace std;
//using brute-force approach
void sortarray(vector<int> &nums){
    int count0=0,count1=0,count2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)  count0++;
        else if(nums[i]==1) count1++;
        else                count2++;
    }
    for(int i=0;i<count0;i++)   nums[i]=0;
    for(int i=count0;i<count0+count1;i++)   nums[i]=1;
    for(int i=count0+count1;i<nums.size();i++)  nums[i]=2;
}
//T.C.->O(N+N)->O(2N)
//S.C.->O(1)
//------------------------------------------------------------------------
//using optimal approach(Dutch National flag algorithm)
void sortarray(vector<int> &nums){
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++, low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
}
//T.C.->O(N)
//S.C.->O(1)
int main()
{
    vector<int> nums={1,1,2,0,1,2,2,2,0,2,1};
    sortarray(nums);
    for(auto it: nums){
        cout<<it<<" ";
    }
    return 0;
}
