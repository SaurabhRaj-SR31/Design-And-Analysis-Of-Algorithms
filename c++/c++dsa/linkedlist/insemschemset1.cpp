#include<iostream>
#include<string.h>
using namespace std;
class student
{
    int regno;
    char name[20];
    int sem;
    char branch[10];
    student *prev;
    student *next;

public:
    student() {}
    student(int r, char n[], int s, char b[])
    {
        regno = r;
        strcpy(name, n);
        sem = s;
        strcpy(branch, b);
        next = NULL;
        prev = NULL;
    }
    void insert_sorted(int r, char n[], int s, char b[]);
    student *deleteNode(student *f, student *d);
    student *removeDuplicates(student *f);
}*first=NULL;


 void student::insert_sorted(int r, char n[], int s, char b[])
{
    student *s1 = new student(r, n, s, b);
    student *c, *prev1 = NULL;
    if (!first)
    {
        first = s1;
        return;
    }
    else if (first->regno > s1->regno)
    {
        s1->next = first;
        first->prev = s1;
        first = s1;
        return;
    }
    prev1 = first;
    for (c = first->next; c != NULL; c = c->next)
    {
        if (s1->regno < c->regno)
            break;
        prev1 = c;
    }
    if (c)
    {
        s1->prev = c->prev;
        s1->next = c;
        c->prev = s1;
        if (prev1)
            prev1->next = s1;
    }
    else
    {
        prev1->next = s1;
        s1->prev = prev1;
    }
}
student *student::deleteNode(student *f, student *d)
{
    if (f == NULL || d == NULL)
        return f;
    if (f == d)
        f = d->next;
    if (d->next != NULL)
        d->next->prev = d->prev;
    if (d->prev != NULL)
        d->prev->next = d->next;
    delete (d);
    return f;
}
student *student::removeDuplicates(student *f)
{
    if (f == NULL || f->next == NULL)
        return f;
    student *c1, *c2, *n;
    for (c1 = f; c1 != NULL; c1 = c1->next)
    {
        c2 = c1->next;
        while (c2 != NULL)
        {
            if (c1->regno == c2->regno)
            {
                n = c2->next;
                deleteNode(f, c2);
                c2 = n;
            }
            else
                c2 = c2->next;
        }
    }
    return (f);
}