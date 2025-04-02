#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value):data(value),next(nullptr){}
};
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList():head(nullptr){}

    void insertAtBeginning(int data){
        Node* newNode = new Node(data);
        newNode->next=head;
        head=newNode;
        cout<<"Node inserted at the beginnig."<<endl;
    }

    bool search(int key){
        Node* temp=head;
        while(temp){
            if(temp->data==key){
                cout<<"Element"<<key<<"found int the list."<<endl;
                return true;
            }
            temp=temp->next;
        }
        cout<<"Element"<<key<<"not found in the list."<<endl;
        return false;
    }

    void deleteNode(int key){
        if(!head){
            cout<<"List is empty."<<endl;
            return;
        }
        if(head->data==key){
            Node* temp=head;
            head=head->next;
            delete temp;
            cout<<"Node with value "<<key<<" deleted from the list."<<endl;
            return;
        }
        Node* temp=head;
        while(temp->next&&temp->next->data!=key){
            temp=temp->next;
        }
        if(!temp->next){
            Node* toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
            cout<<"Node with value "<<key<<" deleted from the list."<<endl;

    }
    else{
        cout<<"Element  not found."<<endl;
    }
    }

    void reverse(){
        Node* prev = NULL;
        Node* current = head;
        Node* next = nullptr;

        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout<<"Linked list reversed."<<endl;

    }
    void display(){
        Node* temp = head;
        if(! temp){
        cout<<"List is empty."<<endl;
        }
        cout<<"Linked list:";
        while(temp){
            cout<<temp->data<<" ->";
            temp = temp->next;

}
cout<<"NULL"<<endl;
    }

};

int main(){
    LinkedList list;
    int choice ,value;
    do{
  
    
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
        cout<<"|===Dynamic Memory Allocation===|"<<endl;
        cout<<"|-------------------------------|"<<endl;
        cout<<"|             MENU:             |  "<<endl;
        cout<<"|    1. Insert at the beginning |  "<<endl;
        cout<<"|    2. Search Element          |  "<<endl;
        cout<<"|    3. Delete Node             |  "<<endl;
        cout<<"|    4. Reverse Linked List     |  "<<endl;
        cout<<"|    5. Display Linked List     |  "<<endl;
        cout<<"|    6. Exit                    |  "<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
      
      cout <<"Enter your choice: ";
      cin>>choice;

      switch(choice){
        case 1:
        cout<<"Enter the value to be inserted: ";
        cin>>value;
        list.insertAtBeginning(value);
        break;

        case 2:
        cout<<"Enter the value to be searched: ";
        cin>>value;
        list.search(value);
        break;

        case 3:
        cout<<"Enter the value to be deleted: ";
        cin>>value;
        list.deleteNode(value);
        break;

        case 4:
        list.reverse();
        break;

        case 5:
        list.display();
        break;

        case 6:
        cout<<"Exiting program..."<<endl;
        break;

        default:
        cout<<"Invalid choice. Please choose a valid option."<<endl;
    
      }

    }
    while(choice!=6);

}