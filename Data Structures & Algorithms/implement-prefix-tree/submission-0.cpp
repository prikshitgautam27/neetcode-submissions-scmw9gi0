class PrefixTree {
public:



struct Node{
Node* children[26];
bool isend ;

Node(){
    isend= false;
    for(int i=0;i<26;i++){
        children[i] = nullptr;
    }

}


};



Node* root;
    PrefixTree() {
        root = new Node();

    }
    
    void insert(string word) {
        Node * cur = root;
        for(char c: word){
            int idx = c-'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = new Node();
            }
            cur=  cur->children[idx];
        }
        cur->isend= true;
    }
    
    bool search(string word) {
     Node * cur = root;
     for( char& c: word){
        int idx = c -'a';
        if(cur->children[idx] == nullptr){
            return false;
        }
        cur = cur-> children[idx];
     }
     return cur->isend;


    }
    
    bool startsWith(string prefix) {
         Node * cur = root;
     for( char & c: prefix){
        int idx = c -'a';
        if(cur->children[idx] == nullptr){
            return false;
        }
        cur = cur-> children[idx];
     }
     return true;
    }
};
