#include <iostream>
#include <map>
#include <stack>
#include <stdexcept>
#include "enumtoken.hpp"
#include"token.hpp"
#include"lexico.hpp"
enum {NULA = 99};



/*
Converts a valid token to the corresponding terminal symbol
*/


int main(){


   // LL parser table, maps < non-terminal, terminal> pair to action

	std::stack<simbolos>pilha;
	std::map<simbolos, std::map<simbolos, int> > tabela;	// symbol stack
		// input buffer

	// initialize the symbols stack
	pilha.push(FIM);	// terminal, $
	pilha.push(comandos);		// non-terminal, S
    int p = 0;
	// initialize the symbol stream cursor
	

	// set up the parsing table
	tabela[comandos][IDENTIFICADOR] =
	tabela[comandos][SE] =
	tabela[comandos][ENQUANTO] =
	tabela[comandos][TIPO] = 1;
	tabela[comandox][IDENTIFICADOR] = 
	tabela[comandox][SE] =
	tabela[comandox][ENQUANTO] =
	tabela[comandox][TIPO] = 1;
	tabela[comandox][FIM] =
	tabela[comandox][ACABOU] =
	tabela[comandox][SENAO] = NULA;
	tabela[bloco][IDENTIFICADOR] =
	tabela[bloco][SE] =
	tabela[bloco][ENQUANTO] = 
	tabela[bloco][TIPO] = 2;
	tabela[comando][IDENTIFICADOR] =
	tabela[comando][SE] =
	tabela[comando][ENQUANTO] = 
	tabela[comando][TIPO] = 3;
	tabela[blocose][SE] = 4;
	tabela[se][SE] = 5;
	tabela[senao][SENAO] =
	tabela[senao][ACABOU] = 6;
	tabela[repeticao][ENQUANTO] = 7;
	tabela[decl_var][TIPO] = 8;
	tabela[atribuicao][IDENTIFICADOR] = 9;
	tabela[explogica][OPB] =
	tabela[explogica][IDENTIFICADOR] = 10;
	tabela[explogica][OPB] = tabela[explogica][NEG] = 11;
	tabela[atrib_decl][TIPO] = 12;
	tabela[atrib_decl][IDENTIFICADOR] = 13;
	tabela[expressao][OPA] =
	tabela[expressao][OPB] = 14;
	tabela[expressao][IDENTIFICADOR] = 
	tabela[expressao][VALOR] = 
	tabela[expressao][ABREPARENTESES] = 15;
	tabela[expressaox][OPA] = 
	tabela[expressaox][OPB] = 16;
	tabela[expressaox][FIM] =
	tabela[expressaox][FECHAPARENTESES] = 
	tabela[expressaox][ENDLINE] = NULA;
	tabela[parent][IDENTIFICADOR] = 17;
	tabela[parent][VALOR] = 18;
	tabela[parent][ABREPARENTESES] = 19;
	tabela[operad][OPA] = 20;
	tabela[operad][OPB] = 21;
	tabela[nopb][OPB] = 22;
	tabela[nopb][NEG] = 23; 
	
   
   	
	const token tk = proxToken();
	while (pilha.size() > 0)
	{
	     
		  if(pilha.top() == pilha.top()){
		  	 
		    p++;
			pilha.pop ();
		  }
		  else{
		         std::cout<< "não bateu vamos olhar na tabela regra";
				 pilha.pop(); 
			switch (p)
			{
				case 1:	// COMANDOS -> COMANDO COMANDOX
					pilha.push(comandox);
					pilha.push(comando);	// F
					break;

				
				case 2: //COMANDOX -> COMANDO COMANDOX
				 pilha.push(comandox);
                pilha.push(comando);
                break;
				
				case 3: //BLOCO -> COMANDOS
				pilha.push(comandos);
				break;
				
				case 4: //COMANDO -> BLOCOSE
				pilha.push(blocose);
				break;
				
				case 5: //COMANDO -> REPETICAO
				pilha.push(repeticao);
				break;
				
				case 6: //COMANDO -> ATRIB_DECL
				pilha.push(atrib_decl);
				break;
				
				case 7: //BLOCOSE ->SE SENAO
				pilha.push(senao);
				pilha.push(se);
				break;
				
				case 8: //SE -> SE EXP LOGICA FACA BLOCO
				pilha.push(bloco);
				pilha.push(FACA);
				pilha.push(explogica);
				pilha.push(SE);
				break;
				
				case 9: //SENAO -> SENAO BLOCO ACABOU
				pilha.push(ACABOU);
				pilha.push(bloco);
				pilha.push(SENAO);
				break;
				
				case 10: //SENAO -> ACABOU
				pilha.push(ACABOU);
				break;
				
				
				case 11: //REPETICAO -> ENQUANTO EXPLOGICA FACA BLOCO ACABOU
				pilha.push(ACABOU);
				pilha.push(bloco);
				pilha.push(FACA);
				pilha.push(explogica);
				pilha.push(ENQUANTO);
				break;
				
				case 12: //DECL_VAR -> TIPO IDENTIFICADOR
				pilha.push(IDENTIFICADOR);
				pilha.push(TIPO);
				break;
				
				case 13: //ATRIBUICAO -> IDENTIFICADOR = EXPRESSAO
				pilha.push(expressao);
				pilha.push(IGUAL);
				pilha.push(IDENTIFICADOR);
				break;
				
				case 14: //EXPLOGICA -> NOPB EXPLOGICA
				pilha.push(explogica);
				pilha.push(nopb);
				break;
				
				case 15: //EXPLOGICA -> IDENTIFICADOR
				pilha.push(IDENTIFICADOR);
				break;
				
				case 16: //ATRIBDECL -> DECL_VAR
				pilha.push(decl_var);
				break;
				
				case 17: //ATRIBDECL -> ATRIBUICAO
				pilha.push(atribuicao);
				break;
				
				case 18: //EXPRESSAO -> OPERAD EXPRESSAO
				pilha.push(expressao);
				pilha.push(operad);
				break;
				
				case 19: //EXPRESSAO -> PARENT EXPRESSAO
				pilha.push(expressao);
				pilha.push(operad);
				break;
				
				case 20: //EXPRESSAOX -> OPERAD EXPRESSAO
				pilha.push(expressao);
				pilha.push(operad);
				break;
				
				case 21: //PARENT -> IDENTIFICADOR
				pilha.push(IDENTIFICADOR);
				break;
				
				case 22: //PARENT -> VALOR
				pilha.push(VALOR);
				break;
				
				case 23: //PARENT->(EXPRESSAO)
				pilha.push(FECHAPARENTESES);
				pilha.push(expressao);
				pilha.push(ABREPARENTESES);
				break;
				
				case 24: //OPERAD -> OPA
				pilha.push(OPA);
				break;
				
				case 25: //OPERAD ->OPB
				pilha.push(OPB);
				break;
				
				case 26: //NOPB	-> NEG
				pilha.push(NEG);
				break;
				
				case nulo: //nulo
				break;
				
				default:
				  std::cout<<"erro sintatico";
				  
				  break;	
					
			}
		}
	}

}






