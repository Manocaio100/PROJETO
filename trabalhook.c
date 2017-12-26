#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
//FAZER UMA FUNÇÃO PARA OS CARACTERES


 struct alunos{
  char nomeAluno [50],matricula[20],cpf[20],quantaluno;
}ALUNO;

 struct livros{
char nomeLivro[50], nomeAutor[50], areaLivro[20];
char quantLivro;
int codLivro;
}LIVRO;


FILE *arq;
FILE *liv;



void cabecalho();
void alunos ();
void cadastro ();
void livro();
void cadastrolivros();
void vizualizarlivros();
int encontra_livro(int n);
int removerlivro();
int removeraluno();
void alterarlivro(void);
void removerli(void);
void vizualizaralunos();
void abrir();
void alteraraluno();
void removeralu();
void sleep();

main (){

system ("color 80");
  int opcao;


printf("\t        **********************************************************\n");
printf("\t                                                           \n");
printf("\t               %c%c%c%c%c%c%c%c%c  SISTEMA DE ACERVO DA  %c%c%c%c%c%c%c%c%c\n\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
printf("\t             %c%c%c%c%c%c  UNIVERSIDADE ESTADUAL DA PARAIBA %c%c%c%c%c%c\n",176,176,176,176,176,176,176,176,176,176,176,176);
printf("\t                                                          \n");
printf("\t                                                          \n");
printf("\t        **********************************************************\n");
system ("pause");
system ("cls");
sleep();

do{

 cabecalho();
j:
system ("color 0A");
printf("\t\t       %c %c %c %c%c%c MENU PRINCIPAL %c%c%c %c %c %c \n\n",176,176,176,176,176,176,176,176,176,176,176,176);
printf("\t\t     | <1> ALUNO                         |\n\n");
printf("\t\t     | <2> LIVROS                        |\n\n");
printf("\t\t     | <3> EMPRESTIMO                    |\n\n");
printf("\t\t     | <4> SAIR DO SISTEMA               |\n\n");
printf("\t\t     %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);

scanf("%d",&opcao);
system("cls");

switch (opcao){
     case 1:
            alunos ();
     break;

     case 2:
            livro ();

     case 3:
         //pesquisar
     break;

     case 4:

         printf ("\t\t\t%c%c%c%c%c%c%c%c BOA LEITURA %c%c%c%c%c%c%c%c\n\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
         printf ("\t\t%c%c%c LEMBRE-SE DA DATA DE ENTREGA DO LIVRO %c%c%c\n\n\n",176,176,176,176,176,176);
         getch();
     break;

        default:

        system ("color 40");
        printf ("\n\n   %c %c %c %c %c %c !!OPCAO INVALIDA!! %c %c %c %c %c %c\n\n",178,178,178,178,178,178,178,178,178,178,178,178);
        printf("PRECIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL!");
        getch ();
        system("cls");
        goto j;

        break;
}

} while (opcao!=4);
}

void sleep(){
        printf ("\n");
printf ("\tAguarde, processsando...\n\n");
printf ("\t*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");Sleep(100);
printf ("*");Sleep(100);printf ("*");
printf ("*\n\n");Sleep(100);
system ("cls");
}


int encontra_livro(int n){

  fread(&LIVRO,sizeof(struct livros),1,liv);
  while (!feof(liv))
  {
    if (LIVRO.codLivro == n)
    {
      fseek(liv,-sizeof(struct livros),SEEK_CUR);
      return 1;
    }
    fread(&LIVRO,sizeof(struct livros),1,liv);
  }
  return 0;}
void cabecalho(){
    system ("cls");
   printf ("\t\t          ---------------------------\n");
   printf ("\t\t          BEM VINDO AO MENU PRINCIPAL\n");
   printf ("\t\t          ---------------------------\n\n");

}
void livro(){


int opcao;

g:
system ("color 0f");
printf("\t\t        %c%c%c%c%c%c%c%c%c%c ACERVO %c%c%c%c%c%c%c%c%c%c%c\n\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
printf("\t\t     %c <1> CADASTRAR LIVRO            %c\n\n",176,176);
printf("\t\t     %c <2> REMOVER LIVRO              %c\n\n",176,176);
printf("\t\t     %c <3> EDITAR LIVRO               %c\n\n",176,176);
printf("\t\t     %c <4> LISTAR LIVROS CADASTRADOS  %c\n\n",176,176);
printf("\t\t     %c <5> VOLTAR AO MENU PRINCIPAL   %c\n\n",176,176);


scanf("%d",&opcao);
system("cls");

switch (opcao){
     case 1:
         cadastrolivros ();
     break;

     case 2:
         removerli();
     break;

     case 3:
         alterarlivro();
     break;

     case 4:
            vizualizarlivros();
     break;

     case 5:
     break;

     default:

        system ("color f0");
        printf ("\n\n   %c %c %c %c %c %c !!OPCAO INVALIDA!! %c %c %c %c %c %c\n\n",176,176,176,176,176,176,176,176,176,176,176,176);
        printf("PRECIONE QUALQUER TECLA PARA VOLTAR AO MENU 'ALUNO'!");
        getch ();
        system("cls");
        goto g;

        break;
}
}
void cadastrolivros(){
    char a;
    liv = fopen("livros01.txt","a+b");
   if (liv == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }
   printf ("%c %c C A D A S T R A M E N T O %c %c\n\n", 176,176,176,176);

  printf ("\nCodigo do Livro: ");
         scanf("%d",&LIVRO.codLivro);
         if(encontra_livro(LIVRO.codLivro) == 1)
         {
             printf("ESTE CODIGO JA ESTA CADASTRADO \n");
            system("pause");
         }
         else
         {
         printf("\nNome do Livro: ");
         fflush(stdin);
         gets (LIVRO.nomeLivro);
         fflush(stdin);
         printf("\nAutor: ");
         gets(LIVRO.nomeAutor);
         fflush(stdin);
         printf("\nArea: ");
         fflush(stdin);
         gets(LIVRO.areaLivro);
         printf("\nQuantidade de livros: ");
         fflush(stdin);
         scanf("%c",&LIVRO.quantLivro);
         fwrite(&LIVRO,sizeof(struct livros),1,liv);
         printf("Livro adicionado ao Acervo");
         }
         fclose(liv);
}
void vizualizarlivros(){

 liv = fopen("livros01.txt","r");
    if (liv == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }

    fread(&LIVRO,sizeof(struct livros),1,liv);
    printf("\tLIVROS CADASTRADOS\n");
    while (!feof(liv))
  {
      if(LIVRO.quantLivro!='0')
  {
  printf("\nNome: %s",LIVRO.nomeLivro);
  printf("\nCodigo: %d",LIVRO.codLivro);
  printf("\nAutor: %s",LIVRO.nomeAutor);
  printf("\nArea: %s",LIVRO.areaLivro);
  printf("\nQuantidade: %c\n",LIVRO.quantLivro);}
  fread(&LIVRO,sizeof(struct livros),1,liv);
  if (feof(liv))
      {
          if (!feof(liv))
        system("Pause");
      }

  }
  system("pause");
  fclose(liv);
}
void alunos (){
    int opcao;

g:
system ("color 0f");
printf("\t\t        %c%c%c%c%c%c%c MENU ALUNO %c%c%c%c%c%c%c\n\n",176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176);
printf("\t\t     %c <1> CADASTRAR ALUNO            %c\n\n",176,176);
printf("\t\t     %c <2> REMOVER ALUNO              %c\n\n",176,176);
printf("\t\t     %c <3> EDITAR ALUNO               %c\n\n",176,176);
printf("\t\t     %c <4> LISTAR ALUNOS CADASTRADOS  %c\n\n",176,176);
printf("\t\t     %c <5> VOLTAR AO MENU PRINCIPAL   %c\n\n",176,176);


scanf("%d",&opcao);
system("cls");

switch (opcao){
     case 1:
         cadastro ();
     break;

     case 2:
         removeralu();
     break;

     case 3:
         alteraraluno();
     break;

     case 4:
        vizualizaralunos();
     break;

     case 5:
     break;

     default:

        system ("color f0");
        printf ("\n\n   %c %c %c %c %c %c !!OPCAO INVALIDA!! %c %c %c %c %c %c\n\n",176,176,176,176,176,176,176,176,176,176,176,176);
        printf("PRECIONE QUALQUER TECLA PARA VOLTAR AO MENU 'ALUNO'!");
        getch ();
        system("cls");
        goto g;

        break;
}
}
void cadastro (){

    arq = fopen("alunos00.txt","a+b");
     if (arq == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }
    printf ("%c %c C A D A S T R A M E N T O %c %c\n\n", 176,176,176,176);

         printf("\nNome do Aluno: ");
         fflush(stdin);
         gets (ALUNO.nomeAluno);
         printf ("\nCPF: ");
         gets(ALUNO.cpf);
         fflush(stdin);
         printf("\nMatricula ");
         gets(ALUNO.matricula);
         fflush(stdin);
         ALUNO.quantaluno='1';
         fwrite(&ALUNO,sizeof(struct alunos),1,arq);


         fclose(arq);
         //MOSTRAR O ALUNO CADASTRADO QUANDO TERMINAR
         //perguntar que quer cadastrar outro aluno
}
void vizualizaralunos(){


    arq = fopen("alunos00.txt","r");
    if (arq == NULL)
  {
    printf("\nErro ao abrir arquivo\n");
    return;
  }
    fread(&ALUNO,sizeof(struct alunos),1,arq);
    printf("\tALUNOS CADASTRADOS\n");
    while (!feof(arq))
  {
      if(ALUNO.quantaluno!='0')
    {
  printf("\nNome: %s",ALUNO.nomeAluno);
  printf("\nCPF: %s",ALUNO.cpf);
  printf("\nMatricula: %s\n",ALUNO.matricula);
    }
  fread(&ALUNO,sizeof(struct alunos),1,arq);
  if (feof(arq))
      {
          if (!feof(arq))
        system("Pause");
      }

  }
  system("pause");
  fclose(arq);
}
int removerlivro() {
   liv = fopen ( "livros01.txt", "r" );

    if ( liv ) {
        fclose(liv);
        printf("Removido");
        remove("livros01.txt");
        return 1;

    }else{
        printf("Nao existe nenhum cadastro.txt");
    }

    getchar();
    return 0;
}
int removeraluno() {
   arq = fopen ( "alunos00.txt", "r" );

    if ( arq ) {
        fclose(arq);
        printf("Removido");
        remove("alunos00.txt");
        return 1;

    }else{
        printf("Nao existe nenhum cadastro.txt");
    }

    getchar();
    return 0;
}//pego do site http://www.clubedohardware.com.br/forums/topic/1197145-como-remover-arquivo-em-c/
int buscalivro (void){
   int achou=-1,posicao=0;
   char marcap[50];
   abrir("rb");

   printf("\nDigite o livro a ser procurado:");
   scanf("%s",marcap);
   rewind(liv);
   while((!feof(liv))&&(achou==-1))
   {
      fread(&LIVRO,sizeof(struct livros),1, liv);
      if (!feof(liv))
    {if (strcmp(marcap, LIVRO.nomeLivro)==0)
       {if (LIVRO.quantLivro=='0')
          {posicao=-2;}
        achou=1;
       }
        else{posicao++;}
    }
     else{posicao=-1;}
   }
   if (achou==-1)
      {posicao=-1;}

   fclose(liv);
   return(posicao);
}
int buscaalunos (void){
   int achou=-1,posicao=0;
   char marcap[50];
   if((arq=fopen("alunos00.txt", "rb+"))==NULL)
     {printf("\n O arquivo nao pode ser aberto!!\n");
      getch();
      exit(1);
     }

   printf("\nDigite o aluno a ser procurado:");
   scanf("%s",marcap);
   rewind(arq);
   while((!feof(arq))&&(achou==-1))
   {
      fread(&ALUNO,sizeof(struct alunos),1, arq);
      if (!feof(arq))
    {if (strcmp(marcap, ALUNO.nomeAluno)==0)
       {if (ALUNO.quantaluno=='0')
          {posicao=-2;}
        achou=1;
       }
        else{posicao++;}
    }
     else{posicao=-1;}
   }
   if (achou==-1)
      {posicao=-1;}

   fclose(arq);
   return(posicao);
}
void alterarlivro(void){
   int pos;
   pos=buscalivro();
   if (pos==-1)
      {
    printf("\nLivro inexistente no acervo");
    getch();
      }
      else if(pos==-2)
         {
       printf("\nLivro inexistente no arquivo!");
       getch();
         }
         else
       {
           abrir("rb+");
          fseek(liv, pos*sizeof(struct livros), SEEK_SET);
          fread(&LIVRO, sizeof(struct livros), 1, liv);
          printf("\nDeseja alterar o seguinte registro...");
          printf("\nNome:%s",LIVRO.nomeLivro);
          printf("\nCodigo:%d",LIVRO.codLivro);
          printf("\nAutor:%s",LIVRO.nomeAutor);
          printf("\nArea:%s",LIVRO.areaLivro);
          printf("\nQuantidade:%c",LIVRO.quantLivro);
          getch();
          printf("\nDigite as informacoes corretas:");
          printf("\nNome:");
          fflush(stdin);
          gets(LIVRO.nomeLivro);
          printf("\nCodigo:");
          fflush(stdin);
          scanf("%d",&LIVRO.codLivro);
          printf("\nAutor:");
          fflush(stdin);
          gets(LIVRO.nomeAutor);
          printf("\nArea:");
          fflush(stdin);
          gets(LIVRO.areaLivro);
          printf("\nQuantidade:");
          fflush(stdin);
          scanf("%d",&LIVRO.quantLivro);

          fseek(liv,pos*sizeof(struct livros),SEEK_SET);
          if(fwrite(&LIVRO, sizeof(struct livros),1, liv)!=1)
             {
           printf("\nErro na gravacao...");
             }
             else
           {
              printf("\nRegravacao feita com sucesso...");
              getch();
           }
       }
   fclose(liv);
}
void removerli(void){
   int pos;
   pos=buscalivro();
   if(pos==-1)
      {
    printf("\nlivro inexistente no arquivo");
    getch();
      }
      else
    {
       if(pos==-2)
          {
        printf("\nlivro excluido do arquivo");
        getch();
          }
          else
        {
           abrir("r+");
           fseek(liv, pos*sizeof(struct livros), SEEK_SET);
           fread(&LIVRO, sizeof(struct livros), 1, liv);
           printf("\nNome: %s",LIVRO.nomeLivro);
           printf("\nCodigo: %d",LIVRO.codLivro);
           printf("\nAutor: %s",LIVRO.nomeAutor);
           printf("\nArea: %s",LIVRO.areaLivro);
           printf("\nQuantidade: %c",LIVRO.quantLivro);
           printf("\nEste Registro #%d sera excluido",(pos+1));
           getch();
           //strcpy(reg.status,"0");
          LIVRO.quantLivro='0';
          LIVRO.codLivro=0;

          printf("%s",LIVRO.nomeLivro);
           fseek(liv, pos*sizeof(struct livros), SEEK_SET);
           if(fwrite(&LIVRO, sizeof(struct livros), 1, liv)!=1)
         {
            printf("\nErro na grava‡ao...");
            getch();
         }
         else
         {
            printf("\nExclusao feita com sucesso!");
            getch();
         }
        }
    }
   fclose(liv);
}
void abrir(char tipo[3]){
     if((liv=fopen("livros01.txt", tipo))==NULL)
     {printf("\n O arquivo nao pode ser aberto!!\n");
      getch();
      exit(1);
     }
}
void alteraraluno(void){
   int pos;
   pos=buscaalunos();
   if (pos==-1)
      {
    printf("\nAluno inexistente no Cadastro");
    getch();
      }
      else if(pos==-2)
         {
       printf("\nAluno inexistente no arquivo!");
       getch();
         }
         else
       {
            if((arq=fopen("alunos00.txt", "rb+"))==NULL)
     {printf("\n O arquivo nao pode ser aberto!!\n");
      getch();
      exit(1);
     }
          fseek(arq, pos*sizeof(struct alunos), SEEK_SET);
          fread(&ALUNO, sizeof(struct alunos), 1, arq);
          printf("\nDeseja alterar o seguinte registro...");
          printf("\nNome:%s",ALUNO.nomeAluno);
          printf("\nMatricula:%s",ALUNO.matricula);
          printf("\nCPF:%s",ALUNO.cpf);
          getch();
          printf("\nDigite as informacoes corretas:");
          printf("\nNome:");
          fflush(stdin);
          gets(ALUNO.nomeAluno);
          printf("\nMatricula:");
          fflush(stdin);
          gets(ALUNO.matricula);
          printf("\nCPF:");
          fflush(stdin);
          gets(ALUNO.cpf);

          fseek(arq,pos*sizeof(struct alunos),SEEK_SET);
          if(fwrite(&ALUNO, sizeof(struct alunos),1, arq)!=1)
             {
           printf("\nErro na gravacao...");
             }
             else
           {
              printf("\nRegravacao feita com sucesso...");
              getch();
           }
       }
   fclose(liv);
}

void removeralu(void){
   int pos;
   pos=buscaalunos();
   if(pos==-1)
      {
    printf("\nAluno inexistente no arquivo");
    getch();
      }
      else
    {
       if(pos==-2)
          {
        printf("\nAluno excluido do arquivo");
        getch();
          }
          else
        {
           if((arq=fopen("alunos00.txt", "rb+"))==NULL)
     {printf("\n O arquivo nao pode ser aberto!!\n");
      getch();
      exit(1);
     }
           fseek(arq, pos*sizeof(struct alunos), SEEK_SET);
           fread(&ALUNO, sizeof(struct alunos), 1, arq);
           printf("\nNome: %s",ALUNO.nomeAluno);
           printf("\nMatricula: %s",ALUNO.matricula);
           printf("\nCPF: %s",ALUNO.cpf);

           printf("\nEste Aluno sera excluido");
           getch();
           //strcpy(reg.status,"0");
          ALUNO.quantaluno='0';

           fseek(arq, pos*sizeof(struct alunos), SEEK_SET);
           if(fwrite(&ALUNO, sizeof(struct alunos), 1, arq)!=1)
         {
            printf("\nErro na grava‡ao...");
            getch();
         }
         else
         {
            printf("\nExclusao feita com sucesso!");
            getch();
         }
        }
    }
   fclose(arq);
}
