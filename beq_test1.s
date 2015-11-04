lw $1, 0($0)
lw $2, 0($0)
add $1, $1, $1
add $2, $2, $2
bne $1, $2, s
add $4, $4, $1
add $5, $5, $5
nop
nop
s: 
add $4, $4, $2