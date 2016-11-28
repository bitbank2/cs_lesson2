//
// Computer science lesson 2
// working with files, chars and pointers
// This program will read a text file and count the letters
// The student will take this further
// 
// Written by Larry Bank 11/28/2016
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <math.h>

int CountLetters(unsigned char *pBuf, int iSize)
{
int i;
int iCount = 0;

   for (i=0; i<iSize; i++)
   {
      if ((pBuf[i] >= 'A' && pBuf[i] <= 'Z') || (pBuf[i] >= 'a' && pBuf[i] <= 'z'))
      {
         iCount++;
      }
   }

   return iCount;
} /* CountLetters() */

int main(int argc, char* argv[])
{
FILE *fhandle;
int iLetters;
size_t filesize;
unsigned char *pBuffer;

   // Make sure the user entered a filename to read
   if (argc != 2)
   {
      printf("Usage: cs2 <filename>\n");
      return 0;
   }

   fhandle = fopen(argv[1], "rb"); // open file for reading
   if (fhandle != NULL)
   {
      fseek(fhandle, 0L, SEEK_END); // seek to the end 
      filesize = ftell(fhandle); // to get the file size
      fseek(fhandle, 0L, SEEK_SET); // reset to the beginning
      pBuffer = malloc(filesize); // allocate memory to hold the text
      if (pBuffer != NULL)
      {
         fread(pBuffer, 1, filesize, fhandle); // read the contents
         iLetters = CountLetters(pBuffer, filesize);
         printf("File %s contains %d letters\n", argv[1], iLetters);
      }
      fclose(fhandle); 
   }

   return 0;
} /* main() */
