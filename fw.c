/* Programmers: Huy Duong & Visalbotr Chan
 * Course: CPE 357
 * Assignment 2 - wf
 *
 * The command line of the program will consist of an optional argument of
 * the form -n <num> to give the number of words, and an optional set of
 * filenames. 
 *
 * If the -n argument is not given, the program should default to
 * 10, and if no filenames are given, the program should take its input from
 * stdin.
 *
 * In case the argument to -n is not an integer, the program should report 
 * the error,print a usage message, and stop.
 *
 * If, while processing files, you encounter a file that cannot be opened, 
 * print an error message explaining why, and continue with the rest.
 *
 * The output of this program will start with one line reading, “The top k
 * words (out of n) are:” where k is the number requested and n is the 
 * numberof unique words encountered in the input.
 *
 * After that header line, the individual words are listed in descending 
 * order on individual lines as the count, right justified in a field nine 
 * characters wide, a space, then the word.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){
   FILE *fp;
   int num;
   if(argc == 1){  //check for -n argument
      fp = stdin;
   }
   else if(!strcmp(argv[1],"-n")){
      if(atoi(argv[2])){
         num = atoi(argv[2]);
      }
      else{ 
         return 1;
         perror("usage: fw [-n num] [ file1 [file 2 ...]]\n");
      }
   }

   return 0;
}
