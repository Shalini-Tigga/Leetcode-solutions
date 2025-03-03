class Solution {
public:
    vector<double> convertTemperature(double c) {
        double k = 0 ; 
        double f = 0;
        k = c + 273.15;
        f = c * 1.80 + 32.00;
        return {k,f};
    }
};
