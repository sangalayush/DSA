#include <iostream>
#include<vector>
using namespace std;
//brute-force approach
void findIntersection(vector<int> &nums1, vector<int> &nums2, vector<int> &ans){
    int i=0;
    int j=0;
    vector<int> vis(nums2.size());
    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j] && vis[j]==0){
                ans.push_back(nums1[i]);
                vis[j]++;
                break;
            }
            if(nums2[j]>nums1[i])   break;
        }
    }
}
//T.C.->O(n1*n2)
//S.C.->O(n2)->bcz. the length of visited array will be equal to the nums2 array.
int main()
{
    vector<int> ans;
    vector<int> nums1={1,2,2,3,3,4,5};
    vector<int> nums2={2,3,3,4,5,6};
    findIntersection(nums1,nums2,ans);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
