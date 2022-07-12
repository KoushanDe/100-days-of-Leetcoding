class Solution {
public:
    bool isPossible(vector<int>& matchsticks, int i, int& target, int s1, int s2, int s3, int s4)
    {   
        if(i==matchsticks.size())
            return (s1==target&&s2==target&&s3==target&&s4==target);
        
        bool side1 = s1+matchsticks[i]<=target?isPossible(matchsticks,i+1,target,s1+matchsticks[i],s2,s3,s4):false;
        if(side1==true) return true;
        
        bool side2 = s2+matchsticks[i]<=target?isPossible(matchsticks,i+1,target,s1,s2+matchsticks[i],s3,s4):false;
        if(side2==true) return true;
        
        bool side3 = s3+matchsticks[i]<=target?isPossible(matchsticks,i+1,target,s1,s2,s3+matchsticks[i],s4):false;
        if(side3==true) return true;
        
        bool side4 = s4+matchsticks[i]<=target?isPossible(matchsticks,i+1,target,s1,s2,s3,s4+matchsticks[i]):false;
        if(side4==true) return true;

        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        int sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        
        if(sum%4!=0) return false;
        
        int target = sum/4;
        
        //to reduce potential function calls in backtracking
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        return isPossible(matchsticks,0,target,0,0,0,0);
        
        //in this problem i learnt some problems cannot be solved by simply converting recursion to dp. if this approach was converted to dp we must have used 5d vector or 5d map which was a nightmare. AND THIS IS SURELY A HARD PROBLEM
    }
};