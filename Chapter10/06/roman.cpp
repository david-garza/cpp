#include "roman.h"
#include "../../dcg.h"

namespace Rome {

    // Function that computes I scenario
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
        else if (rn == "IX")
            return 9;
        else
            return 0;
    }

    // Function that computes the V scenario
    int v_sum()
    {
        string rn;

        cin >> rn;

        if (rn == "V")
            return 5;
        else if (rn == "VI")
            return 6;
        else if (rn == "VII")
            return 7;
        else if (rn == "VIII")
            return 8;
        else
            return 0;
    }
} // End Rome namespace

