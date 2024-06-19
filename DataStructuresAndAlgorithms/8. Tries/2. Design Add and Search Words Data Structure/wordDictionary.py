class TrieNode():
    def __init__(self):
        self.children = {}
        self.wordEnd = None

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        if not word:
            return True
        root = self.root
        for s in word:
            if not s in root.children:
                root.children[s] = TrieNode()
            root = root.children[s]
        root.wordEnd = True

    def search(self, word: str) -> bool:
        if not word:
            return True
        root = self.root
        def find(word, root):
            for i, s in enumerate(word):
                if '.' == s:
                    return sum([find(word[i+1:],vals) for vals in root.children.values()]) > 0
                if s in root.children:
                    root = root.children[s]
                else:
                    return False
            if root.wordEnd:
                return True
            return False
        return find(word, root)


if __name__ == '__main__':
    methods = ["addWord","addWord","addWord","search","search","search","search"]    
    arguments = [["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
    wd = WordDictionary()
    for i, method in enumerate(methods):
        if method == 'addWord':
            print(wd.addWord(arguments[i][0]), end=' ')
        else:
            print(wd.search(arguments[i][0]), end=' ')