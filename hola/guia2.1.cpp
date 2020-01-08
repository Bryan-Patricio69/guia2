#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h> //crear funciones
#include <unistd.h> // libreria para sleep 
#include<windows.h>
#include <string.h>
void *verde(void*); void *naranja(void*); void *rojo(void*);

void *verde(void *tid)
{
system("cls"); //cls o clear es para limpiar la pantalla de comandos system("color 20");
Sleep(3000);

}

void *naranja(void *tid)
{
system("cls"); system("color E0"); Sleep(3000);
}
void *rojo(void *tid)
{
system("cls"); system("color 40"); Sleep(3000);
}
int main()
{
int i = 1;
pthread_t pthread_rojo, pthread_naranja, pthread_verde;

pthread_create (&pthread_verde, NULL, verde, (void *)i); pthread_join(pthread_verde, NULL);

pthread_create (&pthread_naranja,NULL, naranja, (void *)i); pthread_join(pthread_naranja, NULL);

pthread_create (&pthread_rojo, NULL, rojo, (void *)i); pthread_join(pthread_rojo, NULL);

pthread_exit(NULL);

return 0;
}


