#include <stdio.h>
//#include <conio.h>
#include <sqlite3.h>
#include <unistd.h>
#include "commands/command.h"

void create_db(const char *file)
{
    sqlite3 *db;
    int rc;
    char *errmsg = 0;

    rc = sqlite3_open(file, &db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "2 Error al abrir la base de datos %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return;
    }
    const char *sql = "CREATE TABLE IF NOT EXISTS tienda (id INTEGER PRIMARY KEY, product TEXT UNIQUE, amount INTEGER, price REAL);";
    sqlite3_exec(db, sql, NULL, NULL, &errmsg);

    sqlite3_close(db);
}
// saber si existe la base de datos y la tabla

void menu()
{
    printf("\nINVENTARY\n");
    printf("1. view inventary\n");
    printf("2. add inventary\n");
    printf("3. delete products\n");
    printf("4. update add db\n");
    printf("5. migration binary\n");
    printf("6. exit\n");
}

int main()
{
    int option;

    create_db("output/inventary.db");
    do
    {

        menu();
        printf("\nselect >> ");
        scanf("%i", &option);

        switch (option)
        {
        case 1:
            /* code */
            view_inventary();
            break;

        case 2:
            add_inventary();
            break;
        case 3:
            delete_product();
            break;
        case 4:
            break;

        case 5:
            migrate_db("output/inventary.db");
            break;

        default:
            break;
        }

    } while (option != 6);

    //getch();
    return 0;
}
