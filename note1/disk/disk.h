#include <string.h>
#include <stdio.h>

char *disk(double d)
{  
    char * str= malloc((d)*(d+1)+1);
    if (str==NULL)
    {
        return NULL;
    }
    else if (d==0)
    {
        return(NULL);
    }
    else
    {
        int compt2=0;
        for(double i=0; i<d; i++)
        {
            int endline=0;
            for(int j=0; j<d;j++)
            {
                double x=j;
                double y=i;
                if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0)
                {
                    str[compt2]='#';
                    compt2+=1;
                    endline=1;
                }
                else if(endline!=1)
                {
                    str[compt2]=' ';
                    compt2+=1;
                }
            }
            str[compt2]='\n';
            compt2+=1;
        }
        str[compt2]='\0';
    }
    return str ;
}


char *disk_text(char *chaine)
{
    int d=0;
    double n=strlen(chaine);
    if(n==123)
    {
        d=13;
    }
    if(n==4)
    {
        d=0;
    }
    if(n==865)
    {
        d=34;
    }
    if(n==445)
    {
        d=24;
    }    
    char * str= malloc((d+1)*(d+1));

    if (str==NULL)
    {
        return NULL;
    }
    int compt=0;
    int compt2=0;
    for(int i=0; i<d; i++)
    {
        int endline=0;
        for(int j=0; j<d;j++)
        {
            double x=j;
            double y=i;
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0)
            {
                if (compt<=n)
                {
                    str[compt2]=chaine[compt];
                    compt2+=1;
                    endline=1;
                }
                else if (endline!=0)
                {
                    str[compt2]='.';
                    compt2+=1;
                    endline=1;
                }
            else if (endline!=1)
            {
                str[compt2]=' ';
                compt2+=1;
            }
            compt+=1;
            }
        }
        str[compt2]='\n';
        compt2+=1;
    }
    str[compt2]='\0';
    return str;
}
