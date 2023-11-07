# R-TYPE [EPITECH PROJECT] [DOCUMENTATION]

<a href="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" alt="SFML">
        <img src="https://img.shields.io/badge/MADE%20WITH-SFML-brightgreen" /></a>
<a href="https://www.linux.org/" alt="Linux">
    <img src="https://img.shields.io/badge/Powered%20by-Linux-brightgreen" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-C%2B%2B-ff69b4" alt="C++">
        <img src="https://img.shields.io/badge/MADE%20WITH-C%2B%2B-ff69b4" /></a>
<a href="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" alt="Cmake">
        <img src="https://img.shields.io/badge/MADE%20WITH-CMAKE-red" /></a>
<a href="https://github.com/features/actions" alt="GitHub Actions">
    <img src="https://img.shields.io/badge/MADE%20WITH-GitHub%20Actions-blue" />
</a>

![LOGO](Assets/R-type_logo.png)

## Contents

- [Introduction](#Introduction)
- [Installation](#installation)
- [Prerequisites](#prerequisites)
- [Documentation](#documentation)
- [Usage](#usage)
- [Constraints](#constraints)
- [Controllers](#controllers)
- [Commit-standard](#commit-standard)
- [Lisence](#license)
- [Credits](#credits)


> R-Type Game Project Overview

## Introduction

Language: C++

Description:
This advanced C++ project focuses on the development of a networked video game, providing an introduction to game networking and offering an exploration into advanced development techniques and best software engineering practices.

Objective:
The aim is to recreate the legacy video game 'R-Type'. The challenge is to develop a multithreaded server, a graphical client, and a personalized game engine. The development is split into two phases: initially creating the core game architecture and a working prototype, followed by an enhancement phase where specific features can be added.

About R-Type:
R-Type is a renowned Horizontal Shmup (Shoot'em'up) game. Although not the pioneer of its genre, it gained immense popularity in the 90s, leading to various ports, spin-offs, and modern remakes.


## Prerequisites
  - CMake
  - C++17
  - python3

## Dependencies Installation

BOOST prerequisites: 
```bash
sudo apt-get install libboost-system-dev libboost-thread-dev
```

SFML, Doxygen and Build :
**No action required ! SFML, Doxygen & Boost is fetched and built automatically.**


## Documentation
The complete documentation updated at each update of the codebase [Here](https://mvs-source.github.io/Test_doc_host/)

Some more information about the Network [Here](Documentation/rfc2023.txt)


To access the documentation manually :
```bash
mkdir Doxyfile
doxygen Doxyfile
cd doxygen/html/
python3 -m http.server
# Then click on the adress started by http://...
```

## Usage

See the Tutorial in the documentation 👉 [here](https://mvs-source.github.io/Test_doc_host/md__documentation_tutorial.html)


## Installation

### SSH

```bash
git clone git@github.com:EpitechPromo2026/B-CPP-500-LYN-5-1-rtype-bryan.zakka.git
```
## Compilation

### Using CMake

```bash
mkdir build
cd build
cmake ..
```
For Client :
```bash
cd Client
make
```
For Server :
```bash
cd Server
make
```


## Constraints
* **Library:**
SFML Library [cf.SFML](https://github.com/SFML/SFML)


## Controller

**Player**

 Button        | Action
 --------------|-------------
 Arrow Up      | Top
 Arrow Down    | Down
 Arrow Left    | Left
 Arrow Right   | Right
 Space         | Shoot


## Commit Standard
By adhering to these standards, we aim to keep our codebase organized and our development process streamlined. We believe that a well-maintained commit history is a reflection of the team's dedication and professionalism.


[FIX] : For bug fixes

[ADD] : To add a new file/feature

[UP]  : Small changes without fixes

[REM] : For removing

## License
[License](License)

## Credits

* **Guillaume LE COZ**
* **Victor M. SMITH**
* **Paul ANCEY**
* **Neil AYEB**
* **Bryan ZAKKA**