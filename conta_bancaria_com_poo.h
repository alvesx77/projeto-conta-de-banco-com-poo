#ifndef CONTA_BANCARIA_COM_POO_H_INCLUED  
#define CONTA_BANCARIA_COM_POO_H_INCLUED
#include <iostream>
#include <string>
//classe responsavel pelos clientes
class conta{
    private:
        std::string nome_da_conta;
        int numero_da_conta,senha;
        float saldo;
    public:
        void set_nome(std::string nome);
        std::string get_nome();

        void set_numero_da_conta(int num_c);
        int get_numero_da_conta();

        void set_saldo(float sald);
        float get_saldo();

        void set_senha(int pass);
        int get_senha();

        void add_cli(conta *&client,std::string nome_d_cont,int num_d_cont,int pass,float saldo);
        conta *prox;
};
//função responsavel pela troca de nome dos contas
void conta::set_nome(std::string nome){
    nome_da_conta=nome;
}
std::string conta::get_nome(){
    return nome_da_conta;
}

//função responsavel pela troca do numero das contas
void conta::set_numero_da_conta(int num_c){
    numero_da_conta=num_c;
}
int conta::get_numero_da_conta(){
    return numero_da_conta;
}


//função responsavel pela troca de senha das contas
void conta::set_senha(int pass){
    senha=pass;
}
int conta::get_senha(){
    return senha;
}

//função responsavel pelo transação das contas
void conta::set_saldo(float sald){
    saldo=sald;
}
float conta::get_saldo(){
    return saldo;
}

//função responsavel em fazer o encadeamento dos clientes
void conta::add_cli(conta *&client,std::string nome_d_cont,int num_d_cont,int pass,float saldo){
    conta *novo=new conta;
    novo->set_nome(nome_d_cont);
    novo->set_numero_da_conta(num_d_cont);
    novo->set_saldo(saldo);
    novo->set_senha(pass);
    novo->prox=NULL;
    if (client==NULL)
    {
        client=novo;
    }
    else{
        conta *aux=client;
        while (aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=novo;
    }
}
#endif