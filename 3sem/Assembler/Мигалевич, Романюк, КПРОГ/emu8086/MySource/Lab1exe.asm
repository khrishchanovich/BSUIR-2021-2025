DATA SEGMENT
message db 'PRUVET, MAKSIM VALEREVICH, POSTAVTE 9,POZHALUSTA$'
DATA ends

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:  mov ax, DATA
        mov ds, ax
  
        mov ah, 9h
        mov dx, offset message
  
        int 21h

        mov ax, 4c00h
        int 21h

CODE ends
END START