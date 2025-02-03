class Solution {
public:
    static bool comp(pair<int,int> a , pair<int,int> b){
        return a.first < b.first;
    }
    int search(vector<int>& v, int t) {
        int l = 0 , m = 0 , h = v.size()-1;;
        vector<pair<int,int>> res;
        for(int i =0 ; i <= h ; i++){
            res.push_back({v[i] , i});
        }
        sort(res.begin(), res.end(), comp);
        while(l <= h){
            m = l + (h-l)/2;
            if(res[m].first == t){
                return res[m].second;
            }else if (res[m].first > t){
                h = m -1;
            }else{
                l = m +1;
            }
        }
        return -1;
    }
};
