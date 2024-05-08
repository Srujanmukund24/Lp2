#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define mod 1e9 + 7
using namespace std;

int N;
vector<vector<char>>board;
vector<bool>rows;
vector<bool>lefts;
vector<bool>rights;


void printSol(vector<vector<char>> board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(int row,int col){
    for( int i=0;i<col;i++){
        if(board[row][i]=='Q')return false;
    }
    for(int i=row,j=col; i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q')return false;
    }
    for(int i=row,j=col; i<N && j>=0;i++,j--){
        if(board[i][j]=='Q')return false;
    }
    return true;
}

bool solve1(int col){
    if(col==N){
        printSol(board);
        return true;
    }
    for(int row=0;row<N;row++){
        if(isSafe(row,col)==true){
            board[row][col]='Q';
            // printSol(board);
            // cout<<"Recursion for next column";
            solve1(col+1);
            cout<<"backtrack ";
            board[row][col]='.';
        }    
    }
    return false;
}

bool isSafe2(int row,int col){
    if( rows[row] || lefts[row+col] || rights[col-row+N-1]){
        return false;
    }
    return false;
}
bool solve2(int col){
    if(col>=N){
        printSol(board);
        return true;
    }
    for(int row=0;row<N;row++){
        if(isSafe(row,col)){
            rows[row]=true;
            lefts[row+col]=true;
            rights[row+col+N-1]=true;
            board[row][col]='Q';
            // printSol(board)
            solve2(col+1);

            // cout<<"Bactrak from here"
            rows[row]=false;
            lefts[row+col]=false;
            rights[row+col+N-1]=false;
            board[row][col]='.';
        }
    }
    return false;


}

int main()
{     
    cout<<"Enter the no of queens";cin>>N;
    if(N<=2){cout<<"Not Possible "<<endl;}
    board.resize(N,vector<char>(N,'.'));
    // solve1(0);
    
    rows.resize(N,false);
    lefts.resize(2*N-1,false);
    rights.resize(2*N-1,false);
    
    solve2(0);
    return 0;
}


