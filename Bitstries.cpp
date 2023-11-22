#define ll long long

struct Node{

Node* arr[3];
bool flag  = false;

bool contain(int x){
    return arr[x]!=NULL;
}
void put(int x,Node* root){
     arr[x] = root;
}

Node*get(int x){
    return arr[x];
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
    
    void insert(int x) {
        Node*temp = root;
        for(int i = 31;i>=0;i--){
            int val = x & (1<<i);
             if(val>0) val = 1;
             else val = 0;


            if(!temp->contain(val)){
              temp->put(val,new Node());
            }
            temp = temp->get(val);
        }
        temp->setend();
    }
    
    bool search(int x) {
        Node*node = root;
        for(int i = 31;i>=0;i--){
            int val = x & (1<<i);
             if(val>0) val = 1;
             else val = 0;

            if(!node->contain(val)){
                return false;
            }
            node = node->get(val);
        }
        return node->flag;
    }
    
    bool startsWith(int x) {
         Node*node = root;
       for(int i = 31;i>=0;i--){
            int val = x & (1<<i);
             if(val>0) val = 1;
             else val = 0;


            if(!node->contain(val)){
                return false;
            }
            node = node->get(val);
        }
        return true;       
    }


    int maximumxor(int x){
        Node*temp = root;
        ll ans = 0;
         for (int i = 31; i>=0; i--)
         {
            int val = x & (1<<i);
             if(val>0) val = 1;
             else val = 0;


            if(temp->arr[1-val]!=NULL){
                temp = temp->arr[1-val];
                ans = ans+((1-val)*(1<<i));
  
            }
            else {
                ans = ans+((val)*(1<<i));
                temp = temp->arr[val];
        
            }
         }
         return ans^x;
    }
};







