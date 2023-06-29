#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mpp;
vector<vector<string>> ans;
string b;

void dfs(string word, vector<string> &seq)
{
    if(word == b)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
     int sz = word.size();
     int steps= mpp[word];

        for(int i=0;i<sz;i++)
        {
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++)
            {
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word] +1==steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }
    }
vector<vector<string>> findLadder(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<string> q;
    b = beginWord;
    q.push(beginWord);

    mpp[beginWord]=1;
    int sz = beginWord.size();
    st.erase(beginWord);
    while(!q.empty())
    {
        string word = q.front();
        int steps = mpp[word];
        q.pop();
        if(word == endWord)
        break;

        for(int i=0;i<sz;i++)
        {
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.count(word))
                {
                    q.push(word);
                    st.erase(word);
                    mpp[word] = steps+1;
                }
            }
            word[i]=original;
        }
    }
    if(mpp.find(endWord)!=mpp.end())
    {
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
    }
    return ans;
}
bool comp(vector<string> a, vector<string> b)
{
    string x="", y="";
    for(string i : a)
        x+=i;
    for(string i: b)
        y+=i;
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

    vector<vector<string>> ans = findLadder(startWord, targetWord, wordList);
    if(ans.size() == 0)
    cout<<"-1"<<"\n";
    else
    {
        sort(ans.begin(), ans.end(), comp);
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
            cout<<"\n";
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
hit hot dot dog cog 
hit hot lot log cog
*/