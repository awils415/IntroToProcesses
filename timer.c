/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

clock_t start_t, end_t;
int alarmnum;
double runtime_t;

//****

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarm(1);
}

void handler2(int signum)
{ //signal handler
  end_t = clock();
  runtime_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;

  printf("Alarms delivered: %d\n", alarmnum);
  printf("Program ran for %f seconds\n", runtime_t);
}

int main(int argc, char * argv[])
{
  start_t = clock();
  
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,handler2);
  alarm(1); //Schedule a SIGALRM for 1 second
  
  while(1) { //busy wait for signal to be delivered
    sleep(1);
    printf("Turing was right!\n");
    alarmnum++;
  }
  return 0; //never reached
}