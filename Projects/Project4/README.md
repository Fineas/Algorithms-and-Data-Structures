# A software store using BST. <hr>
- **Program Design:**

The Program is implemented in a `menu-based` style, allowing the user to interact with it in a friendly manner and perform two actions such as **adding** / **buying** software.

<!-- ![Emulation](https://raw.githubusercontent.com/Fineas/Algorithms-and-Data-Structures/master/Projects/Project3/img/preview.PNG ) -->

- **Code Design:**

The Program functionality is based on the following 3 methods:
```
BST* Insert(BST *, int, string, string, int, int); // Insert function. 
BST* Search(BST *, string); // Search function. 
void Inorder(BST *); // Inorder traversal. 
```
There is also the `load_db` function and `update_db` which reads and writes data to the `software.txt` file.