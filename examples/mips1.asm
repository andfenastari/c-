.data
foo: .word 0
.data
bar: .space 4
.text
fuun:
# preamble
        sub $sp, $sp, 4
        sw $fp, ($sp)
        sub $sp, $sp, 4
        sw $ra, ($sp)
        add $fp, $sp, 0
# push args
# argument x (offset = 0)
        sub $sp, $sp, 4
        sw $t0, ($sp)
# argument y (offset = 4)
        sub $sp, $sp, 4
        sw $t0, ($sp)
# decl x (offset = 8)
        add $sp, $sp, 1
        li $t1, 1
        sw $t1, 12($fp)
        lw $t1, 12($fp)
        sw $t1, 8($fp)
# decl y (offset = 16)
        add $sp, $sp, 1
        li $t1, 2
        sw $t1, 20($fp)
        lw $t1, 20($fp)
        sw $t1, 16($fp)
# decl z (offset = 24)
        add $sp, $sp, 1
        lw $t1, 8($fp)
        lw $t2, 16($fp)
        add $t1, $t1, $t2
        sw $t1, 32($fp)
        li $t1, 5
        sw $t1, 36($fp)
        lw $t1, 32($fp)
        lw $t2, 36($fp)
        add $t1, $t1, $t2
        sw $t1, 28($fp)
        lw $t1, 28($fp)
        sw $t1, 24($fp)
# decl u (offset = 40)
        add $sp, $sp, 1
        lw $t1, 24($fp)
        lw $t2, 16($fp)
        div $t1, $t2
        mflo $t1
        sw $t1, 44($fp)
        lw $t1, 44($fp)
        sw $t1, 40($fp)
# decl o (offset = 48)
        add $sp, $sp, 1
        lw $t1, 40($fp)
        lw $t2, 8($fp)
        slt $t1, $t1, $t2
        sw $t1, 52($fp)
        lw $t1, 52($fp)
        sw $t1, 48($fp)
# return expr stmt
        lw $v0, 40($fp)
        j .l1
# postamble
.l1:
        add $sp, $fp, 0
        lw $ra, ($sp)
        add $sp, $sp, 4
        lw $fp, ($sp)
        add $sp, $sp, 4
        jr $ra