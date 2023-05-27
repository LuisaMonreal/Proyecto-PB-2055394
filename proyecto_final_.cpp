#include <iostream>
#include <math.h> // calculos matematicos
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using  namespace std;

struct GamesImpact //nombre de la tienda
{
    string nombre, descripcion, genero, clasificacion, consola, disponibilidad;
    int no_item, precio_uni;
    float total, iva;
};
int contador,alta;

GamesImpact *articulos;

void Alta();
void eliminar();
void lista();
void modificar();
void archivos();

int main()
{ 
    int opcion;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c\n Bienvenido\n%c%c%c%c%c%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,205,205,205,205,205,187 ,200,205,205,205,205,205,205,205,205,205,205,188);
    printf("\t %c%c%cMENU DE OPCIONES%c%c%c\n",174,205,175,174,205,175); // \t es tabulador
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
        Alta(); 
        return main();
        break;

    case 2:
        modificar();
        return main();
        break;

    case 3:
        eliminar();
        return main();
        break;

    case 4:
        lista();
        return main();
        break;

    case 5:
        system("cls"); // limpiar pantalla
        return main();
        break;
    case 6:
        archivos();
		printf("%c%c%c%c%c%c%c%c%c%c%c\n  Gracias\n%c%c%c%c%c%c%c%c%c%c%c\n", 201,205,205,205,205,205,205,205,205,205,187 ,200,205,205,205,205,205,205,205,205,205,188);
        return 0;   
        break;
    default:
        cout<<"opcion invalida, regresando al menu"<< endl;
        return main();
        break;
    }
}

void Alta()
{
	printf("¿cuantos registros desea dar de alta? \n");
	scanf("%d", &alta);
    articulos = new GamesImpact[alta]; // uso de new para hacer el arreglo dinamico
    for (int i = 0; i < alta; i++)
	{
        printf("\ningrese No. de producto:\n");
        scanf("%d", &articulos[i].no_item);
        cin.ignore();
        printf("ingrese el nombre del producto:\n");
        getline(cin, articulos[i].nombre);
        printf("ingrese la descripcion del producto:\n");
        getline(cin, articulos[i].descripcion);
        printf("ingrese el genero del producto:\n");
        getline(cin, articulos[i].genero);
        printf("ingrese la clasificacion del producto:\n");
        getline(cin, articulos[i].clasificacion);
        printf("ingrese la consola del producto:\n");
        getline(cin, articulos[i].consola);
        printf("ingrese el precio por unidad del producto:\n");
        scanf("%d", &articulos[i].precio_uni);
        articulos[i].iva=articulos[i].precio_uni*.16;
        articulos[i].total=articulos[i].precio_uni*1.16;
        articulos[i].disponibilidad="DISPONIBLE";
    }
}

void lista()
{
    for (int i = 0; i < alta; i++)
	{
		
		if(articulos[i].disponibilidad == "ELIMINADO")
		{
			printf("REGISTRO ELIMINADO\n");
		}
		else
		{
			int j;
			j = i;
			j = j+1;
			printf("\nregistro %d\n", j);           
			printf("No. de producto: %d \n", articulos[i].no_item);
            printf("Nombre del producto: %s \n", articulos[i].nombre.c_str());
            printf("Descripcion del producto: %s \n", articulos[i].descripcion.c_str());
            printf("Genero del producto: %s \n", articulos[i].genero.c_str());
            printf("Clasificacion del producto: %s \n", articulos[i].clasificacion.c_str());
            printf("Consola del producto: %s \n", articulos[i].consola.c_str());
            printf("Precio por unidad del producto: %d \n", articulos[i].precio_uni);
            printf("Impuestos: %f \n", articulos[i].iva);
            printf("Precio final del producto: %f \n\n", articulos[i].total);	
		}
	}
}

void eliminar()
{
	int j;
	printf("\ningrese el  registro a eliminar\n");
	scanf("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando registro\n");
        j + 1;
		articulos[i].disponibilidad = "ELIMINADO";
	}
}

void modificar()
{
	int j, opcion, op2;
	do
	{ 
	printf("ingrese el numero registro a modificar\n");
	scanf("%d", &j);
	j = j - 1; // esto debido a que i inicia en 0

	for (int i = j; i == j; i++)
	{
		if ((articulos[i].disponibilidad == "ELIMINADO"))
		{
			printf("REGISTRO ELIMINADO");
            i + 1;
			printf("ingrese un registro valido \n");
			op2 = 1;
		}
		else
		{
			op2 = 2;
		}
	}
	} while (op2 == 1);
	printf("ingrese que desea modificar\n");
    printf("1.-No. del producto\n");
    printf("2.-nombre del producto\n");
    printf("3.-descripcion del producto\n");
    printf("4.-genero del producto\n");
    printf("5.-clasificacion del producto\n");
    printf("6.-consola del producto\n");
    printf("7.-precio unitario del producto\n");
	scanf("%d",&opcion);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("Ingrese el No. del producto\n");
			scanf("%d", &articulos[i].no_item);
		}
		break;

	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("Ingrese el nombre del producto\n");
			getline(cin, articulos[i].nombre);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); 
			printf("Ingrese la descripcion del producto\n");
			getline(cin, articulos[i].descripcion);
		}
        break;
    
    case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); 
			printf("Ingrese el genero del producto\n");
			getline(cin, articulos[i].genero);
		}
        break;

    case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); 
			printf("Ingrese la clasificacion del producto\n");
			getline(cin, articulos[i].clasificacion);
		}
        break;

    case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); 
			printf("Ingrese la consola del producto\n");
			getline(cin, articulos[i].consola);
		}
        break;

    case 7:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); 
			printf("Ingrese el precio unitario del producto\n");
			scanf("%d", &articulos[i].precio_uni);
            articulos[i].iva=articulos[i].precio_uni*.16;
            articulos[i].total=articulos[i].precio_uni*1.16;
		}
        break;
	}


}

void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	string texto2;

	nombrearchivo = "GamesImpactArticulos.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	//no.item

	int longitud1=0, long1;
	
	for (int i = 0; i < alta; i++) 
	{
		string numeroString = to_string(articulos[i].no_item);	
        if (numeroString.length() > longitud1) 
		{
            longitud1 = numeroString.length();
        }
	}
	if (longitud1<=18)
	{
	archivo << "NUMERO DE PRODUCTO ";
	longitud1 = 19;
	}
	else
	{
		long1 = longitud1 - 18;
		archivo << "NUMERO DE PRODUCTO";
		for(int i = 0; i < long1; i++)
		{
		archivo << " ";
		}	
	}

	//nombre
	int longitud2=0, long2;
	
	for (int i = 0; i < alta; i++) 
	{
        if (articulos[i].nombre.length() > longitud2) 
		{
            longitud2 = articulos[i].nombre.length();
        }
	}
	if (longitud2<=6)
	{
	archivo << "NOMBRE ";
	longitud2 = 7;
	}
	else
	{
		long2 = longitud2 - 6;
		archivo << "NOMBRE";
		for(int i = 0; i < long2; i++)
		{
		archivo << " ";
		}	
		archivo << " ";
	}

//DESCRIPCION
	int longitud3=0, long3;

	for (int i = 0; i < alta; i++) 
	{
        if (articulos[i].descripcion.length() > longitud3) 
		{
            longitud3 = articulos[i].descripcion.length();
        }
	}
	if (longitud3<=11)
	{
	archivo << "DESCRIPCION ";
	longitud3 = 12;
	}
	else
	{
		long3 = longitud3 - 11;
		archivo << "DESCRIPCION";
		for(int i = 0; i < long3; i++)
		{
		archivo << " ";
		}	
		archivo << " ";
	}

	//GENERO
	int longitud4=0, long4;

	for (int i = 0; i < alta; i++) 
	{
        if (articulos[i].genero.length() > longitud4) 
		{
            longitud4 = articulos[i].genero.length();
        }
	}
	if (longitud4<=6)
	{
	archivo << "GENERO ";
	longitud4 = 7;
	}
	else
	{
		long4 = longitud4 - 6;
		archivo << "GENERO";
		for(int i = 0; i < long4; i++)
		{
		archivo << " ";
		}	
		archivo << " ";
	}

	//CLASIFICACION
	int longitud5=0, long5;

	for (int i = 0; i < alta; i++) 
	{
        if (articulos[i].clasificacion.length() > longitud5) 
		{
            longitud5 = articulos[i].clasificacion.length();
        }
	}
	if (longitud5<=13)
	{
	archivo << "CLASIFICACION ";
	longitud5 = 14;
	}
	else
	{
		long5 = longitud5 - 13;
		archivo << "CLASIFICACION";
		for(int i = 0; i < long5; i++)
		{
		archivo << " ";
		}	
		archivo << " ";
	}

	//CONSOLA
	int longitud6=0, long6;

	for (int i = 0; i < alta; i++) 
	{
        if (articulos[i].consola.length() > longitud6) 
		{
            longitud6 = articulos[i].consola.length();
        }
	}
	if (longitud6<=7)
	{
	archivo << "CONSOLA ";
	longitud6 = 8;
	}
	else
	{
		long6 = longitud6 - 7;
		archivo << "CONSOLA";
		for(int i = 0; i < long6; i++)
		{
		archivo << " ";
		}
		archivo << " ";	
	}

//PRECIO UNITARIO
	int longitud7=0, long7;

	for (int i = 0; i < alta; i++) 
	{
		string numeroString = to_string(articulos[i].precio_uni);
        if (numeroString.length() > longitud7) 
		{
            longitud7 = numeroString.length();
        }
	}
	if (longitud7<=15)
	{
	archivo << "PRECIO UNITARIO ";
	longitud7 = 16;
	}
	else
	{
		long7 = longitud7 - 15;
		archivo << "PRECIO UNITARIO";
		for(int i = 0; i < long7; i++)
		{
		archivo << " ";
		}
		archivo << " ";	
	}

    //IMPUESTOS
	int longitud8=0, long8;

	for (int i = 0; i < alta; i++) 
	{
		string numeroString = to_string(articulos[i].iva);
        if (numeroString.length() > longitud8) 
		{
            longitud8 = numeroString.length();
        }
	}
	if (longitud8<=9)
	{
	archivo << "IMPUESTOS ";
	longitud8 = 10;
	}
	else
	{
		long8 = longitud8 - 9;
		archivo << "IMPUESTOS";
		for(int i = 0; i < long8; i++)
		{
		archivo << " ";
		}	
	}
	archivo << "PRECIO TOTAL" << "\n";
	archivo << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (articulos[i].disponibilidad == "ELIMINADO")
		{
			 texto2 = "REGISTRO ELIMINADO";
			 texto = i;
			 archivo << texto2 << texto << "\n";
		}
		else
		{
		int a;
		//no.item
			string numeroString = to_string(articulos[i].no_item);
			if(numeroString.length()<=18)
			{
				texto = articulos[i].no_item;
				archivo << texto;
				a = 18 - numeroString.length();	
			}
			else
			{
				a = numeroString.length();
				texto = articulos[i].no_item;
				archivo << texto;
				a = longitud1 - numeroString.length();
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}
					archivo << " ";

			//nombre
			
			if(articulos[i].nombre.length()<=6)
			{
				texto2 = articulos[i].nombre;
				archivo << texto2;
				a = longitud2 - articulos[i].nombre.length();
			}
			else
			{
				a=articulos[i].nombre.length();
				texto2 = articulos[i].nombre;
				archivo << texto2;
				a = longitud2 - a;					
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}
					archivo << " ";

			//descripcion
			if(articulos[i].descripcion.length()<=11)
			{
				texto2 = articulos[i].descripcion;
				archivo << texto2;
				a = longitud3 - articulos[i].descripcion.length();
			}	
			else
			{
				a=articulos[i].descripcion.length();
				texto2 = articulos[i].descripcion;
				archivo << texto2;
				a = longitud3 - a;	
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}
					archivo << " ";
            
			//genero
			if(articulos[i].genero.length()<=6)
			{
				texto2 = articulos[i].genero;
				archivo << texto2;
				a = longitud4 - articulos[i].genero.length();
			}	
			else
			{
				a=articulos[i].genero.length();
				texto2 = articulos[i].genero;
				archivo << texto2;
				a = longitud4 - a;	
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}
					archivo << " ";

            //clasificacion
			if(articulos[i].clasificacion.length()<=13)
			{
				texto2 = articulos[i].clasificacion;
				archivo << texto2;
				a = longitud5 - articulos[i].clasificacion.length();
			}	
			else
			{
				a=articulos[i].clasificacion.length();
				texto2 = articulos[i].clasificacion;
				archivo << texto2;
				a = longitud5 - a;	
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}
					archivo << " ";

			//consola
			if(articulos[i].consola.length()<=7)
			{
				texto2 = articulos[i].consola;
				archivo << texto2;
				a = longitud6 - articulos[i].consola.length();
			}	
			else
			{
				a=articulos[i].consola.length();
				texto2 = articulos[i].consola;
				archivo << texto2;
				a = longitud6 - a;	
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}
					archivo << " ";

            //precio uni
			numeroString = to_string(articulos[i].precio_uni);
			if(numeroString.length()<=15)
			{
				texto = articulos[i].precio_uni;
				archivo << texto;
				a = 15 - numeroString.length();	
			}
			else
			{
				a = numeroString.length();
				texto = articulos[i].precio_uni;
				archivo << texto;
				a = longitud7 - numeroString.length();	
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}					

			//iva
			std::stringstream ss;
    		ss << articulos[i].iva;
    		std::string numeroString1 = ss.str();
			if(numeroString1.length()<=9)
			{
				texto = articulos[i].iva;
				archivo << texto;
				a = 10 - numeroString1.length();
			}
			else
			{
				a = numeroString1.length();
				texto = articulos[i].iva;
				archivo << texto;
				a = 10 - a;
			}
			for(int i = 0; i < a; i++)
					{
					archivo << " ";
					}
					archivo << "  ";

            texto = articulos[i].total;
			archivo << texto << "\n";
	}
}
archivo.close();
}


	

    



