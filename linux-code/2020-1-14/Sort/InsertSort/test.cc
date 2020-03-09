#include<iostream>
#include<vector>
using namespace std;

//升序
int main()
{
    size_t  i=0;
    vector<int> v;
    v.resize(4);
    v[0]=2;
    v[1]=8;
    v[2]=5;
    v[3]=9;
    int num=10;
    int end=v.size();
    while(end>=0){
        if(num<=v[end]){
            v[end]=v[end]+1;
            end--;
        }else{
            v[end]=num;
            break;
        }
    }
    for(i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    return 0;
}
