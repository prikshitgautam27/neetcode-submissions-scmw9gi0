class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,int>indeg;
        unordered_map<char,unordered_set<char>>adj;

        for(auto& word : words){
            for(auto & c: word){
                if(indeg.find(c) == indeg.end())  indeg[c] =0;
            }
        }
        
        for(int i=0;i<words.size()-1 ; i++){
            string w1= words[i], w2= words[i+1];
            int len=min(w1.length(), w2.length());

if(w1.length() > w2.length() && w1.substr(0,len) == w2) return "";

            for(int j=0;j< len;j++){
                if(w1[j] != w2[j]){
                    if(adj[w1[j]].find(w2[j])== adj[w1[j]].end()){
                        adj[w1[j]].insert(w2[j]);
                        indeg[w2[j]]++;
                    }
                    break;
                }

            }



        }

// kahn algo
queue<char> q;
for(auto & [node,deg] : indeg){
    if(deg==0) q.push(node);

}

string result ="";
while(!q.empty()){
    char cur= q.front();
    q.pop();
    result += cur;


    for(char nei: adj[cur]){
            indeg[nei]--;
            if(indeg[nei] == 0) q.push(nei);
    }

}


return result.length() == indeg.size() ? result :"";















    }
};
