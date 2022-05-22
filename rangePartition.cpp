#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;

    for(int test=1;test<=T;test++)
    {
        int N,X,Y;
        cin>>N>>X>>Y;

        long long sum=N*(N+1)/2;

        if(sum % (X+Y) != 0)
        {
            cout<<"Case #"<<test<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }

        sum = sum / (X+Y) * X;

        vector<int> list;

        
        while(sum>0)
        {
            if(N>sum)
            {
                list.push_back(sum);
                break;
            }
            else
            {
                list.push_back(N);
                sum = sum-N;
                N--;
            }
        }
        
        
        
            cout<<"Case #"<<test<<": "<<"POSSIBLE"<<endl;
            cout<<list.size()<<endl;
            for(int i=0;i<list.size();i++)
            cout<<list[i]<<" ";
            cout<<endl;
        
    }
}