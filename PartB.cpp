#include <bits/stdc++.h>

using namespace std;

void printAns(vector < vector < int >> & ans) {
  cout << "The Obtained new Dice are : " << endl;
  for (int i = 0; i < ans.size(); i++) {

    cout << "Die"<<i+1<<":"<<"[ ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "]";
    cout<<endl;
  }
}

class dice1Poss {
  public:
    void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        return;
      }
      if (ds.size()==6) {
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      fun(nums, index, ds, res);
      ds.pop_back();
      fun(nums, index + 1, ds, res);
    }
  vector < vector < int >> subsetsWithDup(vector < int > & nums) {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > ds;
    fun(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
    }
    return ans;
  }
};


class dice2Poss {
  public:
    void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        if(ds.size()==6)
          res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      fun(nums, index+1, ds, res);
      ds.pop_back();
      fun(nums, index + 1, ds, res);
    }
  vector < vector < int >> subsetsWithDup(vector < int > & nums) {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > ds;
    fun(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
    }
    return ans;
  }
};

class Check{
    public:
    map<int,int> checker(vector<int> &dice1,vector<int> &dice2){
        map<int,int> sumCount;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                int sum=dice1[i]+dice2[j];
                sumCount[sum]++;
            }
        }
       return sumCount;
    }

    vector<vector<int>> prob(vector < vector < int >> &ans1,vector < vector < int >> &ans2){
        int n=ans1.size();
        int m=ans2.size();
        vector<int> dice1{1,2,3,4,5,6};
        vector<int> dice2{1,2,3,4,5,6};
        vector<vector<int>> ans;
        map<int,int> map0=checker(dice1,dice2);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                map<int,int> map1 = checker(ans1[i],ans2[j]);
                if(map0==map1){
                    ans.push_back(ans1[i]);
                    ans.push_back(ans2[j]);
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main() {
  dice1Poss obj1; 
  dice2Poss obj2;
  Check obj3;

  vector < int > nums1 = {1, 2, 3,4};
  vector < vector < int >> ans1 = obj1.subsetsWithDup(nums1);


  vector < int > nums2 = {1, 2, 3,4,5,6,7,8,9,10,11};
  vector < vector < int >> ans2 = obj1.subsetsWithDup(nums2);
  
  vector<vector<int>> newDice=obj3.prob(ans1,ans2);
  cout<<endl;
  printAns(newDice);

  return 0;
}