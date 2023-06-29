#include<bits/stdc++.h>
using namespace std;

bool comp(vector<string> a, vector<string> b)
{
    string x="", y="";
    for(string i :a)
    x+=i;
    for(string j:b)
    y+=j;
    return x<y;
    
}
int main()
{
    string startWord, targetWord;
    cin>>startWord>>targetWord;
    int n; cin>>n;
    vector<string> wordList(n);
    for(int i=0;i<n;i++)
    cin>>wordList[i];

    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({startWord});

    vector<string> usedonLevel;
    usedonLevel.push_back(startWord);
    int level=0;

    vector<vector<string>> ans;


    while(!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        //erase
        if(vec.size()>level)
        {
            level++;
            for(auto it : usedonLevel)
            st.erase(it);
        }

        string word = vec.back();

        if(word == targetWord)
        {
            if(ans.size()==0)
            ans.push_back(vec);
            else if(ans[0].size()==vec.size())
            ans.push_back(vec);
        }

        for(int i=0;i<word.size();i++)
        {
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.count(word)>0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    vec.pop_back();
                    usedonLevel.push_back(word);
                }
            }
            word[i] = original;
        }
    }

    if(ans.size() == 0)
    cout<<"-1"<<"\n";
    else
    {
    sort(ans.begin(),ans.end(),comp);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
    }
}


/*
IP
hit cog
6
hot dot dog lot log cog
OP
hit hot dot dog cog 
hit hot lot log cog
*/