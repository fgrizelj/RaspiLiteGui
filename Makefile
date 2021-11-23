all:
	make -C ./window
	make -C ./rendering
	make -C ./lodepng
	make -C ./gui
	make -C ./main

clean:
	-make clean -C ./window
	-make clean -C ./rendering
	-make clean -C ./lodepng
	-make clean -C ./gui
	-make clean -C ./main
