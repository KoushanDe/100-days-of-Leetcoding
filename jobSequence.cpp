// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool compareJobs(Job& j1, Job& j2)
    {
        if(j1.profit>j2.profit) return true;
        else if(j1.profit==j2.profit) return j1.dead>j2.dead;
        else return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {   
        vector<int> deadline(101,-1);
        
        sort(arr,arr+n,compareJobs);
        
        
        int job=0,profit=0;
        for(int i=0;i<n;i++)
        {   
            
            if(deadline[arr[i].dead]==-1)
            {
                job++;
                profit+=arr[i].profit;
                deadline[arr[i].dead] = i;
            }
            else
            {   
                for(int j=arr[i].dead-1;j>0;j--)
                {
                    if(deadline[j]==-1)
                    {
                        job++;
                        profit+=arr[i].profit;
                        deadline[j] = i;
                        break;
                    }
                }
            }
        }
        
        return {job,profit};
    } 
};

