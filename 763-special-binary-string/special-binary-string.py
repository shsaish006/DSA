class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        def DFS(string):
            if len(string)<=2: return string 
            lst=[]
            a,b=0,0 
            sub=''
            for i,c in enumerate(string):
                if c=='0': a+=1 
                else: b+=1 
                sub+= c
                if a==b:
                    sub='1'+ DFS(sub[1:-1])+'0' 
                    lst.append(sub)
                    sub=''
            lst.sort(reverse=True)
            return ''.join(lst)
        return DFS(s)