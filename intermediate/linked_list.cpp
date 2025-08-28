#include<iostream>
using namespace std;

struct node {
    int val = 0;
    node *next = NULL;
};

node* create_node(node *c, int v);
void output(node* head);
node* del(node* head, int v);

int main () {
    node *head; node *current;

    head = new node;
    head->val = 2;
    head->next = NULL;

    current = head;
    current = create_node(current, 4);
    current = create_node(current, 6);
    current = create_node(current, 8);

    cout<<"The list we just created: "<<endl;
    output(head);
    cout<<"Now i'm going to del value 4 from it:"<<endl;
    cout<<"Before deletion: ",output(head);
    head = del(head, 4);
    cout<<"After deletion: ",output(head);

    return 0;
}

// function to create a new node save value in it and return it's address
node* create_node(node *c, int v){
    node *n = new node;
    n->val = v;

    c->next = n;

    return n;
}

// function to display the list by passing head pointer as argument
void output(node* head){
    node* current;
    current = head;
    cout<<"[ ";
    while (current!=NULL){
        cout<<current->val<<" ";
        current = current->next;
    }
    cout<<"]"<<endl;
}

// Function to del a node by its value
node* del(node* head, int v) {
    if (head==NULL) {
        cout<<"\nThe list is empty!"<<endl;
        return head;
    }

    node *current = head;
    node *prev = current;
    if (current->val==v){
        node* temp = current->next;
        delete current;
        return temp;
    }
    else {
        current = current->next;
        while (current!=NULL){
            if (current->val == v) {
                prev->next = current->next;
                delete current;
                return head;
            }
            prev = current;
            current = current->next;
        }
        cout<<"\nThe value you want to delete from list is not found!"<<endl;
        return head; //The same head as input in the function as parameter
    }
}

// Adding all the elements of a list and return the value
int sum_list(node* current){
    int sum = 0;
    while (current!=NULL){
        sum += current->val;
        current = current->next;
    }

    return sum;
}
