#ifndef WORD_H
#define WORD_H
#define HASHSIZE 2

typedef struct node{
   char *wd;
   int freq;
   struct node *next;
}word;

unsigned int hash_function(char *);       //done
word *new_word(char *);                   //Huy
void evaluate_word(char *, word **);      //Huy
void append_word(char *, word **);        //Visal
word *look_up_word(char *, word **);      //Visal
int count(word **);                       //Huy
word *hash_to_list(word **);              //Huy
int wordcmp(word* , word*);               //Visal & Huy
void sort_print(int ,word *, word **);    //Huy
void clean_up(word *, word **);           //Huy
char *read_word(FILE *);                  //done
int read_file_check(const char*);         //done
#endif
