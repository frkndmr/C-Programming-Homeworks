#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int shot(int segment, char ring){
	int n;
	if(ring == 'S'){
		n=segment;
	}
	else if(ring == 'D'){
		n=segment*2;
	}
	else if(ring == 'T'){
		n=segment*3;
	}
	else if(ring == 'O'){
		n=25;
	}
	else if(ring =='I'){
		n=50;
	}
	return n;
}
int condition(int segment,char ring,int target,int first){
	int score;
	if(first==1 && ring!='D'){
		return target;
	}
	else{
		score= shot(segment,ring);
		if(target-score<0 || target-score==1){
			return target;
		}
		else if(target-score==0){
			if(ring == 'D'){
				return target-score ;
			}
			else {
				return target;
			}
		}
		else{
			return target-score;
		}
	}
}


int main() {
	int n,s,sum,first=1;
	char r;
	printf("Target: ");
	scanf("%d",&n);
	while(n>1){
		printf("Throw: ");
		scanf("%d %c",&s,&r);
		sum = condition(s,r,n,first);
		printf("Points: %d\n",sum);
		if(sum != n){
			first=0;
			n = n-shot(s,r);
		}
	}	
	return 0;
}
