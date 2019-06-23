#include <vector>
using namespace std;

void swap(int i, int j, vector<int> * array){
	int temp = array->at(j);
	array->at(j) = array->at(i);
	array->at(i) = temp;
	
}


vector<int> selectionSort(vector<int> array) {
	
	if (array.empty()){
		return {};
	}
	int k = 0;
	
	while(k < array.size() - 1){
		
			int minIndex = k;
			for (int j = k + 1 ; j < array.size();j++){
				
					if (array[minIndex] > array[j]){
						minIndex = j;
					}
			}
		
			swap(k,minIndex,&array);
			k++;
		}
  // Write your code here.
	return array;
}


