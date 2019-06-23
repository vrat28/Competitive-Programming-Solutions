/*You can check the input graph in console tab
Create Queue => queue = myQueue(5), where 5 is size of queue
Functions of Queue => queue.enqueue(int), queue.dequeue(), size(), peek(), isEmpty()
class graph => {vertices, array}
class linkedList => {Node headNode}
class Node => {int data, Node nextElement}
Breadth First Traversal of Graph g from source vertex
*/

#include<string>
using namespace std;


string bfsTraversal(Graph g, int source) {
   string result = "";

   int number_of_vertices = g.getVertices();
   myQueue queue(number_of_vertices);
   
   bool * visited_vertices = new bool [number_of_vertices];
   int current ;
   queue.enqueue(source);
   visited_vertices[source] = true;

   while (!queue.isEmpty()){
      current = queue.dequeue();
      result += to_string(current);
      Node * temp = (g.getArray())[current].getHead();

      while (temp!= NULL){

         if (visited_vertices[temp->data] == false){
            queue.enqueue(temp->data);
            visited_vertices[temp->data] = true;
         }   

         temp = temp->nextElement;
      }

   }
   return result; 
}
