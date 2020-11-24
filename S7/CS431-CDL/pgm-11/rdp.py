# E  --> TE'
# E' --> +TE' | e
# T  --> FT'
# T' --> *FT' | e
# F  --> (E)  | val

# Terminals: +, *, val, (, )
# Non terminals: E, E', T, T', F

def E():
    T()
    _E()


def _E():
    if lp == '+':
        match('+')
        T()
        _E()
    else:
        return


def T():
    F()
    _T()


def _T():
    if lp == '*':
        match('*')
        F()
        _T()
    else:
        return


def F():
    if lp == '(':
        match("(")
        E()
        if lp == ')':
            match(")")
    elif lp.isalpha():
            match(lp)
    else:
        return


def match(char):
    global lp, cnt
    if lp == char: # why this warning?
        cnt += 1
        lp = exp[cnt]
    else:
        print("Error!")

if __name__ == "__main__":
    cnt = 0
    exp = input("Enter a expression [w/ only (+ or *) operators]: ").rstrip().replace(' ', '') + '$'
    lp = exp[cnt]
    E()
    print("Accepted" if lp == '$' else "Rejected")
