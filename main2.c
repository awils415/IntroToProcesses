#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>

#define   MAX_COUNT  2

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(int);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int status;

     pid = fork();
     if (pid == 0) 
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
          printf("   This line is from child, value = %d\n", i);
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