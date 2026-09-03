// {(2n)!/(n)!*(n+1)!}
//formula used
class Solution {
public:
    int numTrees(int n) {
        long fact = 1;
        for(int i=0;i<n;i++){
            fact *= (2*n-i);
            fact = fact/(i+1);
        }
        return fact/(n+1);
    }
};