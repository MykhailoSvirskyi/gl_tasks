#include "book.h"
#include <stdlib.h>
#include <stdio.h>

void Book_Print(struct Book *this)
{
    printf("Title: %s  Year: %d Language: %s \n\r",
           this->title,
           this->year,
           this->language);
}

void Book_Print_All(struct Book *thiss)
{
    for (struct Book *nxt = thiss; nxt != NULL; nxt = nxt->next)
    {
        Book_Print(nxt);
    }
}

void Book_Init(struct Book *this, const char *title_in, const char *language_in, int year_in)
{

    if (this != NULL)
    {

        this->title = title_in;
        this->language = language_in;
        this->year = year_in;
    }
}

void Book_Link(struct Book *this, struct Book *other)
{
    this->next = other;
}