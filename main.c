#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <string.h>

#include "rand.h"

int main()
{
  printf("Generating random numbers:\n");
  int * rand_nums = (int *) malloc(10 * sizeof(int));
  for (int i = 0; i < 10; i++)
  {
    rand_nums[i] = myrandom();
    printf("\trandom %d: %d\n", i, rand_nums[i]);
  }


  printf("\nWriting numbers to a file...\n\n");
  int fd = open("randnums.txt", O_CREAT | O_WRONLY, 0777);
  int written_bytes = write(fd, rand_nums, 10 * sizeof(int));
  if (written_bytes == -1)
  {
    printf("Errno: %d\n", errno);
    printf("Error: %s\n", strerror(errno));
  }
  close(fd);


  printf("Reading numbers from a file...\n\n");
  fd = open("randnums.txt", O_RDONLY);
  int * rand_nums2 = (int *) malloc(10 * sizeof(int));
  int read_bytes = read(fd, rand_nums2, 10 * sizeof(int));


  printf("Verification that written values were the same:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("\trandom %d: %d\n", i, rand_nums2[i]);
  }
  close(fd);
}
