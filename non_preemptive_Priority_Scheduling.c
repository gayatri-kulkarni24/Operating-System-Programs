non preemptive priority #include<stdio.h>
#include<stdlib.h>
void main()
{
	int  p[10],AT[10],BT[10],WT[10],TAT[10],pr[10];
	int n,temp,sum=0,i,j;
	float avg=0;
	printf("Enter number of process:");
	scanf("%d",&n);
	printf("Enter process with thier AT and BT\n");
	for(int i=0;i<n;i++){
		printf("Enter process no.:");
		scanf("%d",&p[i]);
		printf("Enter AT.:");
		scanf("%d",&AT[i]);
		printf("Enter BT:");
		scanf("%d",&BT[i]);
		printf("Enter Priority:");
		scanf("%d",&pr[i]);
	}
	for(int i=0;i<n;i++){
		if(AT[i]==0){
			temp=p[0];
			p[0]=p[i];
			p[i]=temp;
			temp=AT[0];
			AT[0]=AT[i];
			AT[i]=temp;
			temp=BT[0];
			BT[0]=BT[i];
			BT[i]=temp;
			temp=pr[0];
			pr[0]=pr[i];
			pr[i]=temp;
			
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
				if(pr[i]>pr[j]){
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
					temp=AT[i];
					AT[i]=AT[j];
					AT[j]=temp;
					temp=BT[i];
					BT[i]=BT[j];
					BT[j]=temp;
					temp=pr[i];
					pr[i]=pr[j];
					pr[j]=temp;	
				}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(pr[i]==pr[j]){
				if(BT[i]>BT[j]){
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
					temp=AT[i];
					AT[i]=AT[j];
					AT[j]=temp;
					temp=BT[i];
					BT[i]=BT[j];
					BT[j]=temp;
					temp=pr[i];
					pr[i]=pr[j];
					pr[j]=temp;	
				}
			}
		}
	}
	printf("After sorting on Burst and Priority time \n");
	printf("Process\tArrival time\t Burst time\n");
	for(int i=0;i<n;i++){
		printf(" P%d\t\t %d\t\t %d\t\t%d\n",p[i],AT[i],BT[i],pr[i]);
	}
	WT[0]=0;
	for(int i=0;i<n;i++){
		WT[i+1]=WT[i]+BT[i];
		sum+=WT[i]-AT[i];
	}
	WT[n]=WT[n-1]+BT[n-1];
	printf("\nSum of Waiting time is  %d",sum);
	avg=(float)sum/(float)n;
	printf("\n Average Waiting time is  %f",avg);
	sum=0;
	for(int i=0;i<n;i++){
		TAT[i]=WT[i]-AT[i];
		sum+=WT[i+1]-TAT[i];
	}
	printf("\nSum of Turn around time is  %d",sum);
	avg=(float)sum/(float)n;
	printf("\n Average Turn around time is  %f",avg);
	printf("Gantt chart will be\n");
	printf("\n-------------------------------------------------\n");
	for(int i=0;i<n;i++){
		printf("||\tP%d\t",p[i]);
	}
	printf("\n-------------------------------------------------\n");
	for(int i=0;i<=n;i++){
		printf("%d\t\t",WT[i]);
	}
	
}           
