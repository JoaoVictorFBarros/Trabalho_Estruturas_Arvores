#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>
#include "AVL.hpp"
#include "RubroNegra.hpp"
#include "binaria.hpp"
using namespace std;

int main (){
	setlocale(LC_ALL,"portuguese");
	avl* t = NULL;
	RN* r = NULL;
	binary* b = NULL;
	short op=0;
	string type;
	while(op != 5){		
		data input;
		system("cls");
		cout<<"Digite:\n1: Inserir valores\n2: Testar desempenho em buscas\n3: Imprimir árvore\n4: Testar todas as estruturas\n5: Sair\n\nOperação: ";
		cin>>op;
		
		switch (op){
			case 1:{
				char nome[100];
				cout<<"Digite o tipo da árvore: ";
				cin>>type;
				cout<<"Digite o nome do arquivo: ";
				cin>>nome;
				FILE *f;
				f = fopen(nome,"r");
				if (f == NULL){
					cout<<"Arquivo inexistente.\n\n";
				}
				else{
					cout<<"\n\nProcessando...\n";
					clock_t timer = clock();
					char dados[2000000];			
					fgets(dados,2000000,f);
					char *token;
					token = strtok (dados,"/");
					vector <string> valuesS;
					
					while (token != NULL){			    				    	
				    	if (token != NULL){
				    		valuesS.push_back(token);
						}
						token = strtok (NULL, "/");					    	
				  	}
				  	data d;
				  	
				  	if (type == "avl"){
				  		for (int i=0;i<valuesS.size();i++){						
							d.value = stod(valuesS[i]);
							insert(&t,d);
						} 
					}
					else if (type == "rn"){
						for (int i=0;i<valuesS.size();i++){					
							d.value = stod(valuesS[i]);						
							insert(&r,NULL,d);
						} 
					}
					else if (type == "binary"){
						for (int i=0;i<valuesS.size();i++){					
							d.value = stod(valuesS[i]);						
							insert(&b,d);
						} 
					}
				  	
					
					timer = clock() - timer; 
					cout<<"Operação concluída em "<<(float)timer/CLOCKS_PER_SEC<<" Segundos \n\n";
				}				
							
				fclose(f);
				break;
			}
			
			case 2:{
				char nome[100];
				cout<<"Digite o nome do arquivo: ";
				cin>>nome;
				FILE *f;
				f = fopen(nome,"r");
				if (f == NULL){
					cout<<"Arquivo inexistente.\n\n";
				}
				else{
					cout<<"\n\nProcessando...\n";
					char dados[2000000];			
					fgets(dados,2000000,f);
					char *token;
					token = strtok (dados,"/");
					vector <string> valuesS;
					
					while (token != NULL){			    				    	
				    	if (token != NULL){
				    		valuesS.push_back(token);
						}
						token = strtok (NULL, "/");					    	
				  	}				  	
				  	data d;
				  	clock_t timer = clock();
				  	if (type == "avl"){
				  		for (int i=0;i<valuesS.size();i++){
							int aux = valuesS.size()/10;				
							d.value = stod(valuesS[i]);
							search(&t,d);
						}
					}
					else if (type == "rn"){
						for (int i=0;i<valuesS.size();i++){
							int aux = valuesS.size()/10;				
							d.value = stod(valuesS[i]);
							search(&r,d);
						}
					}
					else if (type == "binary"){
						for (int i=0;i<valuesS.size();i++){
							int aux = valuesS.size()/10;				
							d.value = stod(valuesS[i]);
							search(&b,d);
						}
					}
					
					timer = clock() - timer;
					cout<<"Busca concluída em "<<(float)timer/CLOCKS_PER_SEC<<" Segundos.\n\n";
				}
				break;
			}
			case 3:{
				cout<<"\nImprimindo em ordem\n";
				
				if (type == "avl"){
					printAvl(t);
				}
				else if (type == "rn"){
					printRN(r);
				}
				else if (type == "binary"){
					printBinary(b);
				}
				
				
				cout<<"\n\n";
				break;
			}
			case 4:{
				int qtdeTestes;
				int cont = 0;
				
				cout<<"Digite a quantidade de testes: ";
				cin>>qtdeTestes;
				
				cout<<"\nTeste para 1000 entradas: \n\n";
						
				FILE *f;
				char ref[100] = "ValoresGerados-Mil.txt";
				
				TESTE_I:
				f = fopen(ref,"r");
				if (f == NULL){
					cout<<"Arquivo inexistente.\n\n";
				}
				else{
					char dados[2000000];			
					fgets(dados,2000000,f);
					char *token;
					token = strtok (dados,"/");
					vector <string> valuesS;
					
					while (token != NULL){			    				    	
				    	if (token != NULL){
				    		valuesS.push_back(token);
						}
						token = strtok (NULL, "/");					    	
				  	}				  	
				  	data d;
					double media,soma = 0;
					for (int i=0;i<qtdeTestes;i++){
						clock_t timer = clock();
					  	for (int j=0;j<valuesS.size();j++){						
							d.value = stod(valuesS[j]);
							insert(&t,d);
						}
						timer = clock() - timer;
						double time =  (double)timer/CLOCKS_PER_SEC;
						soma = soma + time;
						t = NULL;
					}
					media = soma/qtdeTestes;
					cout<<"tempo médio de inserção AVL: "<<media<<" s\n";
					soma = 0;
					for (int i=0;i<qtdeTestes;i++){
						clock_t timer = clock();
						for (int j=0;j<valuesS.size();j++){					
							d.value = stod(valuesS[j]);						
							insert(&r,NULL,d);
						}
						timer = clock() - timer;
						double time =  (double)timer/CLOCKS_PER_SEC;
						soma = soma + time;
						r = NULL;
					}
					media = soma/qtdeTestes;
					cout<<"tempo médio de inserção Rubro Negra: "<<media<<" s\n";
					soma = 0;
					for (int i=0;i<qtdeTestes;i++){
						clock_t timer = clock();
						for (int j=0;j<valuesS.size();j++){					
							d.value = stod(valuesS[j]);						
							insert(&b,d);
						} 
						timer = clock() - timer;
						double time =  (double)timer/CLOCKS_PER_SEC;
						soma = soma + time;
						b = NULL;
					}
					media = soma/qtdeTestes;
					cout<<"tempo médio de inserção binária: "<<media<<" s\n";
					cont++;
					soma = 0;
				}
				
				if (cont == 1){
					cout<<"\n\nTeste para 10 mil entradas: \n\n";
					string aux = "ValoresGerados-Dez_Mil.txt";
					for (int i=0;i<aux.length();i++){
						ref[i] = aux[i];
					}
					cont++;
					goto TESTE_I;	
				}
				if (cont == 3){
					cout<<"\n\nTeste para 1 milhão de entradas: \n\n";
					string aux = "ValoresGerados-1Milhao.txt";
					for (int i=0;i<aux.length();i++){
						ref[i] = aux[i];
					}
					cont++;
					goto TESTE_I;	
				}

				cout<<"\n\n";
				
				for (int i=0;i<100;i++){
					ref[i] = '\0';
				}
				cont=0;
				cout<<"\nTeste busca 5000 itens: \n\n";
				
				string aux = "Busca-5Mil.txt";
				
				for (int i=0;i<aux.length();i++){
					ref[i] = aux[i];
				}
				
				TESTE_S:
				f = fopen(ref,"r");
				
				if (f == NULL){
					cout<<"Arquivo inexistente.\n\n";
				}
				
				char dados[2000000];			
				fgets(dados,2000000,f);
				char *token;
				token = strtok (dados,"/");
				vector <string> valuesS;
					
				while (token != NULL){			    				    	
			    	if (token != NULL){
			    		valuesS.push_back(token);
					}
					token = strtok (NULL, "/");					    	
			  	}				  	
			  	data d;
				double media,soma = 0;
				
				for (int i=0;i<qtdeTestes;i++){
					clock_t timer = clock();
					for (int j=0;j<valuesS.size();j++){						
						d.value = stod(valuesS[j]);
						search(&t,d);
					}
					timer = clock() - timer;
					double time =  (double)timer/CLOCKS_PER_SEC;
					soma = soma + time;
					t = NULL;
				}
				media = soma/qtdeTestes;
				cout<<"tempo médio de busca AVL: "<<media<<" s\n";
				soma = 0;
				for (int i=0;i<qtdeTestes;i++){
					clock_t timer = clock();
					for (int j=0;j<valuesS.size();j++){					
						d.value = stod(valuesS[j]);						
						search(&r,d);
					}
					timer = clock() - timer;
					double time =  (double)timer/CLOCKS_PER_SEC;
					soma = soma + time;
					r = NULL;
				}
				media = soma/qtdeTestes;
				cout<<"tempo médio de busca Rubro Negra: "<<media<<" s\n";
				soma = 0;
				for (int i=0;i<qtdeTestes;i++){
					clock_t timer = clock();
					for (int j=0;j<valuesS.size();j++){					
						d.value = stod(valuesS[j]);						
						insert(&b,d);
					} 
					timer = clock() - timer;
					double time =  (double)timer/CLOCKS_PER_SEC;
					soma = soma + time;
					b = NULL;
				}
				media = soma/qtdeTestes;
				cout<<"tempo médio de busca binária: "<<media<<" s\n";
				cont++;	
				soma = 0;
				
				if (cont == 1){
					cout<<"\n\nTeste busca 10 Mil itens: \n\n";
					string aux = "Busca-10Mil.txt";
					for (int i=0;i<aux.length();i++){
						ref[i] = aux[i];
					}
					cont++;
					goto TESTE_S;	
				}
				if (cont == 3){
					cout<<"\n\nTeste busca 100 Mil itens: \n\n";
					string aux = "Busca-100Mil.txt";
					for (int i=0;i<aux.length();i++){
						ref[i] = aux[i];
					}
					cont++;
					goto TESTE_S;	
				}
				cout<<"\n\n";
				break;
										
			}
		}
		if (op != 5){
			system("pause");	
		}
	}	
	return 0;
}
