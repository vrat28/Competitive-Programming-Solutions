//Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.


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

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
