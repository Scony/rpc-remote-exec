/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "callback.h"


void cout_callback(char * host, char * data)
{
  static int seq = -1;
  CLIENT * clnt;
  int * result;
  params cout_1_arg;

  cout_1_arg.seq = ++seq;
  cout_1_arg.data = data;

  clnt = clnt_create(host,CALLBACK,V1,"udp");
  if(clnt == NULL)
    {
      clnt_pcreateerror(host);
      exit(1);
    }

  result = cout_1(&cout_1_arg, clnt);
  if(result == (int *)NULL)
    {
      clnt_perror(clnt,"call failed");
    }

  clnt_destroy (clnt);
}

void cerr_callback(char * host, char * data)
{
  static int seq = -1;
  CLIENT * clnt;
  int * result;
  params cerr_1_arg;

  cerr_1_arg.seq = ++seq;
  cerr_1_arg.data = data;

  clnt = clnt_create(host,CALLBACK,V1,"udp");
  if(clnt == NULL)
    {
      clnt_pcreateerror(host);
      exit(1);
    }

  result = cerr_1(&cerr_1_arg, clnt);
  if(result == (int *)NULL)
    {
      clnt_perror(clnt,"call failed");
    }

  clnt_destroy (clnt);
}

void result_callback(char * host, int rslt)
{
  CLIENT * clnt;
  int * result;
  int ret_1_arg;

  ret_1_arg = rslt;

  clnt = clnt_create(host,CALLBACK,V1,"udp");
  if(clnt == NULL)
    {
      clnt_pcreateerror(host);
      exit(1);
    }

  result = ret_1(&ret_1_arg, clnt);
  if(result == (int *)NULL)
    {
      clnt_perror(clnt,"call failed");
    }

  clnt_destroy (clnt);
}


int main(int argc, char * argv[])
{
  char * host = argv[1];

  if(argc < 3)
    {
      printf("usage: %s callback_server_host command [arguments]\n", argv[0]);
      exit(1);
    }

  cout_callback(argv[1],"cout test !\n");
  cerr_callback(argv[1],"test cerr.\n");
  result_callback(argv[1],5);
  return 0;
}
