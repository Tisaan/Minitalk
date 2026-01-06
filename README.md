# Minitalk

# Installation
If you're reading this **README.md**, you've probably already clone this project,
but `lib_ft` folder is a submodule. 
So initialize it with:
```bash
git submodule init
git submodule update
```
before continuing with the project.  

# Purpose
Make a `client` and a `server` communicate with *signal*.
The `server` should be started first.
It should display is **PID** to communicate with him.
The client should use the syntax `./client <PID> <message>`, sending the message to `server` which should display it rapidly.

