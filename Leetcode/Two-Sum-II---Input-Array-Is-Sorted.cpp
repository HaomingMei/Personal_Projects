class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> resultVector;
        int i = 0;
        int j = numbers.size()-1;

        while(i<j)
        {
            int sum = numbers[i] + numbers[j] ;
            if(sum == target)
            {
                resultVector.push_back(i+1);
                resultVector.push_back(j+1);
                return resultVector;
            }
            else if(sum>target)
            {
                j--;                
            }
            else{
                i++;
            }

        }
        return resultVector;
    }
};