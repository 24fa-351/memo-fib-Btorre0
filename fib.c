// Beatriz Torres Archundia
// CPSC 351 - 08
// 09.06.24
// btorre0@csu.fullerton.edu
// Github Username: Btorre0

#include <stdio.h>
#include <stdlib.h>

unsigned long long int *mem;

// Recursive function
unsigned long long int fibRec_wrapper(int num)
{
   if (mem[num] != -1)
   {
      return mem[num];
   }

   if (num == 0)
   {
      mem[num] = 0;
   }
   else if (num == 1)
   {
      mem[num] = 1;
   }
   else
   {
      mem[num] = fibRec_wrapper(num - 1) + fibRec_wrapper(num - 2);
   }

   return mem[num];
}

// Iterative function
unsigned long long int fibIter_wrapper(int num)
{
   if (mem[num] != -1)
   {
      return mem[num];
   }

   if (num == 0)
   {
      return 0;
   }
   else if (num == 1)
   {
      return 1;
   }

   unsigned long long int a = 0;
   unsigned long long int b = 1;
   unsigned long long int c;

   for (int ix = 2; ix <= num; ix++)
   {
      c = a + b;
      a = b;
      b = c;
   }

   mem[num] = b;

   return b;
}

unsigned long long int fib_r(int num)
{

   return fibRec_wrapper(num);
}

unsigned long long int fib_i(int num)
{
   return fibIter_wrapper(num);
}

int main(int argc, char *argv[])
{

   if (argc < 3)
   {
      printf("Usage: %s <integer> <r/i> <filename>\n", argv[0]);

      return 1;
   }

   int file_num = -1;
   int num;
   unsigned long long int compute;

   sscanf(argv[1], "%d", &num);

   if (argc == 4)
   {
      FILE *file = fopen(argv[3], "r");

      if (file == NULL)
      {

         printf("file doesnt exist");

         return 1;
      }

      if (0 == fscanf(file, "%d", &file_num))
      {

         printf("file %s doesn't have and int\n", argv[3]);

         return 1;
      }

      printf("read %d from %s\n", file_num, argv[3]);

      fclose(file);
   }

   num += file_num;

   mem = (unsigned long long int *)malloc((num + 1) * sizeof(unsigned long long int));

   if (mem == NULL)
   {
      printf("Memory allocation failed\n");

      return 1;
   }
   for (int ix = 0; ix <= num; ix++)
   {

      mem[ix] = -1;
   }

   // this line is used for debugging/understanding fib location
   // printf("we are about to do the fib of %d \n", num);

   if (argv[2][0] == 'r')
   {
      compute = fib_r(num);
   }
   else
   {
      compute = fib_i(num);
   }

   printf("%llu\n", compute);

   free(mem);

   return 0;
}