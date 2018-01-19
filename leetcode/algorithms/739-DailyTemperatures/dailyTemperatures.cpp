class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size(), 0);
        vector<int> stack;
        vector<int> index;
        
        // push first day temperature
        stack.push_back(temperatures[0]);
        index.push_back(0);
        
        // loop through all temperatures/days
        for(int i=1; i<temperatures.size(); i++) {
            while(!stack.empty() && temperatures[i] > stack.back()) {
                // temperature increased
                int j = index.back();
                days[j] = i-j;
                stack.pop_back();
                index.pop_back();
            }
            stack.push_back(temperatures[i]);
            index.push_back(i);
        }
        return days;
    }
};
