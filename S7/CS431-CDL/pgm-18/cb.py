# Compiler Backend
new_ln, imc, asm_opr = False, [], ''

print("Enter set of intermediate code: ")

while not new_ln:
    code = input()
    if not code:
        new_ln = True
        continue
    imc.append(code)

for idx, im_code in enumerate(imc):
    opr = im_code[3]
    if opr == '+':
        asm_opr = 'ADD'
    elif opr == '-':
        asm_opr = 'SUB'
    elif opr == '*':
        asm_opr = 'MUL'
    elif opr == '/':
        asm_opr = 'DIV'

    print(f"MOV R{idx}, {im_code[2]}")
    print(f"{asm_opr} R{idx}, {im_code[4]}")
    print(f"MOV {im_code[0]}, R{idx}")
