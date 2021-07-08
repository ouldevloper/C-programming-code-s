push   %rbp                                #    add rbp to head of stack
mov    %rsp,%rbp                           #    mov rsp to rbp    
sub    $0x10,%rsp                          #    rsp = rsp-10
movl   $0x0,-0x4(%rbp)                     #    
movl   $0x0,-0x8(%rbp)                     #
mov    $0x100,%edi                         #
call   0x555555555040 <malloc@plt>         #
mov    %rax,-0x10(%rbp)                    #
mov    -0x10(%rbp),%rax                    #
mov    %rax,%rsi                           #
lea    0xe71(%rip),%rdi                    #
mov    $0x0,%eax                           #
call   0x555555555050 <__isoc99_scanf@plt> #
jmp    0x555555555201 <main+156>           #
call   0x555555555060 <__ctype_b_loc@plt>  #
mov    (%rax),%rax                         #
mov    -0x8(%rbp),%edx                     #
movslq %edx,%rcx                           #
mov    -0x10(%rbp),%rdx                    #
add    %rcx,%rdx                           #    
movzbl (%rdx),%edx                         #
movsbq %dl,%rdx                            #
add    %rdx,%rdx                           #
add    %rdx,%rax                           #
movzwl (%rax),%eax                         #
movzwl %ax,%eax                            #
and    $0x800,%eax                         #
test   %eax,%eax                           #
je     0x5555555551fd <main+152>           #
mov    -0x4(%rbp),%edx                     #
mov    %edx,%eax                           #
shl    $0x2,%eax                           #
add    %edx,%eax                           #
add    %eax,%eax                           #
mov    %eax,%ecx                           #
mov    -0x8(%rbp),%eax                     #
movslq %eax,%rdx                           #
mov    -0x10(%rbp),%rax                    #
add    %rdx,%rax                           #
movzbl (%rax),%eax                         #
movsbl %al,%eax                            #
add    %ecx,%eax                           #
sub    $0x30,%eax                          #                                                                                                 
mov    %eax,-0x4(%rbp)                     #                                                                                                 
addl   $0x1,-0x8(%rbp)                     #                                                                                                 
mov    -0x8(%rbp),%eax                     #                                                                                                 
movslq %eax,%rdx                           #
mov    -0x10(%rbp),%rax                    #
add    %rdx,%rax                           #
movzbl (%rax),%eax                         #
test   %al,%al                             #
jne    0x5555555551a3 <main+62>            #
mov    -0x4(%rbp),%eax                     #
mov    %eax,%esi                           #
lea    0xdef(%rip),%rdi                    #
mov    $0x0,%eax                           #
call   0x555555555030 <printf@plt>         #
mov    $0x0,%eax                           #
leave                                      #
ret                                        #
#