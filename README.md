<p align="center">
  <img src="https://github.com/jotavare/jotavare/blob/main/42/banner/42_banner_minitalk.png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/evaluated-06%20%2F%2001%20%2F%202023-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/badge/score-125%20%2F%20100-success?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/languages/top/jotavare/minitalk?color=%2312bab9&style=flat-square" />
	<img src="https://img.shields.io/github/last-commit/jotavare/minitalk?color=%2312bab9&style=flat-square" />
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#disclaimer">Disclaimer</a> •
	<a href="#testers">Testers</a> •
	<a href="#license">License</a>
</p>

## ABOUT
Minitalk is a server/client system that uses UNIX signals for communication. The server displays its PID and receives decrypted signals as characters, while the client encrypts messages and sends true/false signals using SIGUSR1 or SIGUSR2 to the server's PID.

<a href="https://github.com/jotavare/minitalk/blob/master/subject/en_subject_minitalk.pdf">Click here</a> for the subject of this project.

## HOW TO USE
#### 1º - Clone the repository
```bash
git clone https://github.com/jotavare/minitalk
```
#### 2º - Enter the project folder and run `make`
```bash
cd minitalk/minitalk
make
```
#### 3º - Run server or server_bonus and copy its PID
```bash
./server
./server_bonus
```
#### 4º - Open another terminal, run client or client_bonus, paste the PID and write a message
```bash
./client [SERVER PID] [MESSAGE]
./client_bonus [SERVER PID] [MESSAGE] [EMOTE]
```
#### MAKEFILE RULES

`make` - Compiles client and server.

``make bonus`` - Compiles client_bonus and server_bonus.

``make all`` - Compiles all.

``make clean`` - Delete all .o (object files) files.

``make fclean`` - Delete all .o (object files) and .a (executable) files.

``make re`` - use rules `fclean` + `all`

## DISCLAIMER
At 42 School, it is expected that almost every project is written in accordance with the Norm, which is the coding standard of the school.

```bash
- No for, do while, switch, case or goto are allowed
- No more than 25 lines per function and 5 functions per file
- No assigns and declarations in the same line (unless static)
- No more than 5 variables in 1 function
- ...
```

<a href="https://github.com/jotavare/jotavare/blob/main/42/pdf/en_norm.pdf">Click here</a> for more information on 42 norms.

## TESTERS
* [Francinette](https://github.com/xicodomingues/francinette)

## LICENSE
<p>
This work is published under the terms of <a href="https://github.com/jotavare/jotavare/blob/main/LICENSE">42 Unlicense</a>.
</p>
