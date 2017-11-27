class Solution {
public:
    bool validString(string s, int paren) {
        /* base cases */
        if (s.size() == 0) // done
            return (paren==0)? true : false;
        
        if (paren < 0) // invalid
            return false;
        
        /* normal cases */
        // right paren
        if (s[0] == '(')
            return validString(s.substr(1), paren+1);
        
        // left paren
        if (s[0] == ')')
            return validString(s.substr(1), paren-1);
        
        /* special cases */
        // star
        if (s[0] == '*') {
            if (validString(s.substr(1), paren)) // empty string
                return true;
            else if (validString(s.substr(1), paren+1)) // right paren '('
                return true;
            else
                return validString(s.substr(1), paren-1); // left paren ')'
        }
        
        return false; // other symbols are invalid
    }
    
    bool greedyValidString(string s) {
        int high = 0;
        int low = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                high++;
                low++;
            }
            else if (s[i] == ')') {
                high--;
                if (high<0)
                    return false;
                if (low>0)
                    low--;
            }
            else if (s[i] == '*') {
                high++;
                if (low > 0)
                    low--;
            }
        }
        
        if (low > 0)
            return false;

        return true;
    }
    
    bool checkValidString(string s) {
        //return validString(s, 0); // Time limit exceeded (brute force)
        return greedyValidString(s);
        
        /*int paren = 0;
        int star = 0;
        for(int i=0; i<s.size(); i++) {
            if (s[i] == '(')
                paren++;
            else if (s[i] == ')') {
                if (paren == 0) {
                    if (star == 0)
                        return false;
                    else
                        star--;
                } else
                    paren--;
            }
            else if (s[i] == '*')
                star++;
        }
        
        while (paren!=0 && star!=0) {
            paren--;
            star--;
        }
        
        if (paren != 0)
            return false;
            
    
        return true;*/
    }
};
