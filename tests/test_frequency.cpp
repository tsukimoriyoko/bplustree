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

enum {
    BPLUS_TREE_LEAF,
    BPLUS_TREE_NON_LEAF = 1,
};
static inline int is_leaf(struct bplus_node *node) {
    return node->type == BPLUS_TREE_LEAF;
}

#ifdef _FREQUENCY_STATISTIC

queue<bplus_node*> q_node;
queue<int> q_level;

vector<int> frequency[MAX_LEVEL];

void dump(bplus_tree *tree) {
    q_node.push(tree->root);
    q_level.push(0);
    while (!q_node.empty()) {
        bplus_node *node = q_node.front();
        int level = q_level.front();
        q_node.pop();
        q_level.pop();
        if (is_leaf(node)) {
            struct bplus_leaf *ln = (struct bplus_leaf *)node;
            for (int i = 0; i < ln->entries; i++) {
                frequency[level].push_back(ln->frequency[i]);
            }
        } else {
            struct bplus_non_leaf *nln = (struct bplus_non_leaf *)node;
            for (int i = 0; i < nln->children; i++) {
                frequency[level].push_back(nln->frequency[i]);
                q_node.push(nln->sub_ptr[i]);
                q_level.push(level + 1);
            }
        }
    }
    
    int t_level = tree->level;

    for (int i = 0; i <= t_level; i++) {
        sort(frequency[i].begin(), frequency[i].end(), greater<int>());
        // printf("level: %d\n", i);
        int sum = 0;
        for (auto j : frequency[i]) {
            sum += j;
            printf("%lf ", (double)sum / (double)FILE_SIZE);
        }
        // printf("%d\n", frequency[i].size());
        int t = frequency[i].size();
        // for (int j = 1; j <= t; j++) {
        //     printf("%lf ", (double)j / (double)t);
        // }
        printf("\n");
        // printf("sum: %d\n", sum);
    }
}

#endif

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
    // freopen("output_tmp", "w", stdout);

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
        // printf("%d\n", bplus_tree_get(tree, x));
    }
    gettimeofday(&endtime, NULL);
    timeuse = 1000000 * (endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;

    printf("%lf ms\n", timeuse / 1000);

    // printf("hit count: %d\n", tree->r);

    freopen("output", "w", stdout);
    // dump(tree);
    // bplus_tree_dump(tree);

    return 0;
}