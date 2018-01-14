#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,p,b[100], w=0,t;
float awt =0,att=0, aw=0, at=0;

printf("Enter the process no : ");
scanf("%d",&n);

for(int i=0; i<n; i++)
{
printf("Enter the burst time for process %d : ",i+1);
scanf("%d",&b[i]);
}

printf("Process \t bt \t wt \t tt");

for(int i=0; i<n; i++)
{
t = w+b[i];
printf("\n %d \t\t %d \t %d \t %d", i+1,b[i],w,t);
at = at + t;
aw = aw+w;
w = w+b[i];

}
att = at/n;
awt = aw/n;

printf("\n Average waiting time: %f and average turnedaround time: %f",awt,att);


return 0;
}
