#include<iostream>
#include<vector>
using namespace std;
//Brute-force approach
void leftrotatebyk(vector<int> &arr, int k)
{
    k=k%arr.size();
    vector<int> temp(k);  //a temp array which will store first k elemnts
    for(int i=0;i<k;i++)
    {
        temp[i]=arr[i];
    }
    //left-shift n-k elements by k places
    for(int i=k;i<arr.size();i++)
    {
        arr[i-k]=arr[i];
    }
    //push back temp array at last of original array
    for(int i=arr.size()-k;i<arr.size();i++)
    {
        arr[i]=temp[i-arr.size()+k];
    }
}
//T.C--> O(k)+O(n-k)+O(k)-->bcz..storing k elemnts back
//total-->O(n+k)
//S.C.-->O(k)
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int k=3;
    leftrotatebyk(arr,k);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
//Optimal approach
void reverse(vector<int> &arr, int start, int end)
{
    while(start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
void leftrotatebyk(vector<int> &arr, int k)
{
    //empty array or no rotation
    if(arr.size()==0||k==0) return;
    else
    {
        //if k>n
        k= k % arr.size();
        reverse(arr,0,k-1);
        reverse(arr,k,arr.size()-1);
        reverse(arr,0,arr.size()-1);
    }
}
//T.C--> O(n)+O(n)+O(n)-->bcz..each reverse takes linear time
//total-->O(3N)= O(N)
//S.C.-->O(1)-->constant space
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int k=8;
    leftrotatebyk(arr,k);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
