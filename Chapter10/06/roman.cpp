#include "roman.h"
#include "../../dcg.h"

namespace Rome {

    // Function that returns the value of the ones digit
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
            int i_count{ 0 };
            int v_count{ 0 };
            int x_count{ 0 };

            // Read the character and check if it is one of I,V,X
            while (ch!=';') {
                cin >> ch;

                switch (ch)
                {
                case ';':
                    break;
                case 'I': 
                    // Add if i_count = 3 throw error!
                    // Add if s="IV" or "IX" throw error!
                    s += ch;
                    i_count++;
                    break;
                case 'V': 
                    // Add if v_count = 1 throw error!
                    s += ch;
                    v_count++;
                    break;
                case 'X':
                    // Add if x_count = 1 throw error!
                    // Add if s!="I" throw error.
                    s += ch;
                    x_count++;
                    break;
                default:
                    cout << ("Unknown Character\n"); // Add error handling
                    s = "";
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

