import logging

logging.basicConfig(filename="newfile.log",
                    format='%(asctime)s %(message)s', filemode='w')
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)


def deter_precedence(row, col):
    if (row == col and row.isalnum() and col.isalnum()) or row == col == '$':
        return '='
    elif row.isalnum():
        return '>'
    elif row == '$':
        return '<'
    else:
        if row == '+' or row == '-':
            return '<' if (col == '*' or col == '/' or col.isalnum()) else '>'
        else:  # row == '*' or row == '/'
            return '<' if col.isalnum() else '>'


def operator_p_parsing(pr_table, terminals):
    stack, actions = ['$'], ['initate', 'shift', 'reduce', 'accept', 'reject']
    top = lp = act = 0
    ip_string = list(
        map(str, input("\n\nEnter input string (seperated by space): ").split())) + ['$']

    print("\nStack\t\t\tInput\t\t\tCompare\t\t\tAction")
    print("-----\t\t\t-----\t\t\t-------\t\t\t------")

    while lp < len(ip_string):
        if ip_string[lp] not in terminals:
            #print("----> * Invalid terminal * <----")
            act = 4
            break
        print(''.join(stack[:top+1])+'\t\t\t' +
              ''.join(ip_string[lp:])+'\t\t\t' +
              deter_precedence(stack[top], ip_string[lp]) +
              '\t\t\t'+actions[act])
        logger.debug(stack[top] + ip_string[lp] +
                     deter_precedence(stack[top], ip_string[lp]))
        if deter_precedence(stack[top], ip_string[lp]) == '=':
            act = 3
            lp += 1
        elif deter_precedence(stack[top], ip_string[lp]) == '<':  # push | shift
            stack.append(ip_string[lp])
            top += 1
            act = 1
            lp += 1
        elif deter_precedence(stack[top], ip_string[lp]) == '>':  # pop | reduce
            stack.pop(-1)
            top -= 1
            act = 2

    print(''.join(stack[:top+1])+'\t\t\t' +
          ''.join(ip_string[lp:])+'\t\t\t'*2 +
          (actions[act] if act == 3 else actions[4]))


def precedence_table():
    # generate precedence table
    terminals = list(
        map(str, input("Enter terminals (seperated by space): ").split()))
    pr_tbl = []
    print('\nOperator Precedence Table:\n', end='\t')
    for i in terminals:
        print(i, end='\t')
    for idx, row in enumerate(terminals):
        pr_tbl.append([])
        print('\n'+row, end='\t')
        for col in terminals:
            sign = deter_precedence(row, col)
            pr_tbl[idx].append(sign)
            print(sign, end='\t')
    return pr_tbl, terminals


if __name__ == "__main__":
    pr_table, terminals = precedence_table()
    operator_p_parsing(pr_table, terminals)
