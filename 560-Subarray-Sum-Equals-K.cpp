class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        //SLIDING WINDOW
        unordered_map<int,int> pre ;
        int curr = 0 , count = 0;
        //pre[sum] = index
        //sum(0 to i) = a
        //sum(i to j) = k 
        // a+k = b
        pre[0] = 1;
        for(int i = 0 ; i <arr.size();i++){
            curr += arr[i];
            if(pre.find(curr-k) != pre.end()){
                count+= pre[curr-k];
            }
            pre[curr]++;
        }
        return count++;
    }
};
