#include <iostream>
using namespace std;

class Pessoa {
	public:
	int idade;
	string nome;
	Pessoa *filhoEsquerdo;
	Pessoa *filhoDireito;
	
	public:
	//Construtor
	Pessoa(){

		this->filhoEsquerdo = NULL;
		this->filhoDireito = NULL;

	};
	Pessoa (string nome, int idade){
		this->nome =  nome;
		this->idade = idade;
		this->filhoEsquerdo = NULL;
		this->filhoDireito = NULL;
	};
	~Pessoa(){

		cout<<"pessoa: "<<this->nome<<" deletada"<<endl;
	};

	void setNome(string nome){
		this->nome = nome;
	};

	string getNome(){
		return nome;
	};

	void setIdade(int idade){
		this->idade = idade;
	};

	int getIdade(){
		return idade;
	};

	void setFilhoEsquerdo(Pessoa *P){
		filhoEsquerdo = P;
	};

	Pessoa * getFilhoEsquerdo(){
		return filhoEsquerdo;
	};

	void setFilhoDireito(Pessoa *P){
		filhoDireito = P;
	};

	Pessoa * getFilhoDireito(){
		return filhoDireito;
	};
	//Inserir
	void inserirFilho (Pessoa *filho){
		// cout<<filho->getIdade() << filho->getNome()<<endl;

		if (this->idade > filho->idade){
			if (this->filhoEsquerdo == NULL)
				this->filhoEsquerdo =  filho;
			else
				this->filhoEsquerdo->inserirFilho(filho);
		}
		else {
			if (this->filhoDireito == NULL)
				this->filhoDireito = filho;
			else
				this->filhoDireito->inserirFilho(filho);
		};
	};
/*----------------------------------FUNÇÕES LISTAR-------------------------------------*/
	//Impressão em Pré
	void listaPre(){
		
		cout << "Nome: " << this->nome << "  Idade: " << this->idade << endl;
		if (filhoEsquerdo != NULL) filhoEsquerdo->listaPre();
		if (filhoDireito != NULL) filhoDireito->listaPre();	
	};
	//Impressão em Ordem
	void listaOrdem(){
		if (filhoEsquerdo != NULL) filhoEsquerdo->listaOrdem();
		cout << "Nome: " << this->nome << "  Idade: " << this->idade << endl;
		if (filhoDireito != NULL) filhoDireito->listaOrdem();	
	};
	//Impressão em pós
	void listaPos(){
		if (filhoEsquerdo != NULL) filhoEsquerdo->listaPos();
		if (filhoDireito != NULL) filhoDireito->listaPos();	
		cout << "Nome: " << this->nome << "  Idade: " << this->idade << endl;
	};
/*----------------------------------------------------------------------------------------*/

/*----------------------------------FUNÇÕES DELETAR---------------------------------------*/
	//DELETAR TODA A ARVORE
        void deletarArvore (){
		if (filhoEsquerdo != NULL) 
			filhoEsquerdo->deletarArvore();
		if (filhoDireito != NULL) 
			filhoDireito->deletarArvore();
		delete this;	
	};
	//DELETAR NO ESPECIFICO
	void removerNo (int idade,Pessoa *pai){
		if(this->idade==idade){
			if(this->filhoEsquerdo==NULL && this->filhoDireito==NULL){//SE NAO TEM FILHO
					//cout<<"chegou aqui"<<endl;
				if(pai->idade > this->idade){
					pai->filhoEsquerdo = NULL;
					delete this;
					return;
					//cout<<"chegou aqui tambem"<<endl;
				}
				else{
					pai->filhoDireito = NULL;
					delete this;
					return;
				}
			}
			else{//SE TEM ALGUM FILHO
				if(this->filhoEsquerdo==NULL){//SE TEM SÓ O FILHO A DIREITA
					if(pai->idade > this->idade){
							pai->filhoEsquerdo = this->filhoDireito;
					}else{
						pai->filhoDireito = this->filhoDireito;
					}
					delete this;
				}else if(this->filhoDireito==NULL){//SE TEM SÓ O FILHO A ESQUERDA
						if(pai->idade>this->idade)
							pai->filhoEsquerdo=this->filhoEsquerdo;
						else
							pai->filhoDireito = this->filhoEsquerdo;						
						delete this;
					}else{//SE TEM OS DOIS FILHOS
						if(filhoDireito->filhoEsquerdo==NULL){//SE O FILHO A DIREITA NAO TEM FILHO A ESQUERDA
								if(pai->idade>this->idade)
									pai->filhoEsquerdo=this->filhoDireito;
								else
									pai->filhoDireito=this->filhoDireito;
								filhoDireito->filhoEsquerdo=this->filhoEsquerdo;
						}else{//SE O FILHO A DIREITA TEM UM FILHO A ESQUERDA
							Pessoa *fMaisEsq=filhoDireito->filhoEsquerdo, *paiFMaisEsq= filhoDireito;//variaveis pra referenciar o filho mais a esquerda e o pai dele
							while(fMaisEsq->filhoEsquerdo!=NULL){
								paiFMaisEsq=fMaisEsq;
								fMaisEsq=fMaisEsq->filhoEsquerdo;
								
							}
							if(pai->idade>this->idade)
								pai->filhoEsquerdo=fMaisEsq;
							else
								pai->filhoDireito=fMaisEsq;
							paiFMaisEsq->filhoEsquerdo=fMaisEsq->filhoDireito;
							fMaisEsq->filhoEsquerdo=this->filhoEsquerdo;
							fMaisEsq->filhoDireito=this->filhoDireito;
							delete this;
						}
				}
			}
		}else{
				if(this->filhoEsquerdo!=NULL)
					this->filhoEsquerdo->removerNo(idade,this);
				if(this->filhoDireito!=NULL)
					this->filhoDireito->removerNo(idade,this);
			}
		
	};
/*----------------------------------------------------------------------------------------*/



	int contarNos(){
		int quantidade = 0;
		if (filhoEsquerdo != NULL) quantidade = filhoEsquerdo->contarNos();
		if (filhoDireito != NULL) quantidade = quantidade + filhoDireito->contarNos();	
		return quantidade+1;
	};

	int somarNos(){
		int total = 0;
		if (filhoEsquerdo != NULL) total = filhoEsquerdo->somarNos();
		if (filhoDireito != NULL) total = total + filhoDireito->somarNos();	
		return total+this->idade;
	};

	int profundidadeNos(){
		int pEsquerdo = 0, pDireito = 0;
		if (filhoEsquerdo != NULL) pEsquerdo = filhoEsquerdo->profundidadeNos()+1;
		if (filhoDireito != NULL) pDireito = filhoDireito->profundidadeNos()+1;
		return (pEsquerdo > pDireito) ? pEsquerdo : pDireito; 
	};
};
