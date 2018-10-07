#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
char *read_long_line(FILE *file);

/*
int main() {
	char * temp = NULL;
	while((temp = read_long_line(stdin))){
		if(*temp != 0){
		puts(temp);
		free(temp);
		//}else{
		//printf("hello world\n");
		}
	}
}
*/


/*it returns a char pointer when a word is found 
 *it return a char pointer that point to a memory which contains all 0
  when it reads non alphabet charecter such as \n, numbers, special char. 
*/

char *read_long_line(FILE *file){
	char *buffer = NULL; 
	int array_size = 128; 
	buffer = (char*)calloc(sizeof(char), array_size);
  	if(buffer == NULL) 
  	{
     	perror("malloc: failed");
		return NULL;

    }
	int count = 0; 
	int c = 0; 
	
	while(((c = getc(file)) != EOF) && (isalpha(c))){
		
		if(count < array_size){
			buffer[tolower(count)] = c;
			++count;
		}else{
			array_size = array_size *2;
			buffer = realloc(buffer, array_size);
			if(buffer == NULL)
			{
				perror("calloc: failed");
				return NULL;
			} 
			buffer[tolower(count)] = c; 
			++count; 
		}
	  
	}
	if(c == EOF)
	{
		buffer = NULL; 
	}
	return buffer;

}



