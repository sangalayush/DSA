#include<iostream>
#include<vector>
using namespace std;
//brute-force approach
void rightrotatebyk(vector<int> &arr, int k)
{
    //empty array or no rotation
    if(arr.size()==0||k==0) return;
    //if k>n
    k =k%arr.size();
    //store the right k elements in temp array
    vector<int> temp(k);
    for(int i=arr.size()-k;i<arr.size();i++)
    {
        temp[i-arr.size()+k]=arr[i];
    }
    //shift n-k elements of starting to right
    for(int i=arr.size()-k-1;i>=0;i--)
    {
        arr[i+k]=arr[i];
    }
    //push back temp elements to array
    for(int i=0;i<k;i++)
    {
        arr[i]=temp[i];
    }
} 
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int k=19;
    rightrotatebyk(arr,k);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
