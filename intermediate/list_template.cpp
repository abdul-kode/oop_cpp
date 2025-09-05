#include<iostream>
using namespace std;

template <class T>
class List {

    struct node {
        T val;
        node *next = NULL;
    };

    void delete_after_node(node* current);

    public:

    List();
    node *head, *last;
    void push(T val);
    T pop();
    void print_list();
};
template<class T>
List<T>::List () {
    cout<<"Constructor Called: "<<endl;
    head = last = NULL;
}
template<class T>
void List<T>::delete_after_node(node *current){
    node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}
template<class T>
void List<T>::push(T val) {
    node *temp = new node;
    temp->val = val;

    if (head==NULL){
        head = temp;
        last = temp;
    }
    else{
        last->next = temp;
        last = last->next;
    }
}
template<class T>
T List<T>::pop() {
    T val;
    if (head->next == NULL) {
        val = head->val;
        delete head;
        head = NULL;
        last = NULL;
    }
    else {
        val = last->val;
        node* current = head;
        while(current->next != last) {
            current = current->next;
        }
        delete_after_node(current);
        last = current;
    }
    return val;
}
template<class T>
void List<T>::print_list() {
    node* temp = head;
    cout<<"[ ";
    while (temp != NULL) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"]"<<endl;
}

int main () {
    cout<<"\nCreating Integer list ..."<<endl;

    List<int> *li = new List<int>;
    cout<<"Pushing 23 and 1232 value into the list: "<<endl;
    li->push(23);
    li->push(1232);
    li->print_list();

    cout<<"Removing value, as it's a stack DS, the last value will be poped ..."<<endl;
    li->pop();
    li->print_list();

    // String
    cout<<"\nCreating String list ..."<<endl;

    List<string> *ls = new List<string>;
    cout<<"Pushing Abdul and Ali string into the list: "<<endl;
    ls->push("Abdul");
    ls->push("Ali");
    ls->print_list();

    cout<<"Removing value, as it's a stack DS, the last value will be poped ..."<<endl;
    ls->pop();
    ls->print_list();

    cout<<endl;
    return 0;
}
