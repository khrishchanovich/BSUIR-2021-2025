 ldx #$6666
 ldy #$6666
 stx $0
 sty $2

 ldd $2
 subd $0
 tpa 

 staa $4
 bclr $4,%11111011

 ldaa $4