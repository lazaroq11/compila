/* 

DISCIPLINA : FUNDAMENTOS DE COMPILADORES
ALUNO: LÁZARO QUEIROZ DA SILVA
EMAIL: lazaroq11@gmail.com
TÍTULO : TOKEN.H

*/


#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "allocation.hpp"
#include "lexico.hpp"


void retornaToken(){ //rotina para retornar token
	token t;
	
	 do{
	 	
	 	t = proxToken();
	 	
	 	
	 	switch(t.tipo){ //Imprime na tela os tokens
	 		
	 		case 1: printf("Tipo = PALAVRA RESERVADA\n");break;
	 		case 2: printf("Tipo = TIPO\n"); break;
	 		case 3: printf("Tipo = OPA\n"); break;
	 		case 4: printf("Tipo = OPB\n");break;
	 		case 5: printf("Tipo = IGUAL\n"); break;
	 		case 6: printf("Tipo = ABRE PARENTESES\n"); break;
	 		case 7: printf("Tipo = FECHA PARENTESES\n");break;
	 		case 8: printf("Tipo = ENDLINE\n");break;
	 		case 9: printf("Tipo = VIRGULA\n");break;
	 		case 10:printf("Tipo = VALOR\n");break;
	 		case 11:printf("Tipo = IDENTIFICADOR\n");break;
	 		case 12:printf("Tipo = FIM\n");break;
	 		case 13:printf("Tipo = ERRO\n");break;
		 }
		 
		 printf("Lexema = %s\n",t.lexema);
		 printf("Linha = %d\n\n\n",t.posicaoLex);
	 }
	 
	 while(t.tipo != 12); //encerra no final da sentenca
	 	

		 delete [] vet; //libera memória
	 
}
