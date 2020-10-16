def gen_tokens(inp_file):
    with open(inp_file, 'r') as f_inp, open('inter.txt', 'w') as f_itr:
        content = f_inp.read()
        for character in content:
            if character.isalnum() or (character in ['[', ']', '.']):
                f_itr.write(character)
            else:
                f_itr.write('\t$\t' if character ==
                            '\n' else f'\t{character}\t')


def recognize_char():
    with open('inter2.txt', 'r') as f_itr, open('key.txt', 'r') as f_key, open('opr.txt', 'r') as f_opr:
        contents, operators, keys = f_itr.read(), f_opr.readlines(), f_key.readlines()
        flag, l_count = 0, 1
        print(f'Line {l_count}')
        for character in contents.split():
            if character == '$':
                l_count += 1
                print(f'Line {l_count}')
                continue
            # crosscheck operators
            for opr in operators:
                if character == opr[0]:
                    print(f"\t\t{character}\t:\t{opr[2:].strip()}")
                    flag = 1
                continue
            # crosscheck keywords
            for key in keys:
                if character == key.strip():
                    print(f"\t\t{character}\t:\tKeyword")
                    flag = 1
                continue
            # if neither keyword nor operator
            if flag == 0:
                print(f"\t\t{character}\t:\tConstant" if character.isdigit(
                ) else f"\t\t{character}\t:\tIdentifier")
                continue
            flag = 0


if __name__ == '__main__':
    inp_file = input('Enter the file name: ')
    gen_tokens(inp_file)
    print()
    print("Lexical Analysis")
    recognize_char()
