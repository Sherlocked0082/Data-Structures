int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int sum1=0,sum2=0,sum3=0;
        for(int i=0;i<n1;i++)sum1+=s1[i];
        for(int i=0;i<n2;i++)sum2+=s2[i];
        for(int i=0;i<n3;i++)sum3+=s3[i];
        
        int i=0,j=0,k=0;
        while(i<n1 && j<n2 && k<n3)
        {
            if(sum1==sum2 && sum2==sum3 && sum3==sum1)
                return sum1;
            
            if(sum1>=sum2 && sum1>=sum3)
                sum1-=s1[i++];
            else if(sum2>=sum1 && sum2>=sum3)
                sum2-=s2[j++];
            else if(sum3>=sum2 && sum3>=sum1)
                sum3-=s3[k++];
        }
        return 0;
    }

    //1  4  7  8  1 +1+2+2
    //2  3  5  6