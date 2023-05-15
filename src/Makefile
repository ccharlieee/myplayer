cc=gcc
exec=main
obj=main.o start_mplayer.o console.o
flags=-Wall
$(exec):$(obj)
	$(cc) $^ -o $@ $(flags)
%.o:%.c
	$(cc) -c $< -o $@ $(flags)

clean:
	rm $(obj) $(exec)