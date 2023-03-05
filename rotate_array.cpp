//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int x;
    vector<int>nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cin>>k;
    k=k%n;
    rotate(nums.begin(),nums.begin()+nums.size()-k,nums.end());
    for(auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}