 stx $8400
 sty $8403

 staa $8410
 stab $8411

 ldx #$c8fd
 ldy #$c7fe
 ldaa #$c6
 ldab #$c5
 
 ldaa #$c8
 ldab #$c6
 mul
 std $8412

 ldaa #$fd
 ldab #$c5
 mul
 std $8414

 ldaa #$c7
 ldab #$c6
 mul
 std $8416
 
 ldaa #$fe
 ldab #$c5
 mul
 std $8418

 ldd $8412
 addd $8414
 addd $8416
 addd $8418

 std $8420 

 

 