#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, const char **argv)
{
  FILE *fp;
  const char *fname;
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    return 1;
  }
  fname = argv[1];
  fp = fopen(fname, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "Could not open %s: %s\n", fname, strerror(errno));
    return 1;
  }
  if (fcntl(fileno(fp), F_SETLEASE, F_RDLCK) < 0)
  {
    if (errno == EAGAIN)
      fprintf(stderr, "%s: currently open for writing\n", fname);
    else
      fprintf(stderr, "Could not lock %s: %s\n", fname, strerror(errno));
    return 1;
  }
  fclose(fp);
  return 0;
}
