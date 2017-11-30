# cs450_pa4

Open terminal to the xv6 directory (xv6_2 is the original copy from MIT).

Create Makefle with "make"

Run qemu (xv6) with "make qemu"

To make extent/fstat/lseek:

  test c [filename]
  
    - (c)reates extent file with argument
    
  test r [filename]
  
    - (r)eads file and prints statistics
    
  test l [filename]
  
    - (l)seeks file with set offsets and strings
    

If make qemu does not work,
fs.c has to be compiled with a special option via:

gcc -std=c99 -fno-pic -static -fno-builtin -fno-strict-aliasing -O2 -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer -fno-stack-protector -c -o fs.o fs.c

Then, make qemu will work.
