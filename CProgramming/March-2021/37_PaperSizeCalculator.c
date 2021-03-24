
#include <stdio.h>

int main()
{
  int n = 8;
  int a_n_width = 1189, a_n_height = 841, temp;

  for(int i = 0; i <= n; ++i)
  {
    printf("Dimensions of A%d size paper are %dmm x %dmm.\n", i, a_n_width, a_n_height);
     
    temp = a_n_width / 2;
    a_n_width = a_n_height;
    a_n_height = temp;
  }

  return 0;
}
