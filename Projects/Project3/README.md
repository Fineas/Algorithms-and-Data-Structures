# Airline Ticket Reservation Program using Linked Lists. <hr>
- **Program Design:**

The Program in implemented in a `menu-based` style, allowing the user to interact with it in a friendly manner and perform various actions such as **adding** / **removing** / **listing** / **searching** airplane tickets.

![Emulation](https://raw.githubusercontent.com/Fineas/Algorithms-and-Data-Structures/master/Projects/Project3/img/preview.PNG )

- **Code Design:**

The Program functionality is based on 3 main classes:
```
class person{
    public:
        unsigned int age;
        char* name;
        char* ticket;
};
class passager{
    public:
        int seat;
        person *per;
        passager *prev;
        passager *next;
};
class flight{
    public:
        unsigned int flight_no;
        int seats;
        int generate_flight_no(){
            srand((int) time(0));
            return ((rand() ^ 1337 )% 10000);
        };
};
```
All passagers are stored in a double linked list making it easier to remove / add new ones.