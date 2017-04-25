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
	fscanf(tim,"%d",&n);
	int gol1,gol2;
	FILE *jogo = fopen("jogo.txt","a");
	double **tabela;
	char **times,*time1,*time2;

	// ZERAR TABELA
	tabela=(double**)calloc(n,sizeof(double*));
	times=(char**)calloc(n,sizeof(char*));

	// RECEBE OS NOMES E OS GUARDA
	for(i=0;i<n;i++){
	times[i]=(char*)calloc(30,sizeof(char));
	tabela[i]=(double*)calloc(10,sizeof(double));
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
	}
}
	for(i=0;i<n;i++){
		int total_pontos = tabela[i][7] * 3;
		tabela[i][8]=(tabela[i][0]/total_pontos)*100;
	}

	double aux[9];
	int k , t_aux;
	char *aux_time;
	// int tamanho = sizeof(tabela) / sizeof(int);

	t_aux = n - 1;

  for(j = 0; j < n; j++)
  {
    for(i=0; i < t_aux; i++)
    {
      if(tabela[i][0] < tabela[i+1][0])
      {
				aux_time=times[i];
        times[i]=times[i+1];
        times[i+1]=aux_time;
				for (k = 0; k < 9; k++) {
						aux[k]= tabela[i][k];
						tabela[i][k]=tabela[i+1][k];
						tabela[i+1][k]=aux[k];
				}
      }
			if(tabela[i][0] == tabela[i+1][0] && tabela[i][3] < tabela[i+1][3])
			{
				aux_time=times[i];
				times[i]=times[i+1];
				times[i+1]=aux_time;
				for (k = 0; k < 9; k++) {
						aux[k]= tabela[i][k];
						tabela[i][k]=tabela[i+1][k];
						tabela[i+1][k]=aux[k];
				}
			}
			if(tabela[i][0] == tabela[i+1][0] && tabela[i][3] == tabela[i+1][3] && tabela[i][4] < tabela[i+1][4])
			{
				aux_time= times[i];
				times[i]= times[i+1];
				times[i+1]=aux_time;
				for (k = 0; k < 9; k++) {
						aux[k]= tabela[i][k];
						tabela[i][k]=tabela[i+1][k];
						tabela[i+1][k]=aux[k];
				}
			}
    }
  }

//Exibe no terminal
fprintf(stdout, "Total de times: %d\n", n);
fprintf(stdout, "Total de jogos: %d\n", m);

fprintf(stdout,"Time              PG:  GM:  GS:  S:   V:   GA:    J:    E:  AP: \n");

for(j=0;j<n;j++){
	fprintf(stdout,"%15s %4.0lf %4.0lf %4.0lf %4.0lf %4.0lf %6.2lf %4.0lf %4.0lf %6.2lf", times[j],tabela[j][0],tabela[j][1],tabela[j][2],tabela[j][3],tabela[j][4],tabela[j][5],tabela[j][7],tabela[j][6], tabela[j][8]);
	fprintf(stdout,"\n");
}

// Grava no arquivo
	fprintf(jogo, "Total de times: %d\n", n);
	fprintf(jogo, "Total de jogos: %d\n", m);

	fprintf(jogo,"Time              PG:  GM:  GS:  S:   V:   GA:    J:    E:  AP: \n");

	for(j=0;j<n;j++){
		fprintf(jogo,"%15s %4.0lf %4.0lf %4.0lf %4.0lf %4.0lf %6.2lf %4.0lf %4.0lf %6.2lf%s", times[j],tabela[j][0],tabela[j][1],tabela[j][2],tabela[j][3],tabela[j][4],tabela[j][5],tabela[j][7],tabela[j][6], tabela[j][8],"%");
		fprintf(jogo,"\n");
	}
	fclose(jogo);


    return 0;

}
