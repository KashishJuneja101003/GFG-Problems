class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        if(arr.size() == 0) return;
        
        cout<<arr.back()<<" ";
        arr.pop_back();
        
        reverseArray(arr);
    }
};
