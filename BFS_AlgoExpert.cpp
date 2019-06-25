#include <vector>
#include <queue>

using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
  public:
    string name;
    vector<Node*> children;
    Node(string str) {
      name = str;
    }

    vector<string> breadthFirstSearch(vector<string>* array) {
			
				vector<string> output;

                int number_Vertices = array.size();

                if (number_Vertices== 0){
                        return output;
                }

                Node * firstNode = array[0];
                output.push_back(firstNode.name);





			
      // Write your code here.
      return output;
    }

    Node* addChild(string name) {
      Node* child = new Node(name);
      children.push_back(child);
      return this;
    }
};
