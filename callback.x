struct params
{
  string data<>;
  int seq;
};

program CALLBACK
{
  version V1
  {
    int cout(params) = 1;
    int cerr(params) = 2;
    int ret(int) = 3;
  } = 1;
} = 0x20199276;