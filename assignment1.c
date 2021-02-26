#include <stdio.h>
#include <stdlib.h>

int main() {
	int year,month,day,end_year,first_year;
	int q,m,k,j,w_day,w2_day;
	int count=0;
	printf("Enter date [year month day]: ");
	scanf("%d %d %d",&year,&month,&day);
	if((month == 1 && day > 31) || (month == 2 && day > 28) || (month == 3 && day > 31) || (month == 4 && day > 30) || (month == 5 && day > 31) || (month == 6 && day > 30) || (month == 7 && day > 31) || (month == 8 && day > 31) || (month == 9 && day > 30) || (month == 10 && day > 31) || (month == 11 && day > 30) || (month == 12 && day > 31)){
		printf("Invalid date.\n");
		return 1;
	}
	printf("Enter end year: ");
	scanf("%d",&end_year);
	
	
	if(month == 1 || month == 2){
		month = month + 12;
		year --;
	}
	q = day;
	m = month;
	k = year % 100;
	j = year / 100;
	w_day = (q + (13*(m+1))/5 + k + (k/4) + (j/4) + 5*j)%7;
	if(m == 13 || m == 14){
		year ++;
	}
	
	if(w_day == 0){
		printf("It's a Saturday.\n");
	}
	else if(w_day == 1){
		printf("It's a Sunday.\n");
	}
	else if(w_day == 2){
		printf("It's a Monday.\n");
	}
	else if(w_day == 3){
		printf("It's a Tuesday.\n");
	}
	else if(w_day == 4){
		printf("It's a Wednesday.\n");
	}
	else if(w_day == 5){
		printf("It's a Thursday.\n");
	}
	else if(w_day == 6){
		printf("It's a Friday.\n");
	}

	first_year = year+1;
	while(year<end_year){
		year++;
		k = year % 100;
		j = year / 100;
		w2_day = (q + (13*(m+1))/5 + k + (k/4) + (j/4) + 5*j)%7;
		if(w_day == w2_day){
			count++;
		}
		
	}
	printf("Same day-and-month on same weekday between %d and %d: %d\n",first_year,end_year,count);
	
	
	
	return 0;
}