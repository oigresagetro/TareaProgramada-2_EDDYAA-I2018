#ifndef RED_BLACK_rbtree
#define RED_BLACK_rbtree
#include <iostream>
#include <stack>
using namespace std;
enum colors {RED, BLACK};

// Nodos del arbol:
template <typename T>
class rbnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia se hacen los atributos publicos.
		T key;
		rbnode<T> *p, *left, *right;
		enum colors color;

		// Constructor por omision.
		rbnode(){
		};

		// Constructor por copia del nodo.
		rbnode(const rbnode<T> * obj, const rbnode<T> * objNil, rbnode<T> * parent, rbnode<T> * nilPtr){
		}

      // Inicializacion de datos miembro.
		rbnode (const T& k, rbnode<T> *w = NULL, rbnode<T> *y = NULL,
				 rbnode<T> *z = NULL, enum colors c = RED):
					key(k), p(w), left(y), right(z), color(c)
		{};

		~rbnode(){

		}
};

// Arbol:
template <typename T>
class rbtree{
	public:
		rbtree(){
		    this->root = this->nil;

		};
			// Constructor (crea un arbol vacio)

		rbtree(const rbtree<T>& obj){
		};
			// Constructor copia

		~rbtree(){
		};
			// Destructor (borra el arbol)

		void inorderTreeWalk(rbnode<T>* x, stack<T> & pila){
		    if(x != this->nil){
            inorderTreeWalk(x->left, pila);
            pila.push(x->key);
            if(x->color == RED){
              pila.push(0);
            }else{
              pila.push(1);
            }
            inorderTreeWalk(x->right, pila);
        }
		};
            // Efectua un recorrido en orden del subarbol cuya ra�z es apuntada
            // por x. En cada visita apila la llave de cada nodo y su color.
            // Es decir, cada vez que se llega a un nodo se ejecutan las
            // instrucciones pila.push(x->key); y luego pila.push(colorDeX).
            // Para efectos de la tarea, si el color del nodo es rojo,
            // ponga en la pila un 0, y si es negro, ponga un 1.
            // Si se hace correctamente, al finalizar el m�todo la pila deber�a
            // contener las llaves de los nodos del sub�rbol (y su color)
            // ordenadas de mayor a menor.

		rbnode<T>* treeSearch(const T& k){
		    return treeSearchR(this->root, k);
		};
			// Busca la llave recursivamente, si la encuentra devuelve un
            // puntero al nodo que la contiene, sino devuelve NULL.

		rbnode<T>* iterativeTreeSearch(const T& k){
		    rbnode<T> * it = NULL;
            it = this->root; //iterador en la raiz.
            while(it!=NULL && it->key != k){
                if(k < it->key){
                    it = it->left;
                }else{
                    it = it->right;
                }
            }
            return it;
		};
			// Igual que en el anterior pero usa un procedimiento iterativo.

		rbnode<T>* treeMinimum(){
		    rbnode<T>* it = NULL;
            it = this->root; //iterador en la raiz.
            while(it->left != NULL){
                it = it->left;
            }
            return it;
		};
			// Devuelve el nodo con la llave menor.
            // Si el arbol esta vacio devuelve NULL.

		rbnode<T>* treeMaximum(){
		     rbnode<T>* it = NULL;
            it = this->root;
            while(it->right != NULL){
                it = it->right;
            }
            return it;
		};
			// Devuelve el nodo con la llave mayor.
            // Si el arbol esta vacio devuelve NULL.

		rbnode<T>* treeSuccessor(const rbnode<T>* x){
		    rbnode<T>* it = NULL;
            if(x->right != NULL){
                return subTreeMinimum(x->right);
            }
            it = x->p;
            while(it != NULL && x == it->right){
                x = it;
                it = it->p;
            }
            return it;
		};
			// Devuelve el nodo cuya llave es la siguiente mas grande que
            // la del nodo x. Si no existe tal nodo devuelve NULL.

		void treeInsert(rbnode<T>* z){ //aux es y, actual es x.
            rbnode<T>* y = this->nil;
            rbnode<T>* x = this->root;
            while(x != this->nil){
                y = x;
                if(z->key < x->key){
                    x = x->left;
                }else{
                    x = x->right;
                }
            }
            z->p = y;
            if(y == this->nil){
                this->root = z;
            }else{
                if(z->key < y->key){
                    y->left = z;
                }else{
                    y->right = z;
                }
            }
            z->left = this->nil;
            z->right = this->nil;
            z->color = RED;
            this->insertFix(z);
		};
			// Inserta el nodo z en la posicion que le corresponde en el arbol.

		rbnode<T>* treeDelete(rbnode<T>* z){
		};
			// Saca del arbol la llave contenida en el nodo apuntado por z.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de el.

		rbnode<T> * getRoot() const{
			return this->root;
		};

		// Devuelve la raiz del arbol. (Para efectos de revision de la tarea).

		rbnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve T.nil. (Para efectos de revision de la tarea).

		private:

		rbnode<T> *root;	// raiz del arbol
		rbnode<T> *nil;	    // nodo nil (hoja) del arbol
        rbnode<T> * treeSearchR(rbnode<T> * nod, const T&k){
            if(nod == NULL || nod->key == k){
                return nod;
            }
            if(k < nod->key){
                return  treeSearchR(nod->left,k);
            }else{
                return treeSearchR(nod->right,k);
            }
        };

        rbnode<T>* subTreeMinimum(rbnode<T>* nod){
            while(nod->left != NULL){
                nod = nod->left;
            }
            return nod;
		};

void leftRotate(rbnode<T>* x){
    rbnode<T> * y = x->right;
    x->right = y->left;
    if(y->left != this->nil){
        y->left->p = x;
    }
    y->p = x->p;
    if(x->p == this->nil){
        this->root = y;
    }else{
        if(x == x->p->left){
            x->p->left = y;
        }else{
            x->p->right = y;
        }
    }
    y->left = x;
    x->p = y;

};

void rightRotate(rbnode<T>* x){
    rbnode<T>* y = x->left;
    x->left = y->right;
    if(y->right != this->nil){
        y->right->p = x;
    }
    y->p = x->p;
    if(x->p == this->nil){
        this->root = y;
    }else{
        if(x == x->p->right){
            x->p->right = y;
        }else{
            x->p->left = y;
        }
    }
    y->right = x;
    x->p = y;

};

void insertFix(rbnode<T>* node){
    if(node->p != this->nil){
        while(node->p->color == RED){
            if(node->p == node->p->p->left){
                rbnode<T>* y = node->p->p->right;
                if(y->color == RED){
                  node->p->color = BLACK;
                  y->color = BLACK;
                  node->p->p->color = RED;
                  node = node->p->p;
                }else{
                    if(node == node->p->right){
                        node = node->p;
                        leftRotate(node);
                    }
                    node->p->color = BLACK;
                    node->p->p->color = RED;
                    rightRotate(node->p->p);
                }
            }else{
                rbnode<T>* y = node->p->p->left;
                if(y->color == RED){
                  node->p->color = BLACK;
                  y->color = BLACK;
                  node->p->p->color = RED;
                  node = node->p->p;
                }else{
                  if(node == node->p->left){
                    node = node->p;
                    rightRotate(node);
                  }
                  node->p->color = BLACK;
                  node->p->p->color = RED;
                  leftRotate(node->p->p);
                }
            }
        }
    }
    root->color = BLACK;
};


};
#endif	// RED_BLACK_rbtree
