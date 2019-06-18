//https://www.algoexpert.io/questions/Search%20In%20Sorted%20Matrix
//https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

/* 
Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.
Example :

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
Output : Found at (2, 1)

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 100
Output : Element not found

*/

#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int> > matrix, int target) {

	int n = matrix.size();
	int m = matrix[0].size();
	
	int i = 0 ;
	int  j = m - 1;

	while (i < n && j >=0) {
		
		if (matrix[i][j] > target) {
			j--;
		}
		else if (matrix[i][j] < target){
			i++;
		}
		else {
			return {i,j};
		}		
	}

	return {-1,-1};
}
