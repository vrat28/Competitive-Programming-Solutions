#include<stdio.h>
#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:

  static   void swap(vector<int>& arr, int first, int second) {
        int temp = arr[first];
         arr[first] = arr[second];
         arr[second] = temp;
    }

   static  int partition(vector<int>& nums,int left,int right,int pivot){

            int pivotValue = nums[pivot];
            swap(nums,right,pivot);
            int indexOfLesserMostElement = left;

            for (int i = left ; i <= right - 1 ; i++){

                    if (nums[i] < pivotValue){
                        swap(nums,i,indexOfLesserMostElement);
                        indexOfLesserMostElement++;
                    }
            }

            swap(nums,right,indexOfLesserMostElement);

        return indexOfLesserMostElement;
    }


    static int findKthLargest(vector<int>& nums, int k) {
        

        int n  =   nums.size();
        int left = 0;
        int right  = n - 1;
    
        while (left <= right)
        {
            int randomPivotIndex = rand() % right;
            int positionOfPivot = partition(nums,left,right,randomPivotIndex);

            if (positionOfPivot == n - k){

                return nums[positionOfPivot];
            }
            else if (positionOfPivot > n - k){
                right = positionOfPivot - 1;

            }
            else {
                left = positionOfPivot + 1;
            }

        }
    
        return -1;
    }
};


int main(){
    vector<int> sample;
    sample.push_back(1);
    sample.push_back(2);
    sample.push_back(3);
    sample.push_back(4);
    sample.push_back(5 );
    cout << Solution::findKthLargest(sample,2);

    return 0;
}