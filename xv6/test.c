#include "types.h"
#include "stat.h"
#include "user.h"
#include "stdint.h"
#include "fs.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  if(strcmp(argv[1], "c") == 0){ //make file
    int fd = open(argv[2], O_CREATE | O_EXTENT);
    char numStr[] = "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100";
    write(fd, numStr, sizeof(numStr));
    close(fd);
  }
  else{
    int fd = open(argv[2], O_RDONLY | O_EXTENT);
    struct stat stats;
    /*to be moved to filestat in file.c*/
    fstat(fd, &stats);
    printf(1, "name: %s | type: %d | devive: %d | inode: %d | links: %d | size: %d\n", argv[2], stats.type, stats.dev, stats.ino, stats.nlink, stats.size);
    if(stats.type == T_EXTENT){
      int i = 0;
      while(stats.addrs[i]){
        printf(1, "addr: %x | size: %d\n", (((stats.addrs[i]) & 0xFF) >> 8), ((stats.addrs[i]) & 0xFF));
        i++;
      }
    }
  }
  exit();
}
