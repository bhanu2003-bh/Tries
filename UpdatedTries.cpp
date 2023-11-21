#include <bits/stdc++.h> 

struct Node{

Node*arr[27];
int prefix = 0;
int end = 0;

bool flag = false;


bool contain(char x){
    return arr[x-'a']!=NULL;
}

void put(char x,Node*root){
    arr[x-'a'] = root;
}

Node*get(char x){
    return arr[x-'a'];
}


};


class Trie{

private: Node*root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string &s){
        Node*temp = root;
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(!temp->contain(s[i])){
               temp->put(s[i],new Node());
            }
            temp->prefix = temp->prefix+1;
            temp = temp->get(s[i]);
        }
         temp->prefix = temp->prefix+1;
        temp->end = temp->end+1;
      
        temp->flag = true;
    }

    int countWordsEqualTo(string &s){
 Node*temp = root;
        int n = s.length();
        for(int i = 0;i<n;i++){
 
          if(temp->contain(s[i])) temp = temp->get(s[i]);
            else return 0;
        }
        return temp->end;
    }

    int countWordsStartingWith(string &s){
 Node*temp = root;
        int n = s.length();
        for(int i = 0;i<n;i++){
        if(temp->contain(s[i])) temp = temp->get(s[i]);
            else return 0;
          
        }
        return temp->prefix;        
    }

    void erase(string &s){
       Node*temp =  root;
       int n = s.length();


    for(int i = 0;i<n;i++){
      if(temp->contain(s[i])) temp = temp->get(s[i]);
     else return ;   
    }

temp = root;

       for(int i = 0;i<n;i++){
           temp->prefix = temp->prefix-1;
           temp = temp->get(s[i]);
       }
       temp->prefix = temp->prefix-1;
       temp->end = temp->end-1;
    }
};
