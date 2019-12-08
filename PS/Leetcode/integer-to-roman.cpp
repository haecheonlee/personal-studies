class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        
        if(num >= 1000) {
            for(int i=0; i<num/1000; i++) s+= "M";
            num %= 1000;
        }
        
        if(num >= 900) {
            for(int i=0; i<num/900; i++) s+= "CM";
            num %= 900;
        }

        if(num >= 500) {
            for(int i=0; i<num/500; i++) s+= "D";
            num %= 500;
        }

        if(num >= 400) {
            for(int i=0; i<num/400; i++) s+= "CD";
            num %= 400;
        }

        if(num >= 100) {
            for(int i=0; i<num/100; i++) s+= "C";
            num %= 100;
        }

        if(num >= 90) {
            for(int i=0; i<num/90; i++) s+= "XC";
            num %= 90;
        }

        if(num >= 50) {
            for(int i=0; i<num/50; i++) s+= "L";
            num %= 50;
        }

        if(num >= 40) {
            for(int i=0; i<num/40; i++) s+= "XL";
            num %= 40;
        }

        if(num >= 10) {
            for(int i=0; i<num/10; i++) s+= "X";
            num %= 10;
        }

        if(num >= 9) {
            for(int i=0; i<num/9; i++) s+= "IX";
            num %= 9;
        }

        if(num >= 5) {
            for(int i=0; i<num/5; i++) s+= "V";
            num %= 5;
        }

        if(num >= 4) {
            for(int i=0; i<num/4; i++) s+= "IV";
            num %= 4;
        }

        if(num >= 1) {
            for(int i=0; i<num; i++) s+= "I";
        }
        
        return s;
    }
};

/*
https://leetcode.com/problems/integer-to-roman/
INPUT:
1994

OUTPUT:
"MCMXCIV"
*/
