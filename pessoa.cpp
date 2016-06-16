#include <iostream>
using namespace std;

class Pessoa {
	public:
	int idade,profunD,profunE;
	string nome;
	Pessoa *filhoEsquerdo;
	Pessoa *filhoDireito;

	public:
	//Construtor
	Pessoa(){

		this->filhoEsquerdo = NULL;
		this->filhoDireito = NULL;
		this->profunD=0;
		this->profunE=0;

	};
	Pessoa (string nome, int idade){
		this->nome =  nome;
		this->idade = idade;
		this->filhoEsquerdo = NULL;
		this->filhoDireito = NULL;
		this->profunD=0;
		this->profunE=0;
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
	void setProfunDireita(int p){
		profunD = p;
	};

	int getProfunDireita(){
		return profunD;
	};
	void setProfunEsquerda(int p){
		profunE = p;
	};

	int getProfunEsquerda(){
		return profunE;
	};
	int getFatorBalanceamento(){
		return profunE - profunD;
	};

	//Inserir
	void inserirFilho (Pessoa *filho, Pessoa **raiz){
        if((*raiz)==NULL)
            (*raiz)=filho;
        else{
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
		}
		(*raiz)->atualizarFBs(&(*raiz));
		(*raiz)->verificarBalanceamento(&(*raiz),1);

	};
	void inserirFilho (Pessoa *filho){
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
	void removerNo (int idade,Pessoa *pai, Pessoa **raiz){
        if(this->idade==idade){
            if(this->filhoEsquerdo!=NULL && this->filhoDireito!=NULL){//SE TEM DOIS FILHOS
                if(filhoDireito->filhoEsquerdo==NULL){//SE O FILHO A DIREITA NAO TEM FILHO A ESQUERDA
                        if(this==(*raiz))
                            (*raiz)=this->getFilhoDireito();
                        else
                            herdaNeto(pai,this,this->getFilhoDireito());
                        this->getFilhoDireito()->setFilhoEsquerdo(this->getFilhoEsquerdo());
                        delete this;
                }else{//SE O FILHO A DIREITA TEM UM FILHO A ESQUERDA
                     Pessoa *fMaisEsq=filhoDireito->filhoEsquerdo, *paiFMaisEsq= filhoDireito;//variaveis pra referenciar o filho mais a esquerda e o pai dele
                    while(fMaisEsq->filhoEsquerdo!=NULL){
                        paiFMaisEsq=fMaisEsq;
                        fMaisEsq=fMaisEsq->filhoEsquerdo;
                    }
                    if(this==(*raiz))
                        (*raiz)=fMaisEsq;
                    else
                        herdaNeto(pai,this,fMaisEsq);

                    paiFMaisEsq->filhoEsquerdo=fMaisEsq->filhoDireito;
                    fMaisEsq->filhoEsquerdo=this->filhoEsquerdo;
                    fMaisEsq->filhoDireito=this->filhoDireito;
                    delete this;
                }
            }else{
                if(this->filhoEsquerdo!=NULL || this->filhoDireito!=NULL){//SE TEM ALGUM FILHO
                    if(this->filhoDireito!=NULL)//SE TEM SÓ O FILHO A DIREITA
                        if(this==(*raiz))
                            (*raiz)=this->getFilhoDireito();
                        else
                            herdaNeto(pai,this,this->getFilhoDireito());
                    else //SE TEM SÓ O FILHO A ESQUERDA
                        if(this==(*raiz))
                            (*raiz)=this->getFilhoEsquerdo();
                        else
                            herdaNeto(pai,this,this->getFilhoEsquerdo());
                    delete this;
                }
                else{
                    if(this==(*raiz))
                        (*raiz)=NULL;
                    else
                        herdaNeto(pai,this,NULL);
                    delete this;
                }
            }

        }else{
                if(this->filhoEsquerdo!=NULL && idade<this->idade)
                    this->filhoEsquerdo->removerNo(idade,this,raiz);
                if(this->filhoDireito!=NULL && idade>this->idade)
                    this->filhoDireito->removerNo(idade,this,raiz);
            }
            if(this==(*raiz))
                (*raiz)->verificarBalanceamento(&(*raiz),1);
	};
	//Usada para procurar o filho mais à esquerda do filho à direita do nó a ser deletado
	Pessoa *paiDoFilhoMaisAEsquerda(){
		Pessoa *pai=this;
		if(this->getFilhoEsquerdo()->getFilhoEsquerdo()!=NULL)
			pai = this->getFilhoEsquerdo()->paiDoFilhoMaisAEsquerda();
		return pai;
	};
	//Função que referencia o neto direto no avô, para o pai ser deletado
	void herdaNeto (Pessoa *pai, Pessoa *filho, Pessoa *neto){
		if (pai->idade > filho->idade)
			pai->setFilhoEsquerdo(neto);
		else
			pai->setFilhoDireito(neto);
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
	void atualizarFBs(Pessoa **raiz){
		if((*raiz)==NULL)
			cout<<"arvore vazia!"<<endl;
		else{
			if ((*raiz)->filhoEsquerdo != NULL){
				setProfunEsquerda(filhoEsquerdo->profundidadeNos()+1);
				filhoEsquerdo->atualizarFBs();
			}else
				setProfunEsquerda(0);
			if ((*raiz)->filhoDireito != NULL){
				setProfunDireita(filhoDireito->profundidadeNos()+1);
				filhoDireito->atualizarFBs();
			}else
				setProfunDireita(0);
		}
	};
	void atualizarFBs(){

		if (filhoEsquerdo != NULL){
			setProfunEsquerda(filhoEsquerdo->profundidadeNos()+1);
			filhoEsquerdo->atualizarFBs();
		}else
			setProfunEsquerda(0);
		if (filhoDireito != NULL){
			setProfunDireita(filhoDireito->profundidadeNos()+1);
			filhoDireito->atualizarFBs();
		}else
			setProfunDireita(0);
	};
	void listarFBs(Pessoa **raiz){
		if((*raiz)==NULL)
			cout<<"Arvore vazia!"<<endl;
		else{
			if((*raiz)->filhoEsquerdo!=NULL) (*raiz)->filhoEsquerdo->listarFBs();
			cout<<"no: "<<(*raiz)->idade<<"FB:"<<(*raiz)->getFatorBalanceamento()<<endl;
			if((*raiz)->filhoDireito!=NULL) (*raiz)->filhoDireito->listarFBs();
		}
	};
	void listarFBs(){
		if(this->filhoEsquerdo!=NULL) this->filhoEsquerdo->listarFBs();
		cout<<"no: "<<this->idade<<"FB:"<<this->getFatorBalanceamento()<<endl;
		if(this->filhoDireito!=NULL) this->filhoDireito->listarFBs();
	};
	void rotacaoSimplesDireita(Pessoa **referenciaPai){
		(*referenciaPai) = this->filhoEsquerdo;
		this->filhoEsquerdo = (*referenciaPai)->filhoDireito;
		(*referenciaPai)->filhoDireito = this;

	};
	void rotacaoSimplesEsquerda(Pessoa **referenciaPai){
        (*referenciaPai) = this->filhoDireito;
		this->filhoDireito = (*referenciaPai)->filhoEsquerdo;
		(*referenciaPai)->filhoEsquerdo=this;

	};
	void rotacaoDuplaDireita(Pessoa **referenciaPai){
		this->filhoEsquerdo->rotacaoSimplesEsquerda(&(this->filhoEsquerdo));
		this->rotacaoSimplesDireita(&(*referenciaPai));
	};
	void rotacaoDuplaEsquerda(Pessoa **referenciaPai){
		this->filhoDireito->rotacaoSimplesDireita(&(this->filhoDireito));
		this->rotacaoSimplesEsquerda(&(*referenciaPai));
	};
	void verificarBalanceamento(Pessoa **raiz, int i){
        if((*raiz)==NULL)
            cout<<"A arvore está vazia!"<<endl<<endl;
        else{
            if(this->filhoEsquerdo!=NULL)
                this->filhoEsquerdo->verificarBalanceamento(&(this->filhoEsquerdo));
            if(this->filhoDireito!=NULL)
                this->filhoDireito->verificarBalanceamento(&(this->filhoDireito));
            //Pos-ordem
            this->atualizarFBs();
            if(this->getFatorBalanceamento()==2){
                if(this->filhoEsquerdo->getFatorBalanceamento()==1)
                    this->rotacaoSimplesDireita(&(*raiz));
                else
					if(this->filhoEsquerdo->getFatorBalanceamento()==-1)
                		this->rotacaoDuplaDireita(&(*raiz));
            }else{
                if(this->getFatorBalanceamento()==-2){
                    if(this->filhoDireito->getFatorBalanceamento()==-1)
                        this->rotacaoSimplesEsquerda(&(*raiz));
                    else
                        this->rotacaoDuplaEsquerda(&(*raiz));
                }
            }
        }
	};
	void verificarBalanceamento(Pessoa **referenciaPai){

        if(this->filhoEsquerdo!=NULL)
            this->filhoEsquerdo->verificarBalanceamento(&(this->filhoEsquerdo));
        if(this->filhoDireito!=NULL)
            this->filhoDireito->verificarBalanceamento(&(this->filhoDireito));
        //Pos-ordem
        this->atualizarFBs();
        if(this->getFatorBalanceamento()==2){
            if(this->filhoEsquerdo->getFatorBalanceamento()==1){
                this->rotacaoSimplesDireita(&(*referenciaPai));
			}
            else{
				if(this->filhoEsquerdo->getFatorBalanceamento()==-1)
            		this->rotacaoDuplaDireita(&(*referenciaPai));
			}
        }else{
            if(this->getFatorBalanceamento()==-2){
                if(this->filhoDireito->getFatorBalanceamento()==-1)
                    this->rotacaoSimplesEsquerda(&(*referenciaPai));
                else
					if(this->filhoDireito->getFatorBalanceamento()==1)
                		this->rotacaoDuplaEsquerda(&(*referenciaPai));
            }
        }
	};//Versao p/ 05/02/2016





























};
