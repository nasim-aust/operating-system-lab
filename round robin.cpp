#include <stdio.h>
int main()
{
	int p[10],at[10],bt[10],wt[10],tat[10],rem[10],tot[10];
	int n,i,j,temp,q,flag=1,time=0;
	float aw=0, att=0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	for(i=0; i<n;i++)
	{
		p[i] = i;
		printf("burst time of p[%d] ",p[i]);
		scanf("%d",&bt[i]);
		rem[i] = bt[i];
		tot[i] = 0;

	}
	printf("enter q ");
	scanf("%d",&q);



	printf("proc\trem time\ttotal time\n");
	while(flag)
	{
		flag=0;
		for(i=0; i<n; i++)
		{
			if(rem[i]>0)
			{
				if(rem[i] <= q )
				{
					time += rem[i];
					rem[i] = 0;
					tot[i] = time;
					printf("p[%d] \t\t %d \t\t %d\n",i+1,rem[i],tot[i]);
				}
				else
				{
					rem[i] -= q;
					time += q;
					tot[i] = time;
					printf("p[%d] \t\t %d \t\t %d\n",i+1,rem[i],tot[i]);
				}

			}
		}

		for(i=0; i<n; i++)
		{
			if(rem[i]!=0)
			{
				flag=1;

			}
		}
	}

	return 0;
}
