#include "test-tab.h"
#include "nestpasdansBob.h"


int test(const unsigned long long *T, int n)
{
    for(int i=0;i<n;i++)
    {
        if(T[i]==10000000000)
        {
            return 'BOB';
        }
        if(nestpasdansBob(T[i]))
        {
            return 'ALICE';
        }
    }
    return 'BOB';
}
