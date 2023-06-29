#include<bits/stdc++.h>
using namespace std;

int main()
{
    string startWord, targetWord;
    cin>>startWord>>targetWord;
    int n; cin>>n;
    vector<string> wordList(n);
    for(int i=0;i<n;i++)
    cin>>wordList[i];

    queue<pair<string, int>> q;
    q.push({startWord, 1});

    unordered_set<string> st (wordList.begin(), wordList.end());
    st.erase(startWord);

    while(!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetWord)
        {
            cout<<steps<<"\n";
            return 0;
        }

        for(int i=0;i<word.size();i++)
        {
            char original = word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word, steps+1});
                }
                word[i] = original;
            }
        }
    }
    return 0;
}

/*
IP
hit cog
6
hot dot dog lot log cog
OP
5
*/