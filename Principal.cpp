#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
string interseccion(string[],string[],int,int);
string productocartesiano(string[],string[],int,int);
string adjuntar(string[],string[],int,int);
string potencia(string[],int);
int cardinalidad_cartesiano(int,int);
string diferencia(string[],string[],int,int);
string potencia_cartesiana(string[],string[],int,int);
int main(void){
    char A[1000],B[1000];
    char* token1;
    char* token2;
    int cardinalidadA=0,cardinalidadB=0;
    string TemporalA[1000],TemporalB[1000];
    cout<<"introduzca los elementos de los conjuntos"<<endl;
    cout<<"Si ocupa subconjuntos "<<endl;
    cout<<"ocupe | como separador interno"<<endl;
    
    cout<<"Ejemplo:"<<endl;
    cout<<"[1|2],[1|3|4]"<<endl;
    cout<<"LA ENTRADA PRINCIPAL NO PUEDE SER PARES ORDENADOS"<<endl;
    cout<<"El programa calcula los pares ordenados a partir de los conjuntos dados"<<endl;
    cout<<"introduzca los elementos del conjunto A: ";
    cin.getline(A,1000);
    token1=strtok(A,",");
    while(token1!=NULL){
        cardinalidadA++;
        TemporalA[cardinalidadA]=token1;   
        token1=strtok(NULL,",");
      
    }
    string VectorA[cardinalidadA];
    for(int i=0;i<cardinalidadA;i++){
        VectorA[i]=TemporalA[i+1];
    }
    //VectorA se a creado:
    cout<<"Introduzca los elementos del conjunto B: ";
    cardinalidadB=0;
    cin.getline(B,1000);
    token2=strtok(B,",");
    while(token2!=NULL){
        cardinalidadB++;
        TemporalB[cardinalidadB]=token2;
        token2=strtok(NULL,",");
    }
    string VectorB[cardinalidadB];
    for(int i=0;i<cardinalidadB;i++){
        VectorB[i]=TemporalB[i+1];
    }
    cout<<"Cardinalidad De A: "<<cardinalidadA<<endl;
    cout<<"Cardinalidad De B: "<<cardinalidadB<<endl;
    cout<<"El conjunto potencia de A: "<<endl;
    cout<<potencia(VectorA,cardinalidadA)<<endl;;
    cout<<"Cardinalidad del conjunto potencia de A es : "<<pow(2,cardinalidadA)<<endl;
    cout<<"El conjunto potencia de B: "<<endl;
    cout<<potencia(VectorB,cardinalidadB)<<endl;;
    cout<<"Cardinalidad del conjunto potencia de B es : "<<pow(2,cardinalidadB)<<endl;   
    cout<<"La interseccion de A con B es igual a: "<<interseccion(VectorA,VectorB,cardinalidadA,cardinalidadB)<<endl;
    cout<<"El producto cartesiano de A con B es igual A: "<<endl;
    cout<<productocartesiano(VectorA,VectorB,cardinalidadA,cardinalidadB)<<endl;
    cout<<"Cardinalidad del producto cartesiano: "<<cardinalidad_cartesiano(cardinalidadA,cardinalidadB)<<endl;
    cout<<"La union de A con B es: "<<adjuntar(VectorA,VectorB,cardinalidadA,cardinalidadB)<<endl;
    cout<<"La diferencia de A con B es: "<<diferencia(VectorA,VectorB,cardinalidadA,cardinalidadB)<<endl;
    cout<<"Potencia del producto cartesiano:"<<endl;
    cout<<potencia_cartesiana(VectorA,VectorB,cardinalidadA,cardinalidadB)<<endl;
    return 0;
}
string interseccion(string VectorA[],string VectorB[],int cardinalidadA,int cardinalidadB){
    string resultado="{";
    for(int i=0;i<cardinalidadA;i++){
        for(int j=0;j<cardinalidadB;j++){
            if(VectorA[i]==VectorB[j]){
                resultado=resultado+VectorB[j]+",";
            }
        }
    }
    resultado=resultado+"}";
    return resultado;
}
string productocartesiano(string VectorA[],string VectorB[],int cardinalidadA,int cardinalidadB){
    string resultado="{";
    for(int i=0;i<cardinalidadA;i++){
        for(int j=0;j<cardinalidadB;j++){
            resultado=resultado+"("+VectorA[i]+","+VectorB[j]+"),";
        }
    }
    resultado=resultado+"}";
    return resultado;
}
string adjuntar(string VectorA[],string VectorB[],int cardinalidadA,int cardinalidadB){
    string resultado="{";
    bool encontrado=false;
    for(int i=0;i<cardinalidadA;i++){
        resultado=resultado+VectorA[i]+",";
    }
    
    for(int j=0;j<cardinalidadB;j++){
        encontrado=false;
        for(int i=0;i<cardinalidadA;i++){
            if(VectorB[j]==VectorA[i]){
                encontrado=true;
            }
        }
       if(encontrado==false){
           resultado=resultado+VectorB[j]+",";
       }
    }
    resultado=resultado+"}";
    return resultado;
}
string potencia(string vector[],int cardinalidad){
    string resultado="{[],";
    for(int i=0;i<cardinalidad;i++){
        resultado=resultado+"["+vector[i]+"],";
    }
    for(int i=0;i<cardinalidad;i++){
        for(int j=i+1;j<cardinalidad;j++){
            resultado=resultado+"["+vector[i]+","+vector[j]+"],";
        }
    }
    
    if(cardinalidad>2){
        resultado=resultado+"[";
        for(int i=0;i<cardinalidad;i++){
            resultado=resultado+vector[i]+",";
        }
        resultado=resultado+"]";
    }
    resultado=resultado+"}";
    return resultado;
}
int cardinalidad_cartesiano(int cardinalidadA,int cardinalidadB){
    return cardinalidadA*cardinalidadB;
}
string diferencia(string vectorA[],string vectorB[],int cardinalidadA,int cardinalidadB){
    string resultado="{";
    bool encontrado=false;
    for(int i=0;i<cardinalidadA;i++){
        encontrado=false;
        for(int j=0;j<cardinalidadB;j++){
            if(vectorA[i]==vectorB[j]){
                encontrado=true;
            }
        }
       if(encontrado==false){
           resultado=resultado+vectorA[i]+",";
       }
    }
    resultado=resultado+"}";
    return resultado;
}
string potencia_cartesiana(string VectorA[],string VectorB[],int cardinalidadA,int cardinalidadB){
    string resultado;
    for(int i=0;i<cardinalidadA;i++){
        for(int j=0;j<cardinalidadB;j++){
            resultado=resultado+"("+VectorA[i]+","+VectorB[j]+")";
        }
    }
    int tamano=resultado.length(),elementos=0;
    for(int i=0;i<tamano;i++){
        if(resultado[i]==')'){
            elementos++;
        }
    }
    string vector[elementos],auxiliar;
    int j=0;
    for(int i=0;i<tamano;i++){ 
        if(resultado[i]!=')'){
                 auxiliar=auxiliar+resultado[i];
        }else{
            auxiliar=auxiliar+")";
            vector[j]=auxiliar;
            j++;
            auxiliar="";
        }
    }
    resultado="";
    resultado=potencia(vector,elementos);
    return resultado;
}