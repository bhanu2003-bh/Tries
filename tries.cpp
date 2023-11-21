struct Node{

Node* arr[26];
bool flag  = false;

bool contain(char x){
    return arr[x-'a']!=NULL;
}
void put(char x,Node* root){
     arr[x-'a'] = root;
}

Node*get(char x){
    return arr[x-'a'];
}

void setend(){
  flag = true;
}


};

class Trie {
  private:  Node*root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*temp = root;
        for(int i = 0;i<word.length();i++){
            if(!temp->contain(word[i])){
              temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setend();
    }
    
    bool search(string s) {
        Node*node = root;
        for(int i = 0;i<s.length();i++){
            if(!node->contain(s[i])){
                return false;
            }
            node = node->get(s[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string s) {
         Node*node = root;
        for(int i = 0;i<s.length();i++){
            if(!node->contain(s[i])){
                return false;
            }
            node = node->get(s[i]);
        }
        return true;       
    }
};
