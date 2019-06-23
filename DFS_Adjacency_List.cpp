#include<stack>
#include<string>
using namespace std;
string dfsTraversal(Graph g, int source) {
	string result = "";
	int number_vertices = g.getVertices();
	stack <int> myStack;
	bool * visited_Nodes = new bool[number_vertices];
	myStack.push(source);
	visited_Nodes[source] = true;

	int current = 0;

	while(!myStack.empty()) {

		current = myStack.top();
		myStack.pop();
		result += to_string(current);

		Node * temp = (g.getArray())[current].getHead();

		while(temp != NULL){

			if (visited_Nodes[temp->data]==false){
				myStack.push(temp->data);
			}		

			temp = temp->nextElement;
		}

	}
	return result; 
}