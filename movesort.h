//
// Created by Vincent on 30/06/2018.
//

#ifndef TOPPLE_MOVESORT_H
#define TOPPLE_MOVESORT_H

#include "movegen.h"

enum GenMode {
    NORMAL, QUIESCENCE
};

enum GenStage {
    GEN_NONE,
    GEN_HASH,
    GEN_GOOD_CAPT,
    GEN_KILLER_1,
    GEN_KILLER_2,
    GEN_KILLER_3,
    GEN_BAD_CAPT,
    GEN_QUIETS,
};

constexpr int KILLER_BASE = 1000000000;

class movesort_t {
public:
    movesort_t(GenMode mode, const search_t::context_t &context, move_t hash_move, int ply);
    move_t next(GenStage &stage, int &score);

    move_t *generated_quiets(int &count);
private:
    GenMode mode;
    const search_t::context_t &context;
    move_t hash_move;
    int ply;

    move_t killer_1, killer_2, killer_3;

    void buf_swap_main(int a, int b);
    void buf_swap_capt(int a, int b);

    movegen_t gen;

    int main_idx = 0;
    int main_buf_size = 0;
    move_t main_buf[128];
    int main_scores[128];

    int capt_idx = 0;
    int capt_buf_size = 0;
    move_t capt_buf[128];
    int capt_scores[128];
};


#endif //TOPPLE_MOVESORT_H
