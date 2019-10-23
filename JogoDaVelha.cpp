/*
JOGO DA VELHA
AUTORES: KARIM HOMAISSI, GABRIEL OLIVEIRA E RICHARD COSTA
*/
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
	
		char matriz[3][3] = {}; // cria uma matriz global bidimensional(3x3) = 9 posicoes
		int resp, cont = 0, loop = 0;// variavel global resp, contador e loop
		
		void ImprimeDesenho(char matriz[3][3]) // função imprime desenho do jogo
		{		
			cout<<"\n"<<endl;
			cout<<"  0  1  2\n"<<endl;
			cout<<"0  "<<matriz[0][0]<<"|"<<matriz[0][1]<<"|"<<matriz[0][2]<<endl;
			cout<<"  -------"<<endl;
			cout<<"1  "<<matriz[1][0]<<"|"<<matriz[1][1]<<"|"<<matriz[1][2]<<endl;  
			cout<<"  -------"<<endl;  
			cout<<"2  "<<matriz[2][0]<<"|"<<matriz[2][1]<<"|"<<matriz[2][2]<<endl; 
		}
				
		void LimpaMatriz() // função limpa matriz
		{
				int i, j;
				for(i=0; i<3; i++)
				{
					for(j=0; j<3; j++)
					{
						matriz[i][j] = {};
					}
				}
		}
		
	
	void JogarNovamente()//jogar de novo
	{
			cout<<"Deseja jogar novamente ?? 1 - Sim 2 - Não"<<endl;
			cin>>resp;
			if(resp==1)
			{
				cont=0;
				LimpaMatriz();
				system("cls");
				
			}
			else
			{
			loop=1;
			}
	}
		
	void GanharHorizontal() // teste de ganho na horizontal
	{
		int i, j, x, y;
		for(i=0;i<3;i++)
		{
			x = 0;
			y = 0;
			
			for(j=0; j<3; j++)
			{	
				if((matriz[i][j]=='X' || matriz[i][j]=='x'))
				{
					x++;	
				}
				
				if((matriz[i][j]=='O' || matriz[i][j]=='o'))
				{
					y++;
				}
				
				if(x == 3)
				{
					cout<<endl<<"X GANHOU"<<endl<<endl;
					JogarNovamente();
				}
				
				if(y == 3)
				{
					cout<<endl<<"O GANHOU"<<endl<<endl;
					JogarNovamente();
				}
			}
		}
	}
		
	void GanharVertical() // teste de ganho na vertical
	{
		int i, j, x, y;
		for(i=0;i<3;i++)
		{
			x = 0;
			y = 0;
			
			for(j=0; j<3; j++)
			{	
				if((matriz[j][i]=='X' || matriz[j][i]=='x'))
				{
					x++;	
				}
				
				if((matriz[j][i]=='O' || matriz[j][i]=='o'))
				{
					y++;
				}
				
				if(x == 3)
				{
					cout<<endl<<"\nX GANHOU"<<endl<<endl;
					JogarNovamente();
				}
				
				if(y == 3)
				{
					cout<<endl<<"\nO GANHOU"<<endl<<endl;
					JogarNovamente();
				}
			}
		}
	}
	
	
	void GanharDiagonal() // teste de ganho diagonal
	{
		int i, x, y;
		x = 0;
		y = 0;
		for(i=0;i<3;i++)
		{
				
				if(matriz[i][i]=='X' || matriz[i][i] == 'x')
				{
					x++;	
				}
				
				if(matriz[i][i]=='O' || matriz[i][i] == 'o')
				{
					y++;
				}
				
				if(x == 3)
				{
					cout<<endl<<"\nX GANHOU"<<endl<<endl;
					JogarNovamente();
				}
				
				if(y == 3)
				{
					cout<<endl<<"\nO GANHOU"<<endl<<endl;
					JogarNovamente();
			}
		}
	}
	

	void GanharDiagonalEsq()
	{
		int j=2, z = 0 , y = 0;
		for(int i=0; i<3; i++)
		{
			if(matriz[i][j] == 'X' || matriz[i][j] == 'x')
			{
			y++;	
			}
			if(matriz[i][j] == 'O' || matriz[i][j] == 'o')
			{
			z++;	
			}
					
			if(y == 3)
			{
			cout<<"X GANHOU"<<endl;
			JogarNovamente();
			}
		
			if(z == 3)
			{
			cout<<"O GANHOU"<<endl;
			JogarNovamente();
			}		
			j--;
		}
	}
		
	
	int main()
	{
		
		SetConsoleTitle( "Jogo da Velha" ); // titulo do jogo
		system("color 02"); // cor das letras e do fundo do jogo
		int loop1 = 0, loop2 = 0, loop3 = 0, linha, coluna; // define os loops para forcar os digitos corretos, linha e coluna
		setlocale(LC_ALL, "Portuguese"); // Define como o padrão de imprimir o idioma Portugues
		ImprimeDesenho(matriz);//imprime o desenho do jogo da velha
		
		
		while(loop1 == 0) //força digitar um valor de linha correta
		{
		cout<<endl<<"\nDigite um valor para linha(0 - 2): ";
		cin>>linha;
			if(linha == 0 || linha == 1 || linha == 2)
			{
				loop1++;
			}
			else
			{
				cout<<endl<<"opção invalida\n"<<endl;
			}
		}
		
		
		while(loop2 == 0) //força digitar um valor de coluna correto
		{
		cout<<"Digite um valor para coluna(0 - 2): ";
		cin>>coluna;
		
			if(coluna == 0 || coluna == 1 || coluna == 2)
			{
				loop2++;
			}
		
			else
			{
				cout<<endl<<"opcão invalida\n"<<endl;
			}
		}
		
		
		if(matriz[linha][coluna] == 'X' || matriz[linha][coluna] == 'O' || matriz[linha][coluna] == 'x' || matriz[linha][coluna] == 'o')
		//se caso a matriz estiver anteriormente preenchida ele exibe uma mensagem
		{
		cout<<endl<<"essas posições ja estão preenchidas\n"<<endl;
		cout<<"-----------------------\n"<<endl;
		}
		
		
		else
		// senão.. ele pede para que o usuario insira um valor
		{
			while(loop3 == 0) //forca digitar o parametro correto (X ou O)
			{
				cout<<"Digite (X - O): ";
				cin>>matriz[linha][coluna];
					if(matriz[linha][coluna] == 'X' || matriz[linha][coluna] == 'O' || matriz[linha][coluna] == 'x' || matriz[linha][coluna] == 'o')
					//se caso a matriz tiver ou o valor X ou o valor O armazenado , exibe uma mensagem
					{
						cout<<endl<<"Armazenado na linha "<<linha<<" e coluna "<<coluna<<" com sucesso "<<endl;
						cout<<"--------------------------------------------\n"<<endl;
						cont++; // acrescenta 1 ao contador
						loop3++; // encerra o loop3
					}
					else
					//senão.. exibe mensagem de opção invalida
					{
						cout<<endl<<"opção invalida\n"<<endl;
					}
			}
		}
		
		
		//maneiras x e y de se ganhar na horizontal e vertical
		GanharHorizontal();//invoca função de teste
		GanharVertical();//invoca função de teste
		GanharDiagonal();//invoca função de teste
		GanharDiagonalEsq();//invoca função de teste
		
		
		if(cont == 9) // se o contador contar 9 posicoes ja armazenadas ele quebra o loop principal e encerra o programa
		{
			cout<<endl<<"DEU VELHA\n"<<endl;
			JogarNovamente();
		}
		
		else
		{
			return main();
		}
		
		return 0; //retorna 0 da funcao principal (main)	
} //fim main
