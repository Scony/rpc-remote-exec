struct arg
{
  string val<>;
  arg * next;
};

struct rexec_params
{
  string name<>;
  arg * first;
};

struct cin_params
{
  string data<>;
  int seq;
};

program REMOTE_EXEC
{
  version V1
  {
    int rexec(rexec_params) = 1;
    int cin(cin_params) = 2;
  } = 1;
} = 0x20199280;
