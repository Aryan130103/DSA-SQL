class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
    int n=classroom.size();
    int m=classroom[0].size();

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    vector<vector<int>>id(n,vector<int>(m,-1));
 
    int c1=0,sr=0,sc=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(classroom[i][j]=='L')
                id[i][j]=c1++;
            else if(classroom[i][j]=='S'){
                sr=i;
                sc=j;
            }
        }
    }
    if(c1==0) return 0;
    int totalMask=(1<<c1)-1;
    
    vector<vector<vector<int>>>best(n,vector<vector<int>>(m,vector<int>(1<<c1,-1)));

    struct State{
        int r,c,mask,e,moves;
    };
    queue<State>q;

    best[sr][sc][0]=energy;
    q.push({sr,sc,0,energy,0});

    while(!q.empty()){
        State cur=q.front();
        q.pop();

        if(cur.e==0) continue;
        
        for(int i=0;i<4;i++){
            int nrow=dr[i]+cur.r;
            int ncol=dc[i]+cur.c;

            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m) continue;
            if(classroom[nrow][ncol]=='X') continue;

            int ne=(classroom[nrow][ncol]=='R')? energy: cur.e-1;
            if(ne<0) continue;

            int nmask=cur.mask;
            if(classroom[nrow][ncol]=='L'){
                nmask |=(1<<id[nrow][ncol]);
            }
            
            if(nmask==totalMask) return cur.moves+1;

            if(ne<=best[nrow][ncol][nmask]) continue;
            best[nrow][ncol][nmask]=ne;
            
            q.push({nrow,ncol,nmask,ne,cur.moves+1});
        }
    }
    return -1;
    }
};