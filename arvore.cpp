#include <iostream>
#include <bits/stdc++.h> 
#include <queue>


using namespace std;

template <class T>
class No {
	public:
		T el;
		No<T> *left,*right;
		No<T>(){
			left=right=0;			
		}
		
		No<T>(T e,No<T> *l=0,No<T> *r=0){
			el=e;
			left=l;
			right=r;
		}
};

template <class T>
class Arvore {
	protected:
		No<T> *root;
	public:
		Arvore() {
			root = 0;			
		}
		
		Arvore(No<T> *r) {
			root = r;
		}

        No<T> * getRoot() {
            return this->root;
        }

    void insert(T el){
        No<T> *p=root, *prev=0;
        while (p!=0){
            prev=p;
            if (el<p->el)
            p=p->left;
            else p=p->right;
            }

        if (root==0)
        root=new No<T>(el);
        else if (el < prev->el)
        prev->left=new No<T>(el);
        else prev->right=new No<T>(el);

        }

     No<T> * insertWihtIserc(No<T> *no, No<T> *root) {
            if (root == 0) return no; 
            if (no->el < root->el) {
                root->left = insertWihtIserc(no, root->left);
            } else if (no->el > root->el) {
                root->right = insertWihtIserc(no, root->right);
            }

            return root;
        }

		void preOrderRecursion(No<T> *n){
		    //RAIZ-ESQ-DIR
            if (root==NULL){
                cout << "<EMPTY>";
            } else {
                if (n != NULL){
                    cout << "<" << n->el;
                    preOrderRecursion(n->left);
                    preOrderRecursion(n->right);
                    cout << ">";
                } else {
                    cout << "<>";
                }
            }
        }

        void inOrderRecursion(No<T> *n){
            //ESQ-RAIZ-DIR
            if (root==NULL){
                cout << "<EMPTY>";
            } else {
                if (n != NULL){
                    inOrderRecursion(n->left);
                    cout << "<" << n->el;
                    inOrderRecursion(n->right);
                    cout << ">";
                } else {
                    cout << "<>";
                }
            }
        }

        void postOrderRecursion(No<T> *n){
            //ESQ-DIR-RAIZ
            if (root==NULL){
                cout << "<EMPTY>";
            } else {
                if (n != NULL){
                    postOrderRecursion(n->left);
                    postOrderRecursion(n->right);
                    cout << "<" << n->el;
                    cout << ">";
                } else {
                    cout << "<>";
                }
            }
        }

        void preOrderWithStack() {
            stack<No<T>*> stack;
            No<T> *prev = root;
            
            if (prev != 0) {
                stack.push(prev);
                while (!stack.empty()) {
                    prev = stack.top();
                    cout << stack.top()->el << " ";
                    stack.pop();
                    if (prev->right != 0) {
                        stack.push(prev->right);
                    }
                    if (prev->left != 0) {
                        stack.push(prev->left);
                    }
                }
            }
            cout<<"\n";
        }

        void inOrderWithStack() {
            stack<No<T>*> stack;
            No<T> *prev = root;

            while (prev != 0 || stack.empty() == false) { 

                while (prev !=  0) { 
                    stack.push(prev); 
                    prev = prev->left; 
                } 
        
                prev = stack.top(); 
                stack.pop(); 
        
                cout << prev->el << " "; 
        
                prev = prev->right; 
            }
        }

        void postOrderWithStack() {
            stack<No<T>*> stack;
            No<T> *prev = root;

            while (prev != 0 || stack.empty() == false) { 

                if(prev !=  0) { 
                    stack.push(prev); 
                    prev = prev->left; 
                } 
        
                else{
                    if(stack.empty() == true){
                        break;
                        }
                    else{
                        if(stack.top()->right == 0){
                            prev = stack.top();
                            stack.pop();
                            cout << prev->el << " ";
                            while(prev == stack.top()->right){
                                cout << stack.top()->el << " ";
                                prev = stack.top();
                                stack.pop();
                                if (stack.empty()){
                                    break;
                                }
                            }
                        }
                        if (stack.empty() == false){
                            prev = stack.top()->right;
                        }
                        else{
                            prev = 0;
                        }
                    }

                }
                  
            }
        }

    void RemoverFusao(No <T> *node)
    {
        No<T> *temp = node;
        if (node != 0){
            if (!node->right)
                node = node->left;

            else if (node->left == 0)
                node = node->right;
            else{
                temp = node->left;
                while (temp->right != 0){
                    temp = temp->right;
                }
                temp->right = node->right;
                temp = node;
                node = node->left;
            }
            cout << temp->el << "deletado\n";
            delete temp;
        }
    }

    void Procurar(T el){
        No<T> *node = root;
        No<T> *prev = 0;
        while (node!=0){
            if (node->el == el){
                break;
            }
            prev = node;
            if(el < node ->el){
                node = node->left;
            }
            else node = node->right;
        }
        if (node != 0 && node->el==el){
            if(node==root){
                RemoverFusao(root);
            }
            else
            {
                if(prev->left==node){
                    RemoverFusao(prev->left);
                }
                else
                    RemoverFusao(prev->right);
            }
        }
        else if (root!=0){
                    cout<<"elemento "<<el<< "nao esta na arvore\n";
                }
                else cout<<"a arvore esta vazia\n";
            }
            

    void ProcurarCopia(T el){
        No<T> *node = root;
        No<T> *prev = 0;
        while (node!=0){
            if (node->el == el){
                break;
            }
            prev = node;
            if(el < node ->el){
                node = node->left;
            }
            else node = node->right;
        }
        if (node != 0 && node->el==el){
            if(node==root){
                RemoverCopia(root);
            }
            else
            {
                if(prev->left==node){
                    RemoverCopia(prev->left);
                }
                else
                    RemoverCopia(prev->right);
            }
        }
        else if (root!=0){
                    cout<<"elemento "<<el<< "nao esta na arvore\n";
                }
                else cout<<"a arvore esta vazia\n";
            }

    void RemoverCopia(No<T> *node){
        No<T> *previous, *tmp = node;
        if (node->right == 0){
            node = node->left;
        }
        else if (node->left == 0){
            node = node->right;
        }
        else{
            tmp = node->left; 
            previous = node;
            while (tmp->right != 0){
                previous = tmp;
                tmp = tmp->right;
            }
            node->el = tmp->el;
            if (previous == node){
                previous->left = tmp->left;
            }
            else{
                previous->right = tmp->left;
                }
        }
        delete tmp;
    }

};

int main(){
    No<int> *d= new No<int>(2);
    No<int> *f= new No<int>(12);
    No<int> *g= new No<int>(20);
    No<int> *i= new No<int>(29);
    No<int> *h= new No<int>(31,i);
	No<int> *b= new No<int>(10,d,f);
	No<int> *c= new No<int>(25,g,h);
	No<int> *a= new No<int>(13,b,c);
	Arvore<int> *arv = new Arvore<int>(a);
    No<int> *x= new No<int>(6);
    // arv->insert(1);
    // arv->insertWihtIserc(x, arv->getRoot());
	// arv->preOrderRecursion(a);
    // arv->preOrderWithStack();
    // arv->inOrderRecursion(a);
    // arv->postOrderRecursion(a);
    arv->preOrderWithStack();
    arv->Procurar(20);
    arv->preOrderWithStack();
    arv->ProcurarCopia(31);
    arv->preOrderWithStack();

};
