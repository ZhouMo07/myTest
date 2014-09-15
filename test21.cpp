/*meituan 
arrange array
R,B,B,b,W,W,B,R,B,w
b,B,B,B,B,R,R,w,W,W
with O(n)
*/
#include<iostream>

using namespace std;

void fun(char Array[])
{
     int len = strlen(Array);
     //
     if(len == 0)
      {
            printf("the length of Array is 0.\n");
            return;
      }
     for(int i = 0; i < len ; i ++)
     {
             if(Array[i] < 'A' || (Array[i] > 'Z' && Array[i] < 'a') || Array[i] > 'z')
                     {
                           printf("input is not letter.\n");
                           return;
                     }
     }
     
     int cnt[52]={0};
     for(int i = 0; i < len ; i ++)
     {
             if(Array[i] >= 'a' && Array[i] <= 'z')
                         {
                               cnt[Array[i]-'a'] ++;
                         }
            if(Array[i] >= 'A' && Array[i] <= 'Z')
                  {
                              cnt[Array[i]-'A'+26] ++;
                              //printf("%d, ",(Array[i]-'A'+26));
                  }      
     }
     /*
     for(int i = 0; i < 52; i++)
     {
             if(i == 26)
                  printf("\n");
             printf("%d, ",cnt[i]);
             
     }
     printf("\n");
     */
     
     for(int i = -1,j= 0; j < 26; j ++)
     {
             while(cnt[j] != 0)
             {
                       
                       Array[++i] = j + 'a'; 
                      // printf("%c\n",j + 'a');
                       -- cnt[j];
             }
             while(cnt[j+26] != 0)
             {
                       Array[++i] = j  + 'A';
                      // printf("%c\n",j + 'A');
                       -- cnt[j+26];
             }
     }
}

void Test1()
{
     char A[]="RBBbWWBRBw";
     printf("Test1:");
     fun(A);
     for(int i = 0; i < strlen(A); i ++)
     {
      printf("%c, ",A[i]);
     }
     printf("\n");
}

void Test2()
{
     char A[]="";
     
     printf("Test2:");
     fun(A);
     for(int i = 0; i < strlen(A); i ++)
     {
      printf("%c, ",A[i]);
     }
     printf("\n");
}

void Test3()
{
      char A[]=" ";
     
     printf("Test3:");
     fun(A);
     for(int i = 0; i < strlen(A); i ++)
     {
      printf("%c, ",A[i]);
     }
     printf("\n");
}
void Test4()
{
     char A[]="23";
     
     printf("Test3:");
     fun(A);
     for(int i = 0; i < strlen(A); i ++)
     {
      printf("%c, ",A[i]);
     }
     printf("\n");
}
int main()
{
    
    Test1();
    Test2();
    Test3();
    Test4();
    system("pause");
}
