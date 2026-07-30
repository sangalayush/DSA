//bruteforce approach---> using sorting
//TC=O(NlogN+N)
#include<bits/stdc++.h>
using namespace std;
int findsecondlargest(std::vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        sort(arr.begin(),arr.end());        //sort the array
    }
    int largest=arr[arr.size()-1];      //take the largest element
    int slargest=-1;                //consider second largest as -1 if all the elements inside the array are positive &
                                    //if the elements in the array are negative then take slargest=INT_MIN
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>slargest && arr[i]!=largest)      //suppose arr=7,1,5,4,2,7
        {
            slargest=arr[i];
        }
    }
    return slargest;
}
int main()
{
    std::vector<int> arr={2,7,4,7,5,7,6} ;
    int ans=findsecondlargest(arr);
    cout<<"second largest: "<<ans<<endl;
    return 0;
}

//better approach--->without sorting
//TC=O(N+N)=O(2N)
#include<bits/stdc++.h>
using namespace std;
int findlargest(std::vector<int> &arr)
{
    int largest=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    return largest;
}
int findsecondlargest(std::vector<int> &arr)
{
    int largest=findlargest(arr);
    int slargest=-1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>slargest && arr[i]!=largest)
        {
            slargest=arr[i];
        }
    }
    return slargest;
}
int findsmallest(std::vector<int> &arr)
{
    int smallest=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<smallest)
        {
            smallest=arr[i];
        }
    }
    return smallest;
}
int findsecondsmallest(std::vector<int> &arr)
{
    int smallest=findsmallest(arr);
    int ssmallest=INT_MAX;    //this will take the largest number
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<ssmallest && arr[i]!=smallest)    //any number smaller than the INT_MAX will be upadted and it will be compared with the smallest number also
        {
            ssmallest=arr[i];
        }
    }
    return ssmallest;
}
int main()
{
    std::vector<int> arr={4,3,7,5,6,2,2,0,1} ;
    int ans=findsecondlargest(arr);
    int ans1=findsecondsmallest(arr);
    cout<<"second largest: "<<ans<<endl;
    cout<<"second smallest: "<<ans1<<endl;
    return 0;
}
