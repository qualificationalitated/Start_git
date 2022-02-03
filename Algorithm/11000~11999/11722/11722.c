#include<stdio.h>
int list[1002]={0,};
int main()
{
    int n,arr[1002],height=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	for (int i = 0; i < n; i++)
    {
        int max=0;
		for (int j = 0; j < i; j++)
		{
            if(arr[i]<arr[j])
				if(list[j]>max)
                	max=list[j];
        }
		list[i]=max+1;
		if(height<list[i])
			height=list[i];
    }
    printf("%d",height);
    return 0;
}