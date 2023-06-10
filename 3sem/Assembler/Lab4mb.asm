 ldaa #0 
 ldx #$8200
Loop:
 staa 0,x
 inca
 inx
 cpx #$82ff
 ble Loop

 ldx #$8200 ; нижн€€ граница массива
 ldy #$82ff ; верхн€€ граница массива

Swap:
 ldaa 0,x
 psha
 ldaa 0,y
 staa 0,x
 pula
 staa 0,y
 inx
 dey
 cpx #$8280
 ble swap
