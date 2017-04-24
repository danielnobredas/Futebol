#include <stdio.h>
#include <stdlib.h>

int main()

{
	int j,i,n,m;
	//int m,i,j,n,k;
	printf("SELECIONE A QUANTIDADE DE TIMES: \n");
	scanf("%d",&n);
	int PG,GM,S,V,GA,gol1,gol2;
	//char **time,*time1,*time2,**clas;
	int **tabela;
	char **times,**result,*time1,*time2;
	// ZERAR TABELA 
	tabela=(int**)calloc(n,sizeof(int*));
	times=(char**)calloc(n,sizeof(char*));

	// RECEBE OS NOMES E OS GUARDA
	for(i=0;i<n;i++){
	times[i]=(char*)calloc(7,sizeof(char));
	printf("NOME DO TIME NUMERO %d: \n", i+1);
	scanf("%s",&times[i][0]);
	}
	//for(i=0;i<n;i++) printf("\n%s\n",times[i]);
	
	printf("SELECIONE A QUANTIDADE DE JOGOS: \n");
	scanf("%d",&m);
	time1=(char*)calloc(1,sizeof(char));
	time2=(char*)calloc(1,sizeof(char));
	for(i=0;i<m;i++){
		printf("%d° JOGO\n", i+1);
		scanf("%s %s %d %d",&time1,&time2,&gol1,&gol2);
		for(j=0;j<n;j++){
		if (strcmp(time1,times[j])==0)
		{
			printf("EH NOIS\n");	
		}}

	}
	// RECEBE OS NOMES E OS GUARDA
	/*
	for (i = 0; i < n; i++)
	{	
		printf("NOME DO TIME NUMERO %d: \n", i+1);
		scanf("%s",&time[i][0]);
		tabela[i][0]=i;
	}
	// RECEBE A QUANTIDADE DE JOGOS E GUARDA O RESULTADO
	printf("SELECIONE A QUANTIDADE DE JOGOS: \n");
	scanf("%d",&m);
	for (i = 0; i < m; i++)
	{	
		printf("%do JOGO\n", i+1);
		scanf("%s %s %d %d",&time1,&time2,&gol1,&gol2);
		for (j = 0; j < n; j++)
		{	
			// COMPARA OS NOMES DOS TIMES COM OS DA TABELA
			if (strcmp(time1,time[j])==0)
			{
				// ADICIONA OS GOLS MARCADOS NA TABELA 
				if (gol1>gol2)
				{
					tabela[j][1]+=3;
					tabela[j][5]++;
				}else if(gol1==gol2){
					tabela[j][1]+=1;
				}
				tabela[j][2]+=gol1;
				tabela[j][3]+=gol2;

			}
			if (strcmp(time2,time[j])==0)
			{
				if (gol1<gol2)
				{
					tabela[j][1]+=3;
					tabela[j][5]++;
				}else if(gol1==gol2){
					tabela[j][1]+=1;
				}
				tabela[j][2]+=gol2;
				tabela[j][3]+=gol1;
			}
		}
	}
	// CALCULA E ADICIONA OS PONTOS NA TABELA
	for(i=0;i<n;i++){
	tabela[i][4]=tabela[i][2]-tabela[i][3];
	if(tabela[i][3]!=0){
	tabela[i][6]=tabela[i][2]/tabela[i][3];		
		}
	}

	// REORGANIZA OS TIMES DE ACORDO COM A PONTUAÇÃO
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if (tabela[j][1]>tabela[k][1])
				{
					result[i][7]=tabela[j];
					clas[i]=time[j];
				}
			}
		}
	printf("%s\n",clas[i]);
	}*/

	// IMPRIME A CLASSIFICAÇÃO DOS TIMES 

	//printf("%s %d pontos. Gols marcados = %d Vitorias %d\n", time[i],tabela[i][1],tabela[i][2],tabela[i][5]);
    return 0;

}