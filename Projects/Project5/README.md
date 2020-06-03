# Text concordance using BST. <hr>
- **Program Design:**

The Program loads the file reading word by word. Each word is then stored in the BST. If The word already exists, it will only add the position of the new word to the linked list.

![Emulation](https://raw.githubusercontent.com/Fineas/Algorithms-and-Data-Structures/master/Projects/Project5/img/preview.PNG )

- **Code Design:**

```
class BST { 
    public: 
        string word;
        linkedl* occ;
        BST *left, *right; 
        BST();
        BST(string, int);
        BST* Insert(BST *, string, int);
        BST* Search(BST *, string);
        void Inorder(BST *);
}; 

class linkedl{
    public:
        linkedl* next;
        int position;
        linkedl();
};
```