class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size(), maxs = INT_MIN;
        vector<int> v; 
        deque <int> q;
        int i = 0 , j =0 , curr = INT_MIN;
        while(j < n){
            while( !q.empty() && arr[q.back()] < arr[j]){
                q.pop_back();
            }
            q.push_back(j);
            if(q.front() < i){
                q.pop_front();
            }
            if( j - i + 1 == k){
                v.push_back(arr[q.front()]);
                i++;
            }
            j++;
        }
        return v;
    }
};
