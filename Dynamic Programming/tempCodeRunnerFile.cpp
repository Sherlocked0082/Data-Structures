int edit_distance(string s1,string s2,int m,int n)
{
    if(m==0)//if first string ios empty we need to insert n characters
        return n;
    if(n==0)//if second string is empty we need to delete all characters of 1st string
        return m;
    
    
    if(s1[m-1]==s2[n-1])
    {
        return edit_distance(s1,s2,m-1,n-1);
    }
    else
    {
        return 1 + min(edit_distance(s1,s2,m,n-1),edit_distance(s1,s2,m-1,n),edit_distance(s1,s2,m-1,n-1));/*replace*/
    }
    
}