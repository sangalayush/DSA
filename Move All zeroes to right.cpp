#include<iostream>
#include<vector>
using namespace std;
//brute-force approach
void movezeroes(vector<int> &nums){
    vector<int>temp;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);    //store all non-zero elements in temp
        }
    }
    int non_zero= temp.size();      
    for(int i=0;i<non_zero;i++){    //if 7 non_zero elements then store till non_zero position
        nums[i]=temp[i];    // store all temp elements at starting of  nums..
    }
    for(int i=non_zero;i<nums.size();i++){
        nums[i]=0;      //from non_zero position put all elements as zero
    }
}
//T.C.--> O(N)+O(x)->x non_zero elements+ O(N-x)
//total->O(2N)
//S.C.->O(x)->O(N)-> if all elements are non_zero in nums array.
int main(){
    vector<int> nums={1,0,3,0,3,4,0,0,2,0,6};
    movezeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
//optimal approach
void movezeroes(vector<int> &nums){
    int j=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }
//T.C.-->O(x)
    if(j==-1) return;
    for(int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            int temp= nums[i];
            nums[i]=0;
            nums[j]=temp;
            j++;
            
        }
    }
}
//T.C.--> O(N-x)->bcz. we are traversing from forward of x
//total->O(x)+O(N-x)->O(N)
//S.C.->O(1)->constant space
int main(){
    vector<int> nums={1,0,3,0,3,4,0,0,2,0,6};
    movezeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
