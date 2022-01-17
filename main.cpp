//
//  main.cpp
//  coding_
//
//  Created by Ankush Singhania on 05/01/22.
//

#include<bits/stdc++.h>
  
 #define sze 1000005
 #define ll long long
 //#define ll unsigned long long
 #define endl "\n"
 #define pb push_back
 #define mkp make_pair
 #define ff first
 #define ss second
 #define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
 #define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
 #define all(c) (c).begin(),(c).end()
 #define pi                   pair<int,int>
 #define pll                  pair<ll,ll>
 #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define macro(x) squ(x)
#define squ(x) (x*x)
  
 using namespace std;
 
//cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
//const ll inf=1ll<<60;
//const double pii = 3.14159265358979323846;
 
//cout<<"Case #"<<t<<": "<<ans<<endl;
//int N = 1e5;


map<int,int> mp;
vector<int> players;
bool solve(int currPlayer)
{
    int initP = players[currPlayer];
    srand((int)time(0));
    int dice = rand()%6;
    if(dice==0)
        dice = 6;
    int currP = dice;
    currP += initP;
    if(currP>100)
        currP -= initP;
    if(mp.find(currP)!=mp.end()){
        currP = mp[currP];
    }
    players[currPlayer] = currP;
    cout<<"player "<<currPlayer<<" rolled "<<dice<<" moves from "<<initP<<" to "<<currP<<endl;
    if(currP==100)
        return true;
    return false;
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        int x,y; cin>>x>>y;
        mp[x]=y;
    }
}
int main()
{
    IOS;
    int no_of_snakes,ladder; cin>>no_of_snakes>>ladder;
    init(no_of_snakes);
    init(ladder);
    int noPlayer; cin>>noPlayer;
    int p=0;
    players = vector<int>(noPlayer+1,0);
    
    while(true)
    {
        p = (p+1)%noPlayer==0?noPlayer: (p+1)%noPlayer;
        if(solve(p))
        {
            cout<<"player "<<p<<" wins"<<endl;
            return 0;
        }
    }
}
