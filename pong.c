/**
 * @file pong.c
 * @author Samuel Edwin Hoyo Calixto (samshark_13@outlook.com)
 * @brief Video Game based in the popular PONG of the 70's.
 * @version 1.0
 * @date 2022-12-26
 */
#include <stdio.h>
#include<conio.h>
#include<windows.h>
#define WIDTH 100 // Ancho del campo de juego
#define HEIGHT 25 // Alto del campo de juego
#define CENX 7 //Cordenadas para imprimir pong en el eje X
#define CENY 2 //Cordenadas para imprimir pong en el eje Y
#define CMX 27 //Cordenadas para imprimir el mapa en el eje X
#define CMY 13 //Cordenadas para imprimir el mapa en el eje Y
#define CR1X 3 //Cordenadas para imprimir la raqueta 1 en el eje X
#define CR1Y 10 //Cordenadas para imprimir la raqueta 1 en el eje Y
#define CR2X 97 //Cordenadas para imprimir la raqueta 2 en el eje X
#define CR2Y 10 //Cordenadas para imprimir la raqueta 2 en el eje Y
#define CPX 50 //Cordenadas para imprimir la pelota en el eje X
#define CPY 12 //Cordenadas para imprimir la pelota en el eje Y
#define BS 1 //Cordenadas en X para imprimir la linea divisoria en el mapa
char tecla;
void mapaMenu(int x, int y);
void gotoxy(int x,int y);
void ImprimePong(int x,int y);
void Menu(int x,int y);
void MapaJuego(int x, int y);
void imprimeRaqueta(int x, int y);
void imprimePelota(int x, int y);
void loopGame(int a, int b,int c, int d, int e, int f, int ancho, int alto);
void borraRaqueta(int x, int y);
void HideCursor();
void imprimeMedia(int ancho, int alto, int base);
void ImprimePuntuacion(int x, int y, int puntos, int jugador);
int main(){
	    HideCursor();//Oculta el cursor
		mapaMenu(WIDTH, HEIGHT); //Imprime mapa de pong
    	ImprimePong(CENX,CENY); //Imprime la palabra pong en ascii en cordenadas dadas
    	Menu(CMX,CMY);//Imprime parte del menu
    	tecla = getch();//Obtenemos tecla
    	system("cls");
    	if (tecla == ' ') {  	
    	  MapaJuego(WIDTH, HEIGHT); 
          loopGame(CR1X, CR1Y, CR2X, CR2Y, CPX,CPY,WIDTH,HEIGHT); 			
    } 
	return 0;
}

//FUNCIONES UTILIZADAS PARA PONG
void mapaMenu(int x, int y){
	int i,j;
// Dibuja las líneas horizontales
    printf(" +");
    for ( i = 1; i <x - 1; i++)
    {
        printf("=");
    }
    printf("+\n");
    // Dibuja las líneas verticales
    for (j = 0; j < y; j++)
    {
        printf(" |");
        for ( i = 1; i < x- 1; i++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    // Dibuja las líneas horizontales
    printf(" +");
    for ( i = 1; i < x-1 ; i++)
    {
        printf("=");
    }
    printf("+");
}

 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 void HideCursor(){
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}
 void ImprimePong(int x,int y){
	gotoxy(x, y);
    printf("            88    \n");
    gotoxy(x, y+1);
    printf("            **    \n");
    gotoxy(x, y+3);
    printf("8b,dPPYba,  88 8b,dPPYba,   ,adPPYb,d8 8b,dPPYba,   ,adPPYba,  8b,dPPYba,    ,adPPYb,d8\n");
    gotoxy(x, y+4);
    printf("88P'    '8a 88 88P'   `'8a a8'    `Y88 88P'    '8a a8*     *8a 88P'   `'8a  a8'    `Y88\n");
    gotoxy(x, y+5);
    printf("88       d8 88 88       88 8b       88 88       d8 8b       d8 88       88  8b       88\n");
    gotoxy(x, y+6);
    printf("88b,   ,a8* 88 88       88 *8a,   ,d88 88b,   ,a8* *8a,   ,a8* 88       88  *8a,   ,d88\n");
    gotoxy(x, y+7);
    printf("88`YbbdP*   88 88       88 `*YbbdP'Y88 88`YbbdP'    `'YbbdP'   88       88  `'YbbdP''Y8\n");
    gotoxy(x, y+8);
    printf("88                          aa,    ,88 88                                    aa,    ,88\n");
    gotoxy(x, y+9);
    printf("88                           *Y8bbdP*  88                                     *Y8bbdP* \n");
 
}
void Menu(int x,int y){
	int i;
	gotoxy(x+13, y);
    printf("[SPACE BAR]");
    gotoxy(x+27, y);
    printf("BEGIN TO PLAY");
    gotoxy(x+13, y+1);
    printf("[Q]");
    gotoxy(x+27, y+1);
    printf("EXIT");
    gotoxy(x, y+3);
    printf("PLAYER 1");
    gotoxy(x, y+4);
    printf("[W]");
    gotoxy(x+6, y+4);
    printf("UP");
    gotoxy(x, y+5);
    printf("[S]");
    gotoxy(x+6, y+5);
    printf("DOWN");
    gotoxy(x+40, y+3);
    printf("PLAYER 2");	
    gotoxy(x+40, y+4);
    printf("[P]");
    gotoxy(x+46, y+4);
    printf("UP");
    gotoxy(x+40, y+5);
    printf("[L]");
    gotoxy(x+46, y+5);
    printf("DOWN");
    gotoxy(x-9, y+8);
    printf("o     .   _______ _______\n");;
    gotoxy(x-10, y+9);
    printf("%c_ 0     /______//______/|   0_o\n",47);
    gotoxy(x-10, y+10);
    printf("  %c%c_   /______//______/    _%c%c\n",47,92,47,92);
    gotoxy(x-10, y+11);
    printf(" | %c    |      ||      |     / |",92);
    gotoxy(x+30, y+11);
    printf("BY SAMUEL EDWIN HOYO CALIXTO 2022.");	
}
void MapaJuego(int x, int y){
  int i, j;
  // Dibuja las líneas horizontales
  printf(" +");
  for (i = 1; i < x - 1; i++) {
    printf("=");
  }
  printf("+\n");
  // Dibuja las líneas verticales
  for (j = 0; j < y; j++) {
    printf(" |");
    for (i = 1; i < x - 1; i++) {
      if (i == x / 2) {
        printf("#"); // Dibuja una línea vertical en el centro del mapa
      } else {
        printf(" ");
      }
    }
    printf("|\n");
  }
  // Dibuja las líneas horizontales
  printf(" +");
  for (i = 1; i < x - 1; i++) {
    printf("=");
  }
  printf("+");
}

void imprimeRaqueta(int x, int y){
        gotoxy(x,y);
    	printf("@@");
    	gotoxy(x,y+1);
    	printf("##");
    	gotoxy(x,y+2);
    	printf("##");
    	gotoxy(x,y+3);
    	printf("##");
    	gotoxy(x,y+4);
    	printf("##");
    	gotoxy(x,y+5);
    	printf("&&");
 }


 void borraRaqueta(int x, int y){
	    gotoxy(x,y);
    	printf("  ");
    	gotoxy(x,y+1);
    	printf("  ");
    	gotoxy(x,y+2);
    	printf("  ");
    	gotoxy(x,y+3);
    	printf("  ");
    	gotoxy(x,y+4);
    	printf("  ");
    	gotoxy(x,y+5);
    	printf("  ");
 }
void imprimePelota(int x, int y){
        gotoxy(x,y);
        printf("d8b");
        gotoxy(x,y+1);
        printf("O89");
}
void imprimeMedia(int ancho, int alto, int base){
int i,j;
	gotoxy(ancho/2+1, base);
    for (i = 1; i <=alto; i++) {
        printf("#"); // Dibuja una línea vertical en el centro del mapa
        gotoxy(ancho/2+1,i+1);
    }
}
void ImprimePuntuacion(int x, int y, int puntos, int jugador){
	gotoxy(x,y);
	printf("PLAYER %d: %d",jugador, puntos);	
}	

void loopGame(int a, int b,int c, int d, int e, int f, int ancho, int alto){
int dx = 1; // Dirección en el eje x
int dy = 1; // Dirección en el eje y
int puntosP1;
int puntosP2;
int margen=1;
int jugador1=1;
int jugador2=2;
char tecla;
tecla=getch;
while(tecla!= 'q'){
     // Borra la pelota en su posición anterior
     ImprimePuntuacion(ancho/2-14, margen, puntosP1, jugador1);
     ImprimePuntuacion(ancho/2+5, margen, puntosP2, jugador2);
     imprimeRaqueta(a,b);
     imprimeRaqueta(c,d);
	 imprimePelota(e, f);
	 imprimeMedia( WIDTH , HEIGHT, BS);
        gotoxy(e,f);
        printf("   ");
        gotoxy(e,f+1);
        printf("   ");
        // Mueve la pelota
        e += dx;
        f += dy;
        // Si la pelota toca un borde, cambia la dirección
        if(e == 2 || e == ancho-3){
            dx *= -1;
            Beep(1600,50);
        }
        if(f == 1 || f == alto-1){
            dy *= -1;
            Beep(1600,50);
        }
        if(e == 2){
            puntosP2++; // Jugador 2 suma un punto 
            Beep(1500,400);
              e = ancho / 2; // Reubica la pelota en el medio del juego
              f = alto / 2;
        }
        if(e == ancho-3){
            puntosP1++; // Jugador 1 suma un punto
            Beep(1500,400);
              e = ancho / 2; // Reubica la pelota en el medio del juego
              f = alto / 2; 
        }
        // Dibuja la pelota en su nueva posición
        imprimePelota(e, f); 
        Sleep(50); 
		// Espera 50 milisegundos para ver la animación
     if (kbhit() == 1){
        borraRaqueta(a,b);
        borraRaqueta(c, d);
        // Lee la entrada del teclado
        tecla = getch();
        if(GetAsyncKeyState('W') & 0x8000||GetAsyncKeyState('w') & 0x8000&&b>0){
              b--; // Mueve la pelota hacia arriba
             if(b==0){
            	b++;
			}
        }
        else if(GetAsyncKeyState('S') & 0x8000||GetAsyncKeyState('s') & 0x8000){
              b++; // Mueve la pelota hacia abajo
            if(b==21){
            	b--;
			}
        }
        imprimeRaqueta(a,b);
        if(GetAsyncKeyState('p') & 0x8000||GetAsyncKeyState('P') & 0x8000){
             d--; // Mueve la pelota hacia arriba
             if(d==0){
            	d++;
			}
        }
        else if(GetAsyncKeyState('L') & 0x8000|| GetAsyncKeyState('l') & 0x8000){
              d++; // Mueve la pelota hacia abajo
            if(d==21){
            	d--;
			}
        }
        imprimeRaqueta(c,d);   
    }
	    if(e == a+3 && f+1>= b && f <= b+6){
            dx *= -1; // Cambia la dirección en el eje x
              Beep(700,100);
        }
        if(e == c-3 && f+1 >= d && f <= d+6){
            dx *= -1; // Cambia la dirección en el eje x
              Beep(700,100);
        }	  
  }
}