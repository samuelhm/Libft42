
# Libft

**Libft** es una biblioteca de funciones estándar escrita en C, desarrollada como parte del plan de estudios de la escuela 42. La biblioteca incluye una variedad de funciones que complementan la biblioteca estándar de C (`libc`) y proporciona una base sólida para otros proyectos de la escuela.

## Tabla de contenidos

- [Descripción](#descripción)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Compilación e Instalación](#compilación-e-instalación)
- [Funciones Implementadas](#funciones-implementadas)
- [Autores](#autores)

## Descripción

Libft es un proyecto fundamental en la escuela 42 que consiste en recrear y extender la biblioteca estándar de C. Incluye una serie de funciones para la manipulación de cadenas, manejo de memoria, listas enlazadas, y mucho más. Esta biblioteca sirve como una base que puede ser utilizada en muchos otros proyectos a lo largo del programa.

## Estructura del Proyecto

La biblioteca está organizada en varios archivos `.c` con sus correspondientes encabezados `.h`. Cada archivo se centra en un conjunto de funciones relacionadas. Algunas de las categorías incluyen:

- **Funciones de Manipulación de Cadenas** (`ft_strlen`, `ft_strcpy`, `ft_strdup`, etc.)
- **Funciones de Manejo de Memoria** (`ft_memset`, `ft_memcpy`, `ft_bzero`, etc.)
- **Funciones de Conversión** (`ft_atoi`, `ft_itoa`, etc.)
- **Funciones de Manipulación de Listas** (`ft_lstnew`, `ft_lstadd`, `ft_lstdelone`, etc.)

## Compilación e Instalación

1. **Clona el repositorio**:
   ```bash
   git clone https://github.com/samuelhm/Libft42.git
   cd Libft42
   ```

2. **Compila la biblioteca** usando el comando `make`:
   ```bash
   make
   ```

3. **Usa la biblioteca**: Una vez compilada, se generará un archivo `libft.a`. Puedes incluir esta biblioteca en tus propios proyectos en C usando:
   ```c
   #include "libft.h"
   ```

   Luego, compila tu proyecto junto con `libft.a`:

   ```bash
   gcc -Wall -Wextra -Werror -o tu_programa tu_programa.c -L. -lft
   ```

## Funciones Implementadas

La biblioteca **Libft** incluye las siguientes categorías de funciones:

- **Funciones de Cadenas**: `ft_strlen`, `ft_strcpy`, `ft_strncmp`, `ft_strjoin`, `ft_split`, etc.
- **Funciones de Memoria**: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_calloc`, etc.
- **Funciones de Conversión**: `ft_atoi`, `ft_itoa`, `ft_tolower`, `ft_toupper`, etc.
- **Funciones de Manejo de Archivos**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`, etc.
- **Funciones de Listas**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstiter`, etc.


## Autores

- **Samuel H. M.** - [GitHub](https://github.com/samuelhm)

