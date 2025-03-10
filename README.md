# StockLite-

Sistema de inventario en C con SQLite, enfocado en eficiencia y migraciones de datos.

## Características

- Creación automática de la base de datos y tabla al iniciar.
- Visualización del inventario almacenado.
- Agregar productos al inventario.
- Eliminar productos existentes.
- Migración de datos a un formato binario.

## Requisitos

- [GCC](https://gcc.gnu.org/) o cualquier otro compilador de C.
- [SQLite3](https://www.sqlite.org/) instalado.
- Sistema operativo Linux o Windows.

## Instalación

1. Clona este repositorio:
   ```sh
   git clone https://github.com/tuusuario/inventary-system.git
   cd inventary-system
   ```

2. Compila el código fuente:
   ```sh
   gcc -I./include main.c commands/add_inventary.c commands/view_inventary.c commands/migrate_db.c commands/delete_product.c -L./lib -lsqlite3 -static -o inventary && ./inventary
   ```

3. Ejecuta el programa:
   ```sh
   ./inventary
   ```

## Termux

1. Instala el paquete
   ```pkg install binutils-is-llvm```

2. Compila las librería sqlite3
   ```gcc -c lib/sqlite3.c -o lib/sqlite3.o && ar rcs lib/libsqlite3.a lib/sqlite3.o;```

4. Compila el código fuente:
   ```sh
   gcc -I./include main.c commands/add_inventary.c commands/view_inventary.c commands/migrate_db.c commands/delete_product.c -L./lib -lsqlite3 -o inventary && ./inventary
   ```

3. Ejecuta el programa:
   ```sh
   ./inventary
   ```

## Uso

El programa mostrará un menú con las siguientes opciones:

1. **Ver inventario**: Muestra los productos almacenados.
2. **Agregar inventario**: Permite agregar un nuevo producto.
3. **Eliminar productos**: Permite eliminar un producto por nombre.
4. **Actualizar base de datos**: (Próximamente implementado).
5. **Migración binaria**: Exporta los datos a un formato binario.
6. **Salir**: Termina la ejecución del programa.

## Estructura del Proyecto

```
📂 inventary-system
├── 📂 commands
│   ├── command.h
│   ├── view_inventary.c
│   ├── add_inventary.c
│   ├── delete_product.c
│   └── migrate_db.c
├── main.c
├── README.md
└── output/
    └── inventary.db
```

## Contribución

1. Haz un fork del repositorio.
2. Crea una nueva rama: `git checkout -b feature-nueva`.
3. Realiza tus cambios y confírmalos: `git commit -m "Agrega nueva funcionalidad"`.
4. Sube los cambios: `git push origin feature-nueva`.
5. Abre un Pull Request.

## Licencia

Este proyecto está bajo la licencia Apache. Puedes consultar el archivo [LICENSE](LICENSE) para más detalles.




