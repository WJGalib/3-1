#include "include.h"

int f(int a){
	int k;
	k = 5;
	while(k>0){
		a++;
		k--;
	}
    return 3*a - 7;
    a=9;
}

int g(int a, int b){
	
    int x,i;
    x=f(a)+a+b;
    
    i=0;
    while(i<7){
    	if(i%3 == 0){
    		x = x+5;
    	}
    	else{
    		x = x-1;
    	}
    	i++;
    }
    
    return x;
}

int main(){
    int a,b,i;
    a=1;
    b=2;
    a=g(a,b);
    println(a);
    i=0;
    while (i<4){
        a=3;
        while(a>0){
            b++;
            a--;
        }
        i++;
    }
    println(a);
    println(b);
    println( i);
    return 0;
}
