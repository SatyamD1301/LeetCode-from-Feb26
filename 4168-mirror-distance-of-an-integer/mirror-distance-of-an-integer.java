class Solution {
    public int mirrorDistance(int n) {
        int original=n;
        if(n%10==n) return 0;
        int num1=0;
        while(n>0){
            int a=n%10;
            n=n/10;
            num1=num1*10+a;
        }
        return Math.abs(original-num1);

    }
}