#include "command.h"

static int callback(void *NotUsed, int number_columns, char **name_file, char **name_colums)
{
    (void)NotUsed;

    for (int i = 0; i < number_columns; i++)
    {
        printf("%s: %s\n", name_colums[i], name_file[i] ? name_file[i] : "NULL");
    }
    return 0;
}

void view_inventary()
{
    sqlite3 *db;
    // Product p;
    int rc;
    char *errmsg = 0;

    rc = sqlite3_open("output/inventary.db", &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "2 Error al abrir la base de datos %s\n", sqlite3_errmsg(db));
    }

    const char *sql_select = "SELECT * FROM tienda;";

    rc = sqlite3_exec(db, sql_select, callback, 0, &errmsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "3 Error al abrir la base de datos %s\n", sqlite3_errmsg(db));
    }

    sqlite3_close(db);
}