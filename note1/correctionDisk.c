char *disk(int d)
{  
    char * str= calloc((d)*(d+1)+1); //calloc permet de ne pas rajouter de '\0' a la fin, car initialisé a zero.
    for(int y=0;y<d;y++)
    {
        for(int x; x<d;x++)
        {
            if (((d/2.0-0.5) - x)*((d/2.0-0.5) - x) + ((d/2.0-0.5) - y)*((d/2.0-0.5) - y) < d*d/4.0)
            {
               str[(y*(d+1))+x]= '#';   
            }
            else
            {
               str[(y*(d+1))+x]= ' ';   
            }
            

            str[(y*(d+1))+x]= '#';
        }
        str[(y*(d+1))+d]='\n';
    }
    return str;
}