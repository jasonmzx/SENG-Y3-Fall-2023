# Systems Programming

---

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 1.</summary>
  
  #### `pwd` P.rint W.orking D.irectory
  Prints the Directory, that this Terminal is currently in.

  #### `cd` C.hange D.irectory
  Change Directory

  `cd ..` CD One level down

</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 2.</summary>
  
  #### `chmod` (Change Mode)

  Will be discussed next week

  #### `passwd` (Change Password for current User)

  - Important, Linux Supports File Hierachy;

  - Root, with Children, Children with Users, etc...

  ![Linux Directory Structure](./static/linux-directory-structure.webp)

  **Everytime you want to MODIFY a File**, make a backup first!

  So like... how do I know `passwd` is a File, not a Directory


```shell
  (base) jason@debian:/etc$ ls -l passwd
-rw-r--r-- 1 root root 2062 Jul 17 14:44 passwd
(base) jason@debian:/etc$ 
  ```

First character of the `-rw-r--r--` doesn't start with a `d`, there it's a file.

Upon `ls -l <File or Directory>`


#### Example of a Directory, when using ls -l on it

```shell
drwxr-xr-x  4 root root    4096 Jul 17 14:39 apache2
-rw-r--r--  1 root root     433 Aug 23  2020 apg.conf
```

Here **apache2** is a directory, whereas **apg.conf** isn't.

---

What's nice about **Linux** is that we can change Networking & Hosts Configurations quite easily!

```shell
(base) jason@debian:/etc$ cat hosts
127.0.0.1	localhost
127.0.1.1	debian

# The following lines are desirable for IPv6 capable hosts
::1     localhost ip6-localhost ip6-loopback
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters

(base) jason@debian:/etc$ cat networks
default		0.0.0.0
loopback	127.0.0.0
link-local	169.254.0.0
```

View groups; sudo, adm, cdrom, dip, plugdev, lpadmin...
- By doing: `groups`

---

### File Types

**b** Buffered (Block-Oriented) Special File *(Such as a disk drive)*

**-** Regular File

**d** Directory File *(Folder)*

**p** Pipe

</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Lecture 3.</summary>

Creates new Linux Group:
`sudo newgrp {-l groupname}`

List all groups:
`groups`

# `ls -l` Command in Linux

The `ls -l` command is used to list files and directories in a long format, providing detailed information about each item in a directory. The output includes file permissions, ownership, size, modification date, and more.

## File Permissions

The file permissions section in the `ls -l` output consists of ten characters that represent various aspects of a file or directory's access control. These characters are divided into four parts:

### 1. File Type

- The first character indicates the type of the item.
  - `-` indicates a regular file.
  - `d` indicates a directory.
  - `l` indicates a symbolic link.
  - `c` indicates a character device.
  - `b` indicates a block device.
  - `p` indicates a named pipe (FIFO).
  - `s` indicates a socket.

### 2. Owner Permissions

- Characters 2-4 represent permissions for the owner of the file.
  - `r` indicates read permission.
  - `w` indicates write permission.
  - `x` indicates execute permission.
  - `-` indicates no permission.

### 3. Group Permissions

- Characters 5-7 represent permissions for the group associated with the file.
  - `r` indicates read permission.
  - `w` indicates write permission.
  - `x` indicates execute permission.
  - `-` indicates no permission.

### 4. Other Permissions

- Characters 8-10 represent permissions for others (users not in the owner group or group owner).
  - `r` indicates read permission.
  - `w` indicates write permission.
  - `x` indicates execute permission.
  - `-` indicates no permission.

## Examples

Here are some examples of `ls -l` output and their interpretations:

- Regular file with read and write permissions for the owner, read-only for the group and others:
---

## **Interpreter vs. Compiler**

Scripting uses an Interpreter

#### Interpreter


- **Interpreter** is a program that directly executes the source code line by line without converting it into an intermediate machine code or binary.
- It reads, translates, and executes the code line-by-line, which means it's relatively slower in execution compared to compilation.
- Errors are reported as they are encountered during execution, making debugging easier.
- Typically used in scripting languages like Python, Ruby, and JavaScript.

#### Compiler

- **Compiler** is a program that translates the entire source code into machine code or an intermediate representation (e.g., bytecode) before execution.
- It performs analysis of the entire program before execution, which can result in faster execution times.
- Errors are reported after the compilation phase, which means you may need to compile the code again after fixing errors.
- Commonly used in languages like C, C++, and Java.



</details>



<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Introduction to Shell Scripting</summary>

</details>