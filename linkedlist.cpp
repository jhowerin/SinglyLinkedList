#include<iostream>

class Node {
public:
  int val;
  Node *next;
};

class MyLinkedList {
private:
  Node *head;
  int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
      head = NULL;
      size = 0;
      std::cout << "Linked List created\n";
    }

    void display() {
      std::cout << "In the display method\n";
      Node *temp=new Node;
      temp=head;
      while(temp!=NULL) {
        std::cout<<temp->val<< " at address " << temp << " pointing to " << temp->next << std::endl;
        temp=temp->next;
      }
      std::cout<< "The linked list size is " << size << std::endl;
      std::cout << std::endl;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
      //if the index value is negative, just return -1
      if(index<0)
        return -1;
      if(index>size-1)
        return -1;
      //1 create a counter
      int count=0;
      //2 - create a temporary Node
      Node *temp = new Node;
      //3 - set temp equal to head so we can iterate through the linked list
      temp = head;
      //3 - iterate through the nodes until you get to the index place
      while(count < index && temp->next != NULL){
        temp = temp->next;
        count++;
      }
      //4 - return the value of temp
      if(count==index)
        return temp->val;
      else
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
      //1 - create a temporary Node
      Node *temp = new Node;
      //2 - add the value to the temporary Node
      temp->val = val;
      //3 - point the new node to next
      temp->next = head;
      //4 - now head is actually this temp Node
      head = temp;

      //increment the linked list size
      size++;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      //1 - create a temporary Node
      Node *temp = new Node;
      //2 - create a last node
      Node *last = new Node;
      //3 - set temp to head
      temp = head;
      //4 - run through the list until you find next
      //that tells you you are at the last node
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = last;
      last->val = val;
      last->next = NULL;

      //increment the linked list size
      size++;

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
      Node *pre=new Node;
			Node *cur=new Node;
			Node *temp=new Node;
			cur=head;

      if(index==0){
        addAtHead(val);
        return;
      }

      if(index==size){
        addAtTail(val);
        return;
      }

      for(int i=0;i<index;i++) {
      		pre=cur;
      		cur=cur->next;
      }

  		temp->val=val;
  		pre->next=temp;
  		temp->next=cur;
      size++;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

      Node *temp=new Node;
      Node *cur =new Node;
      Node *prev=new Node;

      cur = head;

      //resetting the head to point to the next node.
      if(index==0){
        head = cur->next;
        size--;
        return;
      }

      if(index>=size){
        std::cout << "Index out of range\n";
        return;
      }

      if(index > size)
        return;

      for(int i=0;i<index;i++) {
        prev=cur;
        cur=cur->next;
      }
      prev->next=cur->next;
      size--;

    }
};

int main() {
 //Your MyLinkedList object will be instantiated and called as such:
 //MyLinkedList obj = new MyLinkedList();
 MyLinkedList obj;
 //int param_1 = obj.get(index);
 //obj.addAtHead(val);
 //obj.addAtTail(val);
 //obj.addAtIndex(index,val);
 //obj.deleteAtIndex(index);

 char ans;
 while(ans!='q') {
   std::cout << "Linked List Menu\n";
   std::cout << "****************\n";
   std::cout << "<1> Display\n";
   std::cout << "<2> Add at Head\n";
   std::cout << "<3> Add at Tail\n";
   std::cout << "<4> Get value at index x\n";
   std::cout << "<5> Add at index x\n";
   std::cout << "<6> Delete at index x\n";
   std::cout << "<q> Quit\n";
   std::cin >> ans;
   switch(ans) {
      case '1':
        std::cout << "Calling Display\n";
        obj.display();
        break;
      case '2':
        std::cout << "Add at Head\n";
        std::cout << "Please enter a number to add at head\n";
        int headVal;
        std::cin >> headVal;
        obj.addAtHead(headVal);
        break;
      case '3':
        std::cout << "Add at Tail\n";
        std::cout << "Please enter a number to add to the tail\n";
        int tailVal;
        std::cin >> tailVal;
        obj.addAtTail(tailVal);
        break;
      case '4':
        std::cout << "Get Value\n";
        std::cout << "Enter index to get Node value\n";
        int index;
        int theValue;
        std::cin >> index;
        theValue = obj.get(index);
        std::cout << "The value is " << theValue << std::endl;
        break;
      case '5':
        std::cout << "Add Value at Index x\n";
        std::cout << "Enter Index\n";
        int indexValue, theindex;
        std::cin >> theindex;
        std::cout << "Enter Value\n";
        std::cin >> indexValue;
        obj.addAtIndex(theindex, indexValue);
        break;
      case '6':
        std::cout << "Delete Value at Index x\n";
        std::cout << "Enter Index\n";
        int deleteIndex;
        std::cin >> deleteIndex;
        obj.deleteAtIndex(deleteIndex);
        break;
      case 'q':
        std::cout << "Calling quit\n";
        break;
      default:
        std::cout << "In the break\n";
        break;
   }
 }

  return 0;
}
