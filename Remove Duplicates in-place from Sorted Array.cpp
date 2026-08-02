//Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.
//If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It doesn't matter what you leave beyond the first k elements.
Code:-
#include<iostream>
#include<vector>
#include<set>
using namesapce std;
//using the brute-force approach
int removeduplicates(std::vector<int> & arr)
{
  set<int> st;    //declaring an set 
  for(int i=0;i<arr.size();i++)      //if arr[]={1,1,2,2,2,3,3,3}
  {
      st.insert(arr[i]);    //it will only insert unique elements inside the set,,then set will contain only {1,2,3}
  }
//T.C. of inseting will be O(NlogN)
  int index=0;
  for(auto it:st)
  {
      arr[index]=it;    //this will put the unique elements in the arraay from the stack.
      index++;          //increment the index for the next position to be inserted.
  }
  //T.C. of this will be O(N).
  return index;
}
int main()
{
    std::vector<int> arr={1,1,2,2,2,3,3};
    int result= removeduplicates(arr);
    cout<<"Total unique elements: "<<result<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
//using the optimal approach
int removeduplicates(std::vector<int> &arr)
{
    //as we have to do the removing of duplicate elements in the same array.
    int i=0;
    for(int j=1;j<arr.size();j++)
    {
        if(arr[j]!=arr[i])      //this will check if there is any element that is unique from the ith element
        {
            arr[i+1]=arr[j]; //then it will put the unique element infront of i.
            i++;        //and i will get updated.
        }
    }
    return i+1;     //this will return number of unique elements in array, as i will be the index so +1 is required for elements.
    //T.C. will be O(N).
    //S.C. will be O(1).
    
}
int main()
{
    std::vector<int> arr={1,2,3,3,4,4,5,5};
    int result= removeduplicates(arr);
    cout<<"Total unique elements: "<<result<<endl;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";  //it doesn't matter what it will return beyond returning result unique elemnts.
    }
    return 0;
}
