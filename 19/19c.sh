#! /bin/bash
strace mkfifo myfifo_by_mkfifo_command_strace_1
strace -c mkfifo myfifo_by_mkfifo_command_strace_2

#since myfifo internally calls mknod therefore mknod is always going to be faster than mkfifo