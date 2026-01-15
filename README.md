<img src="https://repository-images.githubusercontent.com/237800104/dfc69080-46fb-11eb-9413-0f02ce8f5532" alt="42 School">
<h1 align="center">
  My Common Core Journey
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42&logoColor=white" alt="42 School Badge">
  <img src="https://img.shields.io/badge/Language-C%20%2F%20C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C/C++ Badge">
  <img src="https://img.shields.io/badge/Focus-Algorithms%20%26%20Unix-red?style=for-the-badge" alt="Focus Badge">
</p>

<p align="center">
  <strong>Hi I'm Paul Mallet 👋. Welcome to my repository gathering all projects from the 42 School.</strong><br>
  This journey starts with rebuilding the C standard library from scratch and leads to complex challenges involving graphics, networking, operating system architecture, and modern C++ Object-Oriented Programming.
</p>

---

## 🛠️ Installation & Setup
To compile and test these Common Core projects, you must use a Unix-based environment (Linux or macOS). All projects are developed following C99 or C++98 standards and strictly adhere to the 42 School Norm. And because they are different requirements, every one of them have its own README.md. Feel free to install and test the ones you want.

### 🧰 Prerequisites
Before starting, ensure your system is equipped with the following tools & packages:

* MacOS :
```bash
xcode-select --install
```

* Windows(WSL2) :
```bash
sudo apt update && sudo apt install -y build-essential git valgrind
```

* Linux(any distribution) :
```bash
sudo apt update && sudo apt install -y build-essential git valgrind
```

### 🚀 Quick Start (Compilation)
Clone the repository:

```bash
git clone https://github.com/Paul-Mallet/42.git repo-name-you-want
cd repo-name-you-want
```

<table data-path-to-node="6"><thead><tr><td><span data-path-to-node="6,0,0,0">Component</span></td><td><span data-path-to-node="6,0,1,0">Requirement</span></td><td><span data-path-to-node="6,0,2,0">Purpose</span></td></tr></thead><tbody><tr><td><span data-path-to-node="6,1,0,0"><b data-path-to-node="6,1,0,0" data-index-in-node="0">Compiler</b></span></td><td><span data-path-to-node="6,1,1,0"><code data-path-to-node="6,1,1,0" data-index-in-node="0">gcc</code> or <code data-path-to-node="6,1,1,0" data-index-in-node="7">clang</code></span></td><td><span data-path-to-node="6,1,2,0">To compile C and C++ source files.</span></td></tr><tr><td><span data-path-to-node="6,2,0,0"><b data-path-to-node="6,2,0,0" data-index-in-node="0">Build Tool</b></span></td><td><span data-path-to-node="6,2,1,0"><code data-path-to-node="6,2,1,0" data-index-in-node="0">make</code></span></td><td><span data-path-to-node="6,2,2,0">To automate the compilation process via Makefiles.</span></td></tr><tr><td><span data-path-to-node="6,3,0,0"><b data-path-to-node="6,3,0,0" data-index-in-node="0">System Libs</b></span></td><td><span data-path-to-node="6,3,1,0"><code data-path-to-node="6,3,1,0" data-index-in-node="0">libc</code> &amp; <code data-path-to-node="6,3,1,0" data-index-in-node="7">ar</code></span></td><td><span data-path-to-node="6,3,2,0">Standard C library and archive tool for <code data-path-to-node="6,3,2,0" data-index-in-node="40">.a</code> files.</span></td></tr><tr><td><span data-path-to-node="6,4,0,0"><b data-path-to-node="6,4,0,0" data-index-in-node="0">Virtualization</b></span></td><td><span data-path-to-node="6,4,1,0"><response-element class="" ng-version="0.0.0-PLACEHOLDER"><link-block _nghost-ng-c3214560500="" class="ng-star-inserted"><a _ngcontent-ng-c3214560500="" target="_blank" rel="noopener" externallink="" _nghost-ng-c404503337="" jslog="197247;track:generic_click,impression,attention;BardVeMetadataKey:[[&quot;r_23e3a7dfd253f463&quot;,&quot;c_df27b05b87149c20&quot;,null,&quot;rc_fb8813ee9330cc58&quot;,null,null,&quot;en&quot;,null,1,null,null,1,0]]" href="https://www.virtualbox.org/" class="ng-star-inserted" data-hveid="0" decode-data-ved="1" data-ved="0CAAQ_4QMahgKEwju4IH8iYiSAxUAAAAAHQAAAAAQvgI">VirtualBox</a></link-block></response-element></span></td><td><span data-path-to-node="6,4,2,0">Required specifically for the <b data-path-to-node="6,4,2,0" data-index-in-node="30">Born2beRoot</b> project.</span></td></tr></tbody></table>

## 🏗️ The C Language Foundation (1)

A deep dive into <b>low-level</b> programming, <b>memory management</b>, <b>concurrent programmation</b> and <b>algorithmic thinking</b> using C Language (C99).

<table border="0">
  <tr>
    <td width="33%" align="center" valign="top">
      <h3>📚 Libft</h3>
      <p>My very first own C library. Recoding <b>standard libc</b> functions (string manipulation, memory handling, linked lists) to understand how they work under the hood.</p>
      <br>
    </td>
    <td width="33%" align="center" valign="top">
      <h3>🖨️ ft_printf</h3>
      <p>Recreating the famous <code>printf</code> function. A deep dive into <b>variadic arguments</b> in C and precise output formatting management.</p>
    </td>
    <td width="33%" align="center" valign="top">
      <h3>📝 Get Next Line</h3>
      <p>A crucial utility function that reads a file line by line. Teaches mastering <b>static variables</b> and complex buffer management to handle diverse <b>file descriptor</b> inputs.</p>
    </td>
  </tr>
  <tr>
     <td width="33%" align="center" valign="top">
      <h3>🐧 Born2beroot</h3>
      <p>System Administration and <b>Virtualization</b>. Setting up a secure Linux server (Debian), managing <b>partitions</b> (LVM), <b>SUDO</b> policies, UFW <b>firewall</b>, and strong password enforcement.</p>
      <br>
    </td>
     <td width="33%" align="center" valign="top">
      <h3>🔢 Push_swap</h3>
      <p>A highly optimized data sorting project using two <b>stacks</b> and a limited set of instructions. The goal is to sort integers with the absolute minimum number of operations using <b>Turk Sort</b> complex algorithmic strategy.</p>
      <br>
    </td>
    <td width="33%" align="center" valign="top">
      <h3>🔄 Pipex</h3>
      <p>Understanding UNIX mechanisms. Reproducing the behavior of shell <b>pipes</b> (<code>|</code>) executions. Mastering file descriptors, <b>redirections</b>, <b>forking</b>, and inter-process communication.</p>
    </td>
  </tr>
</table>

---

## 🎮 Graphics, System & Networking (2)

Advanced projects tackling concurrency, graphical rendering, and recreating core system components.

<table border="0">
  <tr>
    <td width="33%" align="center" valign="top">
      <h3>🐚 Minishell</h3>
      <p>Writing a mini Bash-like shell. A major group project involving parsing complex commands, handling environment variables, <b>signals</b>, processes, and implementing <b>builtins</b>.</p>
      <br>
    </td>
    <td width="33%" align="center" valign="top">
      <h3>🍝 Philosophers</h3>
      <p>An introduction to concurrency and threading. Solving the "Dining Philosophers" problem using mutexes and threads to manage shared resources and avoid <b>data races</b> or <b>deadlocks</b>.</p>
    </td>
    <td width="33%" align="center" valign="top">
      <h3>🌐 NetPractice</h3>
      <p>Practical networking challenges. Understanding <b>IP addressing</b>, <b>subnet masks</b>, <b>routing tables</b>, and configuring small networks to establish connectivity.</p>
    </td>
  </tr>
  <tr>
     <td width="33%" align="center" valign="top">
      <h3>❄️ Fract-ol</h3>
      <p>A 2D graphical project using the MiniLibX library. Exploring <b>Maths</b> fractals (Julia, Mandelbrot) and rendering them interactively with infinite zoom capabilities.</p>
    </td>
    <td width="33%" align="center" valign="top">
      <h3>👾 Cub3d</h3>
      <p>My first 3D game engine inspired by Wolfenstein 3D made with another student. Implementing <b>Raycasting</b> algorithms and <b>Maths</b> logic to render a dynamic 3D world from a 2D map description, handling textures and player movement.</p>
    </td>
     <td width="33%" align="center" valign="top">
      <h3>🏆 ft_transcendence</h3>
      <p>A Fullstack Single Page Application (SPA) featuring a local real-time 1VS1 Pong game in ©Rick&Morty theme. Built with <b>Fastify</b>, <b>React</b>, and <b>SQLite3</b> in team. It includes OAuth 2.0 authentication, 2FA, Avatars selection and a matchmaking system via <b>WebSockets</b> continuous connection.</p>
      <br>
    </td>
  </tr>
</table>

---

## 🤖 The C++ Objects Shift

Transitioning from procedural C to C++, focusing on rigorous <b>Object-Oriented Programming</b> principles, <b>classes</b>, <b>templates</b> and <b>design patterns</b> using C++ Language (C++98).

### Modules 00 to 04

The goal of those exercises are to initiate to the OOP paradigm, by creating many, many, many classes, while discovering concepts such as : Objects creator-destructor, Objects Relations, Design Patterns etc.

<details>
<summary><h4>🔵 CPP_00: The Basics & Namespaces</h4></summary>
<br>
Introduction to C++. Comparing procedural programming with OOP concepts. Discovering namespaces, classes, member attributes, standard input/output streams, and the "orthodox canonical form".
</details>

<details>
<summary><h4>🟢 CPP_01: Memory & References</h4></summary>
<br>
Deeper into memory management in C++. Understanding the difference between stack and heap allocation (`new`/`delete`), mastering references versus pointers, pointers to members, and utilizing the `switch` statement effectively.
</details>

<details>
<summary><h4>🟠 CPP_02: Ad-hoc Polymorphism & Overloading</h4></summary>
<br>
Designed to help understand ad-hoc polymorphism. Implementing function overloading, operator overloading, and reinforcing the usage of orthodox canonical classes for robust code.
</details>

<details>
<summary><h4>🔴 CPP_03: Inheritance</h4></summary>
<br>
The pillars of OOP. Exploring class inheritance, base and derived classes, protected access specifiers, and managing construction/destruction chains in class hierarchies.
</details>

<details>
<summary><h4>🟣 CPP_04: Subtype Polymorphism & Interfaces</h4></summary>
<br>
Advanced polymorphism. Understanding virtual functions, pure virtual functions, abstract classes, and how to implement interfaces to achieve true subtype polymorphism.
</details>

---

### Modules 05 to 09

The main purpose of those days is to discover a more flexible and robust way to code objects by using : errors handling, type casting, templates and STL containers.

<details>
<summary><h4>🟤 CPP_05: Exceptions Scopes</h4></summary>
<br>
Introduction to professional error handling. Learning the <b>try/throw/catch</b> mechanism to manage exceptional states. Deepening class hierarchies with abstract base classes.
</details>
