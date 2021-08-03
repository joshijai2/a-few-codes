#User function Template for python3

class Solution:
    def nQueen(self, n):
        board = list()
        rows = set(range(1,n+1))
        def isSafe(prev, row, col):
            # Check upper diagonal on left side
            i = row - 2
            j = col - 2
            while i>=0 and j>=0:
                if prev[j] == i+1:
                    return False
                i -= 1
                j -= 1
                
            # Check lower diagonal on left side
            i = row
            j = col - 2
            while j >= 0 and i < n:
                if prev[j] == i+1:
                    return False
                i += 1
                j -= 1
        
            return True
            
        def recurFind(col, prev):
            if col <= n:
                for row in rows.difference(set(prev)):
                    
                    if isSafe(prev, row, col):
                        prev.append(row)
                        recurFind(col+1, prev)
                        prev.pop()
            else:
                board.append(tuple(prev))
                
        recurFind(1,[])
        return sorted(board)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        ob = Solution()
        ans = ob.nQueen(n)
        if(len(ans) == 0):
            print("-1")
        else:
            for i in range(len(ans)):
                print("[",end="")
                for j in range(len(ans[i])):
                    print(ans[i][j],end = " ")
                print("]",end = " ")
            print()
                
# } Driver Code Ends