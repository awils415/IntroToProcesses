#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <time.h>

// #define   MAX_COUNT  30

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(int);               /* parent process prototype */
int   RandomNumberGenerator();     

#define   MAX_COUNT  RandomNumberGenerator()

void  main(void)
{
     pid_t   c1_pid, c2_pid;  
     int     status;
     int     x;

     (c1_pid = fork()) && (c2_pid = fork());    // creates two child processes

     if (c1_pid == 0)
          // child 1 code
          ChildProcess(c1_pid);
     else if (c2_pid == 0)
          // child 2 code
          ChildProcess(c2_pid);
     else
          // parent code
          wait(&status);
          ParentProcess(status);
           
}

void  ChildProcess(int pid_t)
{
     int   i;
     int   nap_time;
     int   pid;
     int   ppid;

     pid = getpid();
     ppid = getppid();

     for (i = 1; i <= MAX_COUNT; i++)
          printf("Child Pid: %d is going to sleep!\n", i);
          
          srand(time(0));
          nap_time = (rand() % 10) + 1;
          sleep(nap_time);

          printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", pid, ppid);

     exit(0);
}

void  ParentProcess(int status)
{
     int   pid;
     int   ppid;

     pid = getpid();
     ppid = getppid();

     printf("Child Pid: %d has completed\n", pid);
}

int  RandomNumberGenerator()
{
     srand(time(0));

     int   rand_num;

     rand_num = (rand() % 30) + 1;
     printf("%d\n", rand_num);
     return rand_num;
}