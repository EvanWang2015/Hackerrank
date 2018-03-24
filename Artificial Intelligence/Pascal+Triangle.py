
# coding: utf-8

# In[10]:


import numpy as np

# input k: total number of water unit
# i rows
# j's column of glass
def water_pascal_triangle(k, i, j):
    #total number of glasses of i rows
    n = int((i+1)*i/2)
    # Initialize all glasses empty
    glass = np.zeros(n)
    index = 0
    glass[index]=k
    for row in range(1,i):
        for column in range(1, row+1) :
            #print("index: ", glass[index])
            if(glass[index]>1):
                #print("index: ", index)
                glass[index+row] += (glass[index]-1)/2
                glass[index+row+1] += (glass[index]-1)/2
                glass[index]=1
                index +=1
                
    # the index of i's row and j's column index is given in the following:            
    index = int((i-1)*(i)/2 + j-1)
    print(index)
    print(glass[index])
    
if __name__== "__main__":
    
    t = int( input().strip())
    while(t>=1):
        K = int( input().strip())
        i = int( input().strip())
        j = int( input().strip())
        water_pascal_triangle(K, i, j)
        t -=1

