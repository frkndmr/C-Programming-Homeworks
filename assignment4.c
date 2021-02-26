#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
char word[15];

struct instruction_s {
	int step[6]; 
	int index[6];
};


char* get_word(char* s, int n){
	int i,j;
	int count=0;
	
	for(i=0; *(s+i) != '\0'; i++){  
		
		if(*(s+i) == ' ')
			count++;
		
		if(count == n-1){  //find the word in index
			i++;
			
			for(j=i; *(s+j) != ' '; j++){
				word[j-i] = *(s+j);
			}
			word[j-i] = '\0';

			return word;
		}
	}
	return word;
}

void get_sentence(char lines[SIZE][200], struct instruction_s* instructions, int n_instructions, char* sentence){
	int i,m,t;
	int k=0;
	int fark = 'a' - 'A';
	char *str;
	char *word;
	int sum = 0; 
	
	for(t=0; t < n_instructions ; t++){
		for(i=0; i<SIZE; i++){
			sentence = lines[i];
			for(k=0; k < strlen(lines[i]) ; k++){
				if((*(sentence+k)>= 'A') && (*(sentence+k)<= 'Z'))
					*(sentence+k) += fark; //Convert an uppercase letter to lowercase
			
				else if(!(((*(sentence+k)>= 'A') && (*(sentence+k)<= 'Z'))|| ((*(sentence+k)>= 'a') && (*(sentence+k)<= 'z')) || *(sentence+k) == ' ')){
					for(m=k; m<strlen(lines[i]); m++){	
						*(sentence+m) = *(sentence+m+1); //Ignore punctuation marks
					}
				}	
			}
	
		}
	
	for(i=t; i<=t; i++){
		sum += (instructions->step[i]); //Finding how many steps in the sentence
	}
	
	str = lines[sum-1];
	word = get_word(str,instructions->index[t]);
	printf("%s ",word); //Print the secret sentence
	}
	
}


int main() {

	int n=0;
	int i=0; 
	int process=0;
	struct instruction_s operation;
	struct instruction_s* instructions;
	instructions = &operation;
	char temp[SIZE][200]; 
	FILE *fptr;
	FILE *i_ptr;
	char *sentence = {NULL};


    fptr = fopen("alice.txt","r");
	i_ptr = fopen("instructions.txt","r");
	
	
	while(fgets(temp[i], 200, fptr)) 
	{
        temp[i][strlen(temp[i]) - 1] = '\0'; //Transfer the text to sentence sentence.
        i++;
    }

      
   	while (!feof (i_ptr)){
   
 		fscanf(i_ptr, "%d %d", &operation.step[n], &operation.index[n]); //Exporting the data from the instruction file to the struct.
 		n++;
  		process++;
	}
	process--;

	
	get_sentence(temp,instructions,process,sentence);
	
	fclose(fptr); 
	fclose(i_ptr); 
			
	
	return 0;
}
