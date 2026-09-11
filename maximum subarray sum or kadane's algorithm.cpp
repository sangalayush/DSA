#include<bits/stdc++.h>
using namespace std;
//brut-force approach
int maximumsubarraysum(vector<int> nums){
    int maxi= INT_MIN;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=nums[k];
            }
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
//T.C.->O(N^3)
//S.C.->O(1)
//---------------------------------------------------------------
//Better approach
int maximumsubarraysum(vector<int> nums){
    int maxi= INT_MIN;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+= nums[j];
            maxi= max(sum,maxi);
        }
    }
    return maxi;
}
//T.C.->O(N^2)
//S.C.->O(1)
//----------------------------------------------------------------
//Optimal approach->using kadane's algorithm
int maximumsubarraysum(vector<int> nums){
    int maxi= INT_MIN;
    int sum=0;      //initialize sum as 0
    for(int i=0;i<nums.size();i++){
       sum+= nums[i];               // increment the sum by nums[i] value
       maxi= max(sum,maxi);         //update the maxi if sum>previous maxi
       if(sum<0)                    //if sum<0 leave the sum
        sum=0;                      //and put sum to 0 bcs adding -ve values to sum dec. the sum value
    }
    return maxi;
}
//T.C.->O(N)
//S.C.->O(1)
int main()
{
    vector<int> nums={-2, -3, -7, -2, -10, -4};
    cout<<maximumsubarraysum(nums);
}
//Print the subaaray
#include<bits/stdc++.h>
using namespace std;
//Optimal approach->using kadane's algorithm
int maximumsubarraysum(vector<int> nums){
    int maxi= INT_MIN;
    int sum=0;      //initialize sum as 0
    int ansstart=-1, ansend=-1;
    int start=0;
    for(int i=0;i<nums.size();i++){
        if(sum==0)
            start=i;
       sum+= nums[i];               // increment the sum by nums[i] value
       if(sum>maxi){
        maxi=sum;               //update the maxi if sum>previous maxi
        ansstart= start;
        ansend=i;
       }
       if(sum<0)                    //if sum<0 leave the sum
        sum=0;                      //and put sum to 0 bcs adding -ve values to sum dec. the sum value
    }
    //print the subarray that has the maximum sum
    for(int i=ansstart;i<=ansend;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return maxi;
}
//T.C.->O(N)
//S.C.->O(1)
int main()
{
    vector<int> nums={2, 3, 5, -2, 7, -4};
    cout<<maximumsubarraysum(nums);
}
