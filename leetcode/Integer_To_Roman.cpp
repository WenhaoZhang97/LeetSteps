class Solution {
public:
    string intToRoman(int num) {
        string rc[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int rm[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string output;
        int i=0;
        while(num>0) {
            while(num>=rm[i]) {
                num-=rm[i];
                output+=rc[i];
            }
            i++;
        }
        return output;
    }
};