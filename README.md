## ls-l

This program implements the command `ls-l~` and names it `list_home`. If a user runs the command `list_home` the content of their home directory must be displayed

The implementation creates a new process with `fork()` and then runs a new program within that process' space `execve`.
