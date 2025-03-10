#include "command.h"

void delete_product()
{
    int rc;
    char *errmsg = 0;
    sqlite3 *db;

    rc = sqlite3_open("output/inventary.db", &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db); // Cerrar para evitar fugas de memoria
        return;
    }

    int id_delete;
    printf("\n[delete-id] >> ");
    scanf("%i", &id_delete);

    const char *sql = "DELETE FROM tienda WHERE id = ?";
    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_int(stmt, 1, id_delete);
    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "Error al ejecutar la consulta: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        printf("El producto con ID %d fue eliminado correctamente.\n", id_delete);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
