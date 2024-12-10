class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort (target.begin(),target.end());
        sort(arr.begin(),arr.end());
        int lol = 1;
        for(int i = 0 ; i<target.size();i++){
            if(arr[i]!=target[i]){
                lol = 0;
            
            }
        }
        if (lol == 1){
            return true;
        }else{
            return false;
        }
        
    }
};
