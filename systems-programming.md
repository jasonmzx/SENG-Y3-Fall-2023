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

