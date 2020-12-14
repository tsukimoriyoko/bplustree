#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <queue>
#include <vector>
#include <algorithm>

#ifdef __cplusplus
extern "C" {
#endif

#include "bplustree.h"

#ifdef __cplusplus
}
#endif

using namespace std;

const int FILE_SIZE = 1500000;
const int MAX_LEVEL = 10;


struct bplus_tree_config {
    int order;
    int entries;
};

vector<int> input;
vector<int> run;

int main() {
    struct bplus_tree *tree;
    struct bplus_tree_config config;
    
    config.entries = config.order = 32;
    tree = bplus_tree_init(config.order, config.entries);
    
    if (tree == NULL) {
        fprintf(stderr, "Init failure!\n");
        exit(-1);
    }

    int x, cnt = 0;

    // freopen("/home/tsukimori/bplustree/data/c_1M5_16_load", "r", stdin);
    // for (int i = 0; i < FILE_SIZE; i++) {
    //     scanf("insert user0000000%d\n", &x);
    //     bplus_tree_put(tree, x, x);
    // }

    for (int i = 0; i < FILE_SIZE; i++) {
        input.push_back(i);
    }

    // build the tree randomly
    srand(unsigned(time(0)));
    random_shuffle(input.begin(), input.end());

    for (int i = 0; i < FILE_SIZE; i++) {
        bplus_tree_put(tree, input[i], input[i]);
    }

    printf("%d\n", tree->level + 1);

    freopen("/home/tsukimori/bplustree/data/c_1M5_16_run", "r", stdin);

    for (int i = 0; i < FILE_SIZE; i++)
    {
        scanf("read user0000000%d\n", &x);
        run.push_back(x);
    }

    struct timeval starttime, endtime;
    double timeuse;
    gettimeofday(&starttime, NULL);
    for (int i = 0; i < FILE_SIZE; i++) {
        bplus_tree_get(tree, run[i]);
    }
    gettimeofday(&endtime, NULL);
    timeuse = 1000000 * (endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
    printf("%lf ms\n", timeuse / 1000);

    // printf("hit count: %d\n", tree->r);

    // tree->r = 0;
    tree->cache_off = 1;
    gettimeofday(&starttime, NULL);
    for (int i = 0; i < FILE_SIZE; i++) {
        bplus_tree_get(tree, run[i]);
    }
    gettimeofday(&endtime, NULL);
    timeuse = 1000000 * (endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
    printf("%lf ms\n", timeuse / 1000);

    // printf("hit count: %d\n", tree->r);


    return 0;
}