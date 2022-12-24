#pragma once
struct Book
{
    struct Book *next;
    const char *title;
    int year;
    const char *language;
};

void Book_Print(struct Book *this);                                                            // (&) Print all info about book
void Book_Init(struct Book *this, const char *title_in, const char *language_in, int year_in); // (&a,title,language,year) change book
void Book_Link(struct Book *this, struct Book *other);                                         //(&a,&b) Add link  from a to b
void Book_Print_All(struct Book *thiss);                                                       //(&a) Print "a" and all next books