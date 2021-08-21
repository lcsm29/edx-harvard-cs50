def error_found(args, error=True):
    if len(args) != 1:
        print("Usage: substitution.py <string>")
    elif len(args[0]) != 26:
        print("Key must contain 26 characters.")
    elif sum(1 for c in args[0] if not c.encode().isalpha()):
        print("Key must contain only English alphabets.")
    elif len(set(c.lower() for c in args[0])) != 26:
        print("Key must not contain duplicate letters.")
    else:
        error = False
    return error

args = __import__('sys').argv[1:]
if not error_found(args):
    letters = __import__('string').ascii_letters
    lo, hi = letters[:26], letters[26:]
    key = (
        {k: v.lower() for k, v in zip(lo, args[0])} | 
        {k: v.upper() for k, v in zip(hi, args[0])}
    )
    for c in input("Plaintext: "):
        print(key[c] if c.encode().isalpha() else c, end='')
