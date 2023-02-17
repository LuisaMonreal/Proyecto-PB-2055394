#include <iostream>
#include <math.h> // calculos matematicos
using  namespace std;

int main()
{ 
    char nombre[100], descripcion[100], genero[100], clasificacion[100], consola[100];
    int no_item, desicion, opcion;
    float precio_uni, total;

    cout << "\t ***MENU DE OPCIONES***\n"; // \t es tabulador
    cout << "1.-Alta\n";
    cout << "2.-Modificacion\n";
    cout << "3.-Baja\n";
    cout << "4.-Lista\n";
    cout << "5.-Limpiar Pantalla\n";
    cout << "6.-Salir\n";
    cin >> opcion;

    switch (opcion)
    {
    case 1: //ALTA
        cout << "ingrese No. de producto:(no ingrese espacios en ninguna opcion)  \n ";
        cin>>no_item;
        cout << "ingrese el nombre del producto:\n ";
        cin>>nombre;
        cout << "ingrese la descripcion del producto:\n ";
        cin>>descripcion;
        cout << "ingrese el genero del producto:\n ";
        cin>>genero;
        cout << "ingrese la clasificacion del producto:\n ";
        cin>>clasificacion;
        cout << "ingrese la consola del producto:\n ";
        cin>>clasificacion;
        cout << "ingrese el precio por unidad del producto:\n ";
        cin>>precio_uni;
        total=precio_uni*1.16;
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
        cout << "opcion no disponible por el momento\n";
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
