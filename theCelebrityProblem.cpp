#include<bits/stdc++.h>
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> st;
    
    for(int i=0;i<n;i++)
        st.push(i);
    
    while(st.size()>1)
    {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
        
        if(knows(A,B)&&!knows(B,A))
            st.push(B);
        else if(!knows(A,B)&&knows(B,A))
            st.push(A);
    }
    
    if(st.size()==1)
    {
        int celeb = st.top();
        
        for(int i=0;i<n;i++)
        {
            if(i!=celeb&&!knows(i,celeb))
                return -1;
        }
        return celeb;
    }
    
    return -1;
}