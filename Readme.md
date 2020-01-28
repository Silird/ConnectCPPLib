Проект создан как тестовый пример по связке java и C++ с помощью jni.
Также была использована написанная на с++ библиотека .so или .dll с последующей интеграцией её функций в java.

На линуксе использовался стандартный пакет g++, истанавливаемый через get install и по подсказке, если он не установлен и запустить g++.<br>
На виндоус был установлен minGW с https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download

---

В папке с HelloWorldJNI.java ввести команду для генерации *.h
> javac -h . HelloWorldJNI.java

После чего надо создать .cpp файл с реализацией методов указанных в сгенерированном .h, скопировав сигнатуры функций полностью.
Не забыть импортировать заголовочный файл, который реализуется.

Название файлов можно поменять на любое, далее будет использоваться *nameJNI*<br>
Следует отметить, что .h и .cpp файлы **ОЧЕНЬ** путезависимые, если в проекте меняется путь 
или название класса, отвечающего за jni и имеющий native функции, 
то требуется полностью перегенерить .h файл и изменить сигнатуру функции в .cpp файле, 
после чего провести полный алгоритм создания библиотеки.

Чтобы указать java откуда брать библиотеки можно указать в параметрах запуска:
> -Djava.library.path=libs

Для подлючения библиотеки в java требуется ввести следующий код в класс с native методами:

```java
public class NameJNI {
    static {
        System.loadLibrary("nameJNI");
    }

    // public native ...;
}
```

---

##### Компиляция

linux:<br>
> g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux nameJNI.cpp -o nameJNI.o

`В системе должны быть обязательно прописана переменная JAVA_HOME. 
Проверить её наличие можно с помощью команды:`<br>
> echo ${JAVA_HOME}

`Если её нет, тогда требуется отредактировать файл /etc/profile и в его начало вставить следующие строки:`
> export JAVA_HOME="/usr/lib/jvm/java-X.X.X-openjdk-xxxxx"<br>
> export PATH=$JAVA_HOME/bin:$PATH

windows:<br>
> g++ -c -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" nameJNI.cpp -o nameJNI.o

`В системе должна быть прописана системная переменная JAVA_HOME c параметром например "C:\Program Files\Java\jdkX.X.X_XXX"`

#### Линковка

linux:<br>
> g++ -shared -fPIC -o libnameJNI.so nameJNI.o -lc [./libdynamic.so]

windows:<br>
> g++ -shared -o nameJNI.dll nameJNI.o -Wl,--add-stdcall-alias [dynamic.dll]

---

#### Компиляция динамической библиотеки с++

linux:<br>
> g++ -c dynamic.cpp

windows:<br>
> g++ -c dynamic.cpp

#### Линковка динамической библиотеки с++

linux:<br>
> g++ -shared -fPIC -o dynamic.so dynamic.o

windows:<br>
> g++ -shared -o dynamic.dll dynamic.o

#### Связка программы или библиотеки с библиотекой

linux:<br>
> g++ main.o ./dynamic.so<br>
> g++ main.o .libs/dynamic.so (чтобы библиотека должна была лежать в папке libs относительно исполняемого файла)

windows:<br>
> g++ main.o dynamic.dll

Чтобы библа могла лежать в отдельной папке например libs, надо в системных переменных среды к **PATH** добавить ".\libs"
