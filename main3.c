#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <time.h>

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t   c1_pid, c2_pid;  

     c1_pid = fork();

     if (c1_pid == 0) {
          ChildProcess();
          exit(0);
     } else if (c1_pid < 0) {
          printf("Error, first child process not created.");
     } else {
          ParentProcess();
          c2_pid = fork();
          if (c2_pid == 0) {
              ChildProcess();
              exit(0);
          } else if (c2_pid < 0) {
              printf("Error, first child process not created.");
          } else { 
              ParentProcess();
          }
     }
     return;      
}

void  ChildProcess(void)
{
     int      i;
     int      iter;
     time_t   nap_time;

     srand((unsigned) time(&nap_time));
     iter = rand() % 30;
     
     printf("New child. Sleeping for %d iterations.\n", iter);
     for (i = 1; i < iter; i++) {
          printf("Child Pid: %d is going to sleep!\n", getpid());
          
          unsigned nap_time = rand() % 10;
          sleep(nap_time);

          printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
      }
}

void  ParentProcess(void)
{
     int    status;
     pid_t  pid = wait(&status);

     printf("Child Pid: %d has completed\n", pid);
}