#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO 10
#define LETRA 20

typedef struct nodol {
        int val;
        struct nodol *sig;
    } Nodol;

    typedef Nodol * Lista;

    Lista newList(){
        return NULL;
    }

    void inserta(int x, Lista *L){
        Nodol *p = malloc(sizeof(Nodol));
        p->val = x;
        p->sig = *L;
        *L = p;
    }

    int EsVacia(Lista L){
        return L==NULL;
    }

    int firstInList(Lista L){
        return L->val;
    }

    int estaEn(int x, Lista L){
        Nodol *p = L;
        while(p != NULL && p->val != x) p = p->sig;
        return p != NULL;
    }

    void writeList(Lista L, char name[]){
        printf("\n%s = [",name);
        if (L == NULL) printf("].");
        else {
            while (L->sig != NULL) {
                printf("%d, ", L->val);
                L = L->sig;
            }
            printf("%d].",L->val);
        }
    }

typedef struct nodop {
        int val;
        struct nodo* sig;
    } Nodop;

    typedef Nodop * Pila;

    Pila newPila(){
        return NULL;
    }

    int IsEmpty(Pila p){
        return p == NULL;
    }

    int top(Pila p){
        return p->val;
    }

    void push(int x, Pila *p){
        Nodop *r = malloc(sizeof(Nodop));
        r->val = x;
        r->sig = *p;
        *p = r;
    }

    void pop(Pila *p){
        Nodop *q = *p;
        *p = (*p)->sig;
        free(q);
    }

typedef enum{
            Ninguno,
            Electrificado,
            Quemado,
            Congelado,
            Salud,
        }efecto;

struct Personaje{
        char Nombre[16];
        int PtSalud;
        int PtEnergia;
        Pila Inventario;
        Lista Habilidades;
        int Dano;
        int Rango;
        int Armadura;
        int Evasion;
        int Velocidad;
        int PtAccion;
        int Jugador;
          efecto Efecto;
        }Personaje[5];

        struct Personaje *PE;

struct Habilidad{
        char                    Nombre[16];
        int                     CostoEnergia;
        int                     CostoAccion;
        int                     Rango;
        /*void(*efecto)(Terreno*) efecto;*/
    }Habilidad;



struct Item{
        char                    Nombre[16];
        int                     Costo;
        int                     Rango;
//        void(*efecto)(Terreno*) efecto;
    }Item;



 struct Terreno{
        struct Personaje *PE , Personaje;
       // efecto Efecto;
        Lista     Item;
}Terreno;

struct Terreno *TE;

void IniciarJuego(struct Personaje *PE)
{
    strcpy(Personaje[1].Nombre, "A");
    strcpy(Personaje[2].Nombre, "B");
    strcpy(Personaje[3].Nombre, "C");
    strcpy(Personaje[4].Nombre, "D");

    Personaje[1].PtSalud = 100;
    Personaje[2].PtSalud = 100;
    Personaje[3].PtSalud = 100;
    Personaje[4].PtSalud = 100;

    Personaje[1].PtEnergia = 50;
    Personaje[2].PtEnergia = 25;
    Personaje[3].PtEnergia = 50;
    Personaje[4].PtEnergia = 25;

    Personaje[1].Dano = 30;
    Personaje[2].Dano = 15;
    Personaje[3].Dano = 30;
    Personaje[4].Dano = 15;

    Personaje[1].Rango = 5;
    Personaje[2].Rango = 3;
    Personaje[3].Rango = 5;
    Personaje[4].Rango = 3;

    Personaje[1].Armadura = 10;
    Personaje[2].Armadura = 5;
    Personaje[3].Armadura = 10;
    Personaje[4].Armadura = 5;

    Personaje[1].Evasion = 6;
    Personaje[2].Evasion = 3;
    Personaje[3].Evasion = 6;
    Personaje[4].Evasion = 3;

    Personaje[1].Velocidad = 4;
    Personaje[2].Velocidad = 2;
    Personaje[3].Velocidad = 3;
    Personaje[4].Velocidad = 1;

    Personaje[1].PtAccion = 0;
    Personaje[2].PtAccion = 0;
    Personaje[3].PtAccion = 0;
    Personaje[4].PtAccion = 0;

}

void UbicacionInicial(){
     int i, j;
     char A = 65;
     char B = 66;
     char C = 67;
     char D = 68;
     char ch =176;
     char ef = 178;

     printf("   A B C D E F G H I J K L M N O P Q R S T");
     printf("\n");  /*nueva linea*/
     printf("|------------------------------------------|");
     printf("\n");

     for(i = 0; i <= NUMERO-1; i++)
     {
           printf("| %d", i);
           for(j = 0; j <= LETRA - 1; j++){
            if((i==0 && j ==0) || (i==3 && j==0) || (i==0 && j==4) || (i==3 && j==4) || (i==1 && j==4)){
               if(i==0 && j==0) printf("%c ",A);
               if(i==3 && j==0) printf("%c ",B);
               if(i==0 && j==4) printf("%c ",C);
               if(i==3 && j==4) printf("%c ",D);
               if(i==1 && j==4) printf("%c ",ef);


            }
               else
                    printf("%c ",ch);
           }
          printf("\n");
  /*   printf("|------------------------------------------|");
           printf("\n");*/
     }
}
void moverse(struct Personaje *PE, int s, int t){
    printf("ALO");

    if(s==3 && t == 4){
        srand(time(0));
        int a_alea = rand()%4;
        printf("Entraste a la zona de efecto \n");
        entraefecto(&PE,a_alea);

    }
}
void Moverse(struct Personaje *PE){
    //struct Terreno a;
   // a.Efecto;
   // a.PE;


    int i, j,x,y;
    int VerifLetra;
    int Z, Bandera1, Bandera2;
    char W;
    char letras[21] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
    char A = 65;
    char B = 66;
    char C = 67;
    char D = 68;
    char ch =176;
    char ef = 178;
   if(Personaje[1].PtAccion > 1){
    printf("Se reduciran sus puntos de accion, en un punto por cada cuadro de disstancia.\nSus puntos de Accion actuales son: %d\n",Personaje[1].PtAccion);
    printf("Presione un numero para continuar");
    scanf("%d",&x);
  /*   if(Personaje[1].PtAccion>=2){*/
        system("cls");
     /*   printf("Ahora sus puntos de accion son: %d\n",(Personaje[1].PtAccion-1));
        printf("\n");*/
        Personaje[1].PtAccion = Personaje[1].PtAccion - 1;
        UbicacionInicial();
            do{
                printf("\Ingrese coordenadas: (Letra)+Enter+(Numero)\n");
                printf("Ingrese Letra: ");
                W = getche();
                VerifLetra = 0;
                for(j=0; j<21; j++){
                    if(W != letras[j]) VerifLetra = 0;
                    else{ VerifLetra = 1;
                       x=j;
                       j=21;
                    }
                }
                if(VerifLetra != 1){
                    printf("\nEl primer elemento debe ser una letra entre A y T, intente de nuevo:\n");
                    VerifLetra =0;
                }
            }while(VerifLetra == 0);
                do{
                    printf("\nIngrese Numero: ");
                    scanf("%d",&Z);
                    for(i=0; i<10; i++){
                        if(Z != i) VerifLetra = 0;
                        else{ VerifLetra = 1;
                              y = i;
                              i=10;
                        }
                    }
                    if(VerifLetra != 1){
                        printf("\nEl segundo elemento debe ser un numero entre 0 y 9, intente de nuevo:\n");
                        VerifLetra =0;
                    }
                }while(VerifLetra==0);


/*     system("cls");*/
      printf("   A B C D E F G H I J K L M N O P Q R S T");
      printf("\n");
      printf("|------------------------------------------|");
      printf("\n");

     for(i = 0; i < 10; i++){
        printf("| %d", i);
        for(j = 0; j < 20; j++){
            if((i==y && j ==x) || (i==3 && j==0) || (i==0 && j==4) || (i==3 && j==4)){
               if(i==y && j==x) printf("%c ",A);
               if(i==3 && j==0) printf("%c ",B);
               if(i==0 && j==4) printf("%c ",C);
               if(i==3 && j==4) printf("%c ",D);
            }
            else printf("%c ",ch);
           }
           printf("\n");

  /*   printf("|------------------------------------------|");
           printf("\n");*/

     }
     moverse(&PE,3,4);
     printf("Presiona un numero para volver al menu");
    scanf("%d",&x);
    Menu("\nOpciones");
  } printf("Presiona un numero para volver al menu");
    scanf("%d",&x);
    Menu("\nOpciones");
}

 void SumarPuntosDeAcciion(struct Personajes *PE){
        Personaje[1].PtAccion = Personaje[1].PtAccion + 5;
        printf("%d",Personaje[1].PtAccion);
    }; /*SumarPuntosDeAcciion(&PE);*/

void Menu(char name[]){
        system("cls");
        int M;
        printf("Selecciona que deseas realizar:\n");
        printf("%s\n",name);
        printf("1)Mostrar tablero:\n");
        printf("2)Consultar casilla:\n");
        printf("3)Atacar:\n");
        printf("4)Moverse:\n");
        printf("5)Usar habilidad:\n");
        printf("6)Usar item:\n");
        printf("7)Terminar turno:\n");
        printf("8)Inventario:\n");
        printf("9)Menú sistema:\n");
        scanf("%d",&M);
        Operaciones(&PE,M);
    }

void MostrarTurno(struct Personaje *Pe){
    int x;
    printf("\nLe toca al jugador: %s\n",Personaje[1].Nombre);
    printf("Pulse un numero para continuar:\n");
    scanf("%d",&x);
}

void IniciaTurno(){
   SumarPuntosDeAcciion(&PE);
   Menu("\nOpciones");
/*   Operaciones(&PE);*/

}

void Operaciones(struct Personaje *PE, int M){
        int x,i;
        int Temporal, Bandera1, Bandera2;
        char w = getche();
        char letras[21] = {'A','B','C' ,'D' ,'E' ,'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
    switch(M){
        case 1: system("cls");
                UbicacionInicial();
                printf("Presione una numero para volver al menu:\n");
                scanf("%d",&x);
                Menu("\nOpciones");
                break;
        case 2: system("cls");
                consultarcasilla();
                printf("Presione una numero para volver al menu:\n");
                scanf("%d",&x);
                Menu("\nOpciones");
                //NULL;
                break;
        case 3: Atacar(&PE);
                break;
        case 4: Moverse(&PE);
    }
}/* printf("%d",Personaje[1].Dano);*/

void Atacar(struct Personaje *PE){
    int x,i;
    int Bandera1, Bandera2, Temporal;
    char w;
    char letras[21] = {'A','B','C' ,'D' ,'E' ,'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
    printf("Se reduciran dos puntos de accion, tus puntos de accion actuales son: %d\n",Personaje[1].PtAccion);
    printf("Presione un numero para continuar");
    scanf("%d",&x);
    if(Personaje[1].PtAccion>=2){
        system("cls");
        printf("Ahora sus puntos de accion son: %d\n",(Personaje[1].PtAccion-2));
        printf("\n");
        Personaje[1].PtAccion = Personaje[1].PtAccion - 2;
        UbicacionInicial();
        do{
            printf("\nSeleccione la casilla que desee atacar\n");
            printf("Seleccione una letra: \n");
            w = getch();
            for(i=0; i<21; i++){
                if(w != letras[i]) Bandera2 = 0;
                else{
                    Bandera2 = 1;
                    Temporal = i;
                }
            }
            printf("Seleccione un numero: ");
            scanf("%d",&x);
            if((x < 0 || x > 9)) Bandera1 = 0;
            else Bandera1 =1;
        }while((Bandera1!=1) && (Bandera2 !=1));

        printf("Presiona un numero para volver al menu");
        scanf("%d",&x);
        Menu("\nOpciones");
    }else {
        printf("\nNo tienes suficientes puntos de accion para atacar");
        printf("Presiona una tecla para volver al menu");
        scanf("%d",&x);
        Menu("\nOpciones");
    }
}

void consultarcasilla(struct Personaje *PE){
        int i, j,x,y;
        int VerifLetra;
        int Z, Bandera1, Bandera2;
        char W;
        char letras[21] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
        char A = 65;
        char B = 66;
        char C = 67;
        char D = 68;
        char ch =176;
        char ef = 178;
    if(Personaje[1].PtAccion > 1){
        printf("Se reduciran un punto de accion.\nSus puntos de Accion actuales son: %d\n",Personaje[1].PtAccion);
        printf("Presione un numero para continuar");
        scanf("%d",&x);

        system("cls");

        Personaje[1].PtAccion = Personaje[1].PtAccion - 1;
        UbicacionInicial();
            do{
                printf("\Ingrese coordenadas: (Letra)+Enter+(Numero)\n");
                printf("Ingrese Letra: ");
                W = getche();
                VerifLetra = 0;
                for(j=0; j<21; j++){
                    if(W != letras[j]) VerifLetra = 0;
                    else{ VerifLetra = 1;
                       x=j;
                       j=21;
                    }
                }
                if(VerifLetra != 1){
                    printf("\nEl primer elemento debe ser una letra entre A y T, intente de nuevo:\n");
                    VerifLetra =0;
                }
            }while(VerifLetra == 0);
                do{
                    printf("\nIngrese Numero: ");
                    scanf("%d",&Z);
                    for(i=0; i<10; i++){
                        if(Z != i) VerifLetra = 0;
                        else{ VerifLetra = 1;
                              y = i;
                              i=10;
                        }
                    }
                    if(VerifLetra != 1){
                        printf("\nEl segundo elemento debe ser un numero entre 0 y 9, intente de nuevo:\n");
                        VerifLetra =0;
                    }
                }while(VerifLetra==0);


        if((i==1 && j ==0) || (i==3 && j==3) || (i==1 && j==4) || (i==4 && j==5)){
            printf("\tHay cualquier efecto\n");
        }
        else

        printf("Presiona un numero para volver al menu");
        scanf("%d",&x);
        Menu("\nOpciones");
    }
    printf("Presiona un numero para volver al menu");
    scanf("%d",&x);
    Menu("\nOpciones");
}

void entraefecto(struct personaje*PE, int i){
    struct Personaje t;
    int num_a,x;
    if(i==0){
            t.Efecto;
            printf("Ningun efecto");
            printf("Presiona un numero para volver al menu");
            scanf("%d",&x);
            Menu("\nOpciones");}
    if(i==1){
            t.Efecto;
            srand(time(0));
            num_a= (rand()%100);
            if(num_a<=25){
                printf("%d Electrificado\n",num_a);

                }
            else {
                printf("%d Que suerte, quedaste ileso\n",num_a);}


            printf("Presiona un numero para volver al menu");
            scanf("%d",&x);
            Menu("\nOpciones");
            }
    if(i==2){
            t.Efecto;
            srand(time(0));
            num_a= (rand()%100);
            if(num_a<=40){
                printf("%d Quemado\n",num_a);}
            else {
                printf("%d Que suerte, quedaste ileso\n",num_a);
            }
            printf("Presiona un numero para volver al menu");
            scanf("%d",&x);
            Menu("\nOpciones");
            }
    if(i==3){
            t.Efecto;
                printf("%d Congelado\n",num_a);}

    if(i==4){
            t.Efecto;
            srand(time(0));
            num_a= (rand()%100);
            if(num_a<=80){
            printf("%d SALUD\n",num_a);


}
    }}

void listaa(struct Terreno *TE){
    struct Terreno t;
    t.Item =newList();
    inserta(3,&(t.Item));
    writeList(t.Item,"Cuchillo");
    Pila a =newPila();
    if(IsEmpty(a)){
        push(3,&a);
    }

}
/*void PreguntaRango()*/

int main(){
  UbicacionInicial();
/*Moverse(&PE);*/
  IniciarJuego(&PE);
  Lista L = newList();
  inserta(Personaje[4].Velocidad,&L);
  inserta(Personaje[2].Velocidad,&L);
  inserta(Personaje[3].Velocidad,&L);
  inserta(Personaje[1].Velocidad,&L);
  writeList(L,"Velocidad");
  MostrarTurno(&PE);
  IniciaTurno(&PE);
}

/* printf("%d",Personaje[1].Dano);
void ImprimirTablero(int Tablero[][])
{
     int i, j;
     char ch =176;
     printf("  A B C D E F G H I J K L M N O P Q R S T");
     printf("\n");  /*nueva linea

     for(i = 0; i <= LETRA - 1; i++) printf("--");
     printf("\n");

     for(i = 0; i <= NUMERO-1; i++)
     {
           printf("| %d", i);
           for(j = 0; j <= LETRA - 1; j++){
               printf("%c ",ch);
           }
           printf("|";
           printf("\n");
     }
}
*/
