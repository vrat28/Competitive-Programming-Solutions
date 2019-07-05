
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KLargestNumbers {
 public:
 struct greater {
    bool operator()(const int& a, const int& b) const { return a > b; }
  };

  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {

    vector <int> minHeap(nums.begin(), nums.begin()+k);
     
    std::make_heap(minHeap.begin() ,minHeap.end() ,greater() );
    for (int i = k; i < nums.size();i++){

            if (nums[i] > minHeap.front()){

                    std::pop_heap(minHeap.begin() ,minHeap.end() ,greater() );
                    minHeap.pop_back();
                    minHeap.push_back(nums[i]);
                    std::push_heap(minHeap.begin() ,minHeap.end() ,greater() );

            }
    }
    return minHeap;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
