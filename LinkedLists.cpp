#include <iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = tail -> next;
            //OR
            //tail = newNode;
        }
        cin>>data;
    }
    return head;
}

int length(Node *head)
{
    //Write your code here
    int count = 0;
    Node *temp = head;
    
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

void printIthNode(Node *head, int i)
{
    //Write your code here
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        
        if(count == i){
            cout<<temp -> data;
            break;
        }
        count++;
        temp = temp -> next;
    }
}

Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while(temp != NULL && count < i-1){
        temp = temp -> next;
        count++;
    }
    // Method 1
    if(temp != NULL){
        Node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    

    //Method 2
    // newNode -> next = temp -> next;
    // temp -> next = newNode;
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

int main(){

    Node *head = takeInput();
    print(head);
    int i, data;
    cin>>i>>data;
    head = insertNode(head, i, data);
    print(head);
    // Statically
    // Node n1(1);
    // Node *head = &n1;
    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    

    // print(head);

    /*
    n1.next = &n2;
    n2.next = NULL;

    cout<<n1.data<<" "<<n2.data<<endl;
    //Dynamically
    Node *n3 = new Node(10);
    Node *head = n3;
    Node *n4 = new Node(20);
    n3->next = n4;
    return 0;
    */
}