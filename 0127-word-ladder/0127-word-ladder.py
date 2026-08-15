class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if len(beginWord)!=len(endWord):
            return 0

        words=set(wordList)
        if endWord not in words:
            return 0
        
        q=deque()
        q.append((beginWord,2))

        while len(q)!=0:
            x=len(q)
            for i in range(x):
                [temp,level]=q.popleft()

                for j in range(len(temp)):
                    for k in "abcdefghijklmnopqrstuvwxyz":
                        newt=temp[:j]+k+temp[j+1:]
                       

                        if newt ==endWord:
                            return level
                        
                        if newt in words:
                            q.append((newt,level+1))
                            words.remove(newt)
        return 0