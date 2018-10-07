
#include <stdio.h>
//#include "word.h"
#include <stdlib.h>
#include <ctype.h>
#define HASHSIZE  100 

#include <string.h>
typedef struct node{
   char *wd;
   int freq;
   struct node *next;
}word;

unsigned int hash_function(char *s){
   unsigned int hashval;
   for(hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
   return hashval % HASHSIZE;
}

word *look_up_word(char *str, word **hash_table){
   	unsigned int index = hash_function(str);
   	word *bucket = hash_table[index];
   	if (bucket == NULL)
   	{
		return NULL;
   	}   
   	else if (!(strcmp(bucket -> wd, str)))
	{
		return bucket ;
	}
    
   	while ((bucket = (bucket-> next)))
   	{
		if(!(strcmp(bucket -> wd, str)))
		{
			return bucket;
		}
	}
	return NULL;
   	//word *ret = NULL;
   	//return ret;
}

int main()
{
	char  *myName = "visal";
	word **hash_table = calloc(sizeof(word),100);
	word *first, *second, *third; 
	first = calloc(1, sizeof(word));
	second = calloc(1, sizeof(word));

	first->freq = 10;
	first->wd = "cat";
	first->next = second;  
	
	second->freq = 2;
	second->wd = "dog";

	third->freq = 12;
	third->wd = "corn";
	
	printf("your address is %d\n", &look_up_word(third->wd, hash_table));


	return 0; 
}
