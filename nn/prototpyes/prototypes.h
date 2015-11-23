struct node {
    int id;
    long weight[];
    long out_signal;
    long error;
};

struct layer {
    struct node* nodes[];
    int layer;
};

struct network {
    struct layer* layers[];
    int depth;
    int width;
};
