#include<stdio.h>

void gcd_euclid(int m,int n){
        int r,count=0;
        while(n!=0){
                count++;
                if(n>m){
                        r=n;n=m;m=r;
                }else{
                        r=m%n;
                        m=n;
                        n=r;
                }
        }
        printf("GCD by Euclid Method: %d. Count: %d\n",m,count);
}

void gcd_cicm(int m,int n){
        int r, count=0;

        r=m;
        if(n<=r) r=n;

        while(r>0){
                count++;
                if(m%r==0 && n%r==0){
                        printf("GCD by Consecutive Integer Checking Method: %d. Count: %d\n",r,count);
                        return;
                }
                r-=1;
        }
}

void gcd_msa(int a,int b){
        int t= a>b? b: a, count=0;
        int i,k,primes[t+1];

        for(i=0;i<t+1;i++) primes[i]=1;
        primes[0]=primes[1]=0;

        int ans=1;

        for(i=2;i<=t;i++){
                if(!primes[i]) continue;

                for(k=2*i;k<=t;k+=i){
                        primes[k]=0;
                        count++;
                }

                while(a%i==0 && b%i==0){
                        ans*=i;
                        a/=i;b/=i;
                        count++;
                }
        }
        printf("GCD by Middle School Algorithm: %d. Count: %d\n",ans,count);
}

void main(){
        int m,n;

        printf("Enter two nos.: ");
        scanf("%d%d",&m,&n);

        gcd_euclid(m,n);
        gcd_cicm(m,n);
        gcd_msa(m,n);
}