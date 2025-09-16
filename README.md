# pipex-42malagaProyect
> *“This project aims to deepen your understanding of processes and file descriptors.”*
> *— 42 Network Pipex Subject*

## 🧠 Descripción

**Pipex** es un proyecto del currículo de la **Escuela 42** que replica el comportamiento de una **pipeline de comandos UNIX**. A través de su desarrollo, el estudiante aprende a trabajar con **pipes**, **forks**, **file descriptors**, y el uso del sistema de llamadas como `execve`, `dup2`, y `close`.

Este proyecto emula el siguiente comportamiento:

```shell
< infile cmd1 | cmd2 > outfile
```

---

## ⚙️ Compilación

Para compilar el proyecto, simplemente ejecuta:

```bash
make
```

Esto generará el ejecutable `pipex`.

---

## 🚀 Uso

```bash
./pipex infile "cmd1" "cmd2" outfile
```

📌 **Ejemplo:**

```bash
./pipex infile "grep hello" "wc -l" outfile
```

Este comando:

1. Abre el archivo `infile`.
2. Ejecuta `grep hello` leyendo desde `infile`.
3. Pasa la salida de `grep` como entrada para `wc -l`.
4. Redirige la salida final al archivo `outfile`.

---

## 🛠️ Requisitos

* No se permite usar `system()`.
* Solo se permite el uso de las funciones estándar de C y del sistema (ver manpages).
* Manejo correcto de errores y permisos de archivos.
* Se deben cerrar todos los file descriptors abiertos.
* El proyecto debe ejecutarse correctamente bajo condiciones normales y también ante errores (archivos no encontrados, comandos inválidos, etc.).

---

## 📚 Funciones del sistema utilizadas

* `fork()`
* `pipe()`
* `dup2()`
* `execve()`
* `access()`
* `open()`, `close()`
* `waitpid()`
* `perror()`

---

## ✅ Evaluación

Durante la evaluación se comprobarán:

* Ejecución correcta del binario con distintos comandos y archivos.
* Comprobación del uso de pipes y procesos hijos mediante `lsof`, `ps`, etc.
* Gestión correcta de errores y recursos.
* Norminette.

