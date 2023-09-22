#include "closest_pair_tonum.h"

int main() {
    int upper_limit;
    pii ans;
    cin >> upper_limit;
    ans = closest_pair_tonum(upper_limit);
    cout << ans.first << ' ' << ans.second << '\n';

return 0;
}