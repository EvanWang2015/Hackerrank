/*
Queen's Attack II
A Queen is standing on an nxn chessboard. The chessboard's rows are numbered from 1 to n, going from bottom to top; 
its columns are numbered from 1 to n, going from left to right. Each square on the board is denoted by a tuple, (r,c),
describing the row, r, and column, c, where the square is located.

The queen is standing at position (r_q, c_q) and, in a single move, she can attack any square in any of the eight
direction (left, right, up, down, or the four diagonals). However, there are k obstacles on the chessboard preventing
the queen from attacking any square that has an obstacle blocking the queen's path to it. For example, an obstacle at location(3,5)
in the diagram above would prevent the queen from attacking cells (3,5), (2,6) and (1,7).
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;
      
    int up,left,right,down,uld,urd,dld,drd;
    //set default from queen to each side
    up = n-rQueen;
    down = rQueen-1;
    left = cQueen-1;
    right = n-cQueen;
    
    //find the minimum
    uld=up<left?up:left; //uoper left diagonal
    urd=up<right?up:right; //upper right diagonal
    dld=down<left?down:left;//down left diagonal
    drd=down<right?down:right;//down right diagonal
    

    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;
        // your code goes here
        
        
        if(cObstacle==cQueen){
            //vetrical
            int path = abs(rObstacle-rQueen)-1;
            if(rQueen<rObstacle) //up
            {
                up=up<path?up:path;//minimum
            }
            else//down
            {
                down=down<path?down:path;
                
            }
            }
        else if(rObstacle==rQueen)
        {
            //horizontal
            int path = abs(cObstacle-cQueen)-1;
            if(cQueen<cObstacle)
            {
                right = right<path?right:path;
            }
            else
            {
                left=left<path?left:path;
            }
        }
        else
        {
            int path = abs(cObstacle-cQueen)-1;
            int path2= abs(rObstacle-rQueen)-1;
            
            if(path==path2)//if the obstacle is in the diagonal of queen's position
            {
                if(cQueen <cObstacle && rQueen < rObstacle)//up-right
                    urd = urd<path ? urd: path;
               else if(cQueen > cObstacle && rQueen >rObstacle)//down-left
                    dld = dld<path ? dld:path;
                else if(cQueen >cObstacle && rQueen < rObstacle)//up-left
                    uld = uld<path ? uld:path;
               else// if(cQueen >cObstacle && rQueen < rObstacle)//down-right
                    drd = drd<path ? drd:path;                
            }           
        }
    }
        
    int total = up+down+left+right+urd+uld+drd+dld;
        
    cout<<total<<endl;
        
        
    return 0; 
}

