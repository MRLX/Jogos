#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<conio.c>
#define jog1 8
#define jog2 7

int flag[16],flag2[16];
void jogadores();
void exclusao2(int horizontal,int vertical);
void exclusao1(int horizontal,int vertical);
void comparacao1();
void comparacao2();
void movimentacao2();
void movimentacao1();
int cont=0,cont2=0;
int tabuleiro [8][8]= {{ 0,  1,  2,  3,  4,  5,  6,  7}, 
                        {1,  0,  1,  1,  0,  1,  1,  0},
                        {2,  1,  0,  1,  0,  1,  0,  1},
                        {3,  1,  1,  0,  0,  0,  1,  1},
                        {4,  0,  0,  0,  1,  0,  0,  0},
                        {5,  1,  1,  0,  0,  0,  1,  1},
                        {6,  1,  0,  1,  0,  1,  0,  1},
                        {7,  0,  1,  1,  0,  1,  1,  0}};
void mostratabuleiro()
{
	int i,j;
	textcolor(1);
	printf("\t\t\t\tTABULEIRO\n\n");
    textcolor(14);
    printf("\n\t\t\t===================================");
    printf("\n\n");
	                       
    for(i = 0; i <= 7; i++){
    	printf("\n");
    	for(j = 0; j <= 7; j++){ // condições para impressão colorida.
    		if(i == 0 && j == 0 || i == 0 && j == 1 || i == 0 && j == 2 || i == 0 && j == 3 || i == 0 && j == 4 || i == 0 && j == 5 || i == 0 && j == 6 || i == 0 && j == 7 || i == 1 && j == 0 || i == 2 && j == 0 || i == 3 && j == 0 || i == 4 && j == 0 || i == 5 && j == 0 || i == 6 && j == 0 || i == 7 && j == 0){
    			textcolor(10); // Verde Claro. Indica as orientaçãoes (guias) das posições das peças horizontalmente ou verticalmente.
    			printf("\t%d",tabuleiro [i][j]);
    			textcolor(15); // Branco Brilhante
			}
			if (i == 1 && j == 1 || i == 1 && j == 4|| i == 1 && j == 7 || i == 2 && j == 2 || i == 2 && j == 4 || i == 2 && j == 6 || i == 3 && j == 3 || i == 3 && j == 4|| i == 3 && j == 5 || i == 4 && j == 1 || i == 4 && j == 2|| i == 4 && j == 3 || i == 4 && j == 5 || i == 4 && j == 6|| i == 4 && j == 7 || i == 5 && j == 3 || i == 5 && j == 4|| i == 5 && j == 5 || i == 6 && j == 2 || i == 6 && j == 4|| i == 6 && j == 6 || i == 7 && j == 1 || i == 7 && j == 4|| i == 7 && j == 7){
				textcolor(15); // Branco. Indica as posições corretas para se posicionar cada peça.
    			printf("\t%d",tabuleiro[i][j]);
    			textcolor(15);	
			}
			if (i == 1 && j == 2 || i == 1 && j == 3|| i == 1 && j == 5 || i == 1 && j == 6 || i == 2 && j == 1 || i == 2 && j == 3 || i == 2 && j == 5 || i == 2 && j == 7|| i == 3 && j == 1 || i == 3 && j == 2 || i == 3 && j == 6|| i == 3 && j == 7 || i == 4 && j == 4 || i == 5 && j == 1|| i == 5 && j == 2 || i == 5 && j == 6 || i == 5 && j == 7|| i == 6 && j == 1 || i == 6 && j == 3 || i == 6 && j == 5|| i == 6 && j == 7 || i == 7 && j == 2 || i == 7 && j == 3|| i == 7 && j == 5 || i == 7 && j == 6){
				textcolor(0); //Preto. Algumas posições não aparecem devido a cor ser identica ao do fundo. Isse se deve para melhor desenho do tabuleiro.
    			printf("\t%d",tabuleiro[i][j]);
    			textcolor(15);
			}
        }
        printf("\n");
	}
}

void zeraflag2()
{
	int i;
	for(i=0;i<16;i++)
	{
		flag2[i]=0;
	}
}

void zeraflag()
{
	int i;
	for(i=0;i<16;i++)
	{
		flag[i]=0;
	}
}
                        
void posicaotabuleiro(int horizontal,int vertical)
{
	if(tabuleiro[horizontal][vertical]==0)
		tabuleiro[horizontal][vertical]=jog1;
}

void posicaotabuleiro2(int horizontal,int vertical)
{
	if(tabuleiro[horizontal][vertical]==0)
		tabuleiro[horizontal][vertical]=jog2;
		
}

void checatabuleiro2()
{
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(tabuleiro[i][j]==jog2)
				cont2++;
		}
	}
	if(cont2==2)
	{
		system("cls");
		printf("JOGADOR 1 VENCEUUUU UHUUUUULLL\n");
	}
	else
		cont2=0;
}

void checatabuleiro1()
{
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(tabuleiro[i][j]==jog1)
				cont++;
		}
	}
	if(cont==2)
	{
		system("cls");
		printf("JOGADOR 2 VENCEU UHUUUUUUL\n");
	}
	else
		cont=0;
}

void jogadores()
{
	int g,position1,vertical1,position2,vertical2;
	for(g=0;g<9;g++)
	{
		printf("Digite sua posicao horizontal jogador 1 \n");
		scanf("%d",&position1);
		printf("Digite a vertical jogador 1 \n");
		scanf("%d",&vertical1);
		while(tabuleiro[position1][vertical1]!=0||position1<1||position1>7||vertical1<1||vertical1>7)
		{
			printf("Posicao invalida. Digite novamente\n");
			printf("Digite sua posicao horizontal jogador 1\n");
			scanf("%d",&position1);
			printf("Digite a vertical jogador 1\n");
			scanf("%d",&vertical1);
		}
		posicaotabuleiro(position1,vertical1);
		system("cls");
		comparacao1();
		mostratabuleiro();
		//---------------------------------------jogador2----------------------
		printf("Digite sua posicao horizontal jogador 2\n");
		scanf("%d",&position2);
		printf("Digite a vertical jogador 2\n");
		scanf("%d",&vertical2);
		while(tabuleiro[position2][vertical2]!=0||position2<1||position2>7||vertical2<1||vertical2>7)
		{
			printf("Posicao invalida. Digite novamente\n");
			printf("Digite sua posicao horizontal jogador 2\n");
			scanf("%d",&position2);
			printf("Digite a vertical jogador 2\n");
			scanf("%d",&vertical2);
		}
		posicaotabuleiro2(position2,vertical2);
		system("cls");
		comparacao2();
		mostratabuleiro();
		if(g==8)
		{
			zeraflag();
			zeraflag2();
			while(cont!=2||cont2!=2)
			{
				movimentacao1();
				checatabuleiro1();
				comparacao1();
				checatabuleiro1();
				system("cls");
				mostratabuleiro();
				movimentacao2();
				checatabuleiro2();
				comparacao2();
				checatabuleiro2();
				system("cls");
				mostratabuleiro();
			}
		}
		
		
	}
	
}

void movimentacao1()
{
	int horizontal,vertical,horizontal1,vertical1;
	printf("Jogador 1 digite a posicao horizontal da peca que deseja mover\n");
	scanf("%d",&horizontal);
	printf("Agora digite a posicao vertical\n");
	scanf("%d",&vertical);
	while(tabuleiro[horizontal][vertical]!=jog1)
	{
		printf("Posicao invalida. Digite novamente a posicao horizontal que deseja mover\n");
		scanf("%d",&horizontal);
		printf("Agora digite a posicao vertical\n");
		scanf("%d",&vertical);
		
	}
	if(tabuleiro[horizontal][vertical]==jog1)
	{
		printf("Agora digite a posicao que deseja movimentar a peca. Lembrando que voce so pode movimentar para as posicoes proximas\n");
		printf("Jogador 1 digite a posicao horizontal\n");
		scanf("%d",&horizontal1);
		printf("Agora digite a vertical\n");
		scanf("%d",&vertical1);
		while(tabuleiro[horizontal1][vertical1]!=0)
		{
			system("cls");
			mostratabuleiro();
			printf("Posicao invalida. Digite novamente\n");
			printf("Jogador 1 digite a posicao horizontal\n");
			scanf("%d",&horizontal1);
			printf("Agora digite a vertical\n");
			scanf("%d",&vertical1);
			
		}
		if(tabuleiro[horizontal1][vertical1]==0)
		{
			tabuleiro[horizontal1][vertical1]=jog1;
			tabuleiro[horizontal][vertical]=0;
		}
	}	
}

void movimentacao2()
{
	int horizontal,vertical,horizontal2,vertical2;
	printf("Jogador 2 digite a posicao horizontal da peca que deseja mover\n");
	scanf("%d",&horizontal);
	printf("Agora digite a posicao vertical\n");
	scanf("%d",&vertical);
	while(tabuleiro[horizontal][vertical]!=jog2)
	{
		printf("Posicao invalida. Digite novamente a posicao horizontal que deseja mover\n");
		scanf("%d",&horizontal);
		printf("Agora digite a posicao vertical\n");
		scanf("%d",&vertical);
		
	}
	if(tabuleiro[horizontal][vertical]==jog2)
	{
		printf("Agora digite a posicao que deseja movimentar a peca. Lembrando que voce so pode movimentar para as posicoes proximas\n");
		printf("Jogador 2 digite a posicao horizontal\n");
		scanf("%d",&horizontal2);
		printf("Agora digite a vertical\n");
		scanf("%d",&vertical2);
		while(tabuleiro[horizontal2][vertical2]!=0)
		{
			system("cls");
			mostratabuleiro();
			printf("Posicao invalida. Digite novamente\n");
			printf("Jogador 2 digite a posicao horizontal\n");
			scanf("%d",&horizontal2);
			printf("Agora digite a vertical\n");
			scanf("%d",&vertical2);
		}
		if(tabuleiro[horizontal2][vertical2]==0)
		{
			tabuleiro[horizontal2][vertical2]=jog2;
			tabuleiro[horizontal][vertical]=0;
		}
	}
		
}

void comparacao2()
{
	int i,flag[10],horiz,vertic;
	 if((tabuleiro[4][1]==jog2)&&(tabuleiro[4][2]==jog2)&&(tabuleiro[4][3]==jog2))
			{
					flag2[0]+=1;
			}
	else if((tabuleiro[3][3]==jog2)&&(tabuleiro[4][3]==jog2)&&(tabuleiro[5][3]==jog2))
			{
					flag2[1]+=1;
			}
	else if((tabuleiro[1][4]==jog2)&&(tabuleiro[2][4]==jog2)&&(tabuleiro[3][4]==jog2))
			{
					flag2[2]+=1;
			}
	else if((tabuleiro[5][4]==jog2)&&(tabuleiro[6][4]==jog2)&&(tabuleiro[7][4]==jog2))
			{
					flag2[3]+=1;
			}
	else if((tabuleiro[3][5]==jog2)&&(tabuleiro[4][5]==jog2)&&(tabuleiro[5][5]==jog2))
			{
					flag2[4]+=1;
			}
	else if((tabuleiro[4][5]==jog2)&&(tabuleiro[4][6]==jog2)&&(tabuleiro[4][7]==jog2))
			{
					flag2[5]+=1;
			}
	else if((tabuleiro[1][4]==jog2)&&(tabuleiro[1][1]==jog2)&&(tabuleiro[1][7]==jog2))
		{
			flag2[6]+=1;
		}
	else if((tabuleiro[1][1]==jog2)&&(tabuleiro[4][1]==jog2)&&(tabuleiro[7][1]==jog2))
		{
			flag2[7]+=1;
		}		
	else if((tabuleiro[7][1]==jog2)&&(tabuleiro[7][4]==jog2)&&(tabuleiro[7][7]==jog2))
		{
			flag2[8]+=1;
		}
	else if((tabuleiro[1][7]==jog2)&&(tabuleiro[4][7]==jog2)&&(tabuleiro[7][7]==jog2))
		{
			flag2[9]+=1;
		}
	else if((tabuleiro[2][2]==jog2)&&(tabuleiro[4][2]==jog2)&&(tabuleiro[6][2]==jog2))
		{
			flag2[10]+=1;
		}
	else if((tabuleiro[2][6]==jog2)&&(tabuleiro[4][6]==jog2)&&(tabuleiro[6][6]==jog2))
		{
			flag2[11]+=1;
		}
	else if((tabuleiro[2][2]==jog2)&&(tabuleiro[2][4]==jog2)&&(tabuleiro[2][6]==jog2))
		{
			flag2[12]+=1;
		}
	else if((tabuleiro[6][2]==jog2)&&(tabuleiro[6][4]==jog2)&&(tabuleiro[6][6]==jog2))
		{
			flag2[13]+=1;
		}
	else if((tabuleiro[3][3]==jog2)&&(tabuleiro[3][4]==jog2)&&(tabuleiro[3][5]==jog2))
		{
			flag2[14]+=1;
		}
	else if((tabuleiro[5][3]==jog2)&&(tabuleiro[5][4]==jog2)&&(tabuleiro[5][5]==jog2))
		{
			flag2[15]+=1;
		}
	
	for(i=0;i<16;i++)
	{
		if(flag2[i]==1)
		{
			system("cls");
			mostratabuleiro();
			printf("OBAAAAAAA TRILHAAAAAAAAAAA\n");
			printf("Jogadador 2 digite a posicao horizontal da peca do jogador 1 que deseja excluir\n");
			scanf("%d",&horiz);
			printf("Agora digite a vertical\n ");
			scanf("%d",&vertic);
			system("cls");
			while(tabuleiro[horiz][vertic]==0||horiz<1||horiz>7||vertic<1||vertic>7||tabuleiro[horiz][vertic]==1||tabuleiro[horiz][vertic]==jog2)
			{
				printf("Posicao invalida. Digite novamente\n");
				printf("Digite a posicao horizontal do jogador 1 da peca que deseja excluir \n");
				scanf("%d",&horiz);
				printf("Digite a vertical jogador 2 da peca a excluir \n");
				scanf("%d",&vertic);
				system("cls");
			}
			exclusao2(horiz,vertic);
		}
	}
}

void exclusao1(int horizontal,int vertical)
{
	if(tabuleiro[horizontal][vertical]==jog2)
		tabuleiro[horizontal][vertical]=0;
				
}

void exclusao2(int horizontal,int vertical)
{
	if(tabuleiro[horizontal][vertical]==jog1)
		tabuleiro[horizontal][vertical]=0;
}

void comparacao1()
{
	int i,horiz,vertic;
	if((tabuleiro[4][1]==jog1)&&(tabuleiro[4][2]==jog1)&&(tabuleiro[4][3]==jog1))
			{
					flag[0]+=1;
			}
	else if((tabuleiro[3][3]==jog1)&&(tabuleiro[4][3]==jog1)&&(tabuleiro[5][3]==jog1))
			{
					flag[1]+=1;
			}
	else if((tabuleiro[1][4]==jog1)&&(tabuleiro[2][4]==jog1)&&(tabuleiro[3][4]==jog1))
			{
					flag[2]+=1;
			}
	else if((tabuleiro[5][4]==jog1)&&(tabuleiro[6][4]==jog1)&&(tabuleiro[7][4]==jog1))
			{
					flag[3]+=1;
			}
	else if((tabuleiro[3][5]==jog1)&&(tabuleiro[4][5]==jog1)&&(tabuleiro[5][5]==jog1))
			{
					flag[4]+=1;
			}
	else if((tabuleiro[4][5]==jog1)&&(tabuleiro[4][6]==jog1)&&(tabuleiro[4][7]==jog1))
			{
					flag[5]+=1;
			}
	else if((tabuleiro[1][4]==jog1)&&(tabuleiro[1][1]==jog1)&&(tabuleiro[1][7]==jog1))
		{
			flag[6]+=1;
		}
	else if((tabuleiro[1][1]==jog1)&&(tabuleiro[4][1]==jog1)&&(tabuleiro[7][1]==jog1))
		{
			flag[7]+=1;
		}		
	else if((tabuleiro[7][1]==jog1)&&(tabuleiro[7][4]==jog1)&&(tabuleiro[7][7]==jog1))
		{
			flag[8]+=1;
		}
	else if((tabuleiro[1][7]==jog1)&&(tabuleiro[4][7]==jog1)&&(tabuleiro[7][7]==jog1))
		{
			flag[9]+=1;
		}
		else if((tabuleiro[2][2]==jog1)&&(tabuleiro[4][2]==jog1)&&(tabuleiro[6][2]==jog1))
		{
			flag[10]+=1;
		}
	else if((tabuleiro[2][6]==jog1)&&(tabuleiro[4][6]==jog1)&&(tabuleiro[6][6]==jog1))
		{
			flag[11]+=1;
		}
	else if((tabuleiro[2][2]==jog1)&&(tabuleiro[2][4]==jog1)&&(tabuleiro[2][6]==jog1))
		{
			flag[12]+=1;
		}
	else if((tabuleiro[6][2]==jog1)&&(tabuleiro[6][4]==jog1)&&(tabuleiro[6][6]==jog1))
		{
			flag[13]+=1;
		}
	else if((tabuleiro[3][3]==jog1)&&(tabuleiro[3][4]==jog1)&&(tabuleiro[3][5]==jog1))
		{
			flag[14]+=1;
		}
	else if((tabuleiro[5][3]==jog1)&&(tabuleiro[5][4]==jog1)&&(tabuleiro[5][5]==jog1))
		{
			flag[15]+=1;
		}
	for(i=0;i<16;i++)
	{
		if(flag[i]==1)
		{
			system("cls");
			mostratabuleiro();
			printf("OBAAAAAAA TRILHAAAAAAAAAAA\n");
			printf("Jogadador 1 digite a posicao horizontal da peca do jogador 2 que deseja excluir\n");
			scanf("%d",&horiz);
			printf("Agora digite a vertical\n ");
			scanf("%d",&vertic);
			system("cls");
			while(tabuleiro[horiz][vertic]==0||horiz<1||horiz>7||vertic<1||vertic>7||tabuleiro[horiz][vertic]==1||tabuleiro[horiz][vertic]==jog1)
			{
				printf("Posicao invalida. Digite novamente\n");
				printf("Digite a posicao horizontal do jogador 2 a peca que deseja excluir \n");
				scanf("%d",&horiz);
				printf("Digite a vertical jogador 1 \n");
				scanf("%d",&vertic);
				system("cls");
			}
			exclusao1(horiz,vertic);
		}
	}
}
                 

int main(){
	int opcao;
	
	textcolor(11);
	printf("\n\t################JOGO DE TRILHA#######################\n");
	printf("\n\n");
	textcolor(12);
	printf("O jogador 1 sera representado pelo numero 8\n");
	printf("\n");
	textcolor(13);
	printf("O jogador 2 sera representado pelo numero 7\n");
	textcolor(14);
	printf("\nO jogo consiste em movimentar as pecas pelos 0's e formar as trilhas\n");
	printf("\n\n");
	textcolor(15);
	printf("Digite 1 para jogar 2 para sair\n");
	scanf("%d",&opcao);
	switch(opcao)
	{
		case 1:
			system("cls");
			zeraflag();
			zeraflag2();
			mostratabuleiro();
			jogadores();
			break;
		case 2:
			printf("TCHAUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU\n");
			exit(0);
		default:
			printf("Opcao invalida digite novamente\n");
			while(opcao!=1||opcao!=2)
			{
				scanf("%d",&opcao);
			}
	}
	
	
	return 0;
}
