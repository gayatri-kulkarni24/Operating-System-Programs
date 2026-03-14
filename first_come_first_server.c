#include<stdio.h>
#include<stdlib.h>
void main()
{
	int  p[10],AT[10],BT[10],WT[10],TAT[10];
	int n,temp,sum=0;
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
	}
	//Bubble sort
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
				if(AT[i]>AT[j]){
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
					temp=AT[i];
					AT[i]=AT[j];
					AT[j]=temp;
					temp=BT[i];
					BT[i]=BT[j];
					BT[j]=temp;
				}
		}
	}
	printf("After sorting on arrival time \n");
	printf("Process\tArrival time\t Burst time\n");
	for(int i=0;i<n;i++){
		printf(" P%d\t\t %d\t\t %d\n",p[i],AT[i],BT[i]);
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
		TAT[i+1]=WT[i]+AT[i];
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
