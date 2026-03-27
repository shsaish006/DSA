class WordDictionary {
public:
    struct node{
        node* a[26];
        bool end;
        node(){
            for(int i=0;i<26;i++) a[i]=nullptr;
            end=false;
        }
    };
    node* root;
    WordDictionary() {
        root=new node();
        
    }
    
    void addWord(string word) {
        node* curr=root;
        for(int i=0;i<word.size();i++){
            int c=word[i]-'a';
            if(curr->a[c]==nullptr) curr-> a[c]=new node();
            curr=curr-> a[c];
        }
        curr->end=true;
        
    }
    bool dfs(string &s, int i, node* curr){
        if(i==s.size()) return curr->end;
        if(s[i]!='.'){
            int c=s[i]-'a';
            if(curr-> a[c]==nullptr) return false;
            return dfs(s,i+1, curr->a[c]);
        }else{
            for(int j=0;j<26;j++){
                if(curr->a[j] && dfs(s,i+1,curr->a[j]))
                return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */