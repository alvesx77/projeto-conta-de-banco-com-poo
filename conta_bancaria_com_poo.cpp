#include <iostream>
#include "conta_bancaria_com_poo.h"

using namespace std;

//função responsavel em criar um menu para os clientes
void menu(){
    cout<<"digite 1 para se cadastrar:\ndigite 2 para deposito:\ndigite 3 para saque:\ndigite 4 para encerar:\n";
}
//função responsavel em verificar se o numero da conta existe
bool ver_num_cont(conta *clients,int num_c_t){
    while (clients!=NULL)
    {
        if (clients->get_numero_da_conta()==num_c_t)
        {
            return true;
        }
        clients=clients->prox;
    }
    return false;
}

//função responsavel em verificar se a senha e valida
bool ver_pass(conta *clients,int pass){
    while (clients !=NULL)
    {
        if (clients->get_senha()==pass)
        {
            return true;
        }
        clients=clients->prox;
    }
    return false;
}

//funçao responsavel em retornar o cliente que possui o numero da conta e senha digitadas
conta *buscar_conta(conta *clients,int num_de_conta){
    while (clients!=NULL)
    {
        if (clients->get_numero_da_conta()==num_de_conta)
        {
            return clients;
        }
        clients=clients->prox;
    }
}

int main(){
    conta *clients=new conta;
    string nome;
    int num_da_cont=100,inter=0,senha;
    float saldo;
    while (inter<4)
    {
        menu();
        cout<<"digite a opcao q deseja: ";
        cin>>inter;
        if (inter<4)
        {   //opção de cadastro dos clientes
            if (inter==1)
            {
                cout<<"digite seu nome: ";
                cin>>nome;
                cout<<"o numero da sua conta é "<<num_da_cont<<endl;
                cout<<"digite a sua senha: ";
                cin>>senha;
                cout<<"deposite algum valor: ";
                cin>>saldo;
                clients->add_cli(clients,nome,num_da_cont,senha,saldo);
                num_da_cont++;
            }
            //opçao de deposito dos clientes
            else if (inter==2)
            {   int cont=0,n_c_t,s_t;
                float saldo_d,saldo_atual;
                while (cont<3)
                {   
                    cout<<"digite o numero da sua conta: ";
                    cin>>n_c_t;
                    if (ver_num_cont(clients,n_c_t)==true)
                    {
                        cout<<"digite sua senha: ";
                        cin>>s_t;
                        if (ver_pass(clients,s_t)==true)
                        {   
                            conta *conta_aux=buscar_conta(clients,n_c_t);
                            cout<<"digite quanto vai depositar: ";
                            cin>>saldo_d;
                            saldo_atual=conta_aux->get_saldo();
                            conta_aux->set_saldo(saldo_atual+saldo_d);
                            cout<<"agora seu saldo e de "<<conta_aux->get_saldo()<<"\n";
                        }
                        else{
                            cont++;
                            cout<<"voce errou sua senha da sua conta so le resta "<<3-cont<<"tentativas\n";
                        }
                    }
                    else{
                        cont++;
                        cout<<"voce erro o numero da sua conta so le resta "<<3-cont<<" tentativas\n";
                    }
                }  
            }
            //opção de saque dos clientes 
            else{
                int cont=0,n_c_t,s_t;
                float saldo_d,saldo_atual;
                while (cont<3)
                {   
                    cout<<"digite o numero da sua conta: ";
                    cin>>n_c_t;
                    if (ver_num_cont(clients,n_c_t)==true)
                    {
                        cout<<"digite sua senha: ";
                        cin>>s_t;
                        if (ver_pass(clients,s_t)==true)
                        {   
                            conta *conta_aux=buscar_conta(clients,n_c_t);
                            cout<<"digite quanto vai sacar: ";
                            cin>>saldo_d;
                            saldo_atual=conta_aux->get_saldo();
                            conta_aux->set_saldo(saldo_atual-saldo_d);
                            cout<<"agora seu saldo e de "<<conta_aux->get_saldo()<<"\n";
                        }
                        else{
                            cont++;
                            cout<<"voce errou sua senha da sua conta so le resta "<<3-cont<<"tentativas\n";
                        }
                    }
                    else{
                        cont++;
                        cout<<"voce erro o numero da sua conta so le resta "<<3-cont<<" tentativas\n";
                    }
                } 
            
            }
        }
        
    }
    return 0;
}