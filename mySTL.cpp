#include<bits/stdc++.h>
using namespace std;


template <class type>
class Node{

    public:

    type data;
    Node *next;
    Node *prev;
    Node *left;
    Node *right;

    Node(){

        data  = -1;
        next  = NULL;
        prev  = NULL;
        left  = NULL;
        right = NULL;

    }

    Node(type x){
        data = x;
    }

};


//Single Linkedlist Class
template <class type>
class SingleLinkedList{

    public:
    Node<type> *head;
    Node<type> *tail;

    SingleLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtLast(type newdata){

        Node<type> *newnode = new Node<type>();
        newnode->data = newdata;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
           
            
        }

        Node<type> *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
          
    }

    void insertAtFirst(type newdata){

        Node<type> *newnode = new Node<type>();
        newnode->data = newdata;
        newnode->next = head;
        head = newnode;
        
    }

    void insertAtAnyPos(type place,type newdata){
        if (place == 1)
        {
            return insertAtFirst(newdata);
        }
        Node<type> *newnode = new Node<type>();
        newnode->data = newdata;
        Node<type> *temp = head;
        for (int i = 0; i < place - 2; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
       
    }

    void insertBeforeElement(type olddata, type newdata){

        Node<type> *temp = head;

        int position =1;
        int check = 0;
        while(temp!=NULL){

          if(temp->data==olddata)
            {
                check = 1;
                break;
            }
          else{
            temp=temp->next;
            position++;
          }
        }

        if(check==1){
        insertAtAnyPos(position,newdata);
        }

        else{
        cout << "Data not found before "<<olddata<<endl;
        }

    }

    void deleteElementByValue(type key){
        
        Node<type>* temp = head;
        Node<type>* prev = NULL;
        if(head->data == key){
            head = head->next;
            return;
        }
        while(temp != NULL){
            if(temp->data == key){
                prev->next = temp->next;
                if(tail == temp){
                    tail = prev;

                }

                }
                prev=temp;
                temp = temp->next;
            }

    }

    void deleteAtPos(int pos){

        if (head == NULL) 
            { 
                cout << "No Data Found " << endl; 
            return; 
            } 
            Node<type>* temp = head; 
            if (pos == 1) 
            { 
                head = temp->next; 
                delete temp; 
            return; 
            } 
            for (int i = 1; i < pos - 1; i++) 
            { 
                temp = temp->next; 
            } 
            Node<type>* temp2 = temp->next; 
            temp->next = temp2->next; 
            return; 

    }

    void displayList (){

        Node<type> *temp = head;
        cout<<"The element of Single Linkedlist: "<<endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        
        cout<<endl;
    }

};

//Doubly LinkedList Class
template <class type>
class DoubleLinkedList{

    public:

        Node<type>* head;
        Node<type>* tail;

        DoubleLinkedList(){
            head=NULL;
            tail=NULL;
        }

    void insertAtLast(type key){
        
        Node<type>* nn = new Node<type>();
        nn->data = key;
        if(head == NULL){

            head = nn;
            tail = nn;

            }

        else{

            tail->next = nn;
            nn->prev = tail;
            tail = nn;
            }
        }

    void insertAtFirst(type key){

        Node<type>* nn = new Node<type>();

            nn->data = key;

            if(head == NULL){
                head = nn;
                tail = nn;
            }

            else{
               nn->next = head;
               head->prev = nn;
               head = nn; 
            }
        }

    void inserAtAnyPos(int pos, type key){

        Node<type>* newnode = new Node<type>();

            newnode->data = key;

            if (pos == 1) 
            { 
                newnode->next = head;
                head->prev = newnode;
                head = newnode; 

                return; 
            } 
            
            Node<type>* temp = head; 

            for (int i = 1; i < pos - 1; i++) 
            { 
                temp = temp->next; 
            } 
        
            newnode->next = temp->next;
            newnode->prev = temp;
            Node<type>* temp2 = temp->next;
            temp2->prev = newnode;
            temp->next = newnode; 
        }


    void insertBeforeElement(type olddata, type newdata){
            
        Node<type> *temp = head;

        int position =1;
        int check = 0;
        while(temp!=NULL){
        if(temp->data==olddata)
            {
                 check = 1;
                break;
            }

          else{

            temp=temp->next;
            position++;

             }

         }

        if(check==1){

        inserAtAnyPos(position,newdata);

        }

    else{

        cout << "Data not found before "<<olddata<<endl;

    }
    
    }

    void deleteElementByValue(type key){

            Node<type>* temp = head;
            Node<type>* prev1 =NULL;
            Node<type>* front1 =NULL;

            if(head->data == key){

                head = head->next;
                head->prev = NULL;
                return;

            }

            while(temp != NULL){
                if(temp->data == key){

                    prev1->next = temp->next;
                    front1 = temp->next;
                    front1->prev=prev1;
                    if(tail == temp){
                        tail = prev1;
                        tail->next = NULL;
                    }

                }

                prev1=temp;
                temp = temp->next;
            }

        }

    void deleteAtPos(int n){ 
    
            if (head == NULL) 
            { 
                cout << "Empty Doubly Linkedlist " << endl; 
                return; 

            } 

            Node<type>* temp = head; 
            if (n == 1) 

            { 
                head = temp->next;
                head->prev = NULL;
            return; 
            } 

            for (int i = 1; i < n - 1; i++) 
            { 
                temp = temp->next; 
            } 

            Node<type>* temp2 = temp->next; 
            temp->next = temp2->next;
            Node<type>* temp3 = temp2->next;
            temp3->prev = temp2;
            return; 

        } 

    void displayList(){
            Node<type>* temp = head;
            cout<<"The element of Doubly Linkedlist: "<<endl;
            while(temp != NULL){
                cout << temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

    };


//Stack Class
template <class type>
class Stack{

        public: 

        Node <type>* top;
        int size;
        
        Stack(){

            top = NULL;
            size = 0;

        }

        void Push(int x){

            Node<type>* nn = new Node<type>(x);
            nn->next = top;
            top =nn;
            size++;
            nn = top;

        }

        void pop(){

            if(top == NULL){
                cout<<"Stack is empty. "<<endl;
                return;
            }

            Node<type>* res = top;
            top = top->next;
            size--;
            
        }

        void Top(){

            if(top==NULL){
                cout<<"Stack is empty."<<endl;
                return;
            }

            else{
                cout<<"Top element is: "<<top->data<<endl;
            }

        }
    
    };

//Queue Class
template <class type>
class Queue{

    public:

    Node <type>* front;
    Node <type>* rear;

    Queue(){

        front = NULL;
        rear  = NULL;
    }

    void enqueue(type x){

        Node <type>* n = new Node<type>(x);

        if(front == NULL){

            front=rear=n;
            return;
        }

        rear->next = n;
        rear = n;

    }

    void dequeue(){

         if(front == NULL){
            cout<<"Queue is already empty"<<endl;
            return;
         } 

         Node<type> *todelete = front;
         front = front->next;
         delete todelete;

    }

    void Front(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            cout<<"Front element of queue is: "<<front->data<<endl;
        }
    }

    void Rear(){
        if(rear==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            cout<<"Rear element of queue is: "<<rear->data<<endl;
        }
    }

    };

//BST Class
template <class type>
class BST{

    public: 
    Node<type>* root;

    BST(){
        root = NULL;
    }

    void insertBST(type x){
        Node <type> *nn = new Node <type>();
        nn->data = x;

        if(root==NULL){
            root = nn;
        }
        else{
            Node <type> * curr= root;
            Node <type> * p = NULL;

            while(curr!=NULL){
                p = curr;
                if(x<p->data){
                    curr = p->left;
                }
                else{
                    curr= p->right;
                }
            }

            if(x<p->data){
                p->left = nn;
            }
            else{
                p->right = nn;
            }
        }
    }

    Node<type>* searchInBST(Node <type> *root, type key){

        if(root == NULL){

            return NULL;
        }

        if(root->data == key){

            return root;
        }

        if(root->data > key){

            return searchInBST(root->left, key);
        }

        return searchInBST(root->right,key);
    }

    void displayInorder(Node <type> *node){
        if(node==NULL){
            return;
        }

        displayInorder(node->left);
        cout<<node->data<<" ";
        displayInorder(node->right);
    }

    void displayPostorder(Node <type>* node){
        
        if(node==NULL){
            return;
        }
        displayPostorder(node->left);
        displayPostorder(node->right);
        cout<<node->data<<" ";
    }

    void displayPreorder(Node <type>* node){
        
        if(node==NULL){
            return;
        }
        cout<<node->data<<" ";
        displayPreorder(node->left);
        displayPreorder(node->right);
        
    }

};


int main(){

    //SingleLinkedList
    cout<<"Single Linkedlist Operation Starts Here"<<endl;
    SingleLinkedList<int>sl;

    sl.insertAtFirst(10);
    sl.insertAtAnyPos(2,20);
    sl.insertAtAnyPos(3,30);
    sl.insertAtAnyPos(4,40);
    sl.insertAtAnyPos(5,50);
    sl.insertAtAnyPos(6,60);
    sl.insertAtAnyPos(7,70);
    sl.insertAtAnyPos(8,80);
    sl.insertAtAnyPos(9,90);
    sl.insertAtLast(100);
    sl.insertBeforeElement(100,99);
    sl.insertBeforeElement(80,79);
    sl.displayList();

    cout<<"After Deletion Operation: "<<endl;
    sl.deleteAtPos(3);
    sl.deleteElementByValue(60);
    sl.displayList();
    

    SingleLinkedList<char>slc;

    slc.insertAtFirst('t');
    slc.insertAtFirst('a');
    slc.insertAtFirst('n');
    slc.insertAtFirst('v');
    slc.insertAtLast('i');
    slc.insertAtAnyPos(2,'w');
    slc.insertAtAnyPos(3,'z');

    slc.displayList();

    cout<<"After Deletion Operation: "<<endl;
    slc.deleteAtPos(3);
    slc.deleteElementByValue('w');
    slc.displayList();

    cout<<"Single Linkedlist Operation Completed Here!!!!\n"<<endl;



    //DoubleLinkedList

    cout<<"Double Linkedlist Operation Starts Here"<<endl;
    DoubleLinkedList <int> dl;
    dl.insertAtLast(22);
    dl.insertAtFirst(32);
    dl.inserAtAnyPos(2,42);
    dl.insertAtLast(55);
    dl.insertBeforeElement(55,54);
    dl.insertBeforeElement(32,33);
    dl.insertAtLast(65);
    dl.displayList();
    cout<<"After Deletion Operation: "<<endl;
    dl.deleteAtPos(1);
    dl.insertAtLast(96);
    dl.displayList();
    cout<<"Double Linkedlist Operation Completed Here!!!!\n"<<endl;

    //Stack
    cout<<"Stack Operation Starts Here"<<endl;
    
    Stack<int> ss;

    ss.Push(10);
    ss.Push(20);
    ss.Push(30);
    ss.Push(40);
    ss.Push(50);
    ss.Push(60);
    ss.Top();
    ss.pop();
    ss.Top();
    ss.pop();
    ss.pop();
    ss.pop();
    ss.pop();
    ss.Top();
    ss.pop();
    ss.Push(69);
    ss.Top();
    ss.pop();
    ss.Top();
    
    cout<<"Stack Operation Completed Here!!!!\n"<<endl;

    //Queue
    cout<<"Queue Operation Starts Here"<<endl;
    Queue<int> qq;

    qq.enqueue(12);
    qq.enqueue(13);
    qq.enqueue(14);
    qq.enqueue(15);
    qq.enqueue(16);
    qq.enqueue(18);

    qq.Front();
    qq.dequeue();
    qq.Front();
    qq.dequeue();
    qq.Front();
    qq.dequeue();
    qq.Front();
    qq.dequeue();
    qq.Front();

    qq.Rear();
    
    cout<<"Queue Operation Completed Here!!!!\n"<<endl;
    

    //BST
    cout<<"BST Operation Starts Here"<<endl;

    BST <int> tree;
    
    tree.insertBST(45);
    tree.insertBST(16);
    tree.insertBST(49);
    tree.insertBST(47);
    tree.insertBST(32);
    tree.insertBST(64);
    tree.insertBST(132);
    tree.insertBST(80);
    tree.insertBST(90);
    tree.insertBST(30);
    tree.insertBST(23);
    tree.insertBST(11);

    cout<<"Inorder is: ";
    tree.displayInorder(tree.root);
    cout<<"\nPostorder is: ";
    tree.displayPostorder(tree.root);

    cout<<"\nPreorder is: ";
    tree.displayPreorder(tree.root);



   if(tree.searchInBST(tree.root,11) == NULL){

        cout<<"Key not found in BST"<<endl;

   }

   else{
        cout<<"\nKey found in BST "<<endl;
   }

   if(tree.searchInBST(tree.root,0) == NULL){

        cout<<"Key not found in BST"<<endl;

   }

   else{
        cout<<"Key found in BST "<<endl;
   }

    cout<<"BST Operation Completed Here!!!!"<<endl;



    return 0;
}
