#include <queue>
#include <string>
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        //* Making a max heap, where we store the index and score 
        priority_queue<pair<int,int>> hp;
        int numScores = score.size();
        //Push all the scores
        for(int i = 0; i<numScores; i++){
            hp.push({score[i], i});
        }

        std::vector<string> ranking(numScores);
        int rankNum = 1;
        int old_RankIndex;
        while(!hp.empty()){
            old_RankIndex = hp.top().second;
            if(rankNum == 1){
                ranking[old_RankIndex] = "Gold Medal";
            }
            else if(rankNum ==2){
                ranking[old_RankIndex] = "Silver Medal";
            }
            else if(rankNum ==3){
                ranking[old_RankIndex] = "Bronze Medal";
            }
            else{
                ranking[old_RankIndex] = to_string(rankNum);
            }
            rankNum +=1;
            hp.pop();
        }
        return ranking;
    }
};