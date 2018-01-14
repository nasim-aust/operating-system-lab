#include<bits/stdc++.h>
using namespace std;
int ar[100],wt[100],p[100],i,j,k,l,pp,bu[100],n,realburst[100],small,totbu=0,totwt=0,minn;
int main()
{
    cout<<"Enter number of process" <<endl;
    cin >>n;
     cout<<" Enter arrival time and burst time" <<endl;
    for(i=1;i<=n;i++)
    {
        cin >> ar[i] >> bu[i] ;
        p[i]=i;
        totbu+=bu[i];

    }
    // if arrival time is not sorted

    for(i=1;i<=n;i++)
    {

        for(j=i+1;j<=n;j++)
        {
            if(ar[i]>ar[j])
            {
                swap(ar[i],ar[j]);
                swap(bu[i],bu[j]);
                swap(p[i],p[j]);

            }

        }
    }
    for(i=1;i<=n;i++)
    {

        realburst[i]=bu[i];
    }


    int t=0;
    i=1;
    while(t<=totbu)
    {
          if(ar[i]<=t && i<=n)
            {
                k=i;
                i++;

            }
            minn=99999999;
           // cout<<"k  "<<k<<endl;
            for(j=1;j<=k;j++)
            {
                 if(bu[j]<minn&&bu[j]!=0)
                 {

                     minn=bu[j];
                     small=j;
                 }
            }
           // cout <<"small  " <<small <<endl;
            bu[small]--;
            t++;
            if(bu[small]==0)
            {
                wt[small]= t-ar[small]- realburst[small];

            }




    }

   for(i=1;i<=n;i++)
   {

       cout <<p[i] <<"   " <<wt[i] <<endl;
       totwt+=wt[i];

   }
   double avgwt=0;
   avgwt= totwt/(n*1.0);
   cout <<"avg waiting time   "<<avgwt <<endl;


    return 0;
}

