
// Find three largest numbers from an array and return in sorted order
// https://www.algoexpert.io/questions/Find%20Three%20Largest%20Numbers
// Time - O(N), Space - O(1)

#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
	
		int l1 = INT_MIN;
		int l2 = INT_MIN;
	int l3 = INT_MIN;

	for (int i = 0 ; i < array.size();i++){
		
		if (array[i] > l1){
			
			int temp = l1;
			
			l1 = array[i];
			l3 = l2;
			l2 = temp;
		}
		else if (array[i] > l2) {
			
			 l3 = l2;
			l2 = array[i];
		}
		else if (array[i] > l3){
				l3 = array[i];
		}
	}
	
	
		return {l3,l2,l1};
  // Write your code here.
}
