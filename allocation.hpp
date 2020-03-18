/* 

DISCIPLINA : FUNDAMENTOS DE COMPILADORES
ALUNO: LÁZARO QUEIROZ DA SILVA
EMAIL: lazaroq11@gmail.com
TÍTULO : ALLOCATION.H

*/

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>



typedef struct token {   //definindo tipo token
	
	int tipo;  // tipo de lexema
	char lexema[1];  //lexema
	int posicaoLex; //posicao do lexema
	
}token;


    char a; //caracter a ser analisado
    int contLinha = 1; //contador de linhas
    int iniciolex = 0; //ponteiro que aponta para o inicio do lexema
    int pontSeg; //ponteiro que localiza o fim do lexema 
    char *vet; //ponteiro para o vetor que armazena o arquivo
  

   
    char abreArq (char *nomeArq){
    	
    	
    	FILE *Arq;
    	char letra; //recebe caracteres lidos do arquivo
    	int bloco = 0; //conta as colunas
    	int auxIns = 0; //auxilia na insercao no vetor
	
	
	
	if((Arq = fopen(nomeArq, "r")) == NULL){
		printf("Erro na abertura do arquivo. Verifique o caminho");
	} //rotina de verificação de abertura do arquivo. Se não for encontrado ou não puder ser aberto, retorna uma mensagem de erro
	
	
		
		while((letra = getc(Arq)) != EOF){ //faz a leitura dos caracteres do arquivo
			bloco++; //conta os caracteres do arquivo
		}
	
	
	
	
	vet = new char[bloco]; //alocacao dinamica com a quantidade de caracteres contida no arquivo. 
	
	
	for(int z = 0; z<bloco; z++){  
		vet[z]= NULL;
	}//fazendo a limpa no vetor
	
	rewind(Arq); //o ponteiro retorna para o inicio 
	
	
	while((letra = getc(Arq)) != EOF){ //le caracter por caracter no arquivo
		
		vet[auxIns] = letra; //insere caracter por caracter no vetor
		auxIns++; //vai pra proxima posicao do vetor
	}
	
	vet[bloco] = '\0'; //insere um '/0' no final do vetor para indicar o final
	
	fclose(Arq); //fecha o arquivo

}


   char proxCaract(){ //faz a leitura do proximo caracter 
   	
   	a = vet[pontSeg++]; //incrementa a posição no vetor
   	
   	if(a == '\n'){
   		contLinha++;
   		
	   }
	   
	   return a; //retorna o caracter do vetor;
	  
   }
