#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

// ================
// DEFINITIONS
// ================
#define MAX_SEATS 64

class person{
    public:
        unsigned int age;
        char* name;
        char* ticket;
        person();
        person(person& p);
};

person::person(){
    name = nullptr;
    ticket = nullptr;
    age = 0;
}

person::person(person& p){
    this->age = p.age;
    this->name = p.name;
    this->ticket = p.ticket;
}

class passager{
    public:
        int seat;
        person *per;
        passager *prev;
        passager *next;
        passager();
};

passager::passager(){
    seat = 0x0;
    per = nullptr;
    prev = nullptr;
    next = nullptr;
}

class flight{
    public:
        flight();
        unsigned int flight_no;
        int seats;
        int generate_flight_no(){
            srand((int) time(0));
            return ((rand() ^ 1337 )% 10000);
        };
};

flight::flight(){
    seats = MAX_SEATS;
    flight_no = generate_flight_no();
}

// ================
// GLOBALS
// ================
int empty_seats = MAX_SEATS;
flight f1;
passager *root = nullptr;
bool seats[MAX_SEATS];

// ================
// FUNCTIONS
// ================
void init(){
    setbuf(stdin,NULL );
    setbuf(stdout,NULL );
    setbuf(stderr,NULL );
}

void header(){
    puts("==================================================");
    puts("                     __/\\__");
    puts("                    `==/\\==`");
    puts("          ____________/__\\____________");
    puts("         /____________________________\\");
    puts("           __||__||__/.--.\\__||__||__");
    puts("          /__|___|___( >< )___|___|__\\");
    puts("                    _/`--`\\_");
    puts("                   (/------\\)\n");
    puts(" Welcome to the Airline Ticket Reservation System");
    puts("==================================================");
}

void menu(){
    puts(" [1] Reserve a ticket");
    puts(" [2] Cancel a reservation");
    puts(" [3] Check whether a ticket is reserved for a particular person");
    puts(" [4] Display the passengers");
    puts(" [5] Exit");
}

void generate_ticket_number(char **c, int pos){
    *c = new char [16];
    snprintf(*c,16,"FF%dNN%d",f1.flight_no,pos);
}

void display_passengers(){
    puts("");
    if (root != nullptr){
        passager *i;
        puts(" [*] List of Passagers:");
        for(i = root; i != nullptr; i=i->next){
            printf(" (%d) %s =[%s]=\n",i->seat,i->per->name,i->per->ticket);   
        }    
    }
    else{
        puts(" [#] No Passengers");
    }
    puts("");
}

void cancel_reservation(){
    if (root != nullptr){
        puts("");
        char tmp_name[101];
        int cnt =0;
        memset(tmp_name,'\x00',100);
        printf(" > Please Enter your ticket: ");
        tmp_name[read(0,tmp_name,100)-1] = '\x00';
        if(empty_seats == MAX_SEATS-1){
            seats[root->seat -1] = 0;
            delete root;
            root = nullptr;
            empty_seats++;
        }
        else{
            for(passager *i = root; i != nullptr; i=i->next,cnt++){
                if(!strcmp(tmp_name,i->per->ticket)){
                    delete i->per;
                    i->per = 0;
                    if (i->prev == nullptr){
                        i->next->prev = nullptr;
                        root = i->next;
                        i->next = nullptr;
                    }
                    else if(i->next == nullptr){
                        i->prev->next = nullptr;
                        i->prev = nullptr;
                    }
                    else{
                        i->prev->next = i->next;
                        i->next->prev = i->prev;
                        i->next = nullptr;
                        i->prev = nullptr;
                    }
                    delete i;
                    seats[cnt] = 0;
                    empty_seats++;
                    break;
                }
            }    
        }
    }
    else{
        puts(" [#] No reservations are available.");
    }
    puts("");
}

void register_passager(person *p, int st){
    passager *i;
    if (root == nullptr){
        passager *tmp_p = new passager;
        tmp_p->next = nullptr;
        tmp_p->prev = nullptr;
        tmp_p->per = p;
        tmp_p->seat = st;
        root = tmp_p;
        return;
    }
    else{
        for(i = root; i != nullptr; i=i->next){
            if(strcmp(p->name,i->per->name) <= 0){
                passager *tmp_p = new passager;
                tmp_p->next = i;
                tmp_p->prev = i->prev;
                if (i->prev != nullptr)
                    i->prev->next = tmp_p;
                i->prev = tmp_p;
                tmp_p->per = p;
                tmp_p->seat = st;
                if(i == root)
                    root = tmp_p;
                return;
            }
            if(i->next == nullptr)
                break;
        }
    }
    passager *tmp_p = new passager;
    tmp_p->next = nullptr;
    tmp_p->prev = i;
    i->next = tmp_p;
    tmp_p->per = p;
    tmp_p->seat = st;
    return;
}

void reserve_ticket(){
    puts("");
    if(empty_seats <= 0){
        puts(" [!] No empty seats available!\n");
        return;
    }
    char *tmp_name_buf = new char [100];
    person *p1 = new person;
    int tmp_seat;
    printf(" [?] In order to complete the reservation for flight no %d please fill out the following form:\n",f1.flight_no);
    printf(" Name: ");
    int inp_len = read(0,tmp_name_buf,100);
    if ( inp_len > 0){
        tmp_name_buf[inp_len-1] = '\x00';
        p1->name = tmp_name_buf;
    }
    else{
        puts(" [!] Error encountered, please try again!\n");
        delete p1;
        delete tmp_name_buf;
        return;
    }
    printf(" Age: ");
    scanf("%u",&(p1->age));
    if(p1->age > 120){
        puts(" [!] The age exceeds our age rules, we are sorry for the incoveniences.\n");
        delete p1;
        delete tmp_name_buf;
        return;
    }
    while(1){
        printf(" Seat (1-%d): ",MAX_SEATS);
        scanf("%u",&tmp_seat);
        if(tmp_seat > MAX_SEATS || tmp_seat <= 0){
            puts(" [!] Invalid seat number.\n");
            delete p1;
            delete tmp_name_buf;
            return;
        }
        else if(seats[tmp_seat-1]){
            puts(" [!] This Seat is already taken.");
        }
        else{
            break;
        }
    }
    generate_ticket_number(&(p1->ticket),tmp_seat);
    register_passager(p1,tmp_seat);
    empty_seats--;
    seats[tmp_seat-1] = 1;
    printf(" [*] Reservation succeded! Your ticket number is: =[%s]= \n\n",p1->ticket);
}

void check_ticket(){
    if(root != nullptr){
        char tmp_tt[21];
        puts("");
        printf(" [*] Please Enter Ticket Number: ");
        tmp_tt[read(0,tmp_tt,20)-1] = '\x00';
        for(passager *i = root; i != nullptr; i=i->next){
            if(!strcmp(tmp_tt,i->per->ticket)){
                char tmp_name[101];
                printf(" [*] Please Enter Passager's Name: ");
                tmp_name[read(0,tmp_name,100)-1] = '\x00';
                if(!strcmp(tmp_name,i->per->name)){
                    printf(" [YES] Ticket no. %s is owned by %s.\n\n",i->per->ticket,i->per->name);
                    return;
                }
                else{
                    printf(" [NO] Ticket no. %s is not owned by %s.\n\n",i->per->ticket,i->per->name);
                    return;
                }
            }
        } 
        printf(" [!] Ticket no. %s is not reserved.\n\n",tmp_tt);
    }
}

// ================
// MAIN
// ================
int main(){

    unsigned int option = 0;
    init();
    header();

    while(1){
        menu();
        printf(" > ");
        scanf("%d",&option);
        switch(option){
            case 1:
                reserve_ticket();
                break;
            case 2:
                cancel_reservation();
                break;
            case 3:
                check_ticket();
                break;
            case 4:
                display_passengers();
                break;
            case 5:
                exit(1);
            default:
                puts(" [*] Unknown Option");
        }
    }
    return 0;
}

// Flat week 11
// Mate week 14
// ADS 13th May - first 2