


/*
Naive:
USe teperory Array and Traverse multiple times(3)

*/

//optimised:
//Variations:
//sort 0,1,2 also cld dnf sort
//ALso check 3 way partiotion it is simiar to DNF SORT
void sortColors(vector<int>& v) {
        int N = v.size();
    int low = 0,high = N-1,mid = 0;
    while(mid <= high)//region bw mid nad high will over so stop
    {   
        if(v[mid] == 0)
        swap(v[low++],v[mid++]);
        else if(v[mid] == 2)
        swap(v[mid],v[high--]);//dont increment mid
        else//ignore if 1
        mid++;
    }
    }

/*
high+1 to end is guranteed to be 2 but high we dont know

red white blue Dutch National Flag
0 0 0 0 0  1 1 1 1 1    ? ? ? ? ?   2 2
         low         mid       high 

low->ptr deanti=es starting point of 1s
high >                                2s
mid->unknown region
*/

//Three way partition


//Partition around range
void threeWayPartition(vector<int>& array,int a, int b)
{
    // code here 
    int n=array.size();
    int lo=0,hi=n-1,mid=0;
    while(mid<=hi)
    {
        if(array[mid]<a)
            swap(array[lo++],array[mid++]);
        else if(array[mid]>b)
            swap(array[mid],array[hi--]);
        else
            mid++;
    }
    
    
}

