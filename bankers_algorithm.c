#include<stdlib.h>
int allocation[20][20],max[20][20],need[20][20],available[20],safe[10],s; 
int finish[10],work[10],flag=0,temp=0;
int p,r,i,j,ch,process,req[10];
void check()
{
	 temp=0;
	 s=0;
	 for(i=0;i<p;i++){
	 	for(j=0;j<r;j++){
	 		need[i][j]=max[i][j]-allocation[i][j];
	 	}
	 }
	 printf("Need table is\n");
	 for(i=0;i<p;i++){
	 	for(j=0;j<r;j++){
	 		printf("%d\t",need[i][j]);
	 	}
	 	printf("\n");
	 }
	 for(i=0;i<p;i++){
	 	finish[i]=0;
	 }
	 for(i=0;i<r;i++){
	 	work[i]=available[i];
	 }
	 while(temp<5){
	 	for(i=0;i<p;i++){
	 		for(j=0;j<r;j++){
	 			if(finish[i]==0 && need[i][j]<=work[j]){
	 				flag=1;
	 			}else{
	 				flag=0;
	 				break;
	 			}
	 		}
	 		if(flag==1){
	 			for(j=0;j<r;j++){
	 				work[j]=work[j]+allocation[i][j];
	 			}
	 			finish[i]=1;
	 			safe[s++]=i;
	 		}
	 	}
	 	temp++;
	 }
	 flag=0;
	 for(i=0;i<p;i++){
	 	if(finish[i]==0){
	 		flag=1;
	 		break;
	 	}
	 }
	 if(flag==1){
	 	printf("System is in deadloack state ");
	 }else{
	 	printf("System is in safe state\n");
	 	printf("Safe sequence will be  :");
	 	for(i=0;i<p;i++){
	 		printf("P%d\t",safe[i]);
	 	}
	 }
}
int main()
{
	system("clear");
	printf("-----------banker's algorithm-----------");
	printf("Enter processes:");
	scanf("%d",&p);
	printf("Enter resources:");
	scanf("%d",&r);
	printf("Enter allocation table:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("Enter max table:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter available vector:\n");
	for( i=0;i<r;i++){
		scanf("%d",&available[i]);
	}
	check();
	//resource request algorithm
	printf("Do you want to add a new request(0/1) ");
	scanf("%d",&ch);
	if(ch==0){
		exit(1);
	}
	printf("Enter process no: ");
	scanf("%d",&process);
	printf("Enter a request:\n");
	for(i=0;i<r;i++){
		scanf("%d",&req[i]);
	}
	flag=0;
	for(i=0;i<r;i++){
		if(req[i] <=need[process][i]){
			flag=1;
		}else{
			flag=0;
		}
	}
	if(flag==0){
		printf("\nRequest cannot be statisfied");
		exit(1);
	}
	for(i=0;i<r;i++){
		if(req[i]<=available[i]){
			flag=1;
		}else{
			flag=0;
		}
	}
	if(flag==0){
		printf("\nRequest cannot be statisfied");
		exit(1);
	}
	for(i=0;i<r;i++){
		allocation[process][i]=allocation[process][i]+req[i];
		available[i]=available[i]-req[i];
	}
	check();
	return 0;
	
}
/*
allocation
2 1 0
1 2 2
0 2 0
3 0 1



max
8 6 3
9 4 3
5 3 3 
4 2 3

available
4 3 2


*/
