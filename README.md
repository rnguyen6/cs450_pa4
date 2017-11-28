# cs450_pa4
If make qemu does not work,
fs.c has to be compiled with a special option via:

gcc -std=c99 -fno-pic -static -fno-builtin -fno-strict-aliasing -O2 -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer -fno-stack-protector -c -o fs.o fs.c

Then, make qemu will work.
