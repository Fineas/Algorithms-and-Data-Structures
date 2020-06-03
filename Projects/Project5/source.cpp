#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;
ifstream fin("data.txt");
  
class linkedl{
    public:
        linkedl* next;
        int position;
        linkedl(){
            next = NULL;
            position = 0;
        };
};

class BST { 

    public: 
        string word;
        linkedl* occ;
        BST *left, *right; 
        BST(); // Default constructor. 
        BST(string, int); // Parameterized constructor. 
        BST* Insert(BST *, string, int); // Insert function. 
        BST* Search(BST *, string); // Search function. 
        void Inorder(BST *); // Inorder traversal. 
}; 
  
BST :: BST() : word(),left(NULL),right(NULL),occ(NULL){} 
  
BST :: BST(string word, int pos) { 
    this->word = word;
    this->occ = new linkedl;
    this->occ->position = pos;
    this->occ->next = NULL;
    left = right = NULL; 
} 
  
BST* BST :: Insert(BST *root, string word, int pos) { 
    if(!root) { 
        return new BST(word, pos); 
    } 
    if(word > root->word) { 
        root->right = Insert(root->right, word, pos); 
    } 
    else{ 
        root->left = Insert(root->left, word, pos); 
    } 
    return root; 
} 
  
void BST :: Inorder(BST *root) { 
    if(!root) { 
        return; 
    } 
    Inorder(root->left); 
    
    cout << root->word;
    for(linkedl *i = root->occ; i != NULL; i = i->next){
        cout<<" ["<<i->position<<"] ";
    }
    cout<<endl;
    Inorder(root->right); 
} 

BST* BST :: Search(BST *root, string word){
    if (root == NULL || root->word == word) 
       return root; 
     
    if (root->word < word) 
       return Search(root->right, word); 
  
    return Search(root->left, word); 
}

BST TEXT, *root = NULL;
int software_cnt = 0;

void load_words(){
    string word;
    int word_position = 1;
    BST *tmp;
    while(fin >> word){
        if(root){
            if(tmp = TEXT.Search(root,word)){
                linkedl * i;
                for(i = tmp->occ; i->next != NULL; i = i->next){
                    continue;
                }
                i->next = new linkedl;
                i->next->position = word_position;
                i->next->next = NULL;
            }
            else{
                TEXT.Insert(root,word,word_position); 
            }
        }
        else{
            root = TEXT.Insert(root,word,word_position); 
        }
        word_position++;
    }
}

int main(){

    int op;
    load_words();

    TEXT.Inorder(root);
    
    return 0;
}