class Solution {
    struct treenode{
        treenode* children[26];
        string word;
        treenode(){
            for(int i=0;i<26;i++) children[i] = nullptr;
        }

    };

    void insert(treenode* root ,string word){
            treenode* cur= root;
        for(char & c:word){
            int idx= c -'a';
            if(cur->children[idx] == nullptr) cur->children[idx] = new treenode();
            cur=cur->children[idx];
        }
        cur -> word = word;

    }

       void dfs(vector<vector<char>>& board, int i , int  j ,treenode* node, vector<string>&res){

            char c= board[i][j];
            if(c== '#' || node-> children[c-'a'] ==nullptr) return ;
            node=node->children[c- 'a'];
            if(node-> word !="")//end of current finded word
           { 
            res.push_back(node->word);
            node->word ="";
           }
           board[i][j] ='#';

           // explore all 4 direction
           int dr[4]={-1, 0, 1, 0};
           int dc[4]={0, 1, 0, -1};
           for(int k=0;k< 4;k++ ){
            int ni=i+dr[k], nj = j+ dc[k];

            if(ni>=0 && ni<board.size() && nj>=0 && nj<board[0].size()){
                dfs(board , ni, nj,node  ,res);

            }
           }
          board[i][j] = c;

       }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        treenode* root= new treenode();
        for(string & w:words) insert(root,w );

        vector<string> res;
        int n= board.size(), m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                dfs(board, i , j , root,res);
            }
        }
        return res;
    }
    
};