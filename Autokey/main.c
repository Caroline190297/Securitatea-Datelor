#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *plain, *key, *cih, alp[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int j,k,plen,klen,i,count=0,ct[50];

    printf("dati textul!\n");
    gets(plain);
    printf("dati cheia!\n");
    gets(key);

    plen=strlen(plain);
    klen=strlen(key);

    if(klen<plen)
    {
        for(i=klen;i<plen;i++)
        {
            key[i]=plain[count];
            count++;
        }
    }

    printf("acum cheia este: \n");
    for(i=0;i<plen;i++)
    {
        printf("%s",key[i]);
    }
    printf("\n");

    for(i=0;i<plen;i++)
    {
        for(j=0;i<26;j++)
        {
            if(plain[i]==alp[j])
            {
                ct[i]=j;
                for(k=0;k<26;k++)
                {
                    if(key[i]==alp[k])
                    {
                        ct[i]+=k;
                    }
                }
            }
        }
    }

    printf("textul criptat va fi: \n");
    for(i=0;i<plen;i++)
    {
        ct[i]=ct[i]%26;
        cih[i]=alp[ct[i]];
        printf("%s",alp[ct[i]]);
    }

    printf("decriptare: \n");
    int ctl[100];
    for(i=0;i<plen;i++)
    {
        for(j=0;i<26;j++)
        {
            if(cih[i]==alp[j])
            {
                ctl[i]=j;
                for(k=0;k<26;k++)
                {
                    if(key[i]==alp[k])
                    {
                        ctl[i]-=k;
                    }
                }
            }
        }
    }

    printf("plain textul:\n");
    for(i=0;i<plen;i++)
    {
        ctl[i]=ctl[i]%26;
        if(ctl[i]<0)
        {
            ctl[i]=ctl[i]+26;
        }
        printf("%s",alp[ctl[i]]);
    }

    return 0;
}
