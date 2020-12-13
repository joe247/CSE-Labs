import re


def rec_fst(r_i, r_prods, r_rhs):
    idx = r_prods.index(r_i)
    if idx == len(r_prods) - 1:
        return ''
    if r_rhs[0] in terminals:
        return r_rhs[0]
    else:
        r_prods = r_prods[(r_prods.index(r_i)):]
        r_i = r_prods[idx+1]
        r_rhs = r_i[3:]
        rec_fst(r_i, r_prods, r_rhs)


def get_first(prods):
    first = dict()
    for i in prods:
        if (i[0] not in first):
            first[i[0]] = []

        rhs = i[3:]

        if rhs[0] in terminals:
            first[i[0]].append(rhs[0])
        else:
            first[i[0]].append(rec_fst(i, prods, rhs))

    print(first)


if __name__ == "__main__":
    n_ter = re.compile(r"[A-Z]+")
    ter = re.compile(r"[a-z]+|[\+\*\(\)\$]")

    lmt = int(input("Enter number of productions: "))
    productions = []
    # a = b = set(); a & b becomes object with same value
    terminals, non_terminals = set(), set()

    for i in range(lmt):
        prd = input(f"Production {i+1}: ")
        [terminals.add(i) for i in re.findall(ter, prd)]
        [non_terminals.add(i) for i in re.findall(n_ter, prd)]
        productions.append(prd)

    get_first(productions)

    #print(terminals, non_terminals)
