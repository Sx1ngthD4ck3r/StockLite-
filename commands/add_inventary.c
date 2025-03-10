#include "command.h"

void add_inventary()
{
    Product add_product;

    FILE *file = fopen("output/inventary.bin", "ab+");

    fseek(file, 0, SEEK_END);
    int num_product = ftell(file) / sizeof(Product);
    add_product.id = num_product + 1;

    printf("[add]> ");
    scanf("%49s", add_product.name);

    // scanf("%i", &add_product.id);
    printf("[amount]> ");
    scanf("%i", &add_product.amount);

    printf("[price]> ");
    scanf("%lf", &add_product.price);

    fwrite(&add_product, sizeof(Product), 1, file);

    fclose(file);

    printf("Datos agregados al binario\n");
}