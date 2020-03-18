/* 

DISCIPLINA : FUNDAMENTOS DE COMPILADORES
ALUNO: L�ZARO QUEIROZ DA SILVA
EMAIL: lazaroq11@gmail.com
T�TULO : lEXICO.H

*/

#pragma once
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "allocation.hpp"



int falhouAutomato(int &inicia){
	
	switch(inicia){
	  case 0: return 3; //SE
	  case 3: return 9; //SENAO
	  case 9: return 14; //FACA
	  case 14: return 21; //ACABOU
	  case 21: return 30; //ENQUANTO
	  case 30: return 38; //INTEIRO
	  case 38: return 47; //QUEBRADO
	  case 47: return 54; //LOGICO 
	  case 54: return 56; //*
	  case 56: return 58; //-
	  case 58: return 60; //+
	  case 60: return 62; // /
	  case 62: return 65; //&&
	  case 65: return 68; //||
	  case 68: return 70; //=
	  case 70: return 72; //(
	  case 72: return 74; //)
	  case 74: return 76; //;
	  case 76: return 78; //,
	  case 78: return 81; //numero
	  case 81: return 85; //identificador
	  default: return 87; //erro
	}
}



     token proxToken(){
     	
      token t; // token de retorno
	  int contAux; //contador auxiliar de tokens
	  int estado = 0; //auxilia no posicionamento das comparacoes
	  int inicia = 0; //posiciona as comparacoes
	  int pos = 0; //variavel contadora aux 
	  
	  
	    for(contAux = 0; contAux < 100; contAux++) //Limpa o vetor que recebe o lexema
  {
  		t.lexema[contAux] = NULL;
     }
	    	
	    	
	    while(1){
	    
	    	switch(estado){
	    	//inicio do SE
	    	case 0: a = proxCaract();
	    	  if(isspace(a))//Verifica se é espaço em branco ,tabulação ou final de linha
                    	iniciolex++;//Aponta para o início do Lexema
	    	else if(a == 'S')estado = 1;
	    	
	    	else{
	    		pontSeg = iniciolex;
	    		estado = inicia = falhouAutomato(inicia);
			}
		
		break;
		
		case 1: a = proxCaract();
		if((a == 'E')&&(!islower(vet[pontSeg]))&&(!isupper(vet[pontSeg])))
		estado = 2;
	else{
		
		pontSeg = iniciolex;
		estado = inicia = falhouAutomato(inicia);
	}
	
	break;
	
	case 2:
		
		t.tipo = 1;
		strcpy(t.lexema,"SE");
		t.posicaoLex = contLinha;
		iniciolex = pontSeg;
		
		return t;
		
	// final do SE
	
	
	//inicio SENAO
	 
	 case 3: a = proxCaract();
	 if(isspace(a))//Verifica se é espaço em branco ,tabulação ou final de linha
                    	iniciolex++;//Aponta para o início do Lexema
	 else   if(a == 'S')
	    estado = 4;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break;
		
	case 4: a = proxCaract();
	    if(a == 'E')
	    estado = 5;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
   
   case 5: a = proxCaract();
        if(a == 'N'){
		
		estado = 6;
		
		}else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		} 
		
		
	case 6: a = proxCaract();
	      if(a == 'A'){
		  
		  estado = 7;
		  
		  
		  }else{
		  	pontSeg = iniciolex;
		  	estado = inicia = falhouAutomato(inicia);
		  }	
		  
	case 7: a = proxCaract();
	      if(a == 'O'){
		  
		  estado = 8;
		  
		  
		  }else{
		  	pontSeg = iniciolex;
		  	estado = inicia = falhouAutomato(inicia);
		  }	  
		  
		  
	case 8:
	   t.tipo = 1;
	   strcpy(t.lexema,"SENAO");
	   t.posicaoLex = contLinha;
	   iniciolex = pontSeg;
	   
	   return t;
	   
	   //fim do senao
	   
	   
	   //inicio faca
	   
	   	 	 case 9: a = proxCaract();
	    if(isspace(a))//Verifica se é espaço em branco ,tabulação ou final de linha
                    	iniciolex++;//Aponta para o início do Lexema
		else if(a == 'F')
	    estado = 10;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break; 
		
			 case 10: a = proxCaract();
	    if(a == 'A')
	    estado = 11;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break; 
		
		
		
			 case 11: a = proxCaract();
	    if(a == 'C')
	    estado = 12;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break; 
		
		
		
			 case 12: a = proxCaract();
	    if(a == 'A')
	    estado = 13;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break; 
          case 13:		
			t.tipo = 1;
                  strcpy(t.lexema,"FACA");//Retorna o Lexema
                  t.posicaoLex = contLinha; //Linha do Lexema
                  		iniciolex = pontSeg;
			 return t;
		//FIM FACA
		
		
		//inicio ACABOU
		
			 case 14: a = proxCaract();
			 if(isspace(a))//Verifica se é espaço em branco ,tabulação ou final de linha
                    	iniciolex++;//Aponta para o início do Lexema
	    else if(a == 'A')
	    estado = 15;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break;
		
			 case 15: a = proxCaract();
	    if(a == 'C')
	    estado = 16;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		break;
		
			 case 16: a = proxCaract();
	    if(a == 'A')
	    estado = 17;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break;
		
		
			 case 17: a = proxCaract();
	    if(a == 'B')
	    estado = 18;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		break;
		
			 case 18: a = proxCaract();
	    if(a == 'O')
	    estado = 19;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
		
		break;
		
			 case 19: a = proxCaract();
	    if(a == 'U')
	    estado = 20;
	    
	    else{
	    	pontSeg = iniciolex;
	    	estado = inicia = falhouAutomato(inicia);
		}
			break;
			
			
		 case 20:		
			t.tipo = 1;
                  strcpy(t.lexema,"ACABOU");//Retorna o Lexema
                  t.posicaoLex = contLinha; //Linha do Lexema
                  		iniciolex = pontSeg;
			 return t;	
			 
			 
		//fim ACABOU
		
		//INICIO ENQUANTO
		
		case 21: a = proxCaract();
		if(a == 'E')
		estado = 22;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}	
		
		break;
		
		
		
		case 22: a = proxCaract();
		if(a == 'N')
		estado = 23;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		
		break;
		
		case 23: a = proxCaract();
		if(a == 'Q')
		estado = 24;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		case 24: a = proxCaract();
		if(a == 'U')
		estado = 25;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		case 25: a = proxCaract();
		if(a == 'A')
		estado = 26;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		case 26: a = proxCaract();
		if(a == 'N')
		estado = 27;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		case 27: a = proxCaract();
		if(a == 'T')
		estado = 28;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		case 28: a = proxCaract();
		if(a == 'O')
		estado = 29;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		case 29:
			t.tipo = 1;
			strcpy(t.lexema, "ENQUANTO");
			t.posicaoLex = contLinha;
			iniciolex = pontSeg;
			
			return t; 
			
			//FIM ENQUANTO
			
			//INICIA INTEIRO
			
			case 30: a = proxCaract();
			if(a == 'I')
			estado = 31;
			
			else{
				pontSeg = iniciolex;
				estado = inicia = falhouAutomato(inicia);
			}
			break;
			
			
			case 31: a = proxCaract();
			if(a == 'N')
			estado = 32;
			
			else{
				pontSeg = iniciolex;
				estado = inicia = falhouAutomato(inicia);
			}
			break;
			
			case 32: a = proxCaract();
			if(a == 'T')
			estado = 33;
			
			else{
				pontSeg = iniciolex;
				estado = inicia = falhouAutomato(inicia);
			}
			break;
			
			case 33: a = proxCaract();
			if(a == 'E')
			estado = 34;
			
			else{
				pontSeg = iniciolex;
				estado = inicia = falhouAutomato(inicia);
			}
			break;
			
			case 34: a = proxCaract();
			if(a == 'I' )
			estado = 35;
			
			else{
				pontSeg = iniciolex;
				estado = inicia = falhouAutomato(inicia);
			}
		    break;
			
			
			case 35: a = proxCaract();
			if(a == 'R')
			estado = 36;
			
			else{
				pontSeg = iniciolex;
				estado = inicia = falhouAutomato(inicia);
			}	
			break;
			
			
			case 36: a = proxCaract();
			if(a == 'O')
			estado = 37;
			
			else{
				pontSeg = iniciolex;
				estado = inicia = falhouAutomato(inicia);
			}
			break;
			
			case 37:
				t.tipo = 2;
				strcpy(t.lexema, "INTEIRO");
				t.posicaoLex = contLinha;
				iniciolex = pontSeg;
				
				return t;
		
		
		//FIM INTEIRO
		
		
		//INICIO QUEBRADO
		
		case 38: a = proxCaract();
		if(a == 'Q')
		estado = 39;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		
		case 39: a = proxCaract();
		if(a == 'U')
		estado = 40;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
			
		}
		break;
		
		
		case 40: a = proxCaract();
		if(a == 'E')
		estado = 41;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		
		case 41: a = proxCaract();
		if(a == 'B')
		estado = 42;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		
		case 42: a = proxCaract();
		if(a == 'R')
		estado = 43;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		
		case 43: a = proxCaract();
		if(a == 'A')
		estado = 44;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
		case 44: a = proxCaract();
		if(a == 'D')
		estado = 45;
		
		else{
			pontSeg = iniciolex;
			estado = inicia = falhouAutomato(inicia);
		}
		break;
		
        case 45: a = proxCaract();
        if(a == 'O')
         estado = 46;
         
         else{
         	pontSeg = iniciolex;
         	estado = inicia = falhouAutomato(inicia);
		 }
		 break;
		 
		 case 46:
		 	t.tipo = 2;
		 	strcpy(t.lexema, "QUEBRADO");
		 	t.posicaoLex = contLinha;
		 	iniciolex = pontSeg;
		 	
		 	return t;
		 	
		 	//FIM DO QUEBRADO
		 	
		 	//INICIO LOGICO
		 	
		 	case 47: a = proxCaract();
		 	if(a == 'L')
		 	estado = 48;
		 	
		 	else{
		 		pontSeg = iniciolex;
		 		estado = inicia = falhouAutomato(inicia);
			 }
			 break;
			 
			 
			 case 48: a = proxCaract();
			 if(a == 'O')
			 estado = 49;
			 
			 else{
			 	pontSeg = iniciolex;
			 	estado = inicia = falhouAutomato(inicia);
			 }
			 break;
			 
			 case 49: a = proxCaract();
			 if(a == 'G')
			 estado = 50;
			 
			 else{
			 	pontSeg = iniciolex;
			 	estado = inicia = falhouAutomato(inicia);
			 }
			 break;
			 
			 case 50: a = proxCaract();
			 if(a == 'I')
			 estado = 51;
			 
			 else{
			 	pontSeg = iniciolex;
			 	estado = inicia = falhouAutomato(inicia);
			 }
			 break;
			 
			 
			 case 51: a = proxCaract();
			 if(a == 'C')
			 estado = 52;
			 
			 else{
			 	pontSeg = iniciolex;
			 	estado = inicia = falhouAutomato(inicia);
			 }
			 break;
			 
			 case 52: a = proxCaract();
			 if(a == 'O')
			 estado = 53;
			 
			 else{
			 	pontSeg = iniciolex;
			 	estado = inicia = falhouAutomato(inicia);
			 }
			 break;
			 
			 case 53:
			 	t.tipo = 2;
			 	strcpy(t.lexema, "LOGICO");
			 	t.posicaoLex = contLinha;
			 	iniciolex = pontSeg;
			 	
			 	return t;
			 	
			 	
			 	//fim LOGICO
			 	
			 	//INICIO *
			 	
			 	case 54: a = proxCaract();
			 	if(a == '*')
			 	estado = 55;
			 	
			 	else{
			 		pontSeg = iniciolex;
			 		estado = inicia = falhouAutomato(inicia);
				 }
				 break;
				 
				 case 55:
				 	t.tipo = 3;
				 	strcpy(t.lexema,"*");
				 	t.posicaoLex = contLinha;
				 	iniciolex = pontSeg;
				 	
				 	return t;
				 	
				 	//fim *
				 	
				 	//inicio -
				 	
				 	case 56: a = proxCaract();
				 	if(a == '-')
				 	estado = 57;
				 	
				 	else{
				 		pontSeg = iniciolex;
				 		estado = inicia = falhouAutomato(inicia);
					 }
					 break;
					 
					 case 57:
					 	t.tipo = 3;
					 	strcpy(t.lexema,"-");
					 	t.posicaoLex = contLinha;
					 	iniciolex = pontSeg;
					 	
					 	return t;
					 	
					 	//FIM -
					 	
					 	
					 	//INICIO +
					 	
					 case 58: a = proxCaract();
					 if(a == '+')
					 estado = 59;
					 
					 else{
					 	pontSeg = iniciolex;
					 	estado = inicia = falhouAutomato(inicia);
					 }
					 break;
					 
					 case 59:
					 	t.tipo = 3;
					 	strcpy(t.lexema,"+");
					 	t.posicaoLex = contLinha;
					 	iniciolex = pontSeg;
					 	
					 	return t;
					 	
					 	//fim +
					 	
					 	//inicio /
					 	case 60: a = proxCaract();
					 if(a == '/')
					 estado = 61;
					 
					 else{
					 	pontSeg = iniciolex;
					 	estado = inicia = falhouAutomato(inicia);
					 }
					 break;
					 
					 case 61:
					 	t.tipo = 3;
					 	strcpy(t.lexema,"/");
					 	t.posicaoLex = contLinha;
					 	iniciolex = pontSeg;
					 	
					 	return t;
					 	
					 	//fim /
					 	
					 	//inicio &&
					 	case 62: a = proxCaract();
					 	if(a == '&')
					 	estado = 63;
					 	
					 	else{
					 		pontSeg = iniciolex;
					 		estado = inicia = falhouAutomato(inicia);
						 }
						 break;
						 
						 
						 case 63: a = proxCaract();
						 if(a == '&')
						 estado = 64;
						 
						 else{
						 	pontSeg = iniciolex;
						 	estado = inicia = falhouAutomato(inicia);
						 }
						 break;
						 
						 case 64:
						 	t.tipo = 4;
						 	strcpy(t.lexema, "&&");
						 	t.posicaoLex = contLinha;
						 	iniciolex = pontSeg;
						 	
						 	return t;
						 	
						 	//fim &&
						 	
						 	//inicio ||
						 	
						 	 	case 65: a = proxCaract();
					 	if(a == '|')
					 	estado = 66;
					 	
					 	else{
					 		pontSeg = iniciolex;
					 		estado = inicia = falhouAutomato(inicia);
						 }
						 break;
						 
						 
						 case 66: a = proxCaract();
						 if(a == '|')
						 estado = 67;
						 
						 else{
						 	pontSeg = iniciolex;
						 	estado = inicia = falhouAutomato(inicia);
						 }
						 break;
						 
						 case 67:
						 	t.tipo = 4;
						 	strcpy(t.lexema, "||");
						 	t.posicaoLex = contLinha;
						 	iniciolex = pontSeg;
						 	
						 	return t;
						 	
						 	//fim ||
						 	
						 	//inicio =
						 case 68: a = proxCaract();
						 if(a == '=')
						 estado = 69;
						 
						 else{
						 	pontSeg = iniciolex;
						 	estado = inicia = falhouAutomato(inicia);
						 }
						 break;
						 
						 
						 case 69:
						 t.tipo = 5;
						 strcpy(t.lexema, "=");
						 t.posicaoLex = contLinha;
						 iniciolex = pontSeg;
						 
						 return t;	
						 
					 	//fim =	
					 	
					    //inicio (
					    
					    case 70: a = proxCaract();
					    if(a == '('){
					    estado = 71;
					}
					    else{
					    	pontSeg = iniciolex;
					    	estado = inicia = falhouAutomato(inicia);
						}
						break;
						
						case 71:
							t.tipo = 6;
							strcpy(t.lexema,"(");
							t.posicaoLex = contLinha;
							iniciolex = pontSeg;
							
							return t;
							
							
						//fim (
						
						//inicio )
						
						case 72: a = proxCaract();
						if(a == ')')
						estado = 73;
						
						else{
							pontSeg = iniciolex;
							estado = inicia = falhouAutomato(inicia);
							
						}
						break;
						
						case 73:
							t.tipo = 7;
							strcpy(t.lexema,")");
							t.posicaoLex = contLinha;
							iniciolex = pontSeg;
							return t;
							
							//fim )
							
							//inicio ;
							
							case 74: a = proxCaract();
							if(a == ';')
							estado = 75;
							
							else{
								pontSeg = iniciolex;
								estado = inicia = falhouAutomato(inicia);
							}
							break;
							
							case 75:
								t.tipo = 8;
								strcpy(t.lexema,";");
								t.posicaoLex = contLinha;
								iniciolex = pontSeg;
								return t;
								
							//fim ;
								
						
						 case 76:a = proxCaract();
						 if(a == ',')
						 estado = 77;
						 
						 else{
						 	pontSeg = iniciolex;
						 	estado = inicia = falhouAutomato(inicia);
						 }
						 break;
						 
						 case 77:
						 	t.tipo = 9;
						 	strcpy(t.lexema, ",");
						 	t.posicaoLex = contLinha;
						 	iniciolex = pontSeg;
						 	return t;
						 	
								
						//inicio numero
							
							case 78: a = proxCaract();
							  if(isdigit(a))
							  estado = 79;
							  
							  else{
							  	pontSeg = iniciolex;
							  	estado = inicia = falhouAutomato(inicia);
							  }
							  break;
							  
							  
							  case 79: a = proxCaract();
							  if(isdigit(a))
							  estado = 79;
							  
							  else{
							  	if(a == '\n')
							  	contLinha --;
							  	estado = 80;
							  	pontSeg --;
							  }
							  
							  break;
							  
							  case 80:
							  	t.tipo = 10;
							  	
							  	for(contAux = iniciolex; contAux<pontSeg; contAux++){
							  		
							  		t.lexema[pos] = vet[contAux];
							  		pos++;
								  }
								  
								  t.posicaoLex = contLinha;
								  iniciolex = pontSeg;
								  return t;
							
							
							//fim numero
							
							//inicio identificador
							case 81: a = proxCaract();
							
							if(islower(a) || isupper(a))
							estado = 82;
							
							else{
								pontSeg = iniciolex;
								estado = inicia = falhouAutomato(inicia);
							}
							break;
							
							
							case 82: a = proxCaract();
							if(islower(a) || isupper(a))
							estado = 82;
							
							else{
								
								if(a == '\n')
								contLinha --;
								estado = 83;
								pontSeg--;
							}
							break;
							
							
							case 83: a = proxCaract();
							if(isdigit(a))
							estado = 83;
							
							else{
								if(a == '\n')
								contLinha--;
								estado = 84;
								pontSeg--; 
							}
							break;
							
							case 84:
								t.tipo = 11;
								for(contAux = iniciolex; contAux<pontSeg; contAux++){
									t.lexema[pos] = vet[contAux];
									pos++;
								}
							
								  t.posicaoLex = contLinha;
								  iniciolex = pontSeg;
								  return t;
							   //fim sentenca
							   
							 	//inicio fim
							 	case 85: a = proxCaract();
							 	if(a == '\0')
							 	estado = 86;
							     	
							 	else{
							 		pontSeg = iniciolex;
							 		estado = inicia = falhouAutomato(inicia);
							 		
								 }
							 	
							 	 break;
							 	 
							 	 
							 	 case 86:
							 	 	t.tipo = 12;
							 	 	strcpy(t.lexema,"FEOF");
							 	 	t.posicaoLex = contLinha;
							 	 	iniciolex = pontSeg;
							 	 	return t;
							 	
						 
						 //fim leitura	
						 	//inicio erro
			 	               case 87:
			 	               	
			 	               	pontSeg++;
			 	               	t.tipo = 13;
			 	               	for(contAux = iniciolex; contAux<pontSeg; contAux++){
			 	               	 	  t.lexema[pos] = vet[contAux];
			 	               		  pos++;
			 	               		
									}
									
									t.posicaoLex = contLinha;
									iniciolex = pontSeg;
									return t;
			 
        	
     }
   }
}
	    		

	    	
