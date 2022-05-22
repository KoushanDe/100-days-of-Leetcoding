#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;

    for(int test=1;test<=T;test++)
    {
        int N;
        cin>>N;
        string old;
        cin>>old;

        int uletter=0;
        int lletter=0;
        int dig = 0;
        int spch = 0;
        char c;

        for(int i=0;i<N;i++)
        {
            c = old[i];

            if(c=='#'||c=='@'||c=='*'||c=='&')
            spch++;
            else if(c>='0'&&c<='9')
            dig++;
            else if(c>='a'&&c<='z')
            lletter++;
            else if(c>='A'&&c<='Z')
            uletter++;
        }

        if(uletter==0)
        old = old+'A';
        if(lletter==0)
        old = old+'a';
        if(dig==0)
        old=old+'1';
        if(spch==0)
        old = old+'#';

        while(old.size()<7)
        old=old+'1';

        cout<<"Case #"<<test<<": "<<old<<endl;
    }
}