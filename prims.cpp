#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define mod 1e9 + 7
using namespace std;

//MST for Minimum taxi fare among the places
int main()
{ 
    int places;
    cout<<"No of places ";cin>>places;
    cout<<"Name of places\n";
    map<string,int>node;
    map<int,string>place;
    for(int i=0;i<places;i++){
        string temp;
        cin>>temp;
        node.insert(pair<string,int>(temp,i));
        place.insert(pair<int,string>(i,temp));
    }
    int routes;
    cout<<"Enter no of routes:";cin>>routes;
    vector<vector<int>>adjMat(places,vector<int>(places,0));
    for(int i=0;i<routes;i++){
        string from,to;
        int fare;
       cout<<"stop1"; cin>>from;
        cout<<"stop2"; cin>>to;
        cout<<"fare"; cin>>fare;
        adjMat[node[from]][node[to]]=fare;
        adjMat[node[to]][node[from]]=fare;// bidirectional;
    }

    cout<<"Enter The start Place ";
    string start;cin>>start;
    int src=node[start];
    vector<int>reached(places,0),unreached(places,1);//all reached 0 as no one taken yet
    reached[src]=1;
    unreached[src]=0;
    vector<vector<int>>prims;// {u,v,wt};
    for(int eg=0;eg<places-1;eg++){
        int mini=INT_MAX,u,v,wt;
        for(int i=0;i<places;i++){
            if(reached[i]==1){
                for(int j=0;j<places;j++){
                    if(unreached[j]==1 && adjMat[i][j]!=0 && adjMat[i][j]<mini){
                        mini=adjMat[i][j];
                        u=i;v=j;
                    }
                }
            }
        }
        if(mini!=INT_MAX){
            prims.push_back({u,v,mini});
            reached[v]=1;
            unreached[v]=0;
        }

    }

    int cost=0;
    for(auto it:prims){
        cost+=it[2];
        cout<<place[it[0]]<<" --link-- "<<place[it[1]]<<" fare -"<<it[2]<<endl;
    }
    cout<<"Total Fare"<<cost<<endl;
    return 0;
}
// 4 stops a,b,c,d
//5 routes
// a to b 100     b to c 100  c to a 100  c to d 200  b to d 600

