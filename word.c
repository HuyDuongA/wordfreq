#include <stdio.h>
#include "word.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
unsigned int hash_function(char *s){
   unsigned int hashval;
   for(hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
   return hashval % HASHSIZE;
}


/*call look_up_word to see if the word is in hash table
      if not, call new_word and store return address into hashtable.
            if the bucket[index] is empty at new struct word 
            else add it to the bottom chain (by calling append_word())
      else if it's already in the hashtable, increment frequency of the word
 * */
void evaluate_word (char *str, word **hash_table){
   int hash_val = hash_function(str);
   word *address = look_up_word(str, hash_table);
   if(!address){
	  }

   else{
      address->freq++;
   }
}

/* allocate memory (check error for malloc) for struct word, store str 
 * into wd, then return word.
 * */
word *new_word(char *str){
   int num_word = 1;
   word* w_new = calloc(num_word, sizeof(word));
   w_new->wd = str;
   w_new->freq = 0;
   w_new->next = NULL;
   return w_new;
}

/* call hash function to get the index of bucket, and traverse through
 * the chain until node points to NULL, add new word, increase frequency
 * */
void append_word(char *str, word **hash_table){
	
	if(hash_table[hash_val] == NULL)
	{
		hash_table[hash_val] = new_word(str);
	}
}

/* call hash_function to get the index of str, traverse through the chain
 * if the word isn't found, return NULL
 * if the word is found return the adress of the word
 * */
word *look_up_word(char *str, word **hash_table){
   	unsigned int index = hash_function(str);
   	word *bucket = hash_table[index];
	while(!(strcmp(bucket->wd, str)) && (bucket->next != NULL))
	{
		bucket = bucket -> next; 
	}
	if((strcmp(bucket->wd, str)))
	{
		return bucket;
	}else
	{
		return NULL;
	}



/*

   	if (bucket == NULL)
   	{
		return NULL;
   	}   
   	else if (!(strcmp(bucket->wd, str)))
	{
		return bucket ;
	}
    
   	while ((bucket = (bucket-> next)))
   	{
		if (!(strcmp((bucket -> wd), str)))	
		{
			return bucket;
		}
	}
	return NULL;
   	//word *ret = NULL;
   	//return ret;
}
*/

/* count how many words stored inside hash_table
 * */
int count(word **hash_table){
   int word_num = 5;
   return word_num;
}

/* traverse from left to right of the hash table, at each location, 
 * traverse from top to bottom, increase word count 
 * create array with the size of word count
 * traverse through hash table (left to right, then top to bottom), 
 * and if hash_table[index] is !NULL put each word at the index into 
 * new array list.
 * */
word *hash_to_list(word **hash_table){
   word *list = calloc(count(hash_table), sizeof(word));
   struct node* next_node = NULL;
   int list_index = 0;
   for(int i = 0; i < HASHSIZE; ++i){
      if(hash_table[i]){
         next_node = hash_table[i]; 
         while(next_node){
            list[list_index] = *next_node;
            next_node = next_node->next;
            list_index++;
         }   
      }
   }
   return list;
}

/* call a qsort to sort the array and wordcmp to sort the array and return
 * the sorted array
 * */
word *sort_word_array(word **hashtable){
   word *ret = NULL;
   return ret;
}

/* return negative number if a comes before b
 * return positvie if a comes after b
 * return 0 if a and b are equal 
*/
int wordcmp(word *a, word *b){
	
    if( a->freq == b->freq)
    {
        return strcmp(a->wd, b->wd);
    }
    else if( a->freq > b->freq)
    {
        return -1;
    }else
    {
        return 1;
    }
}

/* call built in sort function and print
 * */
void print(int num, word *sorted_list){
}

int read_file_check(const char* fileName){
   FILE *fp;
   fp = fopen(fileName, "r"); 
   if (fp == NULL){
      fprintf(stderr, "%s: No such file or directory\n", fileName); 
      return 0;  
   }   
   else{
      fclose(fp); 
      return 1;
   }   
}

/* return a word from stdin until it hits EOF
 * 		If numbers, special char are read, it will 
 * 		return a character pointer that point to 0 value
 */
char *read_word(FILE *file){
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
