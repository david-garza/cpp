#include "roman.h"
#include "../../dcg.h"

namespace Rome {

    int i_sum()
    {
        string rn;

        cin >> rn;

        if (rn == "I")
            return 1;
        else if (rn == "II")
            return 2;
        else if (rn == "III")
            return 3;
        else if (rn == "IV")
            return 4;
        else
            return 0;
    }
} // End Rome namespace

