# print('''\nGiven Grammar:
#    E -> E + E
#    E -> E / E
#    E -> E * E
#    E -> E - E
#    E -> id''')

# Accept all string that satisfies this grammar


def shift_reduce_parser(handle, prd_set):
    stack, actions = ['$'], ['initate', 'shift', 'reduce', 'accept', 'reject']
    top = lp = act = 0
    string = input("Enter input string: ") + '$'

    elm = string[lp]
    eqn = ''.join(stack[1:])

    print("\nStack\t\t\tInput\t\t\tAction")
    print("-----\t\t\t-----\t\t\t------")

    while act != 3 or act != 4:
        print(''.join(stack)+'\t\t\t' +
              ''.join(string[lp:])+'\t\t\t' + actions[act])

        if stack[top].isalpha() and stack[top] != 'E':
            act = 2
            stack[top] = handle  # reduce E --> id
            eqn = ''.join(stack[1:])
            continue
        elif eqn in prd_set:
            act = 2
            stack[1:] = handle  # reduce E --> E +-*/ E
            eqn = ''.join(stack[1:])
            top = len(stack) - 1
            continue

        if string[lp] == '$':
            if len(stack) <= 2:
                if stack[top] == handle:
                    act = 3
                    stack.pop()
                    break
            else:
                act = 4
                break

        act = 1
        stack.append(elm)  # shift
        top += 1
        if lp < len(string):
            lp += 1
        else:
            lp = len(string) - 1

        elm = string[lp]

    print(''.join(stack)+'\t\t\t' +
          ''.join(string[lp:])+'\t\t\t' + actions[act])


if __name__ == "__main__":
    start = 'E'
    grammar = ['E+E', 'E/E', 'E*E', 'E-E', 'id']
    print("Given Grammar: ")
    for prd in grammar:
        print(start + ' -> ' + prd)

    shift_reduce_parser(start, grammar)
