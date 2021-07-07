#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/**
* \brief Solicita un numero al usuario , luego de verificarlo devuelve el resultado
* \ param int numero Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \ param string mensaje Es el mensaje a ser mostrado
* \ param string mensajeError Es el mensaje de Error a ser mostrado
* \
* \
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
int pedirEntero(int* numero, char* mensaje, char* mensajeError);
/**
* \brief Solicita un string al usuario , luego de verificarlo devuelve el resultado
* \ param char cadena Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \ param int tam tamaño maximo de la cadena
* \ param string mensaje Es el mensaje a ser mostrado
* \ param string mensajeError Es el mensaje de Error a ser mostrado
* \
* \
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
int pedirCadena(char* cadena, int tam, char* mensaje, char* mensajeError);
/**
* \brief Solicita un numero al usuario , luego de verificarlo devuelve el resultado
* \ param int numero Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \ param string mensaje Es el mensaje a ser mostrado
* \ param string mensajeError Es el mensaje de Error a ser mostrado
* \
* \
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
int pedirFlotante(float* numero, char* mensaje, char* mensajeError);

int pedirChar(char* Uncaracter, char* mensaje,char* mensajeError);
