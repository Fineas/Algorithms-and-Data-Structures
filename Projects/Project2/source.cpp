#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

unsigned int node_counter;

Node* last;

class CircularList{
    public:
        CircularList(Node* last){
            ::last = last;
            if(::last != nullptr){
                ::last->next = ::last;
            }
        }
        void insert_node(int data){
            Node* tmp_node = new Node(data);
            if(last == nullptr){
                tmp_node->next = tmp_node;
            }
            else{
                tmp_node->next = last->next;
                last->next = tmp_node;
            }
            last = tmp_node;
        }
        Node* search_node(int data, bool del=0){
            Node* j = nullptr; Node *i = nullptr;
            for(j = last,i = last->next; i != last; i=i->next,j=j->next){
                if(i->data == data){
                    if(del){
                        return j;
                    }
                    else{
                        return i;
                    }
                }
            }
            if(i->data == data){
                if(del){
                    return j;
                }
                else{
                    return i;
                }
            }
            return nullptr;
        }
        bool delete_node(int data){
            Node* tmp_node1 = search_node(data,1);
            Node* tmp_node2 = nullptr;
            if(tmp_node1){
                tmp_node2 = tmp_node1;
                tmp_node1 = tmp_node1->next;
                if (tmp_node1 == last){
                    last = tmp_node2;
                }
                tmp_node2->next = tmp_node1->next;
                delete tmp_node1;
                return 1;
            }
            else{
                return 0;
            }
        }
        void display_list(){
            if(node_counter == 1){
                cout<<" [ "<<last->data<<" ] "<<endl<<endl;
                return;
            }
            Node* j = nullptr; Node *i = nullptr;int cnt = 0;
            cout<<" ";
            for(j = last,i = last->next; i != last; i=i->next,j=j->next){
                cout<<"[ "<<i->data<<" ] 🠚 ";
                cnt++;
            }
            cout<<"[ "<<i->data<<" ] "<<endl;
            cout<<"  🠙";
            for(int i = 0; i < cnt-1; i++){
                cout<<"________";
            }
            cout<<"_______|"<<endl<<endl;
        }
        void print_third(){
            if(node_counter < 1){
                cout<<" Not enough Nodes. "<<endl<<endl;
                return;
            }
            else{
                int start;
                cout<<" Starting Position: ";
                cin>>start;
                Node* j = nullptr; Node *i = nullptr;
                for(i = last->next; i != last; i=i->next){
                    if(i->data == start){
                        cout<<" Third Node is [ "<<i->next->next->data<<" ]"<<endl<<endl;
                        return;
                    }
                }
            }
            cout<<" Node not found! "<<endl<<endl;
        }    
};

CircularList josephus_prob(last);

void banner(){
    cout<<"                      ,,ggddY\"\"\"\"Ybbgg,,"<<endl;
    cout<<"                 ,agd\"\"'              `\"\"bg,"<<endl;
    cout<<"              ,gdP\"                       \"Ybg,"<<endl;
    cout<<"            ,dP\"                             \"Yb,"<<endl;
    cout<<"          ,dP\"         _,,ddP\"\"\"Ybb,,_         \"Yb,"<<endl;
    cout<<"         ,8\"         ,dP\"'         `\"Yb,         \"8,"<<endl;
    cout<<"        ,8'        ,d\"                 \"b,        `8,"<<endl;
    cout<<"       ,8'        d\"                     \"b        `8,"<<endl;
    cout<<"       d'        d'        ,gPPRg,        `b        `b"<<endl;
    cout<<"       8         8        dP'   `Yb        8         8"<<endl;
    cout<<"       8         8        8)     (8        8         8"<<endl;
    cout<<"       8         8        Yb     dP        8         8"<<endl;
    cout<<"       8         Y,        \"8ggg8\"        ,P         8"<<endl;
    cout<<"       Y,         Ya                     aP         ,P"<<endl;
    cout<<"       `8,         \"Ya                 aP\"         ,8'"<<endl;
    cout<<"        `8,          \"Yb,_         _,dP\"          ,8'"<<endl;
    cout<<"         `8a           `\"\"YbbgggddP\"\"'           a8'"<<endl;
    cout<<"          `Yba                                 adP'"<<endl;
    cout<<"            \"Yba                             adY\""<<endl;
    cout<<"              `\"Yba,                     ,adP\"'"<<endl;
    cout<<"                 `\"Y8ba,             ,ad8P\"'"<<endl;
    cout<<"                      ``\"\"YYbaaadPP\"\"''"<<endl;
    cout<<endl;
    cout<<"                       Josephus problem"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
}

void simulate(int start_pos){
    Node *i = nullptr;
    for(i = last; i->data != start_pos; i=i->next){continue;}
    while(node_counter != 1){
            Node *j = i->next->next;
            josephus_prob.delete_node(i->next->data);
            i->next = j;
            i = j;
            node_counter--;
            josephus_prob.display_list();
    }
    cout<<" WINNING POSITION= "<<last->data<<endl<<endl;
}

void menu(){
    cout<<" 1 - Insert Node"<<endl;
    cout<<" 2 - Delete Node"<<endl;
    cout<<" 3 - Search Node"<<endl;
    cout<<" 4 - Print 3rd Node"<<endl;
    cout<<" 5 - Display List"<<endl;
    cout<<" 6 - SIMULATE!"<<endl;
    cout<<" 7 - Print Menu again"<<endl;
    cout<<" 8 - Exit"<<endl<<endl;
}

int main(){

    int option = 0;
    bool flag = 0;
    Node* instance = nullptr;

    banner();
    menu();

    while(1){
        cout<<" Enter Option: ";
        cin>>option;

        switch(option){
            case 1:
                josephus_prob.insert_node(++node_counter);
                cout<<" Insetion Success!"<<endl<<endl;
                break;
            case 2:
                cout<<" Enter Node Number: ";cin>>option;
                flag = josephus_prob.delete_node(option);
                if(flag){
                    cout<<" Deletion Success!"<<endl<<endl;
                    node_counter--;
                }
                else{
                    cout<<" Deletion Failed!"<<endl<<endl;
                }
                break;
            case 3:
                cout<<" Enter Node Number: ";cin>>option;
                instance = josephus_prob.search_node(option);
                if(instance != nullptr){
                    cout<<" Node "<<option<<" found!"<<endl<<endl;
                }
                else{
                    cout<<" Node "<<option<<" not found!"<<endl<<endl;
                }
                break;
            case 4:
                josephus_prob.print_third();
                break;
            case 5:
                josephus_prob.display_list();
                break;
            case 6:
                cout<<" Starting Position: ";cin>>option;
                simulate(option);
                break;
            case 7:
                menu();
                break;
            case 8:
                exit(0);
            default:
                cout<<" Invalid entry"<<endl<<endl;
                break;
        }
    }
    return 0;
}