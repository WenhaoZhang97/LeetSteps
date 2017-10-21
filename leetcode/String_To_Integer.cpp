class Solution {
public:
    void change_flag(int &f)
{
    if(f==1)
        f=-1;
    else
        f=1;
}

int check_valid(string s)//returns whether it's positive or negative number.
{
    int flag=1;//negative when it equals -1
    int has_number=0,is_begin=0;
    for(auto i=s.begin();i!=s.end();i++){
        while(*i==' ')
            i++;
        if(!s.empty()&&i==s.end())
            return flag;
        auto head=i;
        if(i==head&&(*i=='-'||*i=='+')){
            if(*i=='-')
                change_flag(flag);
            /*if(i!=s.begin()&&*i=='-')
                return 0;*/
            i++;
         }
        if(i-head==1&&(*i>'9')||(*i<'0'))
            return 0;
        if(*i>='0'&&*i<='9')
            has_number=1,is_begin=1;
        /*if(*i<'0'||*i>'9')
            return 0;*/
    }
    if(has_number==0)
        return 0;
    return flag;
}

int myAtoi(string input)
{
    int flag=1;
    if((flag=check_valid(input))==0)
        return 0;//need to be checked--what does it return when it's invalid
    vector<int> s;
    int has_number=0,is_begin=0;
   
    for(auto i=input.begin();i!=input.end();i++){
        while(is_begin==0&&*i==' ')
            i++;
        while(is_begin==0&&(*i=='+'||*i=='-'))
            i++;
        if(is_begin==0&&(*i<'0'||*i>'9'))
            return 0;
        while(is_begin==0&&*i=='0')
            i++;
        is_begin++;
        if(i==input.end())
            break;
        if(*i>'9'||*i<'0')
            break;
        int temp=*i-'0';
        has_number=1;
        s.push_back(temp);
    }
    if(has_number==0)
        return 0;
    double result=0;
    for(auto i=s.begin();i!=s.end();i++){
        result*=10;
        result+=(*i);
    }
    if(flag==-1)
        result*=-1;
    if(result>INT_MAX)
        result=INT_MAX;
    if(result<INT_MIN)
        result=INT_MIN;
    int out=result;
    return out;
}
};