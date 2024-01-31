# `Let's talk about: GNL` 💬

[<img src="https://raw.githubusercontent.com/Chrystian-Natanael/Aleatorios/master/Mycovers/CoverGNL.png" alt="libft_banner" width="1000">](https://github.com/Chrystian-Natanael/Aleatorios/blob/master/Mycovers/CoverGNL.png)

### `Select a language:`

<p align="center">
  <a href="https://github.com/Chrystian-Natanael/Get_next_line/blob/main/README_BR.md">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/Flags/Round_Brazil_Flag.png" alt="libft" width="50">
  </a>
  &nbsp &nbsp &nbsp &nbsp
  <a href="https://github.com/Chrystian-Natanael/Get_next_line">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/Flags/Round_EUA_Flag.png" alt="libft" width="50">
  </a>
</p>

<h3> 🦮 Summary: 🦮 <br>
<br>
<a href="https://github.com/Chrystian-Natanael/Get_next_line#what-is-gnl-" style="color: inherit; text-decoration: none;">🔗 What is GNL </a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/Get_next_line#mandatory-part-" style="color: inherit; text-decoration: none;">🔗 Mandatory part </a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/Get_next_line#how-to-use-it-" style="color: inherit; text-decoration: none;">🔗 How to use it </a>
<br>
</h3>

## `What is GNL?` 🤔

<p align="center">
  <a href="https://github.com/Chrystian-Natanael/Libft">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/badges/get_next_linem.png" alt="libft" width="125">
  </a>
  <br>
</p>

The `GNL` (Get_next_line) is the first project with a higher level of difficulty both in technical aspects and in visualizing and understanding the process of creating it. At first, we have two ways to code it: `Linked list` or with `arrays`.
<br>

`I chose` to use the `linked list`, seeing as I love learning new concepts and this new `data structure` seemed very fun. So, I decided to start by studying about linked lists, and a great start was to follow the videos from the `CodeVault` channel:

<br>

<p align="center">
	<a href="https://www.youtube.com/watch?v=uBZHMkpsTfg">
	<img src="https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white">
	</a>
</p>

<br>

But to summarize, a `linked list` is a sequence of `elements`, where each element is connected to the next one by a `pointer`. Unlike `arrays`, the elements are not placed contiguously in memory, which allows for efficient `insertions` and `deletions` as it doesn't require shifting elements around. Each element, known as a `node`, contains the `data` and a reference (or a `link`) to the next node in the sequence, making the structure `flexible` and `dynamic`.

# `Mandatory part` 📑

The mandatory part of the project states that the `Get_next_line()` function must read a line from a file descriptor. What does this mean? It means we must read up to the `'\n'`. And what if there is no `'\n'`? Then we must read until the end of the file, i.e., until `'\0'`. If something goes wrong, we return `NULL`. Sounds quite straightforward, doesn't it?

## Important notes:

- The `GNL` function must be prototyped as follows: `char *get_next_line(int fd);`

- The `return` value is a `line` that has been `read` ( `NULL` if there is nothing else to read, or an `error` occurred ).

- The function returns its result without `'\n'` if there is one.

- External functions allowed: `read`, `malloc`, `free`.

- The `GNL` function must be able to compile the `BUFFER_SIZE` value directly on the command line with `-D BUFFER_SIZE=\<value>`

- But, it should also run `without` a BUFFER_SIZE defined on the command line

- Remember that your program must `compile` with `-Wall -Wextra -Werror`

- You must only `deliver` the following files to your repository: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`

# `How to use it?` 🤔

### First step, `clone` my repository in the location where you will run it.

```bash
git clone https://github.com/Chrystian-Natanael/Get_next_line.git
```

### Then, simply include the header file in your main file to have access to the `get_next_line()` function.

```c
# include "get_next_line.h"
```

### Finally, just `call` the function in your main file, passing a `file descriptor`. Make sure you have a variable of type `char *` to receive the return of the function. (Which is the read line).

```c
char	*line;

line = get_next_line(fd);
```

### Below we have an example of a main file, just `make sure` you have a `test.txt` file at the root of your repository:

```c
# include "get_next_line.h" // for use get_next_line
# include <stdio.h> // for use printf
# include <fcntl.h> // for use open

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY); // open file
	line = get_next_line(fd); // first line
	printf("%s\n", line); // print first line
	free(line); // free first line
	close(fd); // close file
	return (0);
}
```