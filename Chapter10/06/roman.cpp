#include "roman.h"
#include "../../dcg.h"

namespace Rome {

    // Function that returns the value of the ones group
    int ones_sum()
    {
        string rn;

        rn = ones_read(); // Checks and verifies that the inputs meet the ones criteria

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
            while (cin.get(ch)) {
                switch (ch)
                {
                case ' ': 
                    break;
                case 'I': 
                    // Test if read is complete
                    if (s == "III" || s == "IV" || s == "IX" || s=="VIII") {
                        cin.putback(ch);
                        return(s);
                    }
                    // Else add an I to whatever is there.
                    else {
                        s += ch;
                        break;
                    }
                case 'V': 
                    // Test if read is complete
                    if (s == "V" || s == "VI" || s == "VII" || s == "VIII" || s == "IV" || s == "IX") {
                        cin.putback(ch);
                        return(s);
                    }
                    else {
                        s += ch;
                        break;
                    }                   
                case 'X':
                    if (s == "V" || s == "VI" || s == "VII" || s == "VIII" || s == "II" || s == "III" || s == "IX") {
                        cin.putback(ch);
                        return(s);
                    }
                    else {
                        s += ch;
                        break;
                    }                 
                default:
                    cin.putback(ch);
                    return(s);
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

