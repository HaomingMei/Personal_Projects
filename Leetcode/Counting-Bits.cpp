class Solution {
public:
    vector<int> countBits(int n) {
        int tracker = 1; // As we iterate from 1 to n, the tracker updates when the value is double. This means we will reuse the previous pattern but there would be an addition 1 because of the "double"

        // For example 2->4
        // 010 to 100. The numbers from 4-7 are 3 bits, and will 
        // Repeat everything before 100 101 110 111
        // Note that 0->3 is 00 01 10 11
        // Using this, we can take the value from before and add 1 to it

        vector<int> try_it(n+1);
        for(int i = 1; i <= n; i++)
        {
            if(i == (tracker * 2)){
                tracker = i;
            }
            // Tracker will shift it to the corresponding sequence we repeat
            try_it[i] = try_it[i-tracker] + 1; // +1 because of the new 1 in front
        }
        return try_it;
    }
};