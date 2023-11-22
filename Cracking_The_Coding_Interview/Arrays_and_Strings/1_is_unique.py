# Check if a string has all unique characters.
# Add: Without using any additional data structures
def is_unique_brute_force(s:str)->bool:
    n = len(s)

    for i in range(n):
        for j in range(i+1, n):
            if s[i] == s[j]:
                return False
            
    return True

def is_unique_extra_space(s:str)->bool:
    count_dict = {}

    for c in s:
        count = count_dict.get(c, 0)
        
        if count > 0:
            return False
        
        count += 1
        count_dict[c] = count
        
    return True

def is_unique_sorted(s:str)->bool:
    s_ = sorted(s)
    n = len(s_)

    for i in range(n-1):
        if s_[i] == s[i+1]:
            return False
        
    return True

def main()->None:
    tests = ["nishitjain", "abcdefgh", "", "aaaaaa", "a"]
    tests.append("abcdefghijklmnopqrstuvwxyz")
    results = [False, True, True, False, True, True]
    
    for test, result in zip(tests, results):
        if is_unique_sorted(test) != result:
            print("Failed")

main()