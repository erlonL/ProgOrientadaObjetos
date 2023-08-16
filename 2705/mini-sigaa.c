#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 40
#define TAM_DEP 20
#define TAM_DSCP 60
#define ARG_COUNT 2

/*
 * MINI SIGAA
 * Este código é um exemplo de como implementar estruturas e funções em C 
 * para representar e manipular alunos e turmas (como um mini SIGAA).
 */

// Estrutura para representar um professor
typedef struct {
    char nome[TAM_NOME];
    char codigo_dep[TAM_DEP];
    int ano_contratacao;
    char disciplina[TAM_DSCP];
} t_professor;

// Estrutura para representar um aluno
typedef struct {
	char nome[TAM_NOME];
	int matricula;
	float cra;
} t_aluno;

// Estrutura para representar uma turma
typedef struct {
	t_aluno* alunos;
    t_professor* professor;
	int tam_turma;
	int sala;
} t_turma;

// Função para cadastrar um aluno
void cadastra_aluno(t_aluno *a) {
	char c;
	printf("Digite o nome do aluno: ");
	scanf("%[^\n]", a->nome);
	printf("Digite a matricula do aluno: ");
	scanf("%d", &a->matricula);
	printf("Digite o CRA do aluno: ");
	scanf("%f", &a->cra);
	scanf("%c", &c); //ATS
}

// Função para cadastrar um professor
void cadastra_professor(t_professor *p) {
    char c;
    printf("Digite o nome do professor: ");
    scanf("%[^\n]", p->nome);
    printf("Digite o departamento do professor: ");
    scanf("%[^\n]", p->codigo_dep);
    printf("Digite o ano de contratação do professor: ");
    scanf("%d", &p->ano_contratacao);
    printf("Digite a disciplina lecionada pelo professor: ");
    scanf("%[^\n]", p->disciplina);
    scanf("%c", &c); //ATS (DNV)
}

// Função para exibir informações de um aluno
void exibe_aluno(t_aluno *a) {
	printf("Nome: %s\n", a->nome);
	printf("Matricula: %d\n", a->matricula);
	printf("CRA: %f\n", a->cra);
}

// Função para exibir informações de um professor
void exibe_professor(t_professor *p) {
    printf("Nome: %s\n", p->nome);
    printf("Departamento: %s\n", p->codigo_dep);
    printf("Disciplina: %s\n", p->disciplina);
    printf("Ano de contratação: %d\n", p-> ano_contratacao);
}

// Função para associar um professor a uma turma
void associa_professor_turma(t_turma *t, t_professor *p) {
    t->professor = &p;
}

// Função para cadastrar uma turma
void cadastra_turma(t_turma* t, int tam) {
	printf("Cadastrando turma com %d alunos...\n", tam);
	t->alunos = (t_aluno*) malloc(sizeof(t_aluno) * tam);
	t->tam_turma = tam;
	for (int i = 0; i < tam; i++) {
		cadastra_aluno(&t->alunos[i]);
	}

	printf("Digite o numero da sala: ");
	scanf("%d", &t->sala);
}

// Função para exibir informações de uma turma
void exibe_turma(t_turma* t) {
	printf("Sala: %d\n", t->sala);
	for (int i = 0; i < t->tam_turma; i++) {
		exibe_aluno(&t->alunos[i]);
	}
    printf("Professor associado à turma: \n");
    exibe_professor(t->professor);

}

int main(int argc, char** argv) {
	t_turma turma;
	int tam_turma = 0;
	
	if (argc != ARG_COUNT) {
		printf("Use: %s <NUMERO_DE_ALUNOS>\n", argv[0]);
		exit(0);
	} else {
		tam_turma = atoi(argv[1]);
		cadastra_turma(&turma, tam_turma);
		exibe_turma(&turma);
	}
    
    /*
	for (int i = 0; i < tam_turma; i++) {
		free(turma.alunos[i]);
	}
    */

	return 0;
}
