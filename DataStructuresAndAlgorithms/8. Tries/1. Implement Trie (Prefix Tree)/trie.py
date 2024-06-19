class Trie:

    def __init__(self):
        self.child = {}
        self.wordEnd = None

    def insert(self, word: str) -> None:
        if not word:
            return
        i = 0
        root = self.child
        while i < len(word):
            s = word[i]
            if not s in root:
                root[s] = Trie()
            if i == len(word) - 1:
                root[s].wordEnd = True
            root = root[s].child
            i += 1

    def search(self, word: str) -> bool:
        if not word:
            return True
        i = 0
        root = self
        while i < len(word):
            s = word[i]
            if s in root.child:
                root = root.child[s]
            else:
                return False
            i += 1
        if root.wordEnd:
            return True
        return False

    def startsWith(self, prefix: str) -> bool:
        if not prefix:
            return True
        i = 0
        root = self
        while i < len(prefix):
            s = prefix[i]
            if s in root.child:
                root = root.child[s]
            else:
                return False
            i += 1
        return True


if __name__ == '__main__':
    methods = ["insert", "search", "search", "startsWith", "insert", "search"]
    arguments = [["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]

    trie = Trie()
    for i, method in enumerate(methods):
        if method == 'insert':
            print(trie.insert(arguments[i][0]), end=' ')
        elif method == 'search':
            print(trie.search(arguments[i][0]), end=' ')
        else:
            print(trie.startsWith(arguments[i][0]), end=' ')

