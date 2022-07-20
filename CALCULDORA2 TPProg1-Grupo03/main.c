#include <stdio.h>
#include <stdlib.h>
#include <math.h> // para la potencia, raiz y funciones trigonometricas;

/*Errores críticos:

-El programa me obliga a realizar una y otra vez la misma operación, no me deja cambiar y
utilizar mi resultado para otra operación. (SOLUCIONADO).
La calculadora no cuenta con un historial. (SOLUCIONADO
 */



//INTEGRANTES: PORTILLO DAIRA, SANTIAGO ERNST, ANTONELLA PERALTA.

typedef struct{
double num1;
double num2;
double resultado;
char signoo; //para imprimir el signo de la operación en el historial.
}s_operaciones;


void separador () {printf ("\n--------------------------------\n\n");} /* (ESTÉTICA) para
separar cuando se vuelve a hacer otra operacion y que quede más prolijo */


int main() {

    s_operaciones operaciones [100];//a la estructura la convertimos en un vector que servirá para el historial.
    int cant_cargada = 0; //variable para el historial.
    double y; // para funciones trigonometricas.

    int primera_vez = 1; //  (while) sirve para volver al principio del programa si reinicio.
    int opcion = 1; // (while) inicialzamos opcion en 1, porque sino cuenta como 0 y el ciclo no inicia.

    double resultado; //variables que se usarán para poder realizar cualquier operación con el valor anterior.
    double tengoAnterior = 0;

  while(opcion !=0 ){

        if(tengoAnterior != 0){ //esto sirve para usar el resultado anterior.
            printf("Resultado anterior: %.2lf\n", resultado); //si no es igual a 0 entonces mostrará este mensaje
            separador();
       }else{ // sino, mostrará este
        printf("Nota: usted no tiene resultado anterior guardado.\n\n"); } //llave del else

           printf ("Selecione la opcion que desee realizar:\n\n");
           printf(" 1) Sumar.\n 2) Restar.\n 3) Multiplicar.\n 4) Dividir.\n 5) Potencia.\n 6) Raiz cuadrada\n");
           printf (" 7) Seno.\n 8) Coseno.\n 9) Tangente.\n 10) Historial.\n-1) Reiniciar\n 0) Salir.\n\n");
           printf ("Opcion: ");
           scanf ("%d",&opcion);
            //system("cls"); // para que borre el menú y no se acumule muchas cosas.

        if(tengoAnterior != 0){ //
                operaciones[cant_cargada].num1 = resultado;
        }else {
            printf ("Ingrese el primer numero: "); //servirá para ingresar el primer numero en todas las operaciones.
            scanf ("%lf",&operaciones[cant_cargada].num1);
        }//llave del else

      switch (opcion) { //comienza el switch
    case -1:
            primera_vez = 1;
             system("cls"); //borrará todo lo escrito anteriormente.
            break;

    case 0:
          printf("Fin del programa.\n");
          break;

    case 1:
           printf ("Ingrese el segundo: "); //como ya pedimos al principio del switch el primer numero ahora pedimos el 2do
           scanf("%lf",&operaciones[cant_cargada].num2);
           resultado = operaciones[cant_cargada].num1 + operaciones[cant_cargada].num2; /*le decimos a la variable resultado
           "guardame el valor que da la suma" */
           operaciones[cant_cargada].resultado = resultado; /*lo que hay en variable resultado va a guardarse también en la
           variable que está dentro de la estructura.*/
           printf ("%.2lf + %.2lf = %.2lf\n", operaciones[cant_cargada].num1,
                   operaciones[cant_cargada].num2, operaciones[cant_cargada].resultado);

           operaciones[cant_cargada].signoo = '+'; //para que el signo se imprima en el historial
           cant_cargada++; //Ira cargando en los vectores los numeros que se ingresaron y se imprimiran en el historial
           separador();
           break; // del case 1

    case 2:

           printf ("Ingrese el segundo numero: "); //copiamos y pegamos, cambiando lo signos.
           scanf("%lf",&operaciones[cant_cargada].num2);
           resultado = operaciones[cant_cargada].num1 - operaciones[cant_cargada].num2;
           operaciones[cant_cargada].resultado = resultado;
           printf ("%.2lf - %.2lf = %.2lf\n", operaciones[cant_cargada].num1,
                   operaciones[cant_cargada].num2, operaciones[cant_cargada].resultado);

           operaciones[cant_cargada].signoo = '-';
           cant_cargada++;
            separador();
            break;


    case 3:
           printf ("Ingrese el segundo numero: ");
           scanf("%lf",&operaciones[cant_cargada].num2);
           resultado = operaciones[cant_cargada].num1 * operaciones[cant_cargada].num2;
           operaciones[cant_cargada].resultado = resultado;
           printf ("%.2lf * %.2lf = %.2lf\n", operaciones[cant_cargada].num1,
                   operaciones[cant_cargada].num2,operaciones[cant_cargada].resultado);

        operaciones[cant_cargada].signoo = '*';
        cant_cargada++;
            separador();

           break; //del case 3

    case 4:
           printf ("Ingrese el segundo numero: ");
           scanf("%lf",& operaciones[cant_cargada].num2);

      resultado =  operaciones[cant_cargada].num1 /  operaciones[cant_cargada].num2;
      operaciones[cant_cargada].resultado = resultado;
        printf ("%.2lf / %.2lf = %.2lf\n",  operaciones[cant_cargada].num1,  operaciones[cant_cargada].num2,
                operaciones[cant_cargada].resultado);

        operaciones[cant_cargada].signoo = '/';
        cant_cargada++;
            separador();
           break; // del case


    case 5: // se usa las mismas variables que en la estructura para la potencia
           printf ("Ingrese el exponente: ");
           scanf ("%lf",&operaciones[cant_cargada].num2); //el num1 ra la BASE, el num2 = exponente.
           resultado = pow (operaciones[cant_cargada].num1,operaciones[cant_cargada].num2);
           operaciones[cant_cargada].resultado = resultado;
           printf ("%.0lf ^ %.0lf = %.0lf\n",operaciones[cant_cargada].num1, operaciones[cant_cargada].num2,
                   operaciones[cant_cargada].resultado);
           operaciones[cant_cargada].signoo = '^';
           cant_cargada++;
            separador();
           break;

    case 6: //raiz cuadrada
        printf("La raiz cuadrada de %.2lf es: %.2lf\n", operaciones[cant_cargada].num1, sqrt(operaciones[cant_cargada].num1));
        operaciones[cant_cargada].signoo = 'R';
        cant_cargada++;
        separador();
    	break;


    case 7: //seno
           y =(operaciones[cant_cargada].num1*3.14)/180;
           resultado = sin(y);
           operaciones[cant_cargada].resultado = resultado;
           printf("El valor del seno del angulo de %.2lf grados es: %.2lf\n",operaciones[cant_cargada].num1,
                  operaciones[cant_cargada].resultado);
                  operaciones[cant_cargada].signoo = 'S';
                  cant_cargada++;
            separador();
            break;


    case 8: //coseno
           y=(operaciones[cant_cargada].num1*3.14)/180;
           resultado =cos(y);
           operaciones[cant_cargada].resultado = resultado;
          printf("El valor del coseno del angulo de %.0lf grados es: %.2lf\n",operaciones[cant_cargada].num1,
                 operaciones[cant_cargada].resultado);
                 operaciones[cant_cargada].signoo = 'C';
                 cant_cargada++;
           separador();
            break; // del case 8

    case 9://tangente
           y=(operaciones[cant_cargada].num1*3.14)/180;
            resultado = tan(y);
            operaciones[cant_cargada].resultado = resultado;
           printf("El valor de la tangente del angulo de %.0lf grados es: %.2lf\n",operaciones[cant_cargada].num1,
                  operaciones[cant_cargada].resultado);
                  operaciones[cant_cargada].signoo = 'T';
                  cant_cargada++;
           separador();
           break; //del case 9

    case 10:
        separador();
        printf("Simbolos:\nRaiz cuadrada = R.\nTangente = T.\nSen = S.\nCos = C.\n\n");
        printf ("\nHistorial:\n");
        for (int i = cant_cargada - 1; i >= 0; i--){
        printf("%.2lf %c %.2lf = %.2lf\n", operaciones[i].num1,
               operaciones[i].signoo, operaciones[i].num2,
               operaciones[i].resultado);
               }
         separador();
         break;


        default:
        printf ("La opcion elegida no corresponde a ninguna operacion.\n");

} // llave de switch.

    printf("(Nota: si quiere ver el historial, debera presionar '1' y luego la\nopcion '10',");//mensaje al usuario para orientarlo
     printf(" caso contrario se borraran todos sus registros).\n\n");
     printf("Desea seguir operando con el valor anterior? (1-Si. 0-No.):\n");
     printf("Opcion: ");
     scanf("%lf",&tengoAnterior);/* una vez que sale del switch el resultado ya habrá estado guardado
     entonces le preguntaremos al usuario si quiere usar ese resultado o si quiere empezar de nuevo.*/
     system("cls"); //para borrar lo que está en pantalla.
   /*La pregunta de seguir usando el valor anterior está dentro el ciclo while*/

} // llave del while.

 return 0;
}
