class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l = 0 ;
        int m = 0;
        int h = arr.size() -1;
        while(m <= h){
            if( arr[m] == 0){
                swap(arr[l++],arr[m++]);
            }else if(arr[m] == 1){
                m++;
            }else{
                swap(arr[m], arr[h--]);
            }
        }
    }
};
