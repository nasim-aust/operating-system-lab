#include<bits/stdc++.h>
#define inf 99999
#define Max 100
using namespace std;
int main()
{
    int i,j,k,m=0,process,Count=0,res,reso[Max],pro,alloc[Max][Max],maxi[Max][Max],need[Max][Max],ava[Max],sum=0,check[Max];

    cout << "Enter no. of processes: ";
    cin >> pro;
    cout <<"Enter no. of resources: ";
    cin >> res;

    cout << "Enter resources: ";
    for(i=0; i<res; i++) scanf("%d",&reso[i]);

    cout << "Enter Allocation Matrix: ";
    for(i=0; i<pro; i++)
    {
        for(j=0; j<res; j++) scanf("%d",&alloc[i][j]);
        check[i]=0;
    }

    cout << "Enter Maximum Matrix: ";
    for(i=0; i<pro; i++) for(j=0; j<res; j++) scanf("%d",&maxi[i][j]);

    printf("\nProcess Allocation\t Max\t Need\n");
    for(i=0; i<pro; i++)
    {
        printf("P[%d] ",i);
        for(j=0; j<res; j++) printf("%d ",alloc[i][j]);
        printf("\t");
        for(j=0; j<res; j++) printf("%d ",maxi[i][j]);
        printf("\t");
        for(j=0; j<res; j++)
        {
            need[i][j] = maxi[i][j]-alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<res; i++)
    {
        for(j=0; j<pro; j++) sum=sum+alloc[j][i];
        ava[i]=reso[i]-sum;
        sum=0;
    }
    printf("\nAvailable: ");
    for(i=0; i<res; i++) printf("%d ",ava[i]);
    printf("\n");

while(m<pro){
    for(i=0; i<pro; i++)
    {
        for(k=0; k<res; k++) if(ava[k]>=need[i][k]) Count++;
        if(Count==res)
        {
            process=i;
            break;
        }
        Count=0;
    }
    Count=0;
    check[m]=process;
    m++;
    printf("\n");
    for(i=0;i<res;i++)
    {
        ava[i]=ava[i]+alloc[process][i];
        need[process][i]=inf;
        printf("%d ",ava[i]);
    }
}
printf("\n");
for(i=0;i<pro;i++) printf("P[%d] ",check[i]);
}
