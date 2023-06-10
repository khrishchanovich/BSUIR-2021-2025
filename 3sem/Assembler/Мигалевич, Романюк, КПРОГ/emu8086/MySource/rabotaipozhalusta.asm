.model small
.data
Filename db "file4.txt", 0                                    
Error_mes db "Error",0Dh, 0Ah,'$'
    
fileNotExistError  db 'File not founded'                               
Buffer db "$$$$$"                                             
str_number_mes db "The amount of str: " , '$'                           
FHndl dw 0                                                    
str_number dw 0

IDfileIn dw ?
IDfileOut dw ?    
                        
Error_open db "cannot open file",'$'   
pathError db 'cannot find path!$'
openedFilesError db 'Too many opened files!$'
accessError db 'Acess error!$' 
IOError db 'IO Error!$' 
invalidIdentifierError db 'Invalid identifier$'


.code
start:

mov ax, @data
mov ds, ax
mov es, ax

mov ah, 3dh                  
mov al, 0                    
lea dx, Filename             
int 21h
jc error                      
mov FHndl, ax                    

LP:                         
mov ah, 3Fh                  
lea dx, Buffer               
mov cx, 1
mov bx, FHndl                
int 21h
jc error                     
cmp ax, cx                   
jne EndOfFile
push dx                      
mov dl, Buffer
cmp dl , 10                  
je one_more_str                  

LP2:                        
mov ah, 02h                  
int 21h
pop dx                       
jmp LP                       

EndOfFile:                  
mov bx, FHndl                
mov ah, 3Eh                  
int 21h
inc str_number               
jnc quit                      

one_more_str:               
inc str_number               
jmp LP2                      

error: 
mov ah, 9h
mov dx, OFFSET Error_mes
int 21h                      
mov ah, 9h
mov dx, OFFSET Error_open
int 21h                     

quit:                       
mov ah , 2                   
mov dx , 10
int 21h
mov ah , 09h                 
mov dx , offset str_number_mes
int 21h                       

output:                     
lea di, str_number           
mov bx, 10                   
xor cx,cx                    
mov ax ,  str_number          

ASCII:                      
xor dx,dx                    
div bx                       
add dl,'0'                   
push dx                      
inc cx
test ax,ax                   
jnz ASCII                    

recordRezult:               
pop dx                       
mov ah , 2                   
int 21h
loop recordRezult            
  
  
finish: 


;    fileClose IDfileIn
 ;   fileClose IDfieldOut 
mov ax, 4c00h                
int 21h   


     
output1 macro offs
    pusha
    lea dx,offs
    mov ah,9h
    int 21h
    popa
output1 endm

cmp ax, 0003h
    je cannot_find_path
    cmp ax, 0004h
    je too_many_opened_files
    cmp ax, 0005h
    je cannot_access
    cmp ax, 0006h
    je invalid_identifier
     
    mov dx, offset IOError
    output1 dx
    int 20h
     
    cannot_find_path: 
    mov dx, offset pathError
    output1 dx   
    int 20h 
    
    too_many_opened_files:   
    mov dx, offset openedFilesError
    output1 dx  
    int 20h  
    
    cannot_access:
    mov dx, offset accessError
    output1 dx  
    int 20h    
    
    invalid_identifier:
    mov dx, offset invalidIdentifierError
    output1 dx  
    int 20h    

    
    file_not_exist_error:
     mov dx, offset  fileNotExistError  
    output1 dx
    int 20h    
    output1 dx
    int 20h  
    jmp finish


end start
                                                  