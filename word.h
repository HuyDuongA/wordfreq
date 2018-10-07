#ifndef WORD_H
#define WORD_H
#define HASHSIZE 101

typedef struct node{
   char *wd;
   int freq;
   struct node *next;
}word;

unsigned int hash_function(char *); //done
void evaluate_word(char *, word *); //Huy
word *new_word(char *);             //Huy
void append_word(char *, word *);   //Visal
word *look_up_word(char *, word *); //Visal
word *hash_to_list(word *);         //Huy
word *sort_word_array(word *);      //Visal
int wordcmp(word* , word*);         //Visal
void print(int ,word *);            //Huy
char* readWord(FILE *);             //done
int read_file_check(const char*);   //done
#endif
