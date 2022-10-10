#! /bin/bash
mknod myfifo_by_mknod_command p
ls -l | grep ^p