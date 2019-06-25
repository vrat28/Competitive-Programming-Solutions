// O( Nlog(N) + Mlog(M))
// Space :- O(1)
#include <vector>
#include<bits/stdc++.h>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.

    vector<int> output;
    std::sort (arrayOne.begin(), arrayOne.end()); 
    std::sort (arrayTwo.begin(), arrayTwo.end());   

	int size1 = arrayOne.size();
	int size2 = arrayTwo.size();
    int i = 0, j = 0;

    int minDiff = INT_MAX;
    int minIndex = -1;
    int maxIndex = -1;

    while ( i  < size1 && j < size2){

        int diff = abs(arrayTwo[j] - arrayOne[i]);
        if (diff < minDiff){

             minIndex = i;
            maxIndex = j;
            minDiff = diff;
        }

        if (arrayOne[i]  == arrayTwo[j]){

								
                break ;
        }else if (arrayOne[i] > arrayTwo[j]) {

                j++;
        }   else {
            i++;
        }

    }

    output.push_back(arrayOne[minIndex]); 
    output.push_back(arrayTwo[maxIndex]);
        return output;
}