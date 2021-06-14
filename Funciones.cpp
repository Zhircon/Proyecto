/*
Autor: @Zhircon
Contacto: AgniZahir@gmail.com
Xalapa,Ver.
Ultima Revision: 06/06/2021 
*/

//Bibliotecas a utilizar
#include<iostream>
#include <string.h>
#include <math.h>
using namespace std; 
//Declaracion de prototipos
string interseccion(string[],string[],int,int);
string productocartesiano(string[],string[],int,int);
string adjuntar(string[],string[],int,int);
string potencia(string[],int);
int cardinalidad_cartesiano(int,int);
string diferencia(string[],string[],int,int);
string potencia_cartesiana(string[],string[],int,int);
//Definiciones
//Genera la funcion de interseccion
string interseccion(string VectorA[], string VectorB[], int cardinalidadA, int cardinalidadB){
    string resultado = "{";
    bool borrar = false;
    for (int i = 0; i < cardinalidadA; i++){
        for (int j = 0; j < cardinalidadB; j++){
            if (VectorA[i] == VectorB[j]){
                borrar = true;
                resultado = resultado + VectorB[j] + ",";
            }
        }
    }
    if(borrar){
        resultado[resultado.length() - 1] = '}';
    }else{
        resultado += "}";
    }
    return resultado;
}
//Funcion de producto cartesiano
string productocartesiano(string VectorA[], string VectorB[], int cardinalidadA, int cardinalidadB){
    string resultado = "{";
    bool borrar = false;
    for (int i = 0; i < cardinalidadA; i++){
        for (int j = 0; j < cardinalidadB; j++){
            borrar = true;
            resultado = resultado + "(" + VectorA[i] + "," + VectorB[j] + "),";
        }
    }
    if (borrar){
        resultado[resultado.length() - 1] = '}';
    }else{
        resultado += "}";
    }
    return resultado;
}
//Funcion de Union
string adjuntar(string VectorA[], string VectorB[], int cardinalidadA, int cardinalidadB){
    string resultado = "{";
    bool borrar = false, encontrado = false;
    for (int i = 0; i < cardinalidadA; i++){
        resultado = resultado + VectorA[i] + ",";
    }
    for (int j = 0; j < cardinalidadB; j++){
        encontrado = false;
        for (int i = 0; i < cardinalidadA; i++){
            if (VectorB[j] == VectorA[i]){
                encontrado = true;
            }
        }
        if (encontrado == false){
            resultado = resultado + VectorB[j] + ",";
            borrar = true;
        }
    }
    if (borrar){
        resultado[resultado.length() - 1] = '}';
    }else{
        resultado += "}";
    }
    return resultado;
}
//Funcion de potencia
string potencia(string vector[], int cardinalidad){
    string resultado = "{[],";
    bool borrar = true;
    for (int i = 0; i < cardinalidad; i++){
        resultado = resultado + "[" + vector[i] + "],";
    }
    for (int i = 0; i < cardinalidad; i++){
        for (int j = i + 1; j < cardinalidad; j++){
            resultado = resultado + "[" + vector[i] + "," + vector[j] + "],";
        }
    }
    if (cardinalidad > 2){
        resultado = resultado + "[";
        for (int i = 0; i < cardinalidad; i++){
            resultado = resultado + vector[i] + ",";
        }
        resultado = resultado + "]";
    }
    if(borrar){
        resultado[resultado.length() - 2] = ']';
        resultado[resultado.length() - 1] = '}';
    }else{
        resultado[resultado.length()] = '}';
    }
    return resultado;
}
//Funcion de Cardinalida de un Producto cartesiano
int cardinalidad_cartesiano(int cardinalidadA, int cardinalidadB){
    return cardinalidadA * cardinalidadB;
}
//Funcion de diferencia
string diferencia(string vectorA[], string vectorB[], int cardinalidadA, int cardinalidadB){
    string resultado = "{";
    bool borrar = false, encontrado = false;
    for (int i = 0; i < cardinalidadA; i++){
        encontrado = false;
        for (int j = 0; j < cardinalidadB; j++){
            if (vectorA[i] == vectorB[j]){
                encontrado = true;
            }
        }
        if (encontrado == false){
            resultado = resultado + vectorA[i] + ",";
            borrar = true;
        }
    }
    if (borrar){
        resultado[resultado.length() - 1] = '}';
    }else{
        resultado = resultado + "}";
    }
    return resultado;
}
//Funcion de potencia cartesiana
string potencia_cartesiana(string VectorA[], string VectorB[], int cardinalidadA, int cardinalidadB){
    string resultado;
    for (int i = 0; i < cardinalidadA; i++){
        for (int j = 0; j < cardinalidadB; j++){
            resultado = resultado + "(" + VectorA[i] + "," + VectorB[j] + ")";
        }
    }
    int tamano = resultado.length(), elementos = 0;
    for (int i = 0; i < tamano; i++){
        if (resultado[i] == ')'){
            elementos++;
        }
    }
    string vector[elementos], auxiliar;
    int j = 0;
    for (int i = 0; i < tamano; i++){
        if (resultado[i] != ')'){
            auxiliar = auxiliar + resultado[i];
        }
        else{
            auxiliar = auxiliar + ")";
            vector[j] = auxiliar;
            j++;
            auxiliar = "";
        }
    }
    resultado = "";
    resultado = potencia(vector, elementos);
    return resultado;
}