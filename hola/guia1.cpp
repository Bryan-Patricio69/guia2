#include <stdio.h>
#include <time.h>
//funcion
int cambiarColor( int );
main(  )
{
int tiempoSimulacion, tiempo;
int semaforo1 = 0, semaforo2 = 1;
bool entraPrimerVez = true;
time_t comienzo, actual;
//Se introduce el tiempo durante el cual se va a ejecutar la simulacion
//Y tambien el tiempo en el que queremos que cambie el color del semaforo
printf( "Introduzca el tiempo en segundos en el que se va a realizar la simulacion:" );
scanf( "%d", &tiempoSimulacion );
printf( "Introduzca el tiempo en segundos del cambio del color de los semaforos:" );
scanf( "%d", &tiempo );
comienzo = time( NULL );
do
{
actual = time( NULL );
//Entra al cuerpo del if cada vez que haya transcurrido el tiempo de cambio ingresado por el usuario
if( int( difftime(actual, comienzo) ) % tiempo == 0 && entraPrimerVez )
{
entraPrimerVez = false;
semaforo1 = cambiarColor( semaforo1 );
semaforo2 = cambiarColor( semaforo2 );
if( semaforo1 == 1 )
{
printf( "El semaforo 1 esta en Verde y el semaforo 2 en Rojo\n" );
}
else
{
printf( "El semaforo 1 esta en Rojo y el semaforo 2 en Verde\n" );
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
int cambiarColor( int semaforo )
{
//Si el valor del semaforo_1 es 1 es porque este semáforo este en verde, lo que indica que este
//Y el semaforo_2 pasaría a verde, de lo contrario se invertiría el color según lo explicado
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
