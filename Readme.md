Проект создан как тестовый пример по связке java и C++ с помощью jni.
Также была использована написанная на с++ библиотека .so или .dll с последующей интеграцией её функций в java.

На линуксе использовался стандартный пакет g++, истанавливаемый через get install и по подсказке, если он не установлен и запустить g++
На виндоус был установлен minGW с https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download

В папке с HelloWorldJNI.java ввести команду для генерации *.h
javac -h . HelloWorldJNI.java

После чего надо создать .cpp файл с реализацией методов указанных в сгенерированном .h, скопировав сигнатуры функций полностью.

Компиляция
g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux название_написанного.cpp -o название_написанного.o
g++ -c -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" название_написанного.cpp -o название_написанного.o

link
g++ -shared -fPIC -o libHello.so название_написанного.o -lc
g++ -shared -o hello.dll название_написанного.o -Wl,--add-stdcall-alias


Компиляция динамической либы с++
linux:
g++ -c dynamic.cpp
windows:
g++ -c dynamic.cpp

link
linux:
g++ -shared -fPIC -o dynamic.so dynamic.o
windows:
g++ -shared -o dynamic.dll dynamic.o

Связка программы или библиотеки с библиотекой
linux:
g++ main.o ./dynamic.so
g++ main.o .libs/dynamic.so (чтобы библа должна лежать в папке libs относительно исполняемого файла)
windows:
g++ main.o dynamic.dll
Чтобы библа могла лежать в отдельной папке например libs, надо в системных переменных среды к PATH добавить .\libs
