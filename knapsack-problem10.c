#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, P[20], i, W[20], m, c[20][20], w, k1, k2;
	printf("Enter the no of objects\n");
	scanf("%d",&n);
	printf("Enter Profit value of each object\n");
	for(i=1;i<=n;i++){
		scanf("%d",&P[i]);
	}
	printf("Enter the weight of each object\n");
	for(i=1;i<=n;i++){
		scanf("%d", &W[i]);
	}
	printf("Enter the urn capacity\n");
	scanf("%d",&m);
	for(i=0;i<=n;i++){
		for(w=0;w<=m;w++){
			if(i==0 || w==0){
				c[i][w]=0;
			}
			else if(W[i]>w){
				c[i][w]=c[i-1][w];
			} else {
				k1=c[i-1][w];
				k2=P[i]+c[i-1][w-W[i]];
				if(k1>k2){
					c[i][w]=k1;
				} else {
					c[i][w]=k2;
				}
				
			}
		}
	}
	for(i=0;i<=n;i++){
		for(w=0;w<=m;w++){
			printf("%d\t",c[i][w]);
	    }
	    printf("\n");
   }
   printf("The maximum profit = %d",c[n][m]);			
	return 0;
}