#include <stdio.h>
#include <stdlib.h>

/*
typedef struct {
    char * name;
    int birthYear;
    int id;
} Student;

Student * student_create(void){
    Student * s= malloc(sizeof(Student));
    s->name=malloc(1000*sizeof(char));
    fgets(s->name,1000,stdin);
    scanf("%d",&(s->birthYear));
    scanf("%d",&(s->id));
    if (s!=NULL)
    {
        return(s);
    }
    else
    {
        return(NULL);
    }
}

void student_free(Student * s)
{
    if (s!=NULL)
    {
        free(s->name);
        free(s);
    }
}

void student_print(Student * s)
{
    printf("id:        %d\n", s->id);
    printf("name:      %s", s->name);
    printf("birthYear: %d\n", s->birthYear);
    
}

*/

typedef struct {
    char * name;
    int birthYear;
    int id;
} Student;

Student * student_create(void)
{
    Student * s=malloc (sizeof(Student)*sizeof(Student));
    
    if(s!=NULL)
    {
        s->name=NULL;
        s->name=malloc(1000);
        if(s->name!=NULL) {
            fgets(s->name,1000,stdin);
            scanf("%d",&(s->birthYear));
            scanf("%d",&(s->id));
            return(s);
        }
    }
    free(s);
    return(NULL);
}

void student_print(Student * s)
{
    printf("id:        %i\n",s->id);
    printf("name:      %s",s->name);
    printf("birthYear: %i\n",s->birthYear);

}

void student_free(Student * s)
{
    if (s!=NULL)
    {
        free(s->name);
        free(s);
    }
}

