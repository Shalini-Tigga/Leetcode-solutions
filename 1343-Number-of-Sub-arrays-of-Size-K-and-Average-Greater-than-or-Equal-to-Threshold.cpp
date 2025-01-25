class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int n = arr.size();
        int i = 0 , j  = 0 , curr = 0, count=0;
        int threshold = k * t;
        while(j <n){
            curr += arr[j];
            if(j-i+1 == k){
                if(curr >=threshold){
                    count++;
                }
                curr-= arr[i];
                i++;
            }
            j++;
        }
        return count;
    }
};
