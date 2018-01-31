#include<stdio.h>
int main()
{
    int i,j,memR,memH,count=0,flag=0,req[100],hole[100],val=0,k,memory,sum=0,sub=999;

    //freopen("file.txt","r",stdin);

    printf("Enter no of Memory  Requests: ");
    scanf("%d",&memR);

    printf("Enter the process requests: ");
    for(i=0; i<memR; i++)
    {
        scanf("%d",&req[i]);
    }

    printf("Enter no of Memory  Hole: ");
    scanf("%d",&memH);

    printf("Enter the Memory Holes: ");
    for(i=0; i<memH; i++)
    {
        scanf("%d",&hole[i]);
    }

    printf("Memory Requests\n");
    for(i=0; i<memR; i++)
    {
        printf("%d\n",req[i]);
    }

    printf("Memory Holes\n");
    for(i=0; i<memH; i++)
    {
        printf("%d\n",hole[i]);
    }

    printf("\nOutput\n");
    while(count<memR)
    {
        val=req[count];
        //printf("\nval:%d\n",val);

        for(i=0; i<memH; i++)
        {
            if((hole[i]-val) >= 0 )
            {
                //sub = hole[i]-val;
                //printf("%d ",sub);
                if(sub>=(hole[i]-val) )
                {
                    sub=hole[i]-val;
                       k=i;
                }
            }
        }
        printf("\nK: %d\n",hole[k]);
        hole[k]=hole[k]-val;
        printf("\nMemory Holes\n");
        for(i=0; i<memH; i++)
        {
            printf("%d\n",hole[i]);
        }

        //printf("\n%d\n ",sub);
        count++;
        sub=999;
    }

    for(i=0;i<memH;i++)
    {
        sum=sum+hole[i];
    }
    printf("\nExternal Fragmentation: %d\n",sum);

}
