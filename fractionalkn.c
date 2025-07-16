#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int n, i, m, j;
	double P[20], W[20], t1, t2, X[20], U, pro=0.0;
	printf("Enter the no of objects\n");
	scanf("%d",&n);
	printf("Enter Profit value of each object\n");
	for(i=1;i<=n;i++){
		scanf("%lf",&P[i]);
	}
	printf("Enter the weight of each object\n");
	for(i=1;i<=n;i++){
		scanf("%lf", &W[i]);
	}
	printf("Enter the urn capacity\n");
	scanf("%d",&m);
	
	for(i=1;i<=n;i++){
		printf("%lf\t", P[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("%lf\t",W[i]);
	}
	
	//sorting according to p[i]/w[i]
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++){
			if((P[j]/W[j])<(P[j+1]/W[j+1])){
				t1=P[j];
				t2=W[j];
				P[j]=P[j+1];
				W[j]=W[j+1];
				P[j+1]=t1;
				W[j+1]=t2;
			}
		}
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("%lf\t", P[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("%lf\t",W[i]);
	}
	//Fractional Knapsack Problem
	for(i=1;i<=n;i++){
		X[i]=0.0;
	}
	U=m;
	for(i=1;i<=n;i++){
		if(W[i]>U) 
		   break;
		X[i]=1.0;
		U=U-W[i];
	}
	if(i<=n){
		X[i]=U/W[i];
	}
	//print solution vector
	for(i=1;i<=n;i++){
		printf("%lf\n",X[i]);
	}
	//find total profit
	for(i=1;i<=n;i++){
		pro=pro+X[i]*P[i];
	}			
	//Display profit
	printf("Profit = %lf", pro);
	return 0;
}