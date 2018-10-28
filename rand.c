#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>

#include "rand.h"

int myrandom()
{
  int fd = open("/dev/urandom", O_RDONLY);
  //printf("%d\n", fd);

  int * rand_num = (int *) malloc(sizeof(int));
  int read_bytes = read(fd, rand_num, sizeof(int));

  //printf("Read %d bytes: %d\n", read_bytes, *rand_num);

  if (read_bytes == -1)
  {
    printf("Errno: %d\n", errno);
    printf("Error: %s\n", strerror(errno));
  }

  int cd = close(fd);
  //printf("%d\n", cd);
  return * rand_num;
}
