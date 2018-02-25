class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        for(int i=x; i!=0; i=i/10) {
            // check for multiplication overflow (*10 can move 3 bits at most)
            if((reverse >> 31) != (reverse >> 28))
                return 0;
            
            // update number
            reverse = (reverse*10)+(i%10);
            
            
            // check for addition overflow (+9 can move 1 bit at most)
            if((reverse!=0) && ((x >> 31) != (reverse >> 31)))
                return 0;
        }
        
        return reverse;
    }
};