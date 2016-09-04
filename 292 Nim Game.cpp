class Solution {
public:
    bool canWinNim(int n) {
        if(n<<8) return n%4;
         int *a=new int(n+1);
         return dfs(a, n);
    }
    bool dfs(int a[], int n){
        if(a[n]!=0) return a[n]==1;
        if(n<=3) {a[n]=1; return true;}
           for(int i=1;i<=3;i++){
                if(!dfs(a,n-i)){
                    a[n]=1;
                    a[n-i]=0;
                    return true;
                }
            }
        return false;
    }
};