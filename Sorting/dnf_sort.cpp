//ALso check 3 way partiotion it is simiar to DNF SORT
void sortColors(vector<int>& v) {
    int N = v.size();
    int low = 0,high = N-1,mid = 0;
    while(mid <= high)//region bw mid nad high will over so stop
    {   
        if(v[mid] == 0)
        swap(v[low++],v[mid++]);
        else if(v[mid] == 2)
        swap(v[mid],v[high--]);
        else
        mid++;
    }
}

/*
red white blue Dutch National Flag
0 0 0 0 0  1 1 1 1 1    ? ? ? ? ?   2 2
         low         mid       high 

low->ptr deanti=es starting point of 1s
high >                                2s
mid->unknown region


*/