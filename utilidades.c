#include <stdio.h>
#include <time.h>
#include <string.h>
#include "utilidades.h"
void flush_in() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void eliminarUsuario(Usuarios* usuarios,int* n,int index)
{
  memmove(&usuarios[index], &usuarios[index+1], (*n-index-1)*sizeof(Usuarios));
  (*n)--;
}
void eliminarVehiculos(Vehiculos* vehiculos,int* n,int index)
{
    memmove(&vehiculos[index], &vehiculos[index+1], (*n-index-1)*sizeof(Vehiculos));
    (*n)--;
}
void eliminarViajes(Viajes* viajes,int* n,int index)
{
    memmove(&viajes[index], &viajes[index+1], (*n-index-1)*sizeof(Viajes));
    (*n)--;
}
void eliminarPasos(Pasos* pasos,int* n,int index)
{
    memmove(&pasos[index], &pasos[index+1], (*n-index-1)*sizeof(Pasos));
    (*n)--;
}
void eliminarIncidencias(Incidencias* incidencias,int* n,int index)
{
    memmove(&incidencias[index], &incidencias[index+1], (*n-index-1)*sizeof(Incidencias));
    (*n)--;
}
int buscarUsuarioIndex(Usuarios* usuarios,int n,int id_usuario)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_usuario == usuarios[i].Id_usuario) return i;
  }
  return -1;
}

int buscarVehiculosIndex(Vehiculos* vehiculos,int n,char* id_mat)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(strcmp(id_mat,vehiculos[i].Id_mat) == 0) return i;
  }
  return -1;
}

int buscarViajesIndex(Viajes* viajes,int n,int id_viaje)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_viaje == viajes[i].Id_viaje) return i;
  }
  return -1;
}

int buscarPasosIndex(Pasos* pasos,int n, int id_viaje)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_viaje == pasos[i].Id_viaje) return i;
  }
  return -1;
}
int buscarIncidenciasIndex(Incidencias* incidencias,int n, int id_viaje)
{
  int i;
  for(i = 0; i < n; ++i)
  {
    if(id_viaje == incidencias[i].Id_viaje) return i;
  }
  return -1;
}

int validarFecha(char* cadena)
{
    static const int DiaMes[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    time_t t1={time(NULL)};
    struct tm *t2 = {localtime(&t1)};
    int d=0,m=0,a=0;
    if(sscanf(cadena,"%2d/%2d/%4d",&d,&m,&a) != 3) return 0;
    if( a < t2->tm_year+1900 || a > 2030 ) return 0;
    if( m < t2->tm_mon+1 || m > 12 ) return 0;
    int bisiesto = (a % 4 == 0 && ( a % 400 == 0 || a % 100 != 0));
    if(d < t2->tm_mday || d > (DiaMes[m]+bisiesto) ) return 0;
    return 1;
}

int validarHora(char* cadena)
{
  time_t t1={time(NULL)};
  struct tm* t2={localtime(&t1)};
  int h = 0, m = 0;
  if(sscanf(cadena,"%2d:%2d",&h,&m)!=2) return 0;
  if( h < t2->tm_hour || h > 24 ) return 0;
  if( m < t2->tm_min || m > 59 ) return 0;
  return 1;
}
