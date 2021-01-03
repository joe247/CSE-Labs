# Intermediate Code Generation
'''
Precedence Table
================

Operator 	    Description 	                                    Associativity
---------------------------------------------------------------------------------
( ) 	        Parentheses   	                                    left-to-right

** 	            Exponent  	                                        right-to-left

*  /  % // 	    Multiplication/division/modulus/floor               left-to-right
+  – 	        Addition/subtraction 	                            

<<  >> 	        Bitwise shift left, Bitwise shift right 	        left-to-right

<  <=           Relational less than/less than or equal to          left-to-right
>  >= 	        Relational greater than/greater than or equal to

==  != 	        Relational is equal to/is not equal to              left-to-right

is,  is not     Identity                                            left-to-right
in, not in      Membership operators

& 	            Bitwise AND 	                                    left-to-right
^ 	            Bitwise exclusive OR 	                            left-to-right
| 	            Bitwise inclusive OR 	                            left-to-right
not 	        Logical NOT 	                                    right-to-left
and 	        Logical AND 	                                    left-to-right
or 	            Logical OR 	                                        left-to-right

=               Assignment                                          right-to-left
+=  -=          Addition/subtraction assignment
*=  /=          Multiplication/division assignment
%=  &=          Modulus/bitwise AND assignment
^=  |=          Bitwise exclusive/inclusive OR assignment
<<=  >>= 	    Bitwise shift left/right assignment 	
'''
# from dataclasses import dataclass # only for python 3.7+

# @dataclass
# class Keyval:
#   pos: int
#    opr: str


class Parser:
    def __init__(self, passed_expr) -> None:
        self.pos = []
        self.lft, self.rgt = '', ''
        self.cp_expr = passed_expr
        self.intr_cd = 'ZYXWVUTSRQPONMLKJIHGFEDCBA'

    def get_opr(self):
        for idx, char in enumerate(self.cp_expr):
            if char in ['=', '+', '-', '*', '/']:
                self.pos.append(idx)

    def explore(self):
        for ctr, opr_pos in enumerate(self.pos[1:]):  # skip '='
            self.go_left(opr_pos)
            self.go_right(opr_pos)
            cur_opr = self.cp_expr[opr_pos]
            self.cp_expr = self.cp_expr[:opr_pos] + \
                self.intr_cd[ctr] + self.cp_expr[opr_pos+1:]
            print(
                f"{self.cp_expr[opr_pos]} := {self.lft} {cur_opr} {self.rgt}", end='\t\t\t')
            print(self.cp_expr.replace('$', ''))

        self.go_right(-1)  # why?!
        self.go_left(len(self.cp_expr))
        print(f"{self.rgt} := {self.lft}")
        return

    def go_left(self, l_depth):
        l_depth -= 1
        while l_depth != -1 and self.cp_expr[l_depth] not in ['+', '-', '*', '/']:
            if self.cp_expr[l_depth] != '$':
                self.lft = self.cp_expr[l_depth]
                self.cp_expr = self.cp_expr[:l_depth] + \
                    '$' + self.cp_expr[l_depth+1:]
                break
            l_depth -= 1

    def go_right(self, r_depth):
        r_depth += 1
        while r_depth != -1 and self.cp_expr[r_depth] not in ['+', '-', '*', '/']:
            if self.cp_expr[r_depth] != '$':
                self.rgt = self.cp_expr[r_depth]
                self.cp_expr = self.cp_expr[:r_depth] + \
                    '$' + self.cp_expr[r_depth+1:]
                break
            r_depth += 1


if __name__ == "__main__":
    expr = input("Enter the expression: ")
    print("Intermedeate Code\t\tExpression")

    psr = Parser(expr)

    psr.get_opr()
    psr.explore()
