class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // vector<string>v(n);
        // for(int i=1;i<=n;i++){
        //     if(i%3==0 && i%5==0) v[i-1]="FizzBuzz";
        //     else if(i%3==0) v[i-1]="Fizz";
        //     else if(i%5==0) v[i-1]="Buzz";
        //     else v[i-1]=to_string(i);
        // }
        // return v;
        
        // vector<string>v(n);
        // for(int i=1;i<=n;i++){
        //     int a=i%3, b=i%5;
        //     if(a==0 && b==0) v[i-1]="FizzBuzz";
        //     else if(a==0) v[i-1]="Fizz";
        //     else if(b==0) v[i-1]="Buzz";
        //     else v[i-1]=to_string(i);
        // }
        // return v;
        
        // vector<string>v(n);
        // int j=3,k=5;
        // for(int i=1;i<=n;i++){
        //     if(i==j && i==k) {v[i-1]="FizzBuzz"; j+=3; k+=5;}
        //     else if(i==j) {v[i-1]="Fizz";j+=3;}
        //     else if(i==k) {v[i-1]="Buzz";k+=5;}
        //     else v[i-1]=to_string(i);
        // }
        // return v;
        
        vector<string>v(n);
        int j=0,k=0;
        for(int i=1;i<=n;i++){
            j++;k++;
            if(j==3) {v[i-1]+="Fizz";j=0;}
            if(k==5) {v[i-1]+="Buzz";k=0;}
            if(v[i-1]=="") v[i-1]=to_string(i);
        }
        return v;
    }
};