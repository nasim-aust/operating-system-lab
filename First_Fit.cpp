#include<bits/stdc++.h>

int main()
{
    int i,j,memReq,memHole,arr1[100],arr2[100],flag=0,val,status=0,sum=0;
    //freopen("file.txt","r",stdin);

    printf("Enter memReq : ");
    scanf("%d", &memReq);

    printf("Enter memReq Array : ");
    for(i=0; i<memReq; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter memHole : ");
    scanf("%d", &memHole);

    printf("Enter memHole Array : ");
    for(i=0; i<memHole; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("\nEntered memReq Array : ");
    for(i=0; i<memReq; i++)
    {
        printf("%d ", arr1[i]);
    }

    printf("\nEntered memHole Array : ");
    for(i=0; i<memHole; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n\n\n");

    while(flag != memReq)
    {
        val = arr1[flag];
        //printf("%d ",val);
        for(i=0; i<memHole; i++)
        {
            if((val <= arr2[i]) && (status!=1))
            {
                arr2[i]=arr2[i]-val;
                status=1;
            }
            printf("\n%d", arr2[i]);
        }
        printf("\nAllocation\n");
        status=0;
        flag++;
    }

    for(i=0; i<memHole; i++)
    {
        //printf("%d\n",arr2[i]);
        sum = sum + arr2[i];
    }
    printf("\nExternal Fragmentation: %d\n",sum);

}
