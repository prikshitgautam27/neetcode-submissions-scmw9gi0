class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        

        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        unordered_map<int,vector<string>>memo;
       return dfs(s,0,memo,dict);
        
    }

    vector<string> dfs(string &s,int start, unordered_map<int,vector<string>> &memo , unordered_set<string>&dict){

        if(memo.count(start)) return memo[start];// if start previously cheked
        vector<string>res ;

        if(start==s.size()){
            res.push_back("");
            return res;

        }

        for(int end=start+1 ; end <=s.size() ; end++){
            string word= s.substr(start, end-start);

            if(dict.count(word)){
                vector<string> sublist = dfs(s,end, memo , dict) ;
                for( string sub : sublist){
                    res.push_back(word + (sub.empty() ? "" : " " + sub));

                }
            }
        }

        return memo[start] = res;
    }
};