#include <iostream>
#include<vector>
#include<map>
using namespace std;
//Optimal approach
int longestsubarray(vector<int> &nums,int k){
    int sum=0, maxlen=0;
    map<int,int> prefixsum;
    for(int i=0;i<nums.size();i++){
        sum+= nums[i];
        if(sum==k)
            maxlen= max(maxlen,i+1);
        int rem= sum-k;
        if(prefixsum.find(rem)!= prefixsum.end()){
            int len= i- prefixsum[rem];
            maxlen= max(maxlen,len);
        }
        if(prefixsum.find(sum)== prefixsum.end()){
            prefixsum[sum]=i;
        }
    }
    return maxlen;
}
//T.C.->O(N*logN)
//S.C.->O(N)         //bcz. all the elements sum will be stored in the map..
int main(){
    vector<int> nums={1,1,2,2,3,1,1,1,1,2,-2,5,4};
    int k=4;
    cout<<longestsubarray(nums,k);
    return 0;
}
