class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>v(n);
        for(int i=1;i<=n;i++){
            int a=i%3;
            int b=i%5;
            if(a==0 && b==0) v[i-1]="FizzBuzz";
            else if(a==0) v[i-1]="Fizz";
            else if(b==0) v[i-1]="Buzz";
            else v[i-1]=to_string(i);
        }
        return v;
    }
};