typedef struct student_t
{
    char * first_name;
    char * last_name;
}student_t;

void strAlloc (struct student_t * stud, unsigned long long n)
{
    stud->first_name=calloc(n,sizeof(char));
    stud->last_name=calloc(n,sizeof(char));
    if (stud->first_name==NULL ||stud->last_name==NULL)
    {
        free(stud->first_name);
        free(stud->last_name);
        stud->first_name=NULL;
        stud->last_name=NULL;
    }
}