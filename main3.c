#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <stdlib.h>

// #define   MAX_COUNT  30

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(int);               /* parent process prototype */
int   RandomNumberGenerator();     

#define   MAX_COUNT  RandomNumberGenerator()

void  main(void)
{
     pid_t  pid;
     int status;
     int x;

     pid = fork();
     if (pid == 0)
          // for random number less than 30
          for (x = 0; x <= MAX_COUNT; x++) 
                ChildProcess();
          
     else if (pid < 0)
          printf("Error : Fork Op\n");
     else 
          wait(&status);
          ParentProcess(status);

    
}

void  ChildProcess(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("Child Pid: %d is going to sleep!\n", i);
     printf("   *** Child process is done ***\n");

     exit(0);
}

void  ParentProcess(int status)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done, Child exited with exit status %d***\n", status);
}

int  RandomNumberGenerator()
{
  int   rand_num;

  rand_num = rand() % 30;
  printf("%d\n", rand_num);
  return rand_num;
}