#include <stdio.h>
#include "word.h"
#include <stdlib.h>
#include <ctype.h>

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
      if(hash_table[hash_val] == NULL){
         hash_table[hash_val] = new_word(str);
      }
      else{
         append_word(str, hash_table);
      }
   }
   else{
      address->freq++;
   }
}

/* allocate memory (check error for malloc) for struct word, store str 
 * into wd, then return word.
 * */
word *new_word(char *str){
   word *ret = NULL;
   return ret;
}

/* call hash function to get the index of bucket, and traverse through
 * the chain until node points to NULL, add new word, increase frequency
 * */
void append_word(char *str, word **hash_table){
}

/* call hash_function to get the index of str, traverse through the chain
 * if the word is found, return address of the word
 * else if it hits NULL
 * */
word *look_up_word(char *str, word **hash_table){
   word *ret = NULL;
   return ret;
}

/* traverse from left to right of the hash table, at each location, 
 * traverse from top to bottom, increase word count 
 * create array with the size of word count
 * traverse through hash table (left to right, then top to bottom), 
 * and put each word into new array list.
 * */
word *hash_to_list(word **hash_table){
   word *ret = NULL;
   return ret;
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
	//if the freq of a and and b are equal
	//we want to compare their words 
	//if a come before b strcmp will gives -1
   if( a->freq == b->freq)
		return strcmp(a->wd, b->wd); 
   else
	// if the freq of a and b are not equal 
	// return negative number if a is greater than b
	// return positive number if a is less than b 
		return (a->freq < b->freq);

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

