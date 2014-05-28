/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "remote_exec.h"
#include <poll.h>


void remote_exec(int argc, char * argv[])
{
  int i;
  char * host = argv[1];
  CLIENT * clnt;
  int * result;
  rexec_params rexec_1_arg;

  rexec_1_arg.name = argv[2];
  arg ** p = &rexec_1_arg.first;
  for(i = 3; i < argc; i++)
    {
      arg * tmp = malloc(sizeof(arg));
      tmp->val = argv[i];
      tmp->next = NULL;
      *p = tmp;
      p = &(*p)->next;
    }

  clnt = clnt_create(host,REMOTE_EXEC,V1,"udp");
  if(clnt == NULL)
    {
      clnt_pcreateerror(host);
      exit(1);
    }

  result = rexec_1(&rexec_1_arg, clnt);
  if(result == (int *)NULL)
    {
      clnt_perror(clnt,"call failed");
    }

  clnt_destroy (clnt);

  arg * pp = rexec_1_arg.first;
  while(pp != NULL)
    {
      arg * tmp = pp->next;
      free(pp);
      pp = tmp;
    }
}

void remote_cin(char * host, char * data)
{
  static int seq = -1;
  CLIENT * clnt;
  int * result;
  cin_params cin_1_arg;

  cin_1_arg.data = data;
  cin_1_arg.seq = ++seq;

  clnt = clnt_create(host,REMOTE_EXEC,V1,"udp");
  if(clnt == NULL)
    {
      clnt_pcreateerror(host);
      exit(1);
    }

  result = cin_1(&cin_1_arg, clnt);
  if(result == (int *)NULL)
    {
      clnt_perror(clnt,"call failed");
    }

  clnt_destroy (clnt);
}


int main(int argc, char *argv[])
{
  if(argc < 3)
    {
      printf("usage: %s server_host command [arguments]\n",argv[0]);
      exit(1);
    }

  int coutp[2];
  int cerrp[2];
  pipe(coutp);
  pipe(cerrp);

  int f = fork();
  if(f)				/* parent */
    {
      remote_exec(argc,argv);

      struct pollfd fds[3];

      close(coutp[1]);
      close(cerrp[1]);

      fds[0].fd = coutp[0];
      fds[0].events = POLLIN;
      fds[1].fd = cerrp[0];
      fds[1].events = POLLIN;
      fds[2].fd = 0;
      fds[2].events = POLLIN;

      while(1)
	{
	  char buff[4096];
	  int ret = poll(fds,3,-1);
	  /* printf("poll %d\n",ret); */
	  memset(buff,'\0',4096);
	  if(fds[0].revents & POLLIN || fds[0].revents & POLLHUP) /* cout */
	    {
	      int rd = read(coutp[0],buff,4096);
	      if(!rd)
		break;
	      write(1,buff,rd);
	    }
	  memset(buff,'\0',4096);
	  if(fds[1].revents & POLLIN || fds[1].revents & POLLHUP) /* cerr */
	    {
	      int rd = read(cerrp[0],buff,4096);
	      if(!rd)
		break;
	      write(2,buff,rd);
	    }
	  memset(buff,'\0',4096);
	  if(fds[2].revents & POLLIN || fds[2].revents & POLLHUP) /* cin */
	    {
	      read(0,buff,4096);
	      remote_cin(argv[1],buff);
	    }
	}

      int s;
      wait(&s);
      if(WIFEXITED(s))
	printf("Child's exit code %d\n", WEXITSTATUS(s));
      else
	printf("Child did not terminate with exit\n");
    }
  else				/* child */
    {
      dup2(coutp[1],1);
      dup2(cerrp[1],2);
      close(coutp[0]);
      close(cerrp[0]);
      execl("./callback_server","./callback_server", (char * )0);
    }

  return 0;
}
