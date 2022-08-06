/* when eating allowed in every minute, use bit method, gives guaranteed min number of pigs reqd to find out poison
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        double slots = minutesToTest-minutesToDie+1;
            
        int buckslot = ceil((double)(buckets)/slots);
        
        if(slots==1)
        {
            for(int i=0;i<32;i++)
            {
                if(1<<i>=buckslot)
                    return i;
            }
        }
        else
        {
            for(int i=0;i<32;i++)
            {
                if(1<<i>buckslot)
                    return i;
            }
        }
        
        return 0;
    }
};*/

//combinatorics: ki fuke ei solution ta baar koreche janina
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int slots = minutesToTest/minutesToDie;
            
        return ceil(log(buckets)/log(slots+1));
    }
};