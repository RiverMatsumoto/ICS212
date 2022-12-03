libhomework9.so: homework9.c homework9.h
	gcc -o libhomework9.so -shared -fPIE -I /usr/java/jdk1.8.0_131/include -I /usr/java/jdk1.8.0_131/include/linux -I . homework9.c

homework9.h: homework9.class
	javah homework9

homework9.class: homework9.java
	javac homework9.java

run:
	java -Djava.library.path=. homework9
