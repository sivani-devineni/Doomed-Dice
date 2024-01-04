#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
int main(){
    cout<<endl;
    vector<int> dice1{1,2,3,4,5,6};
    vector<int> dice2{1,2,3,4,5,6};
    map<int,int> sumCount;
    vector<int> ans;
    vector<vector<int>> matrix(7,vector<int>(7,0));
    cout<<"Total Number of Combinations : "<<dice1.size()*dice2.size()<<endl<<endl;

    cout<<"Matrix Obtained : "<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<"("<<dice1[i]<<","<<dice2[j]<<")"<<" ";
            int sum=dice1[i]+dice2[j];
            ans.push_back(sum);
            sumCount[sum]++;
        }
        cout<<endl;
    }
    sort(ans.begin(),ans.end());
    int n=ans.size();
    cout<<endl;
    cout<<"Probabilities of the sums : "<<endl;
    for(auto it : sumCount){
        float p=36;
        float k=(float)it.second/p;
        cout<<"P(sum="<<it.first<<")"<<" ="<<" "<<k<<endl;
    }

    return 0;
}