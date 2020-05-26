#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;
ifstream fin("software.txt");
  
class BST { 


    public: 
        string name;
        string version;
        int quantity;
        int price;
        string key;
        int position; 
        BST *left, *right; 
        BST(); // Default constructor. 
        BST(int, string, string, int, int); // Parameterized constructor. 
        BST* Insert(BST *, int, string, string, int, int); // Insert function. 
        BST* Search(BST *, string); // Search function. 
        void Inorder(BST *); // Inorder traversal. 
}; 
  
BST :: BST() : key(),name(),version(),left(NULL),right(NULL),position(0),quantity(0),price(0){} 
  
BST :: BST(int position, string name, string version, int quantity, int price) { 
    key = name+version;
    this->name = name;
    this->version = version;
    this->quantity = quantity;
    this->price = price; 
    this->position = position;
    left = right = NULL; 
} 
  
BST* BST :: Insert(BST *root, int position, string name, string version, int quantity, int price ) { 
    if(!root) { 
        return new BST(position,name,version,quantity,price); 
    } 
    if(name+version > root->key) { 
        root->right = Insert(root->right,position,name,version,quantity,price); 
    } 
    else{ 
        root->left = Insert(root->left,position,name,version,quantity,price); 
    } 
    return root; 
} 
  
void BST :: Inorder(BST *root) { 
    if(!root) { 
        return; 
    } 
    Inorder(root->left); 
    if(root->quantity){
        cout << root->key << endl;
    }
    Inorder(root->right); 
} 

BST* BST :: Search(BST *root, string name){
    if (root == NULL || root->name == name) 
       return root; 
     
    if (root->name < name) 
       return Search(root->right, name); 
  
    return Search(root->left, name); 
}

BST SOFTWARE, *root = NULL;
int software_cnt = 0;

void load_db(){
    int quant, price, items, i;
    string tmp_name, tmp_version;
    fin>>items;
    software_cnt = i = items;
    while(items){
        fin>>tmp_name>>tmp_version>>quant>>price;
        cout<<">> "<<tmp_name<<" "<<tmp_version<<" "<<quant<<" "<<price<<endl;
        if(root){
            SOFTWARE.Insert(root,i-items,tmp_name,tmp_version,quant,price);
        }
        else{
            root = SOFTWARE.Insert(root,i-items,tmp_name,tmp_version,quant,price); 
        }
        items--;
    }
    return;
}

void menu(){
    cout<<"[1] New Software"<<endl;
    cout<<"[2] Buy Software"<<endl;
    cout<<"[3] Exit"<<endl<<endl;
    return;
}

string fisier[100];

void update_db(BST *root){
    if(!root) { 
        return; 
    } 
    update_db(root->left); 
    
    string payload;
    payload += root->name + " ";
    payload += root->version + " ";
    payload += to_string(root->quantity) + " ";
    payload += to_string(root->price) + " ";
    cout<<"Gonna write "<<payload<<"Position: "<<root->position<<endl;
    fisier[root->position] = payload;
    
    update_db(root->right); 
    return;
}

void add(){
    string add_name;
    cout<<"Enter the name of the software you want to add: ";cin>>add_name;
    BST *tmp = SOFTWARE.Search(root,add_name);
    if(tmp){
        tmp->quantity++;
        cout<<"Add success!"<<endl<<endl;
    }
    else{
        string ver_name;
        int price;
        cout<<"Enter the version name: ";cin>>ver_name;
        cout<<"Enter the price / item: ";cin>>price;
        SOFTWARE.Insert(root,software_cnt,add_name,ver_name,1,price); 
        cout<<"Add success!"<<endl<<endl;
        software_cnt++;
    }
    return;
}

void buy(){
    string buy_name;
    cout<<"Enter the name of the software you want to buy: ";cin>>buy_name;
    BST *tmp = SOFTWARE.Search(root,buy_name);
    if(tmp){
        if(tmp->quantity){
            tmp->quantity--;
            cout<<"Buy success!"<<endl<<endl;
        }
        else{
            cout<<"Out of stock!"<<endl<<endl;
        }
    }
    else{
        cout<<"No such software"<<endl<<endl;
    }
    return;
}

int main(){

    int op;
    load_db();

    while(1){
        menu();
        cout<<"> ";cin>>op;
        if(op == 1){
            add();
        }
        else if(op == 2){
            buy();
        }
        else if(op == 3){
            update_db(root);
            fin.close();
            ofstream fout("software.txt");
            fout<<software_cnt<<endl;
            for(int i = 0; i < software_cnt; i++){
                fout<<fisier[i]<<endl;
            }
            fout.close();
            break;
        }
        else{
            cout<<"Unknown menu entry."<<endl;
        }
    }
    return 0;
}