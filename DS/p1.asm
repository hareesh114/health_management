li $v0,4
syscall

li $t0,1
addi $t0,$t0,2
addi $t1,$t0,1
sub $t2,$t1,$t0

li $v0,1
move $a0,$t2
syscall

add $t1,$t3,$t4
add $t5,$t6,$t7
add $t8,$t5,$t7

li $v0,10
syscall
