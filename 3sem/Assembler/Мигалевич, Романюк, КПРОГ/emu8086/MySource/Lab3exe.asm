.model small
.stack 100h
.data
    bufferStr db 7,7 dup('$')
    massiv dw 60 dup(0)           
    
    msg1 db 0Dh,0Ah, 'Input var $'
    msg2 db ': $'
    msg3 db 0Dh,0Ah,'Error!', 0Dh,0Ah,'$'
    
    msg4 db 0Dh,0Ah,'Decreasing', 0Dh,0Ah,'$'
    msg5 db 0Dh,0Ah,'Increasing', 0Dh,0Ah,'$'  
    msg6 db 0Dh,0Ah,'Mixed', 0Dh,0Ah,'$'  
    MaxArrayLength equ 30
ArrayLength dw ?
InputArrayLengthMsgStr db 'Enter the length of array: $'

ErrorInputMsgStr db 0Ah,0Dh,'Error! Incorrect value! Check yourinput!',0Ah,0Dh, '$'
ErrorInputArrayLengthMsgStr db 'Array length must be between 1 and30!',0Ah,0Dh,'$' 

InputMsgStr db 0Ah, 0Dh,'Input var: $'

CurrentEl db 2 dup(0)
Answer db 20 dup('$'), 0Ah,0Dh, '$'
NumBuffer dw 0
NumLength db 7
EnterredNum db 9 dup('$')
nextStr db 0Ah,0Dh,'$'
ten dw 10
two dw 2
digit_precision db 5
minus db 0
Max dw 0
MaxTemp dw 0
Array dw MaxArrayLength dup (0)
Temp dd 0
OutputArray dd MaxArrayLength dup(0) 
.code
start:          
print macro str              
    push ax
    push di       
    mov ax,0
    mov ah,9
    mov dx,offset str
    int 21h 
    pop di     
    pop ax
endm                
mov ax,@data
mov ds,ax
xor ax,ax
call FullArr
call getStr1
FullArr proc
call inputArrayLength
call inputArray
ret
endp
inputArrayLength proc near
mov cx, 1
inputArrayLengthLoop:
call ShowInputArrayLengthMsg
push cx
call inputElementBuff
pop cx
mov ArrayLength,ax
cmp ArrayLength,0
jle lengthError
cmp ArrayLength,30
jg lengthError
loop inputArrayLengthLoop
ret
endp
lengthError:
    call ErrorInput
    call ErrorInputLength
    jmp inputArrayLengthLoop
    inputArray proc
    xor di,di
    mov cx,ArrayLength
inputArrayLoop:
call ShowInputMsg
push cx
call inputElementBuff
pop cx
mov Array[di], ax
add di,2
loop inputArrayLoop
ret
endp
resetNumBuffer proc
mov NumBuffer, 0
ret
endp
inputElementBuff proc
xor ax,ax
xor cx,cx
mov al,NumLength
mov [EnterredNum],al
mov [EnterredNum+1],0
lea dx,EnterredNum
;


call input
mov cl,[EnterredNum+1]
lea si,EnterredNum
add si,2
xor ax,ax
xor bx,bx
xor dx,dx
mov dx,10
NextSym:
xor ax,ax
lodsb
cmp bl,0
je checkMinus
checkSym:
cmp al,'0'
jl badNum
cmp al,'9'
jg badNum
sub ax,'0'
mov bx,ax
xor ax,ax
mov ax,NumBuffer
imul dx
jo badNum
cmp minus,1
je doSub
add ax, bx
comeBack:
jo badNum
mov NumBuffer,ax
mov bx,1
mov dx,10
loop NextSym
mov ax,NumBuffer
mov minus,0
finish:
call resetNumBuffer
ret
doSub:
sub ax,bx
jmp comeBack
checkMinus:
inc bl
cmp al, '-'
je SetMinus
jmp checkSym
SetMinus:
mov minus,1
dec cx

cmp cx,0
je badNum
jmp NextSym
badNum:
clc
mov minus,0
call ErrorInput
call resetNumBuffer
jmp inputElementBuff
endp
input proc near
mov ah,0Ah
int 21h
ret
input endp
ErrorInput proc
lea dx, ErrorInputMsgStr
mov ah, 09h
int 21h
ret
endp
ErrorInputLength proc
lea dx, ErrorInputArrayLengthMsgStr
mov ah, 09h
int 21h
ret
endp
ShowInputArrayLengthMsg proc
push ax
push dx  
mov ah,09h
lea dx, InputArrayLengthMsgStr
int 21h
pop dx
pop ax
ret
endp
ShowInputMsg proc
    push ax
    push dx
    mov ah,09h ;output command
    lea dx, InputMsgStr ;show input msg to user
    int 21h
    pop dx
    pop ax
    ret
    endp                     
getStr1:
error1:       
    dec ax 
    inc cx
cont:       
    loop getStr1                                  
    mov ax,0
    mov cx,ArrayLength-1 
    mov si,0   
checkMassiv:
    mov bx,massiv[si+2]
    cmp massiv[si],bx
    jg minus2
    cmp massiv[si],bx
    jl plus2
    jmp contin22
minus2: 
    sub ax,1
    jmp contin22  
plus2:
    add ax,1
contin22:   
    add si,2
    loop checkMassiv     
    cmp ax,-ArrayLength+1
    je decreasing
    cmp ax,ArrayLength-1
    je increasing
    jmp mixed                                
decreasing:
    print msg4     
    jmp contin11     
increasing: 
    print msg5
    jmp contin11          
mixed:            
    print msg6    
contin11:                            
    mov ax,4C00h
    int 21h              
;proc                          
input2 proc        
    push ax
    push cx                
    push di
    mov ah,0Ah
    mov dx,offset bufferStr
    int 21h               
    mov di,10            
    mov ax,0               
    mov bx,0                    
    cmp bufferStr[2],'-'
    je minus1        
plus:                
    cmp bufferStr[1],6
    je error      
    cmp bufferStr[1],0
    je error    
    mov si,offset bufferStr+2 
    mov cl,bufferStr[1]   
    jmp loopCheck
minus1: 
    cmp bufferStr[1],0
   je error   
    mov si,offset bufferStr+3
    mov cl,bufferStr[1]
    dec cx     
    jmp loopCheck
loopCheck:
    mov bl,[si]             
    inc si                 
    cmp bl,'0'            
    jl error         
    cmp bl,'9'             
    jg error        
    sub bl,'0'             
    mul di                 
    jc error         
    add ax,bx              
    jc error         
    loop loopCheck 
    cmp ax,32767
    jg error    
    mov cx,1       
    cmp bufferStr[2],'-'
    je mulMinus 
    jmp stop        
mulMinus: 
    neg ax         
    jmp stop                               
error:
    print msg3
    mov cx,2      
stop:  
pop di         
mov massiv[di],ax
pop cx 
pop ax  
ret
input2 endp
end start
