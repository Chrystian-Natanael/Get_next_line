# `Vamos falar sobre: GNL` 💬

[<img src="https://raw.githubusercontent.com/Chrystian-Natanael/Aleatorios/master/Mycovers/CoverGNL.png" alt="libft_banner" width="1000">](https://github.com/Chrystian-Natanael/Aleatorios/blob/master/Mycovers/CoverGNL.png)

### `Selelecione a linguagem:`

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
<a href="https://github.com/Chrystian-Natanael/Get_next_line/blob/main/README_BR.md#o-que-%C3%A9-a-gnl-" style="color: inherit; text-decoration: none;">🔗 O que é a GNL </a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/Get_next_line/blob/main/README_BR.md#parte-mandat%C3%B3ria-" style="color: inherit; text-decoration: none;">🔗 Parte mandatória </a> <br> <br>
<a href="https://github.com/Chrystian-Natanael/Get_next_line/blob/main/README_BR.md#como-usar-isso-" style="color: inherit; text-decoration: none;">🔗 Como usar isso? </a>
<br>
</h3>

## `O que é a GNL?` 🤔

<p align="center">
  <a href="https://github.com/Chrystian-Natanael/Libft">
  <img src="https://github.com/Chrystian-Natanael/Aleatorios/raw/master/badges/get_next_linem.png" alt="libft" width="125">
  </a>
</p>

A `GNL` (Get_next_line) é o primeiro projeto com uma dificuldade maior tanto em questões técnicas quanto em visualizar e entender o processo de criá-la. A um primeiro momento, temos duas maneiras para poder codá-la: `Lista encadeada` ou com `arrays`.
<br>

`Eu escolhi` utilizar a `lista encadeada`, visto que eu adoro conhecer novos conceitos e essa nova `estrutura de dados` parecia muito divertida. Então resolvi começar estudando sobre lista encadeada, um ótimo começo foi acompanhar os vídeos do canal `CodeVault`

<br>

<p align="center">
	<a href="https://www.youtube.com/watch?v=uBZHMkpsTfg">
	<img src="https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white">
	</a>
</p>

<br>

Mas, resumindo um pouco, a `lista encadeada` é uma sequência de `elementos`, onde cada elemento está conectado ao próximo por um `ponteiro`. Diferente de `arrays`, os elementos não são colocados de forma contígua na memória, o que permite `inserções` e `remoções` eficientes, pois não requer o deslocamento de elementos. Cada elemento, conhecido como um `nó`, contém os `dados` e uma referência (ou um `link`) para o próximo nó na sequência, tornando a estrutura `flexível` e `dinâmica`.

# `Parte mandatória` 📑

A parte mandatória do projeto diz que a função `Get_next_line()` deve ler uma linha de um descritor de arquivo. O que isso significa? Significa que devemos ler até o `'\n'`. E se não houver `'\n'`? Então devemos ler até o final do arquivo, ou seja, até `'\0'`. Se algo der errado, retornamos `NULL`. Parece bem simples, não é?

## Notas importantes:

- A função `GNL` deve ser prototipada da seguinte forma: `char *get_next_line(int fd);`

- O valor de `retorno` é uma `linha` que foi `lida` ( `NULL` se não houver mais nada para ler, ou ocorreu um `erro` ).

- A função retorna seu resultado sem `'\n'` se houver um.

- Funções externas permitidas: `read`, `malloc`, `free`.

- A função `GNL` deve ser capaz de compilar o valor `BUFFER_SIZE` diretamente na linha de comando com `-D BUFFER_SIZE=\<valor>`

- Mas, também deve funcionar `sem` um BUFFER_SIZE definido na linha de comando

- Lembre-se de que seu programa deve `compilar` com `-Wall -Wextra -Werror`

- Você deve `apenas entregar` os seguintes arquivos para o seu repositório: `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`

# `Como usar isso?` 🤔

### Primeiro passo, `clone` o meu repositório no local onde você irá executá-lo.

```bash
git clone https://github.com/Chrystian-Natanael/Get_next_line.git
```

### Depois, inclua o cabeçalho em seu arquivo principal para ter acesso à função `get_next_line()`.

```c
# include "get_next_line.h"
```

### E por fim, apenas `chame` a função em seu arquivo principal, passando como argumento um `File descriptor`.
```c
get_next_line(fd);
```

### Abaixo temos um exemplo de arquivo principal, tenha `certeza` de que você possui um arquivo `test.txt` na raiz do seu repositório:

```c
# include "get_next_line.h" // para usar get_next_line
# include <stdio.h> // para usar printf
# include <fcntl.h> // para usar open

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY); // abrindo o arquivo
	line = get_next_line(fd); // lendo a primeira linha
	printf("%s\n", line); // imprimindo a primeira linha
	free(line); // liberando a primeira linha
	close(fd); // fechando o arquivo
	return (0);
}
```