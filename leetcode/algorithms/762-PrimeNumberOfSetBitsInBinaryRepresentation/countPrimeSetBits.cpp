class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int countPrime = 0;
        int primes[] = {2,3,5,7,11,13,17,19};
        set<int> primeSet (primes,primes+8);
        
        for (int i=L; i<=R; i++) {
            int countSet = 0;
            int num = i;
            while(num>0) { // count set bits
                countSet += num%2;
                num = num/2;
            }
            if(primeSet.find(countSet) != primeSet.end()) countPrime++; // increment if prime set bits
        }
        
        return countPrime;
    }
};
