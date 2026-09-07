#include <iostream>
#include<vector>
#include<string>
using namespace std;
//using Brute-force approach 
string reversewords(string s){
    vector<string> words;
    string word="";
    string result="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){          //add the character of the string to the word until we encounter  a spoce
            word+=s[i];
        }
        else if(!word.empty()){ // if space found & also word not empty then add word to the list words
                                // else it will  ignore the trailing and ending spaces and also middle spaces
            words.push_back(word);
            word="";                    //when one word is pushed to the list then do word again as empty
                                        // and move to the next character to collect it
        }
    }
    if(!word.empty())
        words.push_back(word);          // if the last word of the string is left and the iteation finishes 
                                        //then add it also to the list
    for(int i=words.size()-1;i>=0;i--){     //reverse order me rresult string me words ko add krdenge
        if(!result.empty())
            result+=" "+words[i];
        else
            result+= words[i];
    }
    return result;
}
int main()
{
    string s="Hey! man this was easy";
    string ans=reversewords(s);
    cout<<ans;
    return 0;
}
