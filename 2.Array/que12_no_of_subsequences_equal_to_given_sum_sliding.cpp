// leetcode 1498 -> most optimize... power wale func mai , mai fasa tha ..
#define mod 1000000007
class Solution {
public:
    long power(int x, int y){
        if(y==1){
            return x;
        }
        if(y==0){
            return 1;
        }
        long ans = 1;
        if(y%2==0){
            ans=power(x,y/2);
            ans*=ans;
        }else{
            ans=power(x,y-1);
            ans*=x;
        }
        return ans%mod;
    }
    int numSubseq(vector<int>& num, int target) {
        sort(num.begin(),num.end());
        int i=0, j= num.size()-1;
        long ans=0;
        while(i<=j){
            if(num[i]+num[j]<=target){
                ans = ans + power(2,(j-i));
                ans = ans % mod;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
