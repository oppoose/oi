int qsort(vector<int> &a,int l,int r,int k){
    if(l == r) return a[l];
    int mid = (l+r)/2;
    int x = a[mid];
    int i = l, j = r;
    while(i <= j){
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j) {
            swap(a[i],a[j]);i++;j--;
        }
    }
    if(j >= k) return qsort(a,l,j,k);
    else if(i <= k) return qsort(a,i,r,k);
    else return a[k];
}