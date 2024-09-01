#include <stdio.h>
#include <string.h>

typedef struct senha {
        char tipo[20];
        int numero;
}Senha;

typedef struct pessoa{
	char nome[20];
	Senha senha;
}Pessoa;

Senha gera_senha();

void imprimeSenha(Senha cliente);

void imprimePessoa(Pessoa p);

int main(){
	Pessoa p1 = {"Fulano", gera_senha()};
	imprimePessoa(p1);
        return 0;
}

Senha gera_senha(){
        static int senha = 0;
        char *atendimento[2] = {"Prioridade", "Normal"};
        struct senha cliente;
        strcpy(cliente.tipo, atendimento[senha%2]);
        cliente.numero = senha++;
        return cliente;
}

void imprimeSenha(Senha cliente){
        printf("Senha: %s %d\n", cliente.tipo, cliente.numero);
}

void imprimePessoa(Pessoa p){
	printf("Paciente: %s\n", p.nome);
	imprimeSenha(p.senha);
}
