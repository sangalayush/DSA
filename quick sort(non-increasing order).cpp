#include<iostream>
#include<vector>
using namespace std;
int func(std::vector<int> &arr,int low,int high)
{
    int pivot=arr[high];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]>pivot && i<=high-1)
        {
            i++;
        }
        while(arr[j]<=pivot && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int temp1=arr[i];
    arr[i]=arr[high];
    arr[high]=temp1;
    return i;
}
void qs(std::vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int partition=func(arr,low,high);
        qs(arr,low,partition-1);
        qs(arr,partition+1,high);
    }
}

int main(){
    std::vector<int> arr={1,2,3,4,5};
    int low=0, high=arr.size()-1;
    qs(arr,low,high);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
