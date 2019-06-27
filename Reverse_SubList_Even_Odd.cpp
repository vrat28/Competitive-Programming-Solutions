//  Given a LinkedList with ‘n’ nodes, reverse it based on its size in the following way:

// If ‘n’ is even, reverse the list in a group of n/2 nodes.
// If n is odd, keep the middle node as it is, reverse the first ‘n/2’ nodes and reverse the last ‘n/2’ nodes.


#include <iostream>
using namespace std;

class ListNode {
 public:
  int value;
  ListNode *next;

  ListNode() : value(0),next(nullptr) {}

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseSubList {
 public:

  static ListNode *reverseNodesEvenOdd(ListNode * head){
      ListNode * temp = head;
        int n = 0;

        while(temp!=nullptr) {
            temp = temp->next;
            n ++;
            }

        if (n % 2 == 0 ){

            head = reverse(head,1,n/2);
            head = reverse(head,n/2 + 1,n);
        } else {

            head = reverse(head,1,n/2);
            head = reverse(head,n/2 + 2,n);
        }
        return head;
  }  

  static ListNode *reverse(ListNode *head, int p, int q) {
    // TODO: Write your code here

    if (p == q){
      return head;
    }
    ListNode * previous = nullptr;
    ListNode * current = head;

      for (int i = 0 ; i < p-1;i++ ){
        previous = current;
       current = current->next;
      }
      ListNode * firstTail = previous;
      ListNode * middleSegmentHead = current;
      previous = nullptr;
      for (int i = 0 ; i < q - p + 1 ; i++){

          ListNode * temp = current->next;
          current->next = previous;
          previous = current;
          current = temp;
      }

    if (firstTail != nullptr){
      firstTail->next = previous;
    }else {
      head = previous;
    }
      middleSegmentHead->next = current;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  //ListNode *result = ReverseSubList::reverse(head, 2, 4);

  ListNode * result = ReverseSubList::reverseNodesEvenOdd(head);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
