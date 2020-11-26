
                global  ft_strlen

                section .text
ft_strlen:
                mov     rdx, 0
_while:
                mov     cl, [rdi+rdx]
                cmp     cl, 0
                je      return
                inc     rdx
                jmp     _while

return:         mov     rax, rdx
                ret

