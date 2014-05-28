/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "remote_exec.h"

int * rexec_1_svc(rexec_params * argp, struct svc_req * rqstp)
{
  static int result = 0;

  printf("rexec_1_svc: %s\n",argp->name);
  arg * p = argp->first;
  while(p != NULL)
    {
      printf("argv: %s\n",p->val);
      p = p->next;
    }

  return &result;
}

int * cin_1_svc(cin_params * argp, struct svc_req * rqstp)
{
  static int result = 0;

  printf("cin_1_svc: %d %s\n",argp->seq,argp->data);

  return &result;
}
