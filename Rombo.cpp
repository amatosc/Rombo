#include <iostream>
#include <stdio.h>

/**************************************
* NOMBRE: #Alex#
* PRIMER APELLIDO: #Matos#
* SEGUNDO APELLIDO: #Caballero#
***************************************/
// Funcion que controla si la funcion rellono devuelve . ó o
int changeFlag(int flag){

  if(flag==0){
        flag=1;
      }
      else{
        flag = 0;
      }
  return flag;
}

//Esta funcion Devuelve . (,) o ó @ dependiendo del valor de flag
int relleno(int flag,int cntrl){
    char txt_r = 'o';
    char txt_s = '.';
    char txt_a = '@';

    if(cntrl == 2){
      printf("%c",txt_a);
      return 2;
    }
    else{
      if(flag == 0){
        printf("%c",txt_s);
        return 1;
      }
      else{
        printf("%c",txt_r);
        return 0;
      }
    }
}

void linea(int lado,int pos, int lim){

  char txt_p = '@';
  int flag = 0;
  int control = 1;
  int cntrl = 0;

  for(int i=0; i<lado;i++){
    if(i==pos){
      printf("%c",txt_p);
    }
    else if(i>pos && lim == 1){
      if(cntrl > 2){
        cntrl = 0;
      }
      cntrl=cntrl + relleno(flag,cntrl);
      flag = changeFlag(flag);
    }
    else if(i>pos && lim ==3){
      if(cntrl > 2){
        cntrl = 0;
      }
      cntrl=cntrl+ relleno(flag,cntrl);
      flag = changeFlag(flag);
    }
    else if(i<pos && lim ==4){
      if(pos%4 == 0 && control == 1){
        cntrl = 2;flag =0;control = 0;
        }
      else if(pos%2 == 0 && control == 1 ){
        cntrl = 1; flag=1;control = 0;
      }
      else if((pos == 5 ||pos == 9 || pos== 13 ||pos == 17) && control==1){
          flag = 0; cntrl=1; control=0;
      }

      if(cntrl>2){cntrl=0;flag =0 ;}
      cntrl= cntrl + relleno(flag,cntrl);
      flag = changeFlag(flag);
    }
    else if(i<pos && lim ==2){

      if(pos%4 == 0 && control == 1){
        cntrl = 2;flag =0;control = 0;
        }
      else if(pos%2 == 0 && control == 1 ){
        cntrl = 1; flag=1;control = 0;
      }
      else if((pos == 5 ||pos == 9 || pos== 13 ||pos == 17) && control==1){
          flag = 0; cntrl=1; control=0;
      }

      if(cntrl>2){cntrl=0;flag =0 ;}
      cntrl= cntrl + relleno(flag,cntrl);
      flag = changeFlag(flag);

    }
    else if(lim==1 || lim==3){
      printf(" ");
    }
    else{
      printf("");
    }
  }
}


int main(){

int lados = 0;

    printf("Lados del romblo ?");
    scanf ("%i",&lados);

    if(lados >= 1 && lados <= 20)
    {
      for(int i=0;i<lados;i++){
        linea(lados,lados-i-1,1);linea(lados,i-1,2);printf("\n");
      }
      for(int i=0;i<lados-1;i++){
        linea(lados,i+1,3);linea(lados,lados-i-3,4);printf("\n");
      }
      return 0;
    }
    else{
      printf("El numero no esta en el rango aceptado");
      return 0;
    }
    return 0;
}
