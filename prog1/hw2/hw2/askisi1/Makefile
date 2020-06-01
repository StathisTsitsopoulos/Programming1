osx: introGlutLib.c introGlutLib.h simulation.c hw2.c
	gcc -Wall -Wno-deprecated-declarations -framework glut -framework openGL -framework Cocoa introGlutLib.c simulation.c -o hw2

linux: introGlutLib.c introGlutLib.h simulation.c hw2.c
	gcc -Wall introGlutLib.c simulation.c -o hw2 -lglut -lGLU -lGL -lm -o hw2

clean:
	rm a.out
