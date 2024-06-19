def groupAnagrams(strs: list) -> list:
        sort_strs = ["".join(sorted(s)) for s in strs]
        
        hash_table = {}
        
        for i in range(len(strs)):
            
            if sort_strs[i] in hash_table:
                hash_table[sort_strs[i]].append(strs[i])
            else:
                hash_table[sort_strs[i]] = [strs[i]]
        
        return hash_table.values()


if __name__ == "__main__":
    strs = ["eat","tea","tan","ate","nat","bat"]
    # [""]
    # ["a"]
    print(groupAnagrams(strs))