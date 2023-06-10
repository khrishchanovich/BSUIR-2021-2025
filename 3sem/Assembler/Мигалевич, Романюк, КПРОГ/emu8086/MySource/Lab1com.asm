.MODEL tiny
.CODE
ORG 100h  
START:  mov ah, 9h
        mov dx, offset message
        int 21h   
        mov dx, offset message2
        int 21h  
        ret
message db 'PRUVET, MAKSIM VALEREVICH, POSTAVTE 9, POZHALUSTA',0Dh,0Ah,'$'
message2 db 'POSHALUSTA NE MUCHAITE$'

end START


