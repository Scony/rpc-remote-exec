/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "remote_exec.h"

int *
rexec_1_svc(rexec_params *argp, struct svc_req *rqstp)
{
  static int  result;

  printf("rexec_1_svc\n");

  return &result;
}

int *
cin_1_svc(cin_params *argp, struct svc_req *rqstp)
{
  static int  result;

  printf("cin_1_svc\n");

  return &result;
}
