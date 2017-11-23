#include "types.h"
#include "stat.h"
#include "user.h"
#include "stdint.h"
#include "fs.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int fd = open(argv[1], O_RDONLY | O_EXTENT);
  struct stat stats;
  fstat(fd, &stats);
  printf(1, "name: %s | type: %d | devive: %d | inode: %d | links: %d | size: %d\n", argv[1], stats.type, stats.dev, stats.ino, stats.nlink, stats.size);
  if(stats.type == T_EXTENT){
    int i = 0;
    while(stats.addrs[i]){
      printf(1, "addr: %x | size: %d\n", (((stats.addrs[i]) & 0xFF) >> 8), ((stats.addrs[i]) & 0xFF));
      i++;
    }
  }
  exit();
}
