struct nodo {
    int value;
    struct nodo *left;
    struct nodo *right;
};

typedef struct nodo nodo;

void smart_game(int **, int, int);
int ways(int **, int, int, int, nodo **);
int create_tree(nodo **);
int insert(nodo **, int);
int get_max(nodo **, int *);