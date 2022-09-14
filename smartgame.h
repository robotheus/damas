struct nodo {
    int value;
    struct nodo *left;
    struct nodo *right;
};

typedef struct nodo nodo;

void smart_game(int **, int, int);
void create_tree(nodo **);
void insert(nodo **, int);
/*void print(tree *);
void clean(tree *);
void height(tree *);*/