.LC0:
        .base64 "IOOCsuODvOODoOOCkuS9nOOBo+OBpiBDKysg44KS57+S5b6X44GX44KI44GGIAA="
"main":
        push    rbp
        mov     rbp, rsp
        mov     esi, OFFSET FLAT:.LC0
        mov     edi, OFFSET FLAT:"std::cout"
        call    "std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)"
        mov     esi, OFFSET FLAT:"std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)"
        mov     rdi, rax
        call    "std::ostream::operator<<(std::ostream& (*)(std::ostream&))"
        mov     eax, 0
        pop     rbp
        ret
