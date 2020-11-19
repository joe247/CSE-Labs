def display(fa):
    for states, values in fa.items():
        print(f"{states}", end="  |\t")
        for _, nfa in values.items():
            print(f"{nfa}\t", end=" ")
        print()


def find_closure(state, value, sym):
    closure = {}
    ec1 = state
    im_states = ec2 = ""
    if value["e"] != "":
        ec1 += value["e"]  # e*

    for sub_states in ec1:
        if e_NFA_TAB[sub_states][sym] != "":
            im_states += e_NFA_TAB[sub_states][sym]  # 0 / 1

    for sub_states in im_states:
        if e_NFA_TAB[sub_states]["e"] != "":
            ec2 = "".join(set(sub_states + e_NFA_TAB[sub_states]["e"]))  # e*

    closure[sym] = ec2  # e* -> 0 / 1 -> e*
    return closure


def e_closure():
    for state, value in e_NFA_TAB.items():
        tmp = {}
        for sym in ALPHABETS:
            tmp.update(find_closure(state, value, sym))
        NFA_TAB[state] = tmp


if __name__ == "__main__":
    ALPHABETS = {0, 1}
    e_NFA_TAB = {
        "A": {0: "",    1: "",      "e": "BF"},
        "B": {0: "",    1: "C",     "e": ""},
        "C": {0: "",    1: "",      "e": "D"},
        "D": {0: "E",   1: "",      "e": ""},
        "E": {0: "",    1: "",      "e": "BF"},
        "F": {0: "",    1: "",      "e": ""}
    }
    NFA_TAB = {}

    print("e-NFA\n-----")
    print("   |\t0\t 1\t e")
    print("---+------------------------")
    display(e_NFA_TAB)

    e_closure()

    print("\nNFA\n---")
    print("   |\t 0\t 1")
    print("---+----------------")
    display(NFA_TAB)
