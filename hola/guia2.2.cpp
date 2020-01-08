#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h> 
 #include<windows.h>
#include <string.h>
#include <time.h>
int cambiarColor( int semaforo )
{
if( semaforo == 1 )
{
semaforo = 0; 
}
else
{
semaforo = 1;
}
return semaforo;
}  
int cambiarColor( int );
void *verde(void*); 
void *naranja(void*); 
void *rojo(void*);
	int verdes;
	int amarrillo;
	int rojos;
void *verde(void *tid)
{
printf( "Introduzca el tiempo del color Verde" );
scanf( "%d", &verdes);
	printf( "Introduzca el tiempo del color Amarillo" ); 
scanf( "%d", &amarrillo);
	printf( "Introduzca el tiempo del color Rojo" ); 
scanf( "%d", &rojos);
system("cls"); 
system("color A0"); 
Sleep(verdes);
}

void *naranja(void *tid)
{
system("cls"); 
system("color E0"); 
Sleep(amarrillo);
}
void *rojo(void *tid)
{
system("cls"); 
system("color 40");
 Sleep(rojos);
}
int main()
{
int i = 1;
pthread_t pthread_rojo, pthread_naranja, pthread_verde;

pthread_create (&pthread_verde, NULL, verde, (void *)i); pthread_join(pthread_verde, NULL);

pthread_create (&pthread_naranja,NULL, naranja, (void *)i); pthread_join(pthread_naranja, NULL);

pthread_create (&pthread_rojo, NULL, rojo, (void *)i); pthread_join(pthread_rojo, NULL);


int tiempoSimulacion, tiempo;
int semaforo1 = 0, semaforo2 = 1;
bool entraPrimerVez = true; 
time_t comienzo, actual;
printf( "Introduzca el tiempo en segundos en el que se va a realizar la simulacion" );
scanf( "%d", &tiempoSimulacion );
printf( "Introduzca el tiempo en segundos del cambio del color de los semaforos" ); 
scanf( "%d", &tiempo );
comienzo = time( NULL ); 
do
{
actual = time( NULL );
if( int( difftime(actual, comienzo) ) % tiempo == 0 && entraPrimerVez )
{
entraPrimerVez = false;
semaforo1 = cambiarColor( semaforo1 ); 
semaforo2 = cambiarColor( semaforo2 );
if( semaforo1 == 1 )
{
 printf( "El semaforo 1 esta en Verde y el semaforo 2 en Rojo" );
}
else
{
printf( "El semaforo 1 esta en Rojo y el semaforo 2 en Verde" );
}
}
 
if( int( difftime(actual, comienzo) ) % tiempo > 0 )
{
entraPrimerVez = true;
}
}
while( int( difftime(actual, comienzo) ) < tiempoSimulacion );
return 0;
}






