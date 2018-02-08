class Solution {
public:
    int numTrees(int n) {
        /* 
        // Dynamic programming based on G(n) = SUM(G(i-1)*G(n-i)), 0 <= i <= n, O(n2)
        vector<int> G (n+1,0); ;
        G[0] = 1;
        G[1] = 1;
        
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                G[i] += G[j-1] * G[i-j];
            }
        }
        
        return G[n];
        */
        
        // Catalan Number optimization Cn = (2n; n)/(n+1), O(n)
        long long ans = 1;
        for(int i=1; i<=n; i++)
            ans = ans*(i+n)/i;
        
        return ans/(n+1);
    }
};
