def change_string(s:str)->str:
    true_length = len(s.rstrip())
    s = list(s)
    space_count = 0

    for i in range(true_length):
        if s[i] == ' ':
            space_count += 1

    shift = space_count * 2
    
    for i in range(len(s) - shift - 1, -1, -1):
        if s[i] == ' ':
            s[i] = '%'
            s[i+1] = '2'
            s[i+2] = '0'
            shift -= 2
            s[i + shift + 2] = '0'
            s[i + shift + 1] = '2'
            s[i + shift] = '%'
        else:
            s[i + shift] = s[i]

    return ''.join(s)


def main():
    tests = ['Nishit Jain  ', 'My name is Nishit Jain        ', "hello  hello    "]
    results = ['Nishit%20Jain', 'My%20name%20is%20Nishit%20Jain', 'hello%20%20hello']

    for test, result in zip(tests, results):
        print(change_string(test))

main()