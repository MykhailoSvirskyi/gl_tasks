#include <stdlib.h>
#include <stdio.h>
#include "book.c"
#include "book.h"

void main()
{
    struct Book a;
    struct Book b;
    struct Book c;
    struct Book d;
    struct Book e;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    a.title = "Philosopher's Stone";
    a.language = "English";
    a.year = 1997;

    b.title = "Chamber of Secrets";
    b.language = "Franch";
    b.year = 1998;

    c.title = "Prisoner of Azkaban";
    c.language = "English";
    c.year = 1999;

    d.title = "Goblet of Fire";
    d.language = "English";
    d.year = 2000;

    e.title = "Order of the Phoenix";
    e.language = "Italian";
    e.year = 2003;

    Book_Print(&a);
    Book_Init(&a, "Harry 2033", "Uk", 666);
    printf("book changed:\n\r");
    Book_Print_All(&a);
    Book_Link(&a, &c);
    printf("after change link: \n\r");
    Book_Print_All(&a);
}
