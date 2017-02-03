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
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
} arg;

int main(void)
{
  key_t key;
  int semid;

  key = ftok("/tmp/sem.temp", getpid());

  /* создать только один семафор: */

  semid = semget(key, 16, 0666 | IPC_CREAT);

struct sembuf sem_opt[16];
  for (int i = 0 ; i < 16 ; i++)
  {
     arg.val = i;
     semctl(semid, i, SETVAL, arg);	
         semctl(semid, i, IPC_RMID, arg);
  }
  pause();
  return 0;
}
