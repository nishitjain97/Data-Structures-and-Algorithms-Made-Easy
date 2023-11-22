def next_permutation(s:str, prefix:str)->None:
    if len(s) == 0:
        print(prefix)
        return
    
    for i in range(len(s)):
        new_s = s[:i] + s[i+1:]
        next_permutation(new_s, prefix + s[i])

s = "abc"
next_permutation(s, "")