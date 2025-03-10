#include "command.h"

void migrate_db(const char *file_db)
{

    Product p;
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open(file_db, &db);

    FILE *file = fopen("output/inventary.bin", "rb");
    fseek(file, 0, SEEK_END); // Pone le cursor al fianl del archivo

    int file_size = ftell(file); // Cuenta cauntos bytes hay en el archivo
    rewind(file);

    int size = file_size / sizeof(Product);

    const char *sql_prepare = "INSERT OR IGNORE INTO tienda (product, amount, price) VALUES (?, ?, ?);";

    rc = sqlite3_prepare_v2(db, sql_prepare, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, " 1 Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        fclose(file);
        sqlite3_close(db);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        fread(&p, sizeof(Product), 1, file);
        // printf("\nId: %i", p.id);

        sqlite3_bind_text(stmt, 1, p.name, -1, SQLITE_STATIC);
        // printf("\nProduct: %s", p.name);

        sqlite3_bind_int(stmt, 2, p.amount);
        // printf("\nAmount: %i", p.amount);

        sqlite3_bind_double(stmt, 3, p.price);
        // printf("\nPrice: %.2f\n", p.price);

        if (sqlite3_step(stmt) != SQLITE_DONE)
        {
            fprintf(stderr, "Error al insertar datos: %s\n", sqlite3_errmsg(db));
        }
        else
        {
            printf("Migracion de binary a db completada!!\n");
        }
        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    fclose(file);
}