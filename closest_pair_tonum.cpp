#include "closest_pair_tonum.h"

pii closest_pair_tonum(int numb) {
    pii cur_pair;
    int m, n, founded = 0;

    for (int i = numb - 1; i > 0; i--) {
        m = i;

        for (int j = 1; j < numb; j++) {
            n = m - j*j;
           
            if (n > 0) {
                ll sum = m + n;
                int sqr_sum = sqrt(sum);
                if (sqr_sum * sqr_sum == sum) {
                    cur_pair.first = m;
                    cur_pair.second = n;
                    founded = 1;
                    break;
                } else continue;
            } else break;
        }
        if (founded) break;
    }
    return cur_pair;
}
