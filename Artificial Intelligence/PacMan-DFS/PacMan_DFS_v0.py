# r, c as the grid size
# pacman_r and pacman_c as the postion of Pacman 
# food_r and food_c as the position of food
# grid as input

def comp_tuples(tuple1, tuple2):
    if (tuple1[0]== tuple2[0] and tuple1[1]==tuple2[1]): 
        return True
    else:
        return False
    

def dfs(r, c, pacman_r, pacman_c, food_r, food_c, grid):
    
    # stack of added position 
    stack = []
    #add_=[]
    # path_explored, pop out
    path = []
    path_no_dead =[]
    stack.append((pacman_r, pacman_c, '-','-'))
    
    #print(stack)
    while(stack!=[]):
        #Find current position
        cur_pos = stack.pop()
        #print(cur_pos)
        #grid[pacman_r][pacman_c]='a'
        path.append((cur_pos[0], cur_pos[1]))
        path_no_dead.append((cur_pos[0], cur_pos[1]))
        if(cur_pos[0]==food_r and cur_pos[1]==food_c):
            print(len(path))
            #print('do I get here')
            for i in path:
                print(str(i[0]) + ' ' + str(i[1]) )
            print(len(path_no_dead)-1)
            for i in path_no_dead:
                print(str(i[0]) + ' ' + str(i[1]) )
            break;
                

        # Change the current move as visited; we won't visit it again
        grid[cur_pos[0]][cur_pos[1]]='a'        
        
        #Add UP move to list
        dead_pos = []
        for i in range(4):
            dead_pos.append(1)
            
        if(cur_pos[0]  - 1 >= 0 and grid[cur_pos[0]-1][cur_pos[1] ]!='%'):
            if( grid[cur_pos[0]-1][cur_pos[1]]!='a'):
                stack.append([cur_pos[0]-1, cur_pos[1], cur_pos[0], cur_pos[1]])
                grid[cur_pos[0]-1][cur_pos[1]]='a'
                dead_pos[0]=0
        # Add LEFT to list
        if(cur_pos[1]  - 1 >= 0 and grid[cur_pos[0]][cur_pos[1]-1]!='%'):
            if(grid[cur_pos[0]][cur_pos[1]-1]!='a'):
                stack.append([cur_pos[0], cur_pos[1]-1, cur_pos[0], cur_pos[1]])
                dead_pos[1]=0
                grid[cur_pos[0]][cur_pos[1]-1]='a'
        #Add Right move to list
        if(cur_pos[1]  + 1 < c and grid[cur_pos[0]][cur_pos[1]+1 ]!='%'):
            if(grid[cur_pos[0]][cur_pos[1]+1]!='a'):
                stack.append([cur_pos[0], cur_pos[1]+1, cur_pos[0], cur_pos[1]])
                grid[cur_pos[0]][cur_pos[1]+1]='a'
                dead_pos[2]=0
        #Add Down move to list
        if(cur_pos[0]  + 1 < r and grid[cur_pos[0]+1][cur_pos[1] ]!='%'):
            if(grid[cur_pos[0]+1][cur_pos[1]]!='a'):
                stack.append([cur_pos[0]+1, cur_pos[1], cur_pos[0], cur_pos[1]])
                grid[cur_pos[0]+1][cur_pos[1]]='a'
                dead_pos[3]=0
               # add_.append([cur_pos[0], cur_pos[-1]+1]
        #print(len(dead_pos))
        
        if((dead_pos[0]*dead_pos[1]*dead_pos[2]*dead_pos[3])==1 and stack!=[]):
            temp_parent = stack[-1]
            temp_parent=temp_parent[2:]
            #print("top of path_no_dead: ", path_no_dead[-1])
            while(comp_tuples(path_no_dead[-1], temp_parent)!=True):
                path_no_dead.pop()
            #print(path_no_dead.peek())
                 
        

#print all the moves here
if __name__ == "__main__":
    import math
    pos = [int(i) for i in input().strip().split()]
    des = [int(i) for i in input().strip().split()]
    dim = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(dim[0])]
    dfs(dim[0], dim[1], pos[0], pos[1],  des[0], des[1], board)