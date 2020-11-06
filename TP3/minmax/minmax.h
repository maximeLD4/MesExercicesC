void minmax(int *arr, int length, int *min, int *max)
{
    *max=arr[0];
    *min=arr[0];
    for (int i=0; i<length; i++)
    {
        int l= arr[i];
        if (l>=*max)
        {
            *max=l;
        }
        else if (l<=*min)
        {
            *min=l;
        }
    }
}
