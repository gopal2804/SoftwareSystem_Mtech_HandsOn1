#! /bin/bash
mkfifo a=rw myfifo_by_mkfifo_command
ls -l | grep ^p