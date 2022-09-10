#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_CONTAS 10
#define MAX_CLIENTES 10

//NOME: tcliente
//TIPO: ESTRUTURA
typedef struct{
	char nome[51];
	char cpf[12];
	char end[20];
	char telefoneP[12];
	char email[31];
	int contas;
}tcliente;

//NOME: tconta
//TIPO: ESTRUTURA
typedef struct{
	int agencia;
	int conta;
	float saldo;
	char cliente[12];
}tconta;

//NOME : cadconta
//TIPO : VOID
//FUN�AO: CADASTRAR AS CONTAS 1 POR 1
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void cadconta(tconta C[MAX_CONTAS],tcliente V[MAX_CLIENTES], int *posi,int *conti){
	int pos = *posi;
	int cont = *conti;
	int agencia,conta;
	char cpf[12];
	int i,q;
	int j;
	int a,b;
	if(pos < MAX_CONTAS){
		printf("Digite o CPF do cliente que voce deseja criar a conta:\n");
	scanf("%s",cpf);
	q = 0;
	for (i = 0; i <cont; i++){
		if(strcmp(cpf,V[i].cpf) == 0){
			q = 1;
		}
	} 
	if(q == 0){
		printf("O cliente nao existe!\n");
	}
	else{
		for (j = 0; j < cont; j++){
		if (strcmp(cpf,V[j].cpf)==0){
			
		printf("Digite agencia:\n");
		scanf("%d",&agencia);
		printf("Digite a conta:\n");
		scanf("%d",&conta);
		b = 0;
		for(a=0;a<pos;a++){
		if(agencia == C[a].agencia && conta == C[a].conta){
			b = 1;
		}
		}
		if(b!=1)
		{
			C[pos].agencia = agencia;
			C[pos].conta = conta;
			printf("Digite o saldo:\n");
			scanf("%f",&C[pos].saldo);
			strcpy(C[pos].cliente, cpf);
			V[j].contas = V[j].contas + 1;
			pos++;
			*posi = pos;
		}
							
			
		
		}
	}
	if(b!=0){
		printf("Essa conta ja existe!");
			}				
	}
	}else{
		printf("Sem espa�o para novas contas!!");
	}
	
	*posi = pos;
}

//NOME : alteraconta
//TIPO : VOID
//FUN�AO: ALTERAR CONTAS QUE O USUARIO QUISER, 1 POR VEZ
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void alteraconta(tconta C[MAX_CONTAS],tcliente V[MAX_CLIENTES], int *conti,int *posi){
	int cont,w;
	int u;
	int pos = *posi;
	cont = *conti;
	int i,j,q;
	int agencia, conta;
	int b,a;
	char cpff[12];
	int op;
	q = 0;
	printf("Digite a agencia:\n");
	scanf("%d", &agencia);
	printf("Digite a conta\n");
	scanf("%d", &conta);
	for (i = 0; i <pos; i++){
		if(agencia == C[i].agencia && conta == C[i].conta){
			q=1;
	}
	}
	if(q==0){
		printf("Essa conta nao existe!");
	}
	
	else{
		printf("Digite o cpf do cliente:\n");
		scanf("%s", cpff);
		for(j = 0; j < pos; j++){
		if (strcmp(cpff,C[j].cliente)==0){
		do{
			printf("O que voce deseja alterar?\n");
			printf("1.Numero da agencia\n2.Numero da conta\n3.Cpf\n0.Sair\n");
			scanf("%d",&op);
	
			switch(op)
			{
			case 1:
				printf("Numero da agencia: %d\n", C[j].agencia);
				printf("Novo numero:\n");
				scanf("%d",&C[j].agencia);
				do{b = 0;
				
				for(i=0;i<pos;i++){
				   if(C[pos].agencia == C[j].agencia && C[pos].conta == C[j].conta){
					   printf("Digite a agencia novamente:\n");
					   scanf("%d",&C[j].agencia);
					   b = 1;
				   }
				}
				}while(b==1);
					
				break;
			case 2:
				printf("Numero da Conta: %d\n", C[j].conta);
				printf("Novo numero da conta: ");
				scanf("%d", &C[j].conta);
				do{a = 0;
				
				for(u=0;u<pos;u++){
				   if(C[j].agencia == C[pos].agencia && C[pos].conta == C[j].conta){
					   printf("Digite a conta novamente:\n");
					   scanf("%d",&C[j].conta);
					   a = 1;
				   }
				}
				}while(a==1);	
				break;
			case 3:
				printf("Cpf atual: %s\n", C[j].cliente);
				printf("Digite o seu cpf sem os pontos:\n");
				scanf("%s",V[j].cpf);
				q = 0;
				for(i=0;i<cont;i++){
				   if(strcmp(V[j].cpf,V[i].cpf)==0){
					   strcpy(C[j].cliente, V[i].cpf);
					   for(w=0;w<pos;w++){
					    if(strcmp(C[w].cliente,V[i].cpf)==0){
							V[j].contas--;
							V[i].contas++;
						}
			   		}
					   q = 1;
				   }
				}
				 
				if(q == 0){
					printf("O cliente nao existe!\n");
				break;
			case 0:
				break;
			}

				
			}	
		}while(op!=0);
		}
	}
	}
}
//NOME : remover
//TIPO : VOID
//FUN�AO: REMOVE UMA CONTA QUE O USUARIO SOLICITAR
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, E O ENDERE�O DE POS PARA DETERMINAR UMA POSI�AO
void remover(tconta C[MAX_CONTAS], int *posi){
	int pos, i, a, b, q, j;
	pos = *posi;
	printf("informe o numero da agencia e da conta que deseja remover: \n");
	scanf("%d%d", &b, &a);
	q=0;
	for(i=0; i<pos; i++){
		if((C[i].conta==a) && (C[i].agencia==b)){
		q++;	
		j=i;
		}
	}
	if(q==1){
		for(i=j; i<pos-1; i++){
			C[i].agencia=C[i+1].agencia;
			C[i].conta=C[i+1].conta;
		}
		pos--;
	}else{
		printf("CONTA INVALIDA!!\n");
	}
	*posi = pos;
}
//NOME : cadastro
//TIPO : VOID
//FUN�AO: CADASTRAR OS CLIENTES 1 POR 1
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CLIENTE, E O ENDERE�O DE CONT PARA CONTROLAR A POSI�AO QUE SE DESEJA CADASTRAR.
void cadastro(tcliente V[MAX_CLIENTES],int *conti){
	int cont;
	cont = *conti;
	int i;
	int a;
	if(cont < MAX_CLIENTES){
	scanf("%*c");
	printf("Digite o nome:\n");
	do{
	fgets(V[cont].nome,50,stdin);
	}while(strlen(V[cont].nome)==1);
		 
	printf("Digite o seu cpf sem os pontos:\n");
	scanf("%s",V[cont].cpf);
	do{a = 0;
	
	for(i=0;i<cont;i++){
	   if(strcmp(V[cont].cpf,V[i].cpf)==0){
		   printf("Digite o cpf novamente:\n");
		   scanf("%s",V[cont].cpf);
		   a = 1;
	   }
	}
	}while(a==1);
	
	setbuf(stdin, NULL);
	printf("Digite o endereco:\n");
	gets(V[cont].end);
		
	setbuf(stdin, NULL);
	printf("Digite o telefone:\n");
	scanf("%s",V[cont].telefoneP);
	
	setbuf(stdin, NULL);
	printf("Digite o email:\n");
	scanf("%s",V[cont].email);
	
	V[cont].contas = 0;
	cont++;
	*conti = cont;
	}else{
		printf("Sem espa�o para novos clientes!\n");
	}
	printf("%d",cont);
}

//NOME DA FUN�AO: alteracliente
//TIPO: VOID
//FUN�AO: ALTERA OS DADOS DE UM CLIENTE SOLICITADO PELO USUARIO
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CLIENTE, E O ENDERE�O DE CONT PARA CONTROLAR A POSI�AO QUE SE DESEJA CADASTRAR.
void alteracliente(tcliente V[MAX_CLIENTES],int *conti){
	int cont;
	cont = *conti;
	int i,a,j,q;
	char cpff[12];
	char cp[12];
	int op;
	printf("Digite o CPF do cliente que voce deseja alterar:\n");
	scanf("%s",cpff);
	q = 0;
	for (i = 0; i <cont; i++){
		if(strcmp(cpff,V[i].cpf) == 0){
			q = 1;
		}
	} 
	if(q == 0){
		printf("O cliente nao existe!\n");
	}
	else{
		for (j = 0; j < cont; j++){
		if (strcmp(cpff,V[j].cpf)==0){
		printf("O que voce deseja alterar?\n");
		do{
			printf("1.Nome\n2.CPF\n3.Endere�o\n4.Telefone principal\n5.Email principal\n0.Sair\n");
			scanf("%d",&op);
	
			switch(op)
			{
			case 1:
				printf("Nome atual: %s\n", V[j].nome);
				printf("Novo nome:\n");
				scanf("%*c");
				fgets(V[j].nome,50,stdin);
				break;
			case 2:
				strcpy(cp, V[j].cpf);
				printf("CPF atual: %s\n", V[j].cpf);
				printf("Novo CPF: ");
				scanf("%s", cp);
				do{a = 0;
				for(i=0;i<cont;i++){
				   if(strcmp(cp,V[i].cpf)==0){
					   printf("Digite o cpf novamente:\n");
					   scanf("%s",cp);
					   a = 1;
				   }
				}
				}while(a==1);
				strcpy(V[j].cpf, cp);
				break;
			case 3:
				printf("Endereco atual: %s\n", V[j].end);
				printf("Novo endereco: ");
				scanf("%*c");
				fgets(V[j].end,50,stdin);
				break;
			case 4:
				printf("Telefone atual: %s\n", V[j].telefoneP);
				printf("Novo telefone:\n");
				scanf("%s", V[j].telefoneP);
				break;
			
			case 5: printf("Email atual: %s\n", V[j].email);
				    printf("Novo email:\n");
				    scanf("%s", V[j].email);
				    break;
			case 0:
				break;
			}
		}while(op!=0);
	}
	}
	*conti = cont;
}
}
//NOME : saldo
//TIPO : VOID
//FUN�AO: VERIFICA O SALDO DE UMA CONTA
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTA E O ENDERE�O DE POS PARA CONTROLAR A POSI�AO
void saldo(tconta C[MAX_CONTAS], int *posi){
	int pos = *posi;
	int q;
	int conta,i;
	int agencia;
	printf("\nDigite o numero da agencia e o numero da conta:\n");
	scanf("%d",&agencia);
	scanf("%d",&conta);
	q = 0;
	for (i = 0; i <pos; i++){
		if(agencia == C[i].agencia && conta == C[i].conta){
			q = 1;
			printf("Saldo: %2.f",C[i].saldo);
			
		}
	} 
	if(q == 0){
		printf("\n");
		printf("CONTA INVALIDA!\n");
	
}
}
//NOME : deposito
//TIPO : VOID
//FUN�AO: DEPOSITA UM VALOR NA CONTA SOLICITADA
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTA, E O ENDERE�O DE POS PARA CONTROLE DE POSI�AO.
void deposito(tconta C[MAX_CONTAS],int *posi){
	int pos = *posi;
	int q;
	int conta,i;
	int agencia;
	float valor;
	printf("Digite o numero da agencia e o numero da conta:\n");
	scanf("%d",&agencia);
	scanf("%d",&conta);
	q = 0;
	for (i = 0; i <pos; i++){
		if(agencia == C[i].agencia && conta == C[i].conta){
			q = 1;
			printf("Digite quanto voce deseja depositar:\n");
			scanf("%f",&valor);
			C[i].saldo = C[i].saldo + valor;
			
		}
	} 
	if(q == 0){
		printf("\n");
		printf("CONTA INVALIDA!\n");
	
	}
}
//NOME : saque
//TIPO : VOID
//FUN�AO: SACA UMA DETERMINADA QUANTIA DE UMA CONTA SOLICITADA
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTA, E O ENDERE�O DE POS.
void saque(tconta C[MAX_CONTAS], int *posi){
	int pos = *posi;
	int q;
	int conta,i;
	int agencia;
	float valor;
	printf("Digite o numero da agencia e o numero da conta:\n");
	scanf("%d",&agencia);
	scanf("%d",&conta);
	q = 0;
	for (i = 0; i <pos; i++){
		if(agencia == C[i].agencia && conta == C[i].conta){
			q = 1;
			printf("Digite quanto voce deseja sacar:\n");
			scanf("%f",&valor);
			if(C[i].saldo>=valor){
				C[i].saldo = C[i].saldo - valor;
				
			}
			else
			{
				printf("SALDO INSUFICIENTE!\n");
			}
				
			
		}
	} 
	if(q == 0){
		printf("\n");
		printf("CONTA INVALIDA!\n");
	
}
}
//NOME : transferencia
//TIPO : VOID
//FUN�AO: TRANSFERE UM VALOR DE UMA CONTA PARA OUTRA QUE O USUARIO DIGITA
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, E O ENDERE�O DE POS.
void transferencia(tconta C[MAX_CONTAS], int*posi){
	int pos = *posi;
	int q,g;
	int conta,i,j,k;
	int agencia, agenciad, contad;
	float valor;
	printf("Digite o numero da agencia e o numero da conta origem:\n");
	scanf("%d",&agencia);
	scanf("%d",&conta);
	q = 0;
	for (i = 0; i <pos; i++){
		if(C[i].agencia == agencia && C[i].conta == conta){
			q = 1;	
		}
	}
	if(q==0){
		printf("CONTA ORIGEM INVALIDA!\n");
}
	
	else
	{
	printf("Digite o numero da agencia e o numero da conta destino:\n");
			scanf("%d",&agenciad);
			scanf("%d",&contad);
			g = 0;		
	for (j = 0; j<pos; j++){
				if(agenciad == C[j].agencia && contad == C[j].conta){
					g = 1;
					for(k = 0; k<pos; k++){
					if(agencia == C[k].agencia && conta == C[k].conta){
					printf("Digite o valor que deseja transferir:\n");
					scanf("%f",&valor);
					if(C[k].saldo>=valor){
						C[k].saldo = C[k].saldo - valor;
						C[j].saldo = C[j].saldo + valor;
						
					}else{
							printf("SALDO INSUFICIENTE!\n");
						}
				
				}
				}
				}
	}if(g == 0){
		printf("CONTA DESTINO INVALIDA!");
	}
	}
	}
//NOME : exibecontacliente
//TIPO : VOID
//FUN�AO: EXIBE AS INFORMA�OES DA CONTA DE UM CLIENTE
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void exibecontacliente(tconta C[MAX_CONTAS], int *posi, tcliente V[MAX_CLIENTES], int *conti){
	int pos = *posi;
	FILE *port;
	char cpf[12];
	int q,j,op;
	printf("Digite o CPF do cliente:\n");
	scanf("%s",cpf);
	q = 0;
			for(j=0;j<pos;j++){
			if(strcmp(cpf,C[j].cliente)==0){
				q = 1;
				
				printf("Numero da agencia: %d\n",C[j].agencia);
				printf("Numero da conta: %d\n",C[j].conta);
				printf("Saldo: %2.f\n",C[j].saldo);
				printf("-------------------\n");
			}
			}
			printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
			scanf("%d",&op);
			
			switch(op)
				{
				case 1: 
				port = fopen("Exibecontas.txt","w");
				for(j=0;j<pos;j++){
				if(strcmp(cpf,C[j].cliente)==0){
					q = 1;
				         
				         fprintf(port,"Numero da agencia: %d\n",C[j].agencia);
				         fprintf(port,"Numero da conta: %d\n",C[j].conta);
				         fprintf(port,"Saldo: %2.f\n",C[j].saldo);
						}
				}
				         fclose(port);
					break;
				case 2:
				    break;
				default:
					break;
				}
	if(q == 0){
		printf("CONTA NAO EXISTE!\n");
	
}
}
//NOME : dadoscontassaldo
//TIPO : VOID
//FUN�AO: MOSTRA OS DADOS DOS CLIENTE E SUAS CONTAS CONFORME O VALOR DO SALDO DIGITADO PELO USUARIO, PODENDO SER MAIOR, MENOR OU IGUAL A ESSE SALDO.
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void dadoscontassaldo(tconta C[MAX_CONTAS], int *posi, tcliente V[MAX_CLIENTES],int *conti){
	int cont = *conti;
	int pos = *posi;
	FILE *p1;
	int op2,op;
	int i,j;
	float valor;
	printf("Digite o saldo:\n");
	scanf("%f",&valor);
	printf("Deseja informacoes de contas com saldo:\n1.Menor\n2.Igual\n3.Maior\n");
	scanf("%d",&op);
	switch(op)
	{
	case 1: for(i=0;i<pos;i++){
		if(C[i].saldo<valor){
			for(j=0;j<cont;j++){
			if(strcmp(C[i].cliente,V[j].cpf)==0){
				printf("Nome do cliente: %s",V[j].nome);
				printf("CPF do cliente: %s\n",V[j].cpf);
				printf("Numero da agencia: %d\n",C[i].agencia);
				printf("Numero da conta: %d\n",C[i].conta);
				printf("Saldo: %1.f\n",C[i].saldo);
				printf("-------------\n");
			}
		}
	}
	}
	printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
			scanf("%d",&op2);
			
			switch(op2)
				{
				case 1: 
				p1 = fopen("dadosmenor.txt","w");
				 for(i=0;i<pos;i++){
				if(C[i].saldo<valor){
				for(j=0;j<cont;j++){
				if(strcmp(C[i].cliente,V[j].cpf)==0){
					fprintf(p1,"Nome do cliente: %s",V[j].nome);
					fprintf(p1,"CPF do cliente: %s\n",V[j].cpf);
					fprintf(p1,"Numero da agencia: %d\n",C[i].agencia);
					fprintf(p1,"Numero da conta: %d\n",C[i].conta);
					fprintf(p1,"Saldo: %1.f\n",C[i].saldo);
				}
			}
		}
				 }
				         fclose(p1);
					break;
				case 2:
				    break;
				default:
					break;
				}
	break;
	case 2: for(i=0;i<pos;i++){
		if(C[i].saldo == valor){
			for(j=0;j<cont;j++){
			if(strcmp(C[i].cliente,V[j].cpf)==0){
				printf("Nome do cliente: %s",V[j].nome);
				printf("CPF do cliente: %s\n",V[j].cpf);
				printf("Numero da conta: %d\n",C[i].conta);
				printf("Numero da agencia: %d\n",C[i].agencia);
				printf("Saldo: %1.f\n",C[i].saldo);
			}
			}
		}
	}
	printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
			scanf("%d",&op2);
			
			switch(op2)
				{
				case 1: 
				p1 = fopen("dadosigual.txt","w");
				 for(i=0;i<pos;i++){
				if(C[i].saldo==valor){
				for(j=0;j<cont;j++){
				if(strcmp(C[i].cliente,V[j].cpf)==0){
					fprintf(p1,"Nome do cliente: %s",V[j].nome);
					fprintf(p1,"CPF do cliente: %s\n",V[j].cpf);
					fprintf(p1,"Numero da conta: %d\n",C[i].conta);
					fprintf(p1,"Numero da agencia: %d\n",C[i].agencia);
					fprintf(p1,"Saldo: %1.f\n",C[i].saldo);
				}
			}
		}
				 }
				         fclose(p1);
					break;
				case 2:
				    break;
				default:
					break;
				}
		break;
	case 3: for(i=0;i<pos;i++){
		if(C[i].saldo>valor){
			for(j=0;j<cont;j++){
			if(strcmp(C[i].cliente,V[j].cpf)==0){
				printf("Nome do cliente: %s",V[j].nome);
				printf("CPF do cliente: %s\n",V[j].cpf);
				printf("Numero da conta: %d\n",C[i].conta);
				printf("Numero da agencia: %d\n",C[i].agencia);
				printf("Saldo: %1.f\n",C[i].saldo);
			}
			}
		}
	}
	printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
			scanf("%d",&op2);
			
			switch(op2)
				{
				case 1: 
				p1 = fopen("dadosmaior.txt","w");
				 for(i=0;i<pos;i++){
				if(C[i].saldo>valor){
				for(j=0;j<cont;j++){
				if(strcmp(C[i].cliente,V[j].cpf)==0){
					fprintf(p1,"Nome do cliente: %s",V[j].nome);
					fprintf(p1,"CPF do cliente: %s\n",V[j].cpf);
					fprintf(p1,"Numero da conta: %d\n",C[i].conta);
					fprintf(p1,"Numero da agencia: %d\n",C[i].agencia);
					fprintf(p1,"Saldo: %1.f\n",C[i].saldo);
				}
			}
		}
				 }
				         fclose(p1);
					break;
				case 2:
				    break;
				default:
					break;
				}
		break;
	default:
		break;
	}

}
//NOME : dadosclientes
//TIPO : VOID
//FUN�AO: MOSTRA OS DADOS DE TODOS OS CLIENTES
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CLIENTES, E 1 ENDERE�O PARA CONTROLE DE POSI��O
void dadosclientes(tcliente V[MAX_CLIENTES], int *conti){
	int i;
	int cont = *conti;
	int op;
	FILE *p2;
	for(i=0;i<cont;i++){
		printf("Nome do cliente: %s",V[i].nome);
		printf("CPF do cliente: %s\n",V[i].cpf);
		printf("Endereco: %s\n",V[i].end);
		printf("Telefone: %s\n",V[i].telefoneP);
		printf("Email: %s\n",V[i].email);
		printf("Numero de contas: %d\n",V[i].contas);
		printf("---------------\n");
	}
	printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
	scanf("%d",&op);
			switch(op)
				{
				case 1: 
				p2 = fopen("Dadosclientes.txt","w");
				for(i=0;i<cont;i++){
					fprintf(p2,"Nome do cliente: %s",V[i].nome);
					fprintf(p2,"CPF do cliente: %s\n",V[i].cpf);
					fprintf(p2,"Endereco: %s\n",V[i].end);
					fprintf(p2,"Telefone: %s\n",V[i].telefoneP);
					fprintf(p2,"Email: %s\n",V[i].email);
					fprintf(p2,"Numero de contas: %d\n",V[i].contas);
					fprintf(p2,"---------------\n");
				 }
				         fclose(p2);
					break;
				case 2:
				    break;
				default:
					break;
				}
}

//NOME : todascontas
//TIPO : VOID
//FUN�AO: MOSTRA OS DADOS DO CLIENTE E DAS CONTAS, MOSTRA OS DADOS DAS COTNAS SE O CLIENTE TIVER PELO MENOS 1 CONTA
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void todascontas(tconta C[MAX_CONTAS], tcliente V[MAX_CLIENTES],int*conti,int*posi){
	int cont = *conti;
	int pos = *posi;
	int i,j,op;
	FILE *p3;
		for(i=0;i<cont;i++){
		printf("Nome do cliente: %s",V[i].nome);
		printf("CPF do cliente: %s\n",V[i].cpf);
		printf("Email: %s\n",V[i].email);
		printf("Numero de contas: %d\n",V[i].contas);
		if(V[i].contas!=0){
			for(j=0;j<pos;j++){
				if(strcmp(V[i].cpf,C[j].cliente)==0){
					printf("Numero da agencia: %d\n",C[j].agencia);
					printf("Numero da conta: %d\n",C[j].conta);
					printf("Saldo: %1.f\n",C[j].saldo);
					printf("----------------\n");
				}
			}
		}
		printf("----------------\n");
	}
	printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
	scanf("%d",&op);
			switch(op)
				{
				case 1: 
				p3 = fopen("Todascontas.txt","w");
				for(i=0;i<cont;i++){
				fprintf(p3,"Nome do cliente: %s",V[i].nome);
				fprintf(p3,"CPF do cliente: %s\n",V[i].cpf);
				fprintf(p3,"Email: %s\n",V[i].email);
				fprintf(p3,"Numero de contas: %d\n",V[i].contas);
				if(V[i].contas!=0){
					for(j=0;j<pos;j++){
						if(strcmp(V[i].cpf,C[j].cliente)==0){
							fprintf(p3,"Numero da conta: %d\n",C[j].conta);
							fprintf(p3,"Numero da agencia: %d\n",C[j].agencia);
							fprintf(p3,"Saldo: %1.f\n",C[j].saldo);
							fprintf(p3,"----------------\n");
						}
					}
				}
				fprintf(p3,"----------------\n");
			}
				         fclose(p3);
					break;
				case 2:
				    break;
				default:
					break;
				}
		}
		
//NOME : infoclientes
//TIPO : VOID
//FUN�AO: MOSTRA OS DADOS DE TODOS OS CLIENTES, INCLUSIVE AS CONTAS.
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void infoclientes(tconta C[MAX_CONTAS],tcliente V[MAX_CLIENTES],int*conti,int*posi){
	int i;
	int cont = *conti;
	int pos = *posi;
	int j;
	int op;
	FILE *p4;
	
	for(i=0;i<cont;i++){
		printf("Nome do cliente: %s",V[i].nome);
		printf("CPF do cliente: %s\n",V[i].cpf);
		printf("Endereco: %s\n",V[i].end);
		printf("Telefone: %s\n",V[i].telefoneP);
		printf("Email: %s\n",V[i].email);
		printf("Numero de contas: %d\n",V[i].contas);
		if(V[i].contas!=0){
			for(j=0;j<pos;j++){
				if(strcmp(V[i].cpf,C[j].cliente)==0){
					printf("Numero da agencia: %d\n",C[j].agencia);
					printf("Numero da conta: %d\n",C[j].conta);
					printf("Saldo: %1.f\n",C[j].saldo);
				}
			}
		}
		else
		{
			printf("O cliente nao possui contas\n");
		}
		printf("---------------\n");
	}
	printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
	scanf("%d",&op);
			switch(op)
				{
				case 1: 
				p4 = fopen("Infoclientes.txt","w");
				for(i=0;i<cont;i++){
				fprintf(p4,"Nome do cliente: %s",V[i].nome);
				fprintf(p4,"CPF do cliente: %s\n",V[i].cpf);
				fprintf(p4,"Endereco: %s\n",V[i].end);
				fprintf(p4,"Telefone: %s\n",V[i].telefoneP);
				fprintf(p4,"Email: %s\n",V[i].email);
				fprintf(p4,"Numero de contas: %d\n",V[i].contas);
				if(V[i].contas!=0){
					for(j=0;j<pos;j++){
						if(strcmp(V[i].cpf,C[j].cliente)==0){
							fprintf(p4,"Numero da conta: %d\n",C[j].conta);
							fprintf(p4,"Numero da agencia: %d\n",C[j].agencia);
							fprintf(p4,"Saldo: %1.f\n",C[j].saldo);
						}
					}
				}
				else
				{
					fprintf(p4,"O cliente nao possui contas\n");
				}
				fprintf(p4,"---------------\n");
			}
				         fclose(p4);
					break;
				case 2:
				    break;
				default:
					break;
				}
	
}
//NOME : dadoscadastrais
//TIPO : VOID
//FUN�AO: MOSTRA OS DADOS CADASTRAIS DE TODOS OS CLIENTES ORDENADOS PELO CPF
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void dadoscadastrais(tcliente V[MAX_CLIENTES],int *conti, int *posi){
	int i,j;
	int cont = *conti;
	char cpff[12];
	char nome[51];
	char end[51];
	char tel [30];
	char email[30];
	int num;
	int op,k;
	FILE *p10;
	for(i=0;i<cont;i++){
		for(j=i+1; j<cont; j++){
			if(strcmp(V[i].cpf,V[j].cpf)>0){
	    			strcpy(cpff,V[i].cpf);
	    			strcpy(V[i].cpf,V[j].cpf);
	    			strcpy(V[j].cpf,cpff);
	    			
	    			strcpy(nome,V[i].nome);
	    			strcpy(V[i].nome,V[j].nome);
	    			strcpy(V[j].nome,nome);
	    			
	    			strcpy(end,V[i].end);
	    			strcpy(V[i].end,V[j].end);
	    			strcpy(V[j].end,end);
	    			
	    			strcpy(tel,V[i].telefoneP);
	    			strcpy(V[i].telefoneP,V[j].telefoneP);
	    			strcpy(V[j].telefoneP,tel);
	    			
	    			strcpy(email,V[i].email);
	    			strcpy(V[i].email,V[j].email);
	    			strcpy(V[j].email,email);
	    			
	    			num = V[i].contas;
	    			V[i].contas = V[j].contas;
	    			V[j].contas = num;
	    			
	    			
        	}
		}
		            
		if(V[i].contas > 0){
			printf("Nome do cliente: %s",V[i].nome);
			printf("CPF do cliente: %s\n",V[i].cpf);
			printf("Endereco: %s\n",V[i].end);
			printf("Telefone: %s\n",V[i].telefoneP);
			printf("Email: %s\n",V[i].email);
			printf("Numero de contas: %d\n",V[i].contas);
			printf("---------------\n");
			
				
		}
		
	}
	
printf("Deseja gerar um arquivo com essas informacoes?\n1.SIM\n2.NAO\n");
	scanf("%d",&op);
			switch(op){
				case 1:
					p10 = fopen("Dadoscadastrais.txt","w"); 
				for(k=0;k<cont;k++){
					if(V[k].contas > 0){
					fprintf(p10,"Nome do cliente: %s",V[k].nome);
					fprintf(p10,"CPF do cliente: %s\n",V[k].cpf);
					fprintf(p10,"Endereco: %s\n",V[k].end);
					fprintf(p10,"Telefone: %s\n",V[k].telefoneP);
					fprintf(p10,"Email: %s\n",V[k].email);
					fprintf(p10,"Numero de contas: %d\n",V[k].contas);
					fprintf(p10,"---------------\n");
					}
				}
				fclose(p10);
					break;
				case 2:
					break;
				default: printf("OPCAO INVALIDA!");
			}

}

//NOME : mrelatorio
//TIPO : VOID
//FUN�AO: MOSTRA O MENU RELATORIO
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void mrelatorio(tconta C[MAX_CONTAS], int *posi, tcliente V[MAX_CLIENTES],int *conti){
	int up;
	int cont = *conti;
	int pos = *posi;
	do{
	printf("\nMENU RELATORIOS\n1- Contas de um cliente\n2- Dados dos clientes com saldo inferior, superior ou igual a um valor\n3- Dados cadastrais de todos clientes (ativos ou nao)\n4- Informacoes de todas as contas\n5- Informacoes de todos os clientes\n6- Dados cadastrais de todos clientes de uma agencia(ativos) ordenados pelo CPF\n0- Sair\n\nR = ");
	scanf("%d", &up);
	switch(up){
		case 1: exibecontacliente(C,&pos,V,&cont);
			break;
		case 2: dadoscontassaldo(C,&pos,V,&cont);
			break;
		case 3: dadosclientes(V,&cont);
			break;
		case 4: todascontas(C,V,&cont,&pos);
			break;
		case 5: infoclientes(C,V,&cont,&pos);
			break;
		case 6: dadoscadastrais(V,&cont,&pos);
		    break;
		case 0:
			break;
		default: printf("OPCAO INVALIDA!\n\n");
			break;
	}
	}while(up != 0);
	*conti = cont;
	*posi = pos;
}
//NOME : mmovimento
//TIPO : VOID
//FUN�AO: MOSTRA O MENU MOVIMENTO
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS 1 ENDERE�O PARA CONTROLE DE POSI��O
void mmovimento(tconta C[MAX_CONTAS], int *posi){
	int pos = *posi;
	int ip;
	do{
	printf("\nMENU MOVIMENTO\n1- Saldo\n2- Deposito\n3- Saque\n4- Transferencia\n0- Sair\n\nR = ");
	scanf("%d", &ip);
	switch(ip){
		case 1: saldo(C,&pos);
			break;
		case 2: deposito(C,&pos);
			break;
		case 3: saque(C,&pos);
			break;
		case 4: transferencia(C,&pos);
			break;
		case 0:
			break;
		default: printf("OPCAO INVALIDA!\n\n");
			break;
	}
	}while(ip != 0);
	*posi = pos;
}

//NOME : mconta
//TIPO : VOID
//FUN�AO: MOSTRA O MENU CONTA
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CONTAS, O VETOR CLIENTES, E 2 ENDERE�OS PARA CONTROLE DE POSI��O
void mconta(tconta C[MAX_CONTAS], tcliente V[MAX_CONTAS],int *posi, int *conti){
	int ep;
	int pos = *posi;
	int cont = *conti;
	
	do{
		
	printf("\nMENU CONTA\n1- Cadastrar Conta\n2- Alterar Conta\n3- Remover Conta\n0- Sair\n\nR = ");
	scanf("%d", &ep);
	switch(ep){
		case 1:cadconta(C,V,&pos,&cont);
			break;
		case 2:alteraconta(C,V,&cont,&pos);
			break;
		case 3:remover(C,&pos);
			break;
		case 0:
			break;
		default: printf("OPCAO INVALIDA!\n\n");
			break;
	}
	}while(ep != 0);
	*conti = cont;
	*posi = pos;
}

//NOME : mcliente
//TIPO : VOID
//FUN�AO: MOSTRA O MENU CLIENTE
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O VETOR CLIENTES, E 1 ENDERE�O PARA CONTROLE DE POSI��O
void mcliente(tcliente V[MAX_CLIENTES], int *conti){
	int ap;
	int cont = *conti;
	do{
	printf("\nMENU CLIENTE\n1- Cadastrar Cliente\n2- Alterar Cliente\n0- Sair\n\nR = ");
	scanf("%d", &ap);
	switch(ap){
		case 1: cadastro(V,&cont);
			break;
		case 2: alteracliente(V,&cont);
			break;
		case 0:
			break;
		default: printf("OPCAO INVALIDA!\n\n");
			break;
	}
	}while(ap != 0);
	*conti = cont;
}
//NOME : menu
//TIPO : VOID
//FUN�AO: MOSTRA O MENU PRINCIPAL
//RETORNO: NADA, POIS � VOID
//PARAMETROS: O ENDERE�O DE OP.
void menu(int *op){
	printf("\nMENU PRINCIPAL\n1- Cliente\n2- Conta\n3- Movimento\n4- Relatorio\n0- Sair\n\nR = ");
	scanf("%d", op);
	
}
//NOME : main
//TIPO : INT
//FUN�AO: PONTO DE PARTIDA PRA EXECU�AO DO PROGRAMA
//RETORNO: O INTEIRO 0
//PARAMETROS: NADA.
	int main(){
		int cont = 0;
		int pos = 0;
		tcliente V[MAX_CLIENTES];
		tconta C[MAX_CONTAS];
	int op;
	do{
		menu(&op);
		switch(op){
			case 1:mcliente(V,&cont);
				break;
			case 2:mconta(C,V,&pos,&cont);
				break;
			case 3:mmovimento(C,&pos);
				break;
			case 4:mrelatorio(C,&pos,V,&cont);
				break;
			case 0:
				break;
			default: printf("OPCAO INVALIDA!\n\n");
				break;
		}
		
	}while(op != 0);
		
	return 0;
}