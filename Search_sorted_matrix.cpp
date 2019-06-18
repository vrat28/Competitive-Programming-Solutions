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
