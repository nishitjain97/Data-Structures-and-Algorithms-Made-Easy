def is_perm_sorted(s1:str, s2:str)->bool:
    if len(s1) != len(s2):
        return False
    
    s1_ = sorted(s1)
    s2_ = sorted(s2)

    if s1_ == s2_:
        return True
    return False

def main()->None:
    tests = ["nishitjain", "aa", "a", ""]
    args = ["jnatishini", "aa", "b", "c"]
    results = [True, True, False, False]
    
    for test, arg, result in zip(tests, args, results):
        if is_perm_sorted(test, arg) != result:
            print("Failed")

main()