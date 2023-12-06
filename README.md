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
<a href="https://github.com/Chrystian-Natanael/" style="color: inherit; text-decoration: none;">🔗 Bonus part </a>
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