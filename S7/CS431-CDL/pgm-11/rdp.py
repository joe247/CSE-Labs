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
    global count
    try:
        if exp[count] == '+':
            count += 1
            T()
            _E()
    except IndexError as e:
        #print("Out of Bound!")
        return


def T():
    F()
    _T()


def _T():
    global count
    try:
        if exp[count] == '*':
            count += 1
            F()
            _T()
    except IndexError as e:
        #print("Out of Bound!")
        return


def F():
    global count, flag
    try:
        if exp[count].isalnum():
            count += 1
        elif exp[count] == '(':
            count += 1
            E()
            if exp[count] == ')':
                count += 1
            else:
                flag = 1
        else:
            flag = 1
    except IndexError as e:
        #print("Out of Bound!")
        return


if __name__ == "__main__":
    count = flag = 0
    exp = input(
        "Enter a expression [w/ only (+ or *) operators]: ").rstrip().replace(' ', '')

    E()

    if len(exp) == count and flag == 0:
        print("Valid Expression")
    else:
        print("Invalid Expression")
