#include<stdio.h>
int main()
{
	int n,pages[20],frames,i,j,temp[10];
	int flag1,flag2,faults=0,pos=0;
	printf("Enter no. of pages:");
	scanf("%d",&n);
	printf("Enter reference string:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("Enter no. of frames:");
	scanf("%d",&frames);
	for(i=0;i<frames;i++)
	{
		temp[i]=-1;
	}
	printf("\n Page reference string | frames\n");
	for(i=0;i<n;i++)
	{
		flag1=flag2=0;
		for(j=0;j<frames;j++)
		{
			if(temp[j]==pages[i]){
				flag1=flag2=1;
				break;
			}
		}
		if(flag1==0){
		for(j=0;j<frames;j++){
			if(temp[j]==-1){
				temp[j]=pages[i];
				flag2=1;
				faults++;
				break;
			}
		}
		}
	
	if(flag2==0){
		temp[pos]=pages[i];
		pos=(pos+1)%frames;
		faults++;
	}
	printf("\n %2d\t\t\t",pages[i]);
	for(j=0;j<frames;j++){
		if(temp[j]!=-1){
			printf("%2d",temp[j]);
		}else{
			printf("- ");
		}
	}
	}
	printf("\n\ntotal pages faults=%d\n",faults);
	return 0;
	
}   
