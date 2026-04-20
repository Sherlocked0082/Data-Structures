#include<stdio.h>

int main()
{
    int n;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++)
    {
        int flag=1;
        if(A[i]==1)
            flag=0;
        else if(A[i]==2 || A[i]==3)
            flag=1;
        else
        {
            for(int j=2;j*j<=n;j++)
            {
                if(A[i]%j==0)
                    flag=0;
                break;
            }
        }
        if(flag==1)
            printf(" %d ",A[i]);
    }

}