typedef struct {
    int value;
    struct tree *first;
    struct tree *next;
} tree;

void smart_game(int **, int, int);
tree *create_tree(int);
void insert(tree *, tree *);
void print(tree *);
void clean(tree *);
void height(tree *);