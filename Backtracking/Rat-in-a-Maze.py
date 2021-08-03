#User function Template for python3

class Solution:
    def findPath(self, maze, n):
        d = {"D":[1,0], "U":[-1,0], "R":[0,1], "L":[0,-1]}
        paths = set()
        
        def isSafe(x,y,mat):
            if 0<=x<n and 0<=y<n and mat[x][y] == 1:
                return True
            return False
            
        # A recursive function to solve Maze problem
        def recurFind(maze, x, y, path):
            mat = [[j for j in i] for i in maze]
            # Check if maze[x][y] is valid
            if isSafe(x,y,mat):
                mat[x][y] = 0
                
                # if (x, y is goal) return True
                if x == n-1 and y == n-1: #Base Condition
                    paths.add(path)
                    return True
                
                for m in "DURL":
                    path += m
                    if isSafe(x + d[m][0], y + d[m][1], mat):
                        recurFind(mat, x + d[m][0], y + d[m][1], path)
                    path = path[:-1]
                
                mat[x][y] = 1
            
            return False
        
        recurFind(maze, 0, 0, "")

        return sorted(paths)
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        
        matrix = [[0 for i in range(n[0])]for j in range(n[0])]
        k=0
        for i in range(n[0]):
            for j in range(n[0]):
                matrix[i][j] = arr[k]
                k+=1
        ob = Solution()
        result = ob.findPath(matrix, n[0])
        if len(result) == 0 :
            print(-1)
        else:
            for x in result:
                print(x,end = " ")
            print()
# } Driver Code Ends