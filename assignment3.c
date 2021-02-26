#include <stdio.h>
#include <stdlib.h>
#define N 50

int absolute(int a){ 
	if(a<0){
		a = a*-1;
	}
	return a;
}


void distance(int park[][N],int size){
    int i,j,k,l,dis,loc_x,loc_y;
    int max=0;
    int near=N+N; //The greatest distance to be found in the parking area of max 50 * 50
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(park[i][j]==0){ //to find the empty slot in the park, respectively
                for(k=0;k<size;k++){
                    for(l=0;l<size;l++){
                        if(park[k][l]==1){ //to find the area with the car in the park respectively
                            dis= absolute(i-k) + absolute(j-l); //distance between each empty slot and the car
                            if(dis<near){
                            	near=dis; // nearest car
							}							
                        }
                    }
                }
                if(near>max){ //the empty slot which has the LARGEST distance to the NEAREST car
                	max=near;
                	loc_x=i+1;
                	loc_y=j+1;
				}
				near=N+N; //The greatest distance to be found in the parking area of max 50 * 50
            }
        }
    }

    printf("Best Slot Found In: %d %d\n",loc_x,loc_y);
}



int main() {
    int size,car,x,y,i,j;
    int park[N][N];
    do{
		printf("Size: ");
 	    scanf("%d",&size);
 	    if(size>50 || size<0){
 	    	printf("Size must be between 50 and 1");
 	    	printf("\n");
		 }
    }while(size>50);
   	printf("Cars: ");
	scanf("%d",&car);
	if(car>=(size*size)){
		printf("Best Slot Found In: 0 0\n");
		return 0;
	}
	else if(car==0){
		printf("Best Slot Found In: 1 1\n");
		return 0;
	}
	else{
		for(i=0;i<car;i++){
       		printf("Locations: ");
       		scanf("%d %d",&x,&y);
       		if(x>size || y>size || park[x][y] == 1){
       		}
       		else{
       			park[x-1][y-1]=1;
			   }
		   }
       	}
       	for(i=0;i<size;i++){
       		for(j=0;j<size;j++){
       			if(park[i][j]!=1){
       				park[i][j]=0;
				   }
			   }
		   }
		distance(park,size);

   	return 0;
}
