import re
from pprint import pprint


def get_if_nt(handle, prods):
    """Loops over the passed production"""
    temp = []
    for sub_seq in prods[handle]:
        if sub_seq[0] in terminals:
            temp.append(sub_seq[0])
        else:
            if handle == sub_seq[0]:
                prods[handle].remove(sub_seq)
            return get_if_nt(sub_seq[0], prods)
    return temp

def get_first(grammar):
    """Loops over the given grammar"""
    first = dict()
    for lhs, rhs in grammar.items():
        first[lhs] = []
        for seq in rhs:
            if seq[0] in terminals:
                first[lhs].append(seq[0])  # first character in the first item
            else:
                # get if rhs[0][0] turned out to be a non-terminal
                if lhs == seq[0]:
                    grammar[lhs].remove(seq)
                first[lhs] = get_if_nt(seq[0], grammar)

    print("\nFIRST(NT) =>")
    pprint(first)


if __name__ == "__main__":
    n_ter = re.compile(r"[A-Z]+")  # match non-terminals
    ter = re.compile(r"[a-z]+|[\+\*\(\)\$]")  # match terminals

    lmt = int(input("Enter number of productions: "))
    # a = b = set(); a & b becomes object with same value
    productions, terminals, non_terminals = dict(), set(), set()

    for i in range(lmt):
        prd = input(f"Production {i+1}: ")
        lhs, rhs = prd[0], prd[3:]
        if lhs not in productions:
            productions[lhs] = []
        productions[lhs].append(rhs)
        [terminals.add(i) for i in re.findall(ter, prd)]
        [non_terminals.add(i) for i in re.findall(n_ter, prd)]

    # first = dict.fromkeys(productions.keys(), []) <- creating this causes trouble!
    get_first(productions)
