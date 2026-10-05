char* minRemoveToMakeValid(char* s) {
    int open=0;
    int length=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
        {
            open++;
        }
        else if(s[i]==')'){
            if(open>0){
                open--;
            }
            else{
                s[i]='*';
            }
        }
        length++;
    }
    for(int i=length-1;i>=0;i--)
    {
        if(s[i]=='('&& open>0)
        {
            s[i]='*';
            open--;
        }
    }
    int index=0;
    for(int i=0;i<length;i++)
    {
        if(s[i]!='*')
        {
            s[index]=s[i];
            index++;
        }
    }
    s[index]='\0';
    return s;
}
