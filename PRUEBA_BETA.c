#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

///_________________LISTAS___________________

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


///_______________FIN LISTAS___________________

///_______________PILAS____________________

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

///__________________FIN PILAS_________________

///_______________PILAS(Version simple)____________________

typedef struct pila{
        int top;
        int a[200];
        }PilaArr;
        
        typedef PilaArr * Pila;

        Pila newPila(){
           Pila p=malloc(sizeof(PilaArr));
           p->top=0;
           return p;
        }

        int esVacia(Pila p){
          return p->top==0;
        }

        int esFull(Pila p){
          return p->top==200;
        }

        int top(Pila p){
          return p->a[p->top-1];
        }

        void push(int x, Pila p){
            p->a[p->top]=x;
            p->top=p->top+1;
        }

        void pop(Pila p){
           p->top=p->top-1;
        }

///_______________FIN PILAS(Version simple)____________________
               
///___________________PERSONAJE, HABILIDADES, ITEMS, TERRENO_____________________

struct Personaje{
        char Nombre[16];
        int PtSalud;
        int PtEnergia;
        Pila* Inventario;
        Lista* Habilidades;
        int Dano;
        int Rango;
        int Armadura;
        int Evasion;
        int Velocidad;
        int PtAccion;
        int Jugador;
        }Personaje[5];

        struct Personaje *PE;

struct Habilidad{
        char Nombre[16];
        int CostoEnergia;
        int CostoAccion;
        int Rango;
        void (*efecto)(Terreno*) efecto;
    }Habilidad;
        
        struct Habilidad *Hab;

struct Item{
        char Nombre[16];
        int Costo;
        int Rango;
        void(*efecto)(Terreno*) efecto;
    }Item;

        struct Item *items;

 struct Terreno{
        struct Personaje *PT , Personaje;
        int Efecto[10][20];
        Lista Item;
     }Terreno;

///___________________FIN PERSONAJE, HABILIDADES, ITEMS, TERRENO_____________________

///___________Inicialización de variables_____________

int *PosVA;
int *PosHA;
int *PosVB;
int *PosHB;
int *PosVC;
int *PosHC;
int *PosVD;
int *PosHD;
int *inicioh;
int *iniciov;
int *PosHI;
int *PosVI;

///_________________INICIALIZACIÓN PERSONAJES__________________

void IniciarJuego(struct Personajes *PE){
        
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

void funcion(Lista *p,struct Item*items){

    inserta (Item.Costo,*p);
    inserta(Item.Rango,*p);
    writeList(p,"PRUEBA");
}

///_________________Prueba de consultar casilla__________________


/**
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
        /*void(*efecto)(Terreno*) efecto;
    }Habilidad;

    struct Habilidad*Hab;

struct Item{
        char                    Nombre[16];
        int                     Costo;
        int                     Rango;
     /*   void(*efecto)(Terreno*) efecto;
    }Item;

struct Item*items;


 struct terreno{
        struct  Personaje *PE;
       // int         Efecto[10][20];
       // struct Item *items;
        Lista      * Item;
        struct Habilidad *Hab;
        efecto Efecto;
        int indice;
}T;
struct T *TE;*/
/**
void consultar(struct T *TE, int x){ ///int x
    struct T *aa= (struct terreno*)malloc(sizeof(struct terreno));
    struct terreno personitA;
    int aci,acj,bci,bcj; int aux;
     char a = 'A', b='B', c = 'C', d = 'D';

     strcpy(T.PE[1].Nombre[1],PE[1].Nombre[1]);
     strcpy(T.PE[2].Nombre[1],PE[2].Nombre[1]);
     strcpy(T.PE[3].Nombre[1],PE[3].Nombre[1]);
     strcpy(T.PE[4].Nombre[1],PE[4].Nombre[1]);
     for(aci = 0; aci <= 9; aci++)
     {

           for( acj= 0; acj <= 19; acj++){
            if((aci==*PosHA && acj ==*PosVA) || (aci==*PosHB && acj==*PosVB) || (aci==*PosHC && acj==*PosVC) || (aci==*PosHD && acj==*PosVD)){
               if(aci==*PosHA && acj==*PosVA) int aux1 =true; printf("%c ",A);
               if(aci==*PosHB && acj==*PosVB) int aux2 = true; printf("%c ",B);
               if(aci==*PosHC && acj==*PosVC) int aux3 =true; printf("%c ",C);
               if(aci==*PosHD && acj==*PosVD) int aux4 =true; printf("%c ",D);
               if(aci == *Positemx && acj == *Positemy) int aux5 =true;  printf("* items");
               if(aci==posiefectox && acj posiefctoyy) int aux6= true; printf("%c efecto",178);

            }
            else printf("no hay nada");
           }

	}
        if(aux1 || aux2|| aux3 ||aux4){
            imprimirdatosen_pantalla();
        }

}*/
/**
void dejaritemsuelo(struct Personaje *Pe, struct T*TE, char *x){
    char a = 'A', b='B', c = 'C', d = 'D';
    struct T *aa= (struct terreno*)malloc(sizeof(struct terreno));

     if((x=a)){
         printf("Item dejado por A en el suelo es: ");
         dejaitemsuelo(&aa,&PE);
        }
    if((x=b)){
         printf("Item dejado por B en el suelo es: ");
         dejaitemsuelo(&aa,&PE);

     }
	 
	 if((x=c)){
         printf("Item dejado por B en el suelo es: ");
         dejaitemsuelo(&aa,&PE);

     }
	 
	 if((x=d)){
         printf("Item dejado por B en el suelo es: ");
         dejaitemsuelo(&aa,&PE);

     }
}
________________Dejar item en el suelo____________________
  void dejaitemsuelo(struct T*TE, struct Personaje*PE){
      struct T *a = TE; ///de prueba porque aja
      ///con apuntador
      struct Personaje *perolitoX;
      (*perolitoA).Inventario;

      struct terreno *ab;
      (*ab).Item;
	  while(!IsEmpty(*perolitoX).Inventario)){
		if((!IsEmpty(*perolitoX).Inventario)){  ///No correra porque falta crear pila structura
        if((*ab).Item == NULL){

                popstructura((top(*perolitoX).Inventario));
                insertaaa((top(*perolitoX).Inventario), &((*ab).Item));



		}else
		printf("Ya no puedes dejar nada\n");}

		///sin apuntador. 

		struct terreno LISTA;
		LISTA.Item;

		Lista personA = newList();

		LISTA.Item = newList();

		}
	}

 insertaaa(struct Item i, struct *TE t ){
    Nodola *p= malloc(sizeof(Nodola));


 }
*/







///_________________UBICACIÓN INICIAL__________________

void UbicacionInicial(int *PosHA,int *PosVA,int *PosHB,int *PosVB,int *PosHC,int *PosVC, int *PosHD,int *PosVD){
     int i, j;
     char A = 65;
     char B = 66;
     char C = 67;
     char D = 68;
     char ch =176;
     char it = 178;
     printf("   A B C D E F G H I J K L M N O P Q R S T");
     printf("\n");  /*nueva linea*/
     printf("|------------------------------------------|");
     printf("\n");

     for(i = 0; i <= 9; i++)
     {
           printf("| %d", i);
           for(j = 0; j <= 19; j++){
            if((i==*PosHA && j ==*PosVA) || (i==*PosHB && j==*PosVB) || (i==*PosHC && j==*PosVC) || (i==*PosHD && j==*PosVD)){
               if(i==*PosHA && j==*PosVA) printf("%c ",A);
               if(i==*PosHB && j==*PosVB) printf("%c ",B);
               if(i==*PosHC && j==*PosVC) printf("%c ",C);
               if(i==*PosHD && j==*PosVD) printf("%c ",D);
            }
            else printf("%c ",ch);
           }
          printf("\n");
  /*   printf("|------------------------------------------|");
           printf("\n");*/
     }
     return;
}

///_____________________MOVIMIENTO________________________

void Moverse(struct Personaje *PE, int *PosHA,int *PosVA,int *PosHB,int *PosVB,int *PosHC,int *PosVC, int *PosHD,int *PosVD){
    int i, j,x,y;
    int VerifLetra;
    int Z, Bandera1, Bandera2;
    char W;
    int inicioH = *PosHA;
    int inicioV = *PosVA;
    char letras[21] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
    char A = 65;
    char B = 66;
    char C = 67;
    char D = 68;
    char ch =176;
        printf("Se reduciran sus puntos de accion, en un punto por cada cuadro de distancia.\nSus puntos de Accion actuales son: %d\n",Personaje[1].PtAccion);
        printf("Presione un numero para continuar\n");
        scanf("%d",&x);
        /*system("cls");*/
        printf("\n");
                                        /*Personaje[1].PtAccion = Personaje[1].PtAccion - 1;*/
                                        /*  UbicacionInicial(&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD);*/
        do{
            printf("\nIngrese coordenadas:\n");
            printf("Ingrese Letra: ");
            W = getche();
            VerifLetra = 0;
            for(j=0; j<21; j++){
                if(W != letras[j]) VerifLetra = 0;
                else{ VerifLetra = 1;
                    *PosVA=j;
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
                              *PosHA = i;
                              i=10;
                        }
                    }
                    if(VerifLetra != 1){
                        printf("\nEl segundo elemento debe ser un numero entre 0 y 9, intente de nuevo:\n");
                        VerifLetra =0;
                    }
                }while(VerifLetra==0);
        
    if(Personaje[1].PtAccion > DeterminaMovimieinto(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD,inicioH,inicioV)){                                              /*     system("cls");*/
      printf("   A B C D E F G H I J K L M N O P Q R S T");
      printf("\n");
      printf("|------------------------------------------|");
      printf("\n");
      for(i = 0; i < 10; i++){
        printf("| %d", i);
        for(j = 0; j < 20; j++){
            if((i==*PosHA && j ==*PosVA) || (i==*PosHB && j==*PosVB) || (i==*PosHC && j==*PosVC) || (i==*PosHD && j==*PosVD)){
               if(i==*PosHA && j==*PosVA) printf("%c ",A);
               if(i==*PosHB && j==*PosVB) printf("%c ",B);
               if(i==*PosHC && j==*PosVC) printf("%c ",C);
               if(i==*PosHD && j==*PosVD) printf("%c ",D);
            }
                                    /* if((i==y && j ==x) || (i==3 && j==0) || (i==0 && j==4) || (i==3 && j==4)){
                                       if(i==y && j==x) printf("%c ",A);
                                       if(i==3 && j==0) printf("%c ",B);
                                       if(i==0 && j==4) printf("%c ",C);
                                       if(i==3 && j==4) printf("%c ",D);   ESTA ES LA ORIGINAL}*/
            else printf("%c ",ch);
        }
        printf("\n");
  /*   printf("|------------------------------------------|");
           printf("\n");*/
      }
    int SustiHA;
    int SustiVA;
    SustiHA = *PosHA;
    SustiVA = *PosVA;
    printf("\nSustiHA = %d",SustiHA);
    printf("\nSustiVA = %d",SustiVA);

        Personaje[1].PtAccion = Personaje[1].PtAccion - DeterminaMovimieinto(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD,inicioH,inicioV);
        printf("\nSe mueve: %d",DeterminaMovimieinto(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD,inicioH,inicioV));
        printf("\nPuntos de accion restantes: %d",Personaje[1].PtAccion);
        printf("\nPresiona un numero para volver al menu");
        scanf("%d",&x);
        Menu("\nOpciones");
     return;
    }else{
        printf("\nNo tienes suficientes puntos de accion para realizar un movimiento\n");
        printf("\nPresiona un numero para volver al menu");
        scanf("%d",&x);
        Menu("\nOpciones");
        return;
    }
}

///_________DETERMINA MOVIMIENTO_________________

int DeterminaMovimieinto(struct Personaje *PE, int **PosHA,int **PosVA,int *PosHB,int *PosVB,int *PosHC,int *PosVC,
                int *PosHD,int *PosVD,int inicioH, int inicioV){
                       int FinalH = **PosHA;
                       int FinalV = **PosVA;
                       int primeroh = inicioH;
                       int primerov = inicioV;
                       int Distancia; /*Distancia del jugador al enemigo*/
                       Distancia = (abs(FinalH-primeroh) + abs(FinalV-primerov));
                       return Distancia;
}

///_______________SUMAR PUNTOS ACCION________________

 void SumarPuntosDeAcciion(struct Personajes *PE){
        Personaje[1].PtAccion = Personaje[1].PtAccion + 5;
        printf("%d",Personaje[1].PtAccion);
    }; /*SumarPuntosDeAcciion(&PE);*/

///________________FUNCIONES HABILIDADES_________________

void restaurar(Terreno *t){
        t->efecto=RESTAURADO;
}

void incendiar(Terreno *t){
        t->efecto=INCENDIADO;
}

void congelar(Terreno *t){
        t->efecto=CONGELADO;
}

void electrocutar(Terreno *t){
        t->efecto=ELECTROCUTADO;
}

///_______________USO HABILIDAD________________

void UsoHabilidad(struct Habilidad *Hab,struct Personaje *PE,char name[],int *PosHA,int *PosVA,int *PosHB,int *PosVB,int *PosHC,int *PosVC, int *PosHD,int *PosVD){
        int i,j,x,y,M;
        int VerifLetra;
        char letras[21] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
        char W;
        int inicioH = *PosHA;
        int inicioV = *PosVA;
        char A = 65;
        char B = 66;
        char C = 67;
        char D = 68;
        char ch =176;
        printf("¿Desea usar alguna habilidad?\n");
        printf("Selecciona la accion que quieres realizar:\n");
        printf("%s\n",name);
        printf("1)Restaurar\n");
        printf("2)Incendiar\n");
        printf("3)Congelar\n");
        printf("4)Electrocutar\n");
        scanf("%d",&M);
        
        printf("Se reduciran sus puntos de accion, en un punto por cada cuadro de distancia.\nSus puntos de Accion actuales son: %d\n",Personaje[1].PtAccion);
        printf("Presione un numero para continuar\n");
        scanf("%d",&x);
        printf("\n");
        

///__________________MENU____________________

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
        printf("10)Guardar partida:\n");
        scanf("%d",&M);
        Operaciones(&PE,M);
        return;
    }


///________________TURNO ACTUAL_______________

void MostrarTurno(struct Personaje *Pe){
    int x;
    printf("\nLe toca al jugador: %s\n",Personaje[1].Nombre);
    printf("Pulse un numero para continuar:\n");
    scanf("%d",&x);
    return;
}

///__________________INICIO TURNO___________________

void IniciaTurno(){
   SumarPuntosDeAcciion(&PE);
   Menu("\nOpciones");
   return;
/*   Operaciones(&PE);*/

}

///______________________OPERACIONES___________________

void Operaciones(struct Personaje *PE, int M){
    int x,i;
    int Temporal, Bandera1, Bandera2;
    char w = getche();
    char letras[21] = {'A','B','C' ,'D' ,'E' ,'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
    switch(M){
        case 1: system("cls");
                UbicacionInicial(&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD);
                printf("Presione una numero para volver al menu:\n");
                scanf("%d",&x);
                Menu("\nOpciones");
                break;
        case 2: NULL;
                break;
        case 3: Atacar(&PE);
                break;
        case 4:
                UbicacionInicial(&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD);
                Moverse(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD);
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:          
    }
    return;
}/* printf("%d",Personaje[1].Dano);*/

///_______________________ATACAR__________________________

void Atacar(struct Personaje *PE){
    int x,i;
    int Bandera1, Bandera2, PosEnemigoH,PosEnemigoV;
    char w;
    char letras[21] = {'A','B','C' ,'D' ,'E' ,'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','\0'};
    printf("Se reduciran dos puntos de accion, tus puntos de accion actuales son: %d\n",Personaje[1].PtAccion);
    printf("Presione un numero para continuar");
    scanf("%d",&x);
   /* if(Personaje[1].PtAccion>=2){
        system("cls");
        printf("Ahora sus puntos de accion son: %d\n",(Personaje[1].PtAccion-2));
        printf("\n");
        Personaje[1].PtAccion = Personaje[1].PtAccion - 2;*/
        UbicacionInicial(&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD);
        do{
            printf("\nSeleccione la casilla que desee atacar:\n ");
            printf("\nSeleccione la letra de la casilla:");
            w = getche();
            for(i=0; i<21; i++){
                if(w != letras[i]) Bandera2 = 0;
                else{
                    Bandera2 = 1;
                    PosEnemigoH = i;
                }
            }
            printf("\nSeleccione el numero de la casilla: ");
            scanf("%d",&x);
            if((x < 0 || x > 9)) Bandera1 = 0;
            else Bandera1 =1;
        }while((Bandera1!=1) && (Bandera2 !=1));
        PosEnemigoV = x;

         if(Personaje[1].Rango >= PreguntaRango(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD,PosEnemigoH,PosEnemigoV)){
            if(Personaje[1].PtAccion >= 2){
                    Personaje[1].PtAccion = Personaje[1].PtAccion - 2;
                    Personaje[3].PtSalud = Personaje[3].PtSalud  - Personaje[1].Dano;
                    printf("\nAhora la salud del enemigo 3 es:  %d\n",Personaje[3].PtSalud);
                    printf("La distancia al rango es: %d\n",PreguntaRango(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD,PosEnemigoH,PosEnemigoV));
                    printf("Presiona un numero para volver al menu");
                    scanf("%d",&x);
                    Menu("\nOpciones");
            }else{
                printf("\nLa distancia al rango es: %d\n",PreguntaRango(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD,PosEnemigoH,PosEnemigoV));
                printf("\nNo tienes suficientes puntos de =accion para realizar este ataque\n");
                printf("Presiona un numero para volver al menu");
                scanf("%d",&x);
                Menu("\nOpciones");
            }
        }
        else {
            printf("\nNo tienes suficientes puntos de Rango atacar\n");
            printf("Presiona un numero para volver al menu");
            scanf("%d",&x);
            Menu("\nOpciones");
        }
        return;
    }

///____________________________RANGO____________________

int PreguntaRango(struct Personaje *PE, int *PosHA,int *PosVA,int *PosHB,int *PosVB,int *PosHC,int *PosVC,
                int *PosHD,int *PosVD,int PosEnemigoH, int PosEnemigoV){
                       int DistobjH = PosEnemigoH;
                       int DistobjV = PosEnemigoV;
                       int DistanciaDelOb; /*Distancia del jugador al enemigo*/
                       DistanciaDelOb = (abs(PosEnemigoH-*PosHA) + abs(PosEnemigoV-*PosVA));
                       return DistanciaDelOb;
}

///________________________MAIN____________________________

int main(){
  PosVA = 0;
  PosHA = 0;
  PosVB = 3;
  PosHB = 0;
  PosVC = 0;
  PosHC = 4;
  PosVD = 3;
  PosHD = 4;
 //osHI=
 //osVI=
  UbicacionInicial(&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD); /*Muestra el estado inicial del juego*/
  IniciarJuego(&PE); /*Inicializa todas las variables de los personajes*/
  Lista L = newList();
  inserta(Personaje[4].Velocidad,&L);
  inserta(Personaje[2].Velocidad,&L);
  inserta(Personaje[3].Velocidad,&L);
  inserta(Personaje[1].Velocidad,&L);
  writeList(L,"T");
  MostrarTurno(&PE); /*Inidica de quien es el turno*/
  IniciaTurno(&PE); /*Suma los puntos de accion del personaje*/
  Menu("\nOpciones"); /*Muestra el menu de opciones*/
 /* Moverse(&PE,&PosHA,&PosVA,&PosHB,&PosVB,&PosHC,&PosVC,&PosHD,&PosVD);*/
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
