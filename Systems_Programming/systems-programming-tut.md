
<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Tutorial 6.</summary>

### Zombie Process

A Zombie Process is a process that's still running, after it's main body has been executed, and it's just waiting to be closed or joined back
to main thread. *(Parent)*

- If a process's parent is alive but never executes a **wait()**, the process's return code will never be accepted and
the process will remain a zombie.

*More info: (extra)*

- A process that terminates cannot leave the system until its parent accepts its return code.
- If its parent process is already dead, it will already have been adopted by the "init" process, which always accepts its children's return codes.
- A zombie process doesn't have any code, data, or stack, so it doesn't use up many system resources, but it does continue to inhabit the system's task list.

### Orphan Processes

If the parent process dies before its child, the child is automatically adopted by the original "init" process, PID 1.

</details>