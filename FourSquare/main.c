#include<stdio.h>
#include<string.h>


char fs[10][10],c[1000],ans[1000],decy[1000];;

struct index
{
       int x,y;
};

void table(char *k1, char *k2)
{
       int i,j,k=65,lk1=0,lk2=0,vk1[26]={0},vk2[26]={0},lv1=0,lv2=0,m=65;
       for(i=0;i<10;i++)
       {
              for(j=0;j<10;j++)
              {
                     if(i<5)
                     {
                           if(j<5)
                           {
                                  fs[i][j] = k;
                                  k++;
                           }
                           else
                           {
                                  if(lk1<strlen(k1))
                                  {
                                         fs[i][j] = k1[lk1];
                                         vk1[k1[lk1]-97] = 1;
                                         lk1++;
                                  }
                                  else
                                  {
                                         while(vk1[lv1]==1)
                                         {
                                                lv1++;
                                         }
                                         fs[i][j] = lv1 + 97;
                                         lv1++;
                                  }

                           }
                     }
                     else
                     {
                           if(j<5)
                           {
                                  if(lk2<strlen(k2))
                                  {
                                         fs[i][j] = k2[lk2];
                                         vk2[k2[lk2]-97] = 1;
                                         lk2++;
                                  }
                                  else
                                  {
                                         while(vk2[lv2]==1)
                                         {
                                                lv2++;
                                         }
                                         fs[i][j] = lv2 + 97;
                                         lv2++;
                                  }
                           }
                           else
                           {
                                  fs[i][j] = m;
                                  m++;
                           }
                     }
                     printf("%s\n",fs[i][j]);
              }

       }

}

int convert(char *s)
{
       int i,j = 0,f=0;
       for(i=0;i<strlen(s);i++)
       {
              if( (s[i]>47 && s[i]<58) || (s[i]>96 && s[i]<123) )
              {
                     if((i+f)%2!=0 && c[j-1]==s[i])
                     {
                           c[j] = 'x';
                     }
                     else
                     {
                           c[j] = s[i];
                     }
                     printf("%s\n",c[j]);
                     j++;
              }
              else
              {
                     f++;
              }
       }
       if(j%2!=0)
       {
              c[j] = 'x';
              printf("%s\n",c[j]);
              j++;
       }
       return j;
}

struct index findIndex1(char ch)
{
       int i,j;
       struct index f;
       for(i=0;i<5;i++)
       {
              for(j=5;j<10;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=5;
                           j=10;;
                     }
              }
       }
       return f;
}

struct index findIndex2(char ch)
{
       int i,j;
       struct index f;
       for(i=5;i<10;i++)
       {
              for(j=0;j<5;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=10;
                           j=5;
                     }
              }
       }
       return f;
}

void encrypt(int l)
{
       int i,ax,ay,bx,by;
       struct index f;
       for(i=0;i<l;i=i+2)
       {
              f = findIndex1(c[i]);
              ax = f.x;
              ay = f.y;
              f = findIndex2(c[i+1]);
              bx = f.x;
              by = f.y;
              ans[i] = fs[ax][by];
                      ans[i+1] = fs[bx][ay];
              printf("%s %s\n",ans[i],ans[i+1]);
       }
}

struct index findIndex3(char ch)
{
       int i,j;
       struct index f;
       for(i=0;i<5;i++)
       {
              for(j=0;j<5;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=5;
                           j=10;;
                     }
              }
       }
       return f;
}

struct index findIndex4(char ch)
{
       int i,j;
       struct index f;
       for(i=5;i<10;i++)
       {
              for(j=5;j<10;j++)
              {
                     if(fs[i][j]==ch)
                     {
                           f.x = i;
                           f.y = j;
                           i=10;
                           j=5;
                     }
              }
       }
       return f;
}


void decrypt(int l)
{
       int i,ax,ay,bx,by;
       struct index f;
       for(i=0;i<l;i=i+2)
       {
              f = findIndex3(ans[i]);
              ax = f.x;
              ay = f.y;
              f = findIndex4(ans[i+1]);
              bx = f.x;
              by = f.y;
                     decy[i] = fs[ax][by];
                     decy[i+1] = fs[bx][ay];
              printf("%s %s\n",decy[i],decy[i+1]);
       }
}

int main()
{
       char *s,*k1,*k2;
       printf("Enter the String to be Ciphered \n");
       gets(s);
       printf("Enter the Keys : \n");
       gets(k1);
       gets(k2);
       int f=0;
       printf("Four Square Matrix : \n");
       table(k1,k2);
       printf("Message : ");
       f = convert(s);
       printf("\nEncrypted Message : ");
       encrypt(f);
       printf("\nDecrypted Message : ");
       decrypt(f);
       return  0;
}
