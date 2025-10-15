#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node*next;
    Node(int x){
        this->data = x;
        this->next = nullptr;
    }
};

class linkList{
    private:
    Node* head;
    public:
    int n = 0;
    linkList(){
        head = nullptr;
    }
    
    void traver(){
        Node* cur = head;
        while (cur !=nullptr)
        {
            cout << cur->data << "->";
            cur = cur->next;
        }
        cout << "NULL" << endl;
        cout << n <<endl;
    }

    void insertFront(int val){
        Node* new_node = new Node(val);
        new_node->next = head;
        head = new_node;
        n++;
    }

    void insertEnd(int val){
        Node* new_node = new Node(val);
        if (head == nullptr)
        {
            head = new_node;
            n++;
            return;
        }
        
        Node* cur = head;

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = new_node;
        n++;
    }
    void insertAt(int val , int pos){
        Node* new_node = new Node(val);
        if (pos <= 1)
        {
            insertFront(val);
            return;
        }
        
        if (pos > n)
        {
           insertEnd(val);
           return;
        }
         Node* cur = head; 
        for (int i = 1; i < pos - 1; i++)
        {
            cur = cur->next;
        }
        
        new_node->next = cur->next;
        cur->next      = new_node;
        n++;
    }
    void deleteFront(){
        if (head == nullptr)
        {
            cout << " node is empty\n ";
        }
        
        Node* temp = head;
        
        head = head->next;

        delete temp;
        n--;
    }
    void deleteEnd(){
        if (n == 0)
        {
            cout << "node is empty\n";
        }
        
        if (n == 1)
        {
            delete head;
            head = nullptr;
        }
        
        Node* cur = head;
        while (cur->next->next != nullptr)
        {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
        n--;
    }
    void deleteAt(int pos){
        Node* temp = head;
        if (n == 0)
        {
            cout <<"node is empty\n";
            return;
        }

        if (pos == 1)
        {
            deleteFront();
            return;
        }
        
        if ( pos == n)
        {
            deleteEnd();
            return;
        }
        Node* cur = nullptr;
        
        for (int i = 1; i < pos ; i++)
        {
            cur = temp;
            temp = cur->next;
        }
        
        cur->next = temp->next;

        delete head;
        n--;
    }
    void swapNode(int val1,int val2){
        if (val1 == val2 ) return;

        Node* prv_val1 = nullptr , *cur_val1 = head;
        Node* prv_val2 = nullptr , *cur_val2 = head;

        while (cur_val1&&cur_val1->data != val1)
        {
           prv_val1 = cur_val1;
           cur_val1 = cur_val1->next;
        }
        
        while (cur_val2&&cur_val2->data != val2)
        {
            prv_val2 = cur_val2;
            cur_val2 = cur_val2->next;
        }
        
        if (cur_val1 == nullptr || cur_val2 == nullptr)
        {
            return;
        }
        if (prv_val1 != nullptr)
        {
            prv_val1->next = cur_val2;
        }
        else{
            head = cur_val2;
        }

        if (prv_val2 != nullptr)
        {
            prv_val2->next = cur_val1;
        }
        else{
            head = cur_val1;
        }

        Node* temp = cur_val1->next;
        cur_val1->next = cur_val2->next;
        cur_val2->next = temp;
    }
    bool searchLinklist( int key){
        Node* cur = head;
       while (cur != nullptr)
       {
            if (cur->data == key)
            {
            return true;
        }
        cur = cur->next;
       }
       return false;
    }
};

int main (){
    linkList link;
    link.insertFront(0);
    link.insertFront(10);
    link.insertFront(20);
    link.insertFront(30);
    link.insertFront(40);
    link.insertFront(50);
    link.swapNode(50,20);
    link.traver();
    if (link.searchLinklist(60))
    {
       cout<<"True\n";
    }else{
        cout <<"False\n";
    }
    
   return 0;
}