int nestpasdansBob(int n)
{
    int tab1[10000000000];
    int tab2[10000000000];
    int tab3[10000000000];
    int k=0;
    int m=0;
    int o=0;
    for (int p=0;p<10000000000;p++)
    {
        tab2[m]=p;
        m++;
    }
    for (int i=0;i<100000;i++)
    {
        for(int j=0; j<100000;j++)
        {
            int verif=0;
            tab1[k]=i*j;
            k++;
            for (int l=0;l<10000000;l++)
            {
                if (tab2[l]==tab1[k])
                {
                    int verif=1;
                }
            }
            if (verif==0)
            {
                tab3[o]=tab1[k];
                o++;
            }
        }
    }
    for (int y=0;y<o;y++)
    {
        if(n==tab3[y])
        {
            return 1;
        }
    }
}