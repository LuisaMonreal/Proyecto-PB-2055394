#include <iostream>
#include <math.h> // calculos matematicos
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using  namespace std;

struct tienda
{
    string nombre, descripcion, genero, clasificacion, consola;
    int no_item, precio_uni;
    float total, iva;
}art[3];

int main()
{ 
    int opcion;

    printf("\t ***MENU DE OPCIONES***\n"); // \t es tabulador
    printf("1.-Alta\n");
    printf("2.-Modificacion\n");
    printf("3.-Baja\n");
    printf("4.-Lista\n");
    printf("5.-Limpiar Pantalla\n");
    printf("6.-Salir\n");
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1: //ALTA
        for (int i = 0; i < 3; i++)
        {
            printf("\ningrese No. de producto:\n");
            scanf("%d", &art[i].no_item);
            cin.ignore();
            printf("ingrese el nombre del producto:\n");
            getline(cin, art[i].nombre);
            printf("ingrese la descripcion del producto:\n");
            getline(cin, art[i].descripcion);
            printf("ingrese el genero del producto:\n");
            getline(cin, art[i].genero);
            printf("ingrese la clasificacion del producto:\n");
            getline(cin, art[i].clasificacion);
            printf("ingrese la consola del producto:\n");
            getline(cin, art[i].consola);
            printf("ingrese el precio por unidad del producto:\n");
            scanf("%d", &art[i].precio_uni);
            art[i].iva=art[i].precio_uni/100*16;
            art[i].total=art[i].precio_uni*1.16;
        }
        return main();
        break;
    case 2:
        cout << "opcion no disponible por el momento\n";
        return main();
        break;

    case 3:
        cout << "opcion no disponible por el momento\n";
        return main();
        break;

    case 4:
        for (int i = 0; i < 3; i++)
        {
            printf("No. de producto: %d \n", art[i].no_item);
            printf("Nombre del producto: %s \n", art[i].nombre.c_str());
            printf("Descripcion del producto: %s \n", art[i].descripcion.c_str());
            printf("Genero del producto: %s \n", art[i].genero.c_str());
            printf("Clasificacion del producto: %s \n", art[i].clasificacion.c_str());
            printf("Consola del producto: %s \n", art[i].consola.c_str());
            printf("Precio por unidad del producto: %d \n", art[i].precio_uni);
            printf("Impuestos: %f \n", art[i].iva);
            printf("Precio final del producto: %f \n\n", art[i].total);

        }
        return main();
        break;

    case 5:
        system("cls"); // limpiar pantalla
        return main();
        break;
    case 6:
        exit(1); // cierra la pantalla
        return 0;   
        break;
    default:
        cout<<"opcion invalida, regresando al menu"<< endl;
        return main();
        break;
    }
return main();
system("pause");
}