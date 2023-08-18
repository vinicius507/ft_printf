<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/ft_printfm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# 42 Printf
[![build](https://github.com/vinicius507/libft/actions/workflows/build.yml/badge.svg)](https://github.com/vinicius507/libft/actions/workflows/build.yml)
[![norminette](https://github.com/vinicius507/libft/actions/workflows/norminette.yml/badge.svg)](https://github.com/vinicius507/libft/actions/workflows/norminette.yml)

This repository contains my submission to the 42 Printf project for 42 School.
The goal of this project is to create a library that provides `printf` like utility functions.

## Introduction
The **libftprintf** library is a collection of formatted output functions inspired by the standard `printf` function.
It encompasses a variety of variations, each serving a specific purpose:

- `ft_printf` and `ft_vprintf`: Format and print data to the console.
- `ft_dprintf` and `ft_vdprintf`: Format and write data to a file descriptor.
- `ft_sprintf` and `ft_vsprintf`: Format and store output in a string buffer.
- `ft_asprintf` and `ft_vasprintf`: Dynamically allocate memory for formatted output as a string.

## Usage
> **Warning**
>
> During the 42 curriculum you are required to develop and use your **libftprintf** library.

To use the **libftprintf** library, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the repository's root directory.
3. Run `make` to compile the library.

A compiled library named `libftprintf.a` will be generated. You can link this library with your C programs to access the provided functions.

## Related Projects

- [Libft](https://github.com/vinicius507/libft).
- [42 Printf](https://github.com/vinicius507/ft_printf).
