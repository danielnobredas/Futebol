#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()

{
	int j,i,n,m;
	//int m,i,j,n,k;
	/* 
	
	[0]=PG
	[1]=GM
	[2]=GS
	[3]=S(SALDO)
	[4]=V(VITORIAS)
	[5]=GA(GM/GS)
	[6]=E(EMPATE)
	[7]=J(JOGOS)
	[8]=AP(APROVEITAMENTO)

	*/
	printf("SELECIONE A QUANTIDADE DE TIMES: \n");
	scanf("%d",&n);
	int *E,*PG,*GM,*S,*V,*GA,*GS,gol1,gol2,*J;
	FILE *jogo = fopen("jogo.txt","a");
	//char **time,*time1,*time2,**clas;
	int **tabela;
	char **times,**result,*time1,*time2;
	// ZERAR TABELA 
	tabela=(int**)calloc(n,sizeof(int*));
	times=(char**)calloc(n,sizeof(char*));
	PG=(int*)calloc(n,sizeof(int));
	GM=(int*)calloc(n,sizeof(int));
	GS=(int*)calloc(n,sizeof(int));
	S =(int*)calloc(n,sizeof(int));
	V =(int*)calloc(n,sizeof(int));
	GA=(int*)calloc(n,sizeof(int));
	E =(int*)calloc(n,sizeof(int));

	// RECEBE OS NOMES E OS GUARDA
	for(i=0;i<n;i++){
	times[i]=(char*)calloc(30,sizeof(char));
	tabela[i]=(int*)calloc(10,sizeof(int));
	printf("NOME DO TIME NUMERO %d: \n", i+1);
	scanf("%s",&times[i][0]);
	}
	//for(i=0;i<n;i++) printf("\n%s\n",times[i]);
	
	printf("SELECIONE A QUANTIDADE DE JOGOS: \n");
	scanf("%d",&m);
	time1=(char*)calloc(30,sizeof(char));
	time2=(char*)calloc(30,sizeof(char));
	for(i=0;i<m;i++){
		printf("%d° JOGO\n", i+1);
		scanf("%s %s %d %d",time1,time2,&gol1,&gol2);
		fprintf(jogo,"%s %s %d %d\n", time1,time2,gol1,gol2);
		for(j=0;j<n;j++){
		if (strcmp(time1,times[j])==0)
		{
			if(gol1>gol2){
				tabela[j][0]+=3;
				tabela[j][1]+=gol1;
				tabela[j][2]+=gol2;
				tabela[j][4]++;
				tabela[j][7]++;
			}else if(gol1==gol2){
				tabela[j][0]+=1;
				tabela[j][1]+=gol1;
				tabela[j][2]+=gol2;
				tabela[j][6]++;
				tabela[j][7]++;
			
			}else if(gol1<gol2){
				tabela[j][1]+=gol1;
				tabela[j][2]+=gol2;
				tabela[j][7]++;
			}
		}
		if (strcmp(time2,times[j])==0)
		{
			if(gol2>gol1){
				tabela[j][0]+=3;
				tabela[j][1]+=gol2;
				tabela[j][2]+=gol1;
				tabela[j][4]++;
				tabela[j][7]++;
			}else if(gol1==gol2){
				tabela[j][0]+=1;
				tabela[j][1]+=gol2;
				tabela[j][2]+=gol1;
				tabela[j][6]++;
				tabela[j][7]++;
			
			}else if(gol2<gol1){
				tabela[j][1]+=gol2;
				tabela[j][2]+=gol1;
				tabela[j][7]++;
			}			
		}
	}
	}
	for(j=0;j<n;j++) fprintf(stdout,"%15s PG:%d GM:%d GS:%d SALDO:%d JOGOS:%d EMPATE:%d VITORIAS:%d\n", times[j],tabela[j][0],tabela[j][1],tabela[j][2],tabela[j][1]-tabela[j][2],tabela[j][7],tabela[j][6],tabela[j][4]);
	
	//fprintf(jogo,"%s PG:%d VITORIAS%d\n", time1,tabela[j][0],tabela[j][4]);
	fclose(jogo);
	return 0;
}
