/*Writer Process*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
int fd;
char buf[1024]="Hello RNSIT";
/* create the FIFO (named pipe) */
char * myfifo = "/tmp/guest-uivabk/Desktop/tmp";
mkfifo(myfifo, 0666);
printf("Run Reader process to read the FIFO File\n");
fd = open(myfifo, O_WRONLY);
write(fd,buf,sizeof(buf));
close(fd);
unlink(myfifo); /* remove the FIFO */
return 0;
}
/* Reader Process */
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#define MAX_BUF 1024
int main()
{
int fd;
/* A temp FIFO file is not created in reader */
char *myfifo = "/tmp/guest-uivabk/Desktop/tmp";
char buf[MAX_BUF];
/* open, read, and display the message from the FIFO */
fd = open(myfifo, O_RDONLY);
read(fd, buf, MAX_BUF);
printf("Reader process has read : %s\n", buf);
close(fd);
return 0;
}
