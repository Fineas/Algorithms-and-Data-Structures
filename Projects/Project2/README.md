# Josephus problem with circular lists.<hr>
- **Program Design:**

The Program in implemented in a `menu-based` style, allowing the user to interact with it in a friendly manner and construct a custom circular linked list by **adding** / **removing** nodes.
The solution to Josephus' problem is in the `simulate()` function which basically emulates the game and finds the last person to live. Another way to determin the position is by applying the following formula:

> **n** - number of people in the circle
 - if n is a power of 2, the last person to live is exactly the person that starts the game
 - if n is not a power of 2, then the following formula can be applied: 
 considering $2^m < n < 2^{m+1}$, the last man will be on position: $2 * (n - 2^m) + 1$

![Emulation](https://github.com/Fineas/Algorithms-and-Data-Structures/tree/master/Projects/Project2/img/emulation.PNG )

- **Code Design:**

The Program functionality is based on the `CircularList` class which provides the following methods:
```
class CircularList{
    public:
        CircularList(Node* last){ ... }
        void insert_node(int data){ ... }
        Node* search_node(int data, bool del=0){ ... }
        bool delete_node(int data){ ... }
        void display_list(){ ... }
};
CircularList josephus_prob(last);
```
>**Insertion**: is done in O(1) by simply linking a new node to the tail (`Node *last`).
>**Deletion**: is done in O(m) where `m` is the index in the linked list.
>**Searching**: is done in O(m) where `m` is the index in the linked list.
