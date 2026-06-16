SECTION "MemCopy", ROM0

;; Function MemCopy
;; @param de: Source
;; @param hl: Dest
;; @param bc: Len
MemCopy::
    ld a, [de]
    ld [hl+], a
    inc de
    dec bc
    ld a, b
    or a, c
    jp nz, MemCopy
    ret
