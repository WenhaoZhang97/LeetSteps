class Solution {
public:
    void initial() {
        rl['I']=1;
        rl['V']=5;
        rl['X']=10;
        rl['L']=50;
        rl['C']=100;
        rl['D']=500;
        rl['M']=1000;
    }
    int romanToInt(string s) {
        initial();
        int result=0,i=1;
        result+=rl[s[0]];   
        while(s[i]!=0) {
            if(rl[s[i]]<=rl[s[i-1]]) {
                result+=rl[s[i]];
                i++;
            }
            else {
                result-=rl[s[i-1]]*2;
                result+=rl[s[i]];
                i++;
            }
        }
        return result;
    }
protected:
    int rl[100];
};