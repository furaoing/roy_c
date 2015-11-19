struct node {
    int sn;
    long weight[];
    long out_signal;
    long error;
};

struct layer {
    struct nood* nodes[];
    int layer;
};

struct nn {
    struct layer* layers[];
    int depth;
    int width;
};
