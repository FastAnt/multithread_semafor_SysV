#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/sem.h>
#include <iostream>

#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>


int main(void)
{
  key_t key;
  int semid;

  key = ftok("/etc/fstab", getpid());

  /* создать только один семафор: */
  semid = semget(key, 16, 0666 | IPC_CREAT);
  for (int i = 0 ; i < 16 ; i++)
  {
     semctl(semid, i, SETVAL, i);	
  }

  return 0;
}
