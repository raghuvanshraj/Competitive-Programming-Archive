    /*
    // Sample code to perform I/O:
     
    cin >> name;                            // Reading input from STDIN
    cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
     
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
    */
     
    // Write your code here
    #include<bits/stdc++.h>
    using namespace std;
    #define mod 1000000007
    #define ll long long int
     
    void mul(ll a[2][2],ll b[2][2]){
      ll temp[2][2];
      for(int i=0;i<2;i++){
        for(int k=0;k<2;k++){
          temp[i][k]=0;
          for(int j=0;j<2;j++){
            temp[i][k]+=(a[i][j]* b[j][k])%(mod-1);
          }
        }
      }
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          a[i][j]=temp[i][j];
        }
      }
    }
     
    ll fib(ll f[2][2],ll n){
      ll temp[2][2];
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          temp[i][j]=f[i][j];
        }
      }
      if(n<0){
        return 0;
      }
      if(n<=1){
        return f[0][0];
      }
      fib(f,n/2);
      mul(f,f);
      
      if(n%2!=0){
      	mul(f,temp);  
      }
      return f[0][0];
    }
     
    ll pow(ll a, ll n){
      ll ans=1;
      while(n){
        if(n&1){
          ans=(ans*a)%mod;
        }
        a=((a%mod)*(a%mod))%mod;
        n>>=1;
      }
      return ans%mod;
    }
     
    ll calculate(ll a,ll n){
      ll t[2][2]={{1,1},{1,0}};
      ll f=fib(t,n-1);
      /**f=fib()%(mod-1)**/
      if(f<0){
        f+=(mod-1);
      }
      ll ans=pow(a,f);
      return ans;
    }
     
    int main() {
      int t;
      cin>>t;
      while(t--){
        ll f0,f1,n;
        cin>>f0>>f1>>n;
        if(n==0){
          cout<<f0<<endl;
          continue;
        }
        if(n==1){
          cout<<f1<<endl;
          continue;
        }
        ll temp_1=calculate(f0+1,n-1);
        ll temp_2=calculate(f1+1,n);
        ll gn=((temp_1%mod)*(temp_2%mod));
        ll fn=gn-1;
        fn=fn%mod;
        if(fn<0){
          fn+=mod;
        }
        cout<<fn<<endl;
      }
    }