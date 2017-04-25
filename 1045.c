#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()

{
	int j,i,n,m;
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
	FILE *tim= fopen("times.txt","r");
	FILE *jogos=fopen("jogos.txt","r");
	printf("\n\n****************%10s*****************\n\n","CLASSIFICAÇÃO");
	fscanf(tim,"%d",&n);
	int gol1,gol2;
	int **tabela;
	char **times,*time1,*time2;

	// ZERAR TABELA 
	tabela=(int**)calloc(n,sizeof(int*));
	times=(char**)calloc(n,sizeof(char*));

	// RECEBE OS NOMES E OS GUARDA
	for(i=0;i<n;i++){
	times[i]=(char*)calloc(30,sizeof(char));
	tabela[i]=(int*)calloc(10,sizeof(int));
	fscanf(tim,"%s",&times[i][0]);
	}	
	
	fscanf(jogos,"%d",&m);
	time1=(char*)calloc(30,sizeof(char));
	time2=(char*)calloc(30,sizeof(char));
	for(i=0;i<m;i++){
		fscanf(jogos,"%s %s %d %d",time1,time2,&gol1,&gol2);
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
	
	//fprintf(jogo,"%s PG:%d VITORIAS%d\n", time1,tabela[j][0],tabela[j][4]);
	for(i=0;i<n;i++){
		tabela[i][3]=tabela[i][1]-tabela[i][2];
		if(tabela[i][2]!=0){
			tabela[i][5]=tabela[i][1]/tabela[i][2];
		}else{
			tabela[i][5]=999;
		}
	//APROVEITAMENTO
		tabela[i][8]=(tabela[i][0]/(tabela[i][7]*3))*100;
	}

	//for(j=0;j<n;j++) fprintf(stdout,"%15s PG:%d GM:%d GS:%d SALDO:%d JOGOS:%d VITORIAS:%d EMPATE:%d GA:%d\n", times[j],tabela[j][0],tabela[j][1],tabela[j][2],tabela[j][3],tabela[j][7],tabela[j][4],tabela[j][6],tabela[j][5]);
	
	//CLASSIFICACAO
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		if (tabela[i][0]>tabela[j][0])
		{			
			time1=times[i];
			times[i]=times[j];
			times[j]=time1;
			m=tabela[i][0];
			tabela[i][0]=tabela[j][0];
			tabela[j][0]=m;
			m=tabela[i][1];
			tabela[i][1]=tabela[j][1];
			tabela[j][1]=m;
			m=tabela[i][2];
			tabela[i][2]=tabela[j][2];
			tabela[j][2]=m;
			m=tabela[i][3];
			tabela[i][3]=tabela[j][3];
			tabela[j][3]=m;
			m=tabela[i][4];
			tabela[i][4]=tabela[j][4];
			tabela[j][4]=m;
			m=tabela[i][5];
			tabela[i][5]=tabela[j][5];
			tabela[j][5]=m;
			m=tabela[i][6];
			tabela[i][6]=tabela[j][6];
			tabela[j][6]=m;
			m=tabela[i][7];
			tabela[i][7]=tabela[j][7];
			tabela[j][7]=m;
			m=tabela[i][5];
			tabela[i][5]=tabela[j][5];
			tabela[j][5]=m;
		}else if(tabela[i][0]==tabela[j][0]){
			if (tabela[i][3]>tabela[j][3])
			{
			time1=times[i];
			times[i]=times[j];
			times[j]=time1;
			m=tabela[i][0];
			tabela[i][0]=tabela[j][0];
			tabela[j][0]=m;
			m=tabela[i][1];
			tabela[i][1]=tabela[j][1];
			tabela[j][1]=m;
			m=tabela[i][2];
			tabela[i][2]=tabela[j][2];
			tabela[j][2]=m;
			m=tabela[i][3];
			tabela[i][3]=tabela[j][3];
			tabela[j][3]=m;
			m=tabela[i][4];
			tabela[i][4]=tabela[j][4];
			tabela[j][4]=m;
			m=tabela[i][5];
			tabela[i][5]=tabela[j][5];
			tabela[j][5]=m;
			m=tabela[i][6];
			tabela[i][6]=tabela[j][6];
			tabela[j][6]=m;
			m=tabela[i][7];
			tabela[i][7]=tabela[j][7];
			tabela[j][7]=m;
			m=tabela[i][5];
			tabela[i][5]=tabela[j][5];
			tabela[j][5]=m;
			}else if(tabela[i][3]==tabela[j][3]){
			if (tabela[i][1]<tabela[j][1])
			{
			time1=times[i];
			times[i]=times[j];
			times[j]=time1;
			m=tabela[i][0];
			tabela[i][0]=tabela[j][0];
			tabela[j][0]=m;
			m=tabela[i][1];
			tabela[	i][1]=tabela[j][1];
			tabela[j][1]=m;
			m=tabela[i][2];
			tabela[i][2]=tabela[j][2];
			tabela[j][2]=m;
			m=tabela[i][3];
			tabela[i][3]=tabela[j][3];
			tabela[j][3]=m;
			m=tabela[i][4];
			tabela[i][4]=tabela[j][4];
			tabela[j][4]=m;
			m=tabela[i][5];
			tabela[i][5]=tabela[j][5];
			tabela[j][5]=m;
			m=tabela[i][6];
			tabela[i][6]=tabela[j][6];
			tabela[j][6]=m;
			m=tabela[i][7];
			tabela[i][7]=tabela[j][7];
			tabela[j][7]=m;
			m=tabela[i][5];
			tabela[i][5]=tabela[j][5];
			tabela[j][5]=m;
			}
		}
	}
	}
}
	for(j=0;j<n;j++) fprintf(stdout,"%15s PG:%d GM:%d GS:%d SALDO:%d JOGOS:%d VITORIAS:%d EMPATE:%d GA:%d\n", times[j],tabela[j][0],tabela[j][1],tabela[j][2],tabela[j][3],tabela[j][7],tabela[j][4],tabela[j][6],tabela[j][5]);
	free(time1);
	free(time2);
	for(i=0;i<n;i++){
		free(tabela[i]);
		free(times[i]);
	}
	fclose(jogos);
	fclose(tim);
	printf("\n\n\n");
	
	
    return 0;

}
