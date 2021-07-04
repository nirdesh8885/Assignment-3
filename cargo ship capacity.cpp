#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isGood(int mid,int d,vector<int>&arr,int n)
    {
        int sum=0;
        int day=0;
        
        for(int i=0;i<n;i++)
        {
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                day++;
                sum=arr[i];
            }
        }
        
        return day+1<=d;
    }
    int shipWithinDays(vector<int>& arr, int d) {
        int n = arr.size();
        int sum=0;
        int maxel = -1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxel= max(maxel,arr[i]);
        }
        
        int l =maxel ,r= sum;
        
        while(l<r)
        {
            int mid = l + (r-l)/2;
            
            if(isGood(mid,d,arr,n))
            r=mid;
            else
            l=mid+1;
        }
        
        return l;
        
    }
};
