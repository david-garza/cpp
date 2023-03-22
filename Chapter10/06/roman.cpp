#include "roman.h"
#include "../../dcg.h"

namespace Rome {

    // Function that returns the value of the ones digit
    int ones_sum()
    {
        string rn;

        // Replace with the read function
        cin >> rn;

        if (rn == "I")
            return 1;
        else if (rn == "II")
            return 2;
        else if (rn == "III")
            return 3;
        else if (rn == "IV")
            return 4;
        else if (rn == "V")
            return 5;
        else if (rn == "VI")
            return 6;
        else if (rn == "VII")
            return 7;
        else if (rn == "VIII")
            return 8;
        else if (rn == "IX")
            return 9; 
        else
            return 0;
    }

    // reads the I through IX values and checks for errors
    string ones_read()
    {
        char ch{};
        string s;

        // Read the character and check if it is one of I,V,X
        while (cin >> ch) {
            switch (ch)
            {
            case 'I': case 'V': case 'X':
                s += ch;
            default:
                error("Unexpected ones value"); // Add proper try and catch blocks
                break;
            }
        }
        return string(s);
    }

    // Function that sums the tens digits
    int tens_sum()
    {
        string rn;

        cin >> rn;

        if (rn == "X")
            return 10;
        else if (rn == "XX")
            return 20;
        else if (rn == "XXX")
            return 30;
        else if (rn == "XL")
            return 40;
        else if (rn == "L")
            return 50;
        else if (rn == "LX")
            return 60;
        else if (rn == "LXX")
            return 70;
        else if (rn == "LXXX")
            return 80;
        else if (rn == "XC")
            return 90;
        else
            return 0;
    }
} // End Rome namespace

