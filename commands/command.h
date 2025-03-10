#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <sqlite3.h>

typedef struct
{
    int id;
    char name[50];
    int amount;
    double price;
} Product;

// Prototipo de función
void add_inventary();
void view_inventary();

void migrate_db(const char *file_db);
void delete_product();

#endif