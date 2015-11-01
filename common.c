#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

void pr_exit(char *err)
{
	perror(err);
	exit(0);
}

void setnonblocking(int fd)
{
	int opts;
	if((opts=fcntl(fd,F_GETFL))<0)
		pr_exit("fcntl F_GETFL");
	opts=opts|O_NONBLOCK;
	if(fcntl(fd,F_SETFL,opts)<0)
		pr_exit("fcntl F_SETFL");
}
