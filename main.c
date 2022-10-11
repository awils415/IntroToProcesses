#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <stdlib.h>


#define   MAX_COUNT  3
#define   BUF_SIZE   100

void  main(void)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];

     fork(); //p1 created c1
     fork(); //p1 created c2, c1 created c3
     pid = getpid(); //p1, c1, c2, c3
     for (i = 1; i <= MAX_COUNT; i++) {
          sprintf(buf, "This line is from pid %d, value = %d, my parent pid %d\n", pid, i, getppid());
          sleep(10);
          write(1, buf, strlen(buf));
     }
}