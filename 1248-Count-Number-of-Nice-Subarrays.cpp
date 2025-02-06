class Solution {
public:
    int atmost (int k, vector<int>& arr){
        int n = arr.size();
        int i = 0 , j  = 0 , count = 0;
        while(j <n){
            if(arr[j] % 2 != 0){
                k--;
            }
            while(k < 0){
                if(arr[i]%2 != 0){
                    k++;
                }
                i++;
            }
            count += j - i + 1;
            j++;

        }
        return count;
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
        return atmost(k,arr) - atmost(k-1,arr);
    }
};
