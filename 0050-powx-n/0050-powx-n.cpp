class Solution {
public:
    double Pow(double x, long long n){
        if(x == 1 || n == 0) return 1;
        if(x == 0) return 0;
        if(n%2){
            //odd
            return x*Pow(x*x, n/2);
        }
        else{
            //even
            return Pow(x*x, n/2);
        }
    } 
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0) {
            N = -1*N; x = 1/x;
        }
        return Pow(x, N);
        
    }
};