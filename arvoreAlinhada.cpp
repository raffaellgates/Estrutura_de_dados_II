#include <iostream>
#include <bits/stdc++.h> 
#include <queue>


using namespace std;

template <class T>
class No {
	public:
		T el;
		No<T> *left,*right;
        int sucessor;
		No<T>(){
			left=right=0;
            sucessor=0;			
		}
		
		No<T>(T e,No<T> *l=0, No<T> *r=0, int s=0){
			el=e;
			left=l;
			right=r;
            sucessor=s;
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
        No<T> *p=root, *prev=0, *newNode;
        newNode = new No<T>(el);

        if (root == 0){
            root = newNode;
            return;
        }
        p = root;
        while (p!=0){
            prev = p;
            if (p->el>el){
                p=p->left;
            }
            else if (p->sucessor == 0){
                p=p->right;
            }
            else break;
        }

        if (prev->el > el){
            prev->left=newNode;
            newNode->sucessor = 1;
            newNode->right = prev;
        }

        else if (prev->sucessor == 1){
            newNode->sucessor=1;
            prev->sucessor=0;
            newNode->right=prev->right;
            prev->right = newNode;
        }

        else{
            prev->right = newNode;
        }
    }

    void preOrder(No<T> *root){
    No<T> *p = root;

    while(p!=0)
    {
        cout << p->el << " ";

        if(p->left!=0)
            p=p->left;

        else if(p->sucessor==0)
            p=p->right;

        else
        {
            while(p->right!=0 && p->sucessor==1)
                p=p->right;

            if(p->right == 0)
            break;                          
            else
                p=p->right;

        }
    }
}
};
int main(){
	No<int> *a= new No<int>(70);
	Arvore<int> *arv = new Arvore<int>(a);
    arv->insert(15);
    arv->insert(80);
    arv->insert(9);
    arv->insert(11);
    arv->insert(100);
	arv->preOrder(arv->getRoot());
};