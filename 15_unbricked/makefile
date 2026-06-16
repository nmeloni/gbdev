RGBASM  = rgbasm
RGBLINK = rgblink
RGBFIX  = rgbfix

TARGET  = unbricked.gb

$(TARGET): main.o input.o memcpy.o ball.o
	$(RGBLINK) -o $@ $^
	$(RGBFIX) -v -p 0xFF $@

%.o: %.asm
	$(RGBASM) -o $@ $^

clean:
	rm *.o $(TARGET)
