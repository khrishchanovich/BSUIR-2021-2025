 ldx #$6666
 ldy #$7777
 stx $0
 sty $2

 

 ldd $2
 subd $0
 aba

 ldab #$0
 staa $0100
 ldaa #$10
 tpa
 staa $0101
 ldaa $0100
 cba
 tpa
 ldab $0101
 sba