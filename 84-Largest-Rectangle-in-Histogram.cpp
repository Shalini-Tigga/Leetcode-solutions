class Solution {
public:
    vector<int> nextLesserElement(vector<int>& arr){
        int n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = 0 ; i < n ; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                res[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            res[s.top()] =n;
            s.pop();
        }
        return res;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int> nle = nextLesserElement(arr);
        reverse(arr.begin() , arr.end());
        vector<int> ple = nextLesserElement(arr);
        int n = arr.size();
        for(auto &it : ple){
            it = n - it - 1;
        }
        reverse(arr.begin() , arr.end());
        reverse(ple.begin() , ple.end());
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            ans = max(ans, arr[i]*(nle[i] - ple[i] -1));
        }
        return ans;
    }
};
