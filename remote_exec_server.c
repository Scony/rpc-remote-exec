/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "remote_exec.h"

int link[2];

int * rexec_1_svc(rexec_params * argp, struct svc_req * rqstp)
{
  static int result = 0;

  wait();
  pipe(link);

  if(fork())			/* parent */
    {
      close(link[0]);
    }
  else				/* child */
    {
      dup2(link[1],0);
      close(link[0]);

      int argc = 4;			/* because we need command, host and NULL at the end */
      arg * p = argp->first;
      while(p != NULL)
  	{
  	  p = p->next;
  	  argc++;
  	}

      char * argv[argc];
      argv[0] = "./callback_client";
      argv[1] = "127.0.0.1";
      argv[2] = argp->name;

      p = argp->first;
      int i;
      for(i = 3; i < argc - 1; i++)
  	{
  	  argv[i] = p->val;
  	  p = p->next;
  	}
      argv[argc-1] = NULL;

      execv("./callback_client",argv);
    }

  return &result;
}

int * cin_1_svc(cin_params * argp, struct svc_req * rqstp)
{
  static int result = 0;

  printf("cin_1_svc: %d %s\n",argp->seq,argp->data);
  write(link[1],argp->data,strlen(argp->data));

  return &result;
}
