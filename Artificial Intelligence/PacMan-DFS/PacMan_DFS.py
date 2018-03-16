class node:
     def __init__(self, row, column, parent):
            self.r = row
            self.c = column
            self.parent = parent

def dfs(r, c, pacman_r, pacman_c, food_r, food_c, grid):
    
    # stack of added position 
    stack = []
    path = []
    explored =[]
    start_node = node(pacman_r, pacman_c, None)
    stack.append(start_node)
    goal = None
    while(stack!=[]):
        #Find current position
        cur_pos = stack.pop()
        # change it to visited
        
        explored.append(cur_pos)
        grid[cur_pos.r][cur_pos.c]='a'
        if((cur_pos.r == food_r) and (cur_pos.c==food_c)):
            goal = cur_pos
            #print("we are here")
            break;      
        
 
        #Add UP move to list           
        if(cur_pos.r  - 1 >= 0 and grid[cur_pos.r-1][cur_pos.c ]!='%' and grid[cur_pos.r-1][cur_pos.c]!='a'):
            temp_node = node(cur_pos.r-1, cur_pos.c, cur_pos)
            stack.append(temp_node)
            grid[cur_pos.r-1][cur_pos.c]='a'
        # Add LEFT to list
        if(cur_pos.c  - 1 >= 0 and grid[cur_pos.r][cur_pos.c-1]!='%' and grid[cur_pos.r][cur_pos.c-1]!='a'):
            temp_node = node(cur_pos.r, cur_pos.c-1, cur_pos)
            stack.append(temp_node)
            grid[cur_pos.r][cur_pos.c-1]='a'
        #Add Right move to list
        if(cur_pos.c  + 1 < c and grid[cur_pos.r][cur_pos.c+1 ]!='%' and grid[cur_pos.r][cur_pos.c+1]!='a'):
            temp_node = node(cur_pos.r, cur_pos.c+1, cur_pos)
            stack.append(temp_node)
            grid[cur_pos.r][cur_pos.c+1]='a'
        #Add Down move to list
        if(cur_pos.r  + 1 < r and grid[cur_pos.r+1][cur_pos.c ]!='%' and grid[cur_pos.r+1][cur_pos.c]!='a'):
            temp_node = node(cur_pos.r+1, cur_pos.c,cur_pos)
            stack.append(temp_node)
            grid[cur_pos.r+1][cur_pos.c]='a'           
    
    cur_pos = goal
    #print(cur_pos)
    while(cur_pos!=None):
        path.append(cur_pos)
        cur_pos = cur_pos.parent
    
    print(len(explored))
    for i in explored:
        print(str(i.r)+" "+str(i.c))
    print(len(path)-1)
    while(path!=[]):
        i=path.pop()
        print(str(i.r)+" "+str(i.c))

#print all the moves here
if __name__ == "__main__":
    import math
    pos = [int(i) for i in input().strip().split()]
    des = [int(i) for i in input().strip().split()]
    dim = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(dim[0])]
    dfs(dim[0], dim[1], pos[0], pos[1],  des[0], des[1], board)