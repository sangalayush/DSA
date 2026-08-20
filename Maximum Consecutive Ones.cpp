#include <iostream>
#include<vector>
using namespace std;
int consecutiveones(vector<int> &nums){
    int cnt=0, maxi=0;
    for(int i=0;i<nums.size();i++){
    if(nums[i]==1)
        cnt++;
    else
        cnt=0;
    maxi= max(maxi,cnt);
    }
    return maxi;
}
//T.C.->O(N)
//S.C.->O(1)
int main(){
    vector<int> nums={1,1,0,1,1,1};
    int ans= consecutiveones(nums);
    cout<<ans<<endl;
    return 0;
}
