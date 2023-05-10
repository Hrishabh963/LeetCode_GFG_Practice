class Solution {
    public int[][] generateMatrix(int n) {
        int[][] spiral = new int[n][n];
        int k = 0;
        int l = 0;
        int p = spiral.length;
        int q = spiral[0].length;
        int r = 1;
        while(k<p && l<q){
            for (int i = l; i < q; i++) {
                spiral[k][i] = r;
                r++;
            }
            k++;
            for (int i = k; i < p; i++) {
                spiral[i][q-1] = r;
                r++;
            }
            q--;
            if(k<p){
                for (int i = q-1; i >=l; i--) {
                    spiral[p-1][i] = r;
                    r++;
                }
                p--;
            }
            if(l<q){
                for (int i = q-1; i >=k; i--) {
                    spiral[i][l] = r;
                    r++;
                }
                l++;
            }
        }
        return spiral;
    }
}