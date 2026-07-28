#include<iostream>
#include<vector>
using namespace std;
void merge(std::vector<int> &arr,int low,int mid,int high){
    std::vector<int> temp={} ;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(std::vector<int> &arr,int low,int high){
    if(low==high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    std::vector<int> arr={1,2,5,3,4} ;
    int low=0, high=arr.size()-1;
    mergesort(arr,low,high);
    for(int x:arr){
        cout<<x<<" "<<endl;
    }
    return 0;
}
