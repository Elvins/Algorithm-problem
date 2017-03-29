#include <stdio.h>
#include <string.h>
using namespace std;
bool zhishuflag[1100];
void dabiao()
{
  memset(zhishuflag, 0, sizeof(zhishuflag));
  for(int i = 2; i <= 1000; i++)
  {
    if(!zhishuflag[i])
    {
      for(int j = 2; (j*i) <= 1000; j++)
      {
        zhishuflag[j*i] = true;
      }
    }
  }
}

int main(int argc, char** argv)
{
  	dabiao();
    int num;
    scanf( "%d", &num );
    
    int result = 0;
    
    for(int i = 2; i <= num/2; i++)
    {
      if(zhishuflag[i] || zhishuflag[num-i])
      {
        continue;
      }else
      {
        result++;
      }
    }  
    
    printf("%d",result);
    
    return 0;
}