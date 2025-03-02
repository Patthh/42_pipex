# 42 Pipex

██████╗░██╗██████╗░███████╗██╗░░██╗ <br>
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝ <br>
██████╔╝██║██████╔╝█████╗░░░╚███╔╝░ <br>
██╔═══╝░██║██╔═══╝░██╔══╝░░░██╔██╗░ <br>
██║░░░░░██║██║░░░░░███████╗██╔╝╚██╗ <br>
╚═╝░░░░░╚═╝╚═╝░░░░░╚══════╝╚═╝░░╚═╝ <br>


## 📖 What is `pipex` 📊?
<details>
<summary><b>A program that simulates the Unix pipe mechanism</b></summary><br>
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Pipex is a project associated with the curriculum of École 42, a coding school known for its project-based learning approach.
The Pipex project uses the C programming language to recreate the behavior of the shell pipe operator `|` along with file redirections.
The goal of this project is to teach students about Unix processes, file descriptors, pipes, and inter-process communication while deepening their understanding of how shell commands are executed.
</p>
</details>

## ✅ Status
<details>
<summary><b>Project completion status</b></summary><br>
<p align="center">
Completed on : 2024-04-30 <br> 100/100</p>
</details>

## 🚀 Usage
To clone and compile:
```shell
git clone https://github.com/Patthh/42_pipex.git
cd 42_pipex && make
```

To run the program:
```shell
./pipex infile cmd1 cmd2 outfile
```

For example:
```shell
./pipex input.txt "grep hello" "wc -l" output.txt
```
This is equivalent to: `< input.txt grep hello | wc -l > output.txt` in shell

## ✨ Features
- 🔄 Handles multiple pipes and commands
- 📂 Properly manages file descriptors to avoid leaks
- 🔍 Robust error handling and informative error messages
- 🚀 Efficient process creation and management
- 🛠️ Support for commands with arguments and options
- 🔎 PATH environment variable parsing
- 📝 Clean code following the 42 Norm

> [!WARNING]
> Improper handling of file descriptors may result in memory leaks or zombie processes

## 🛠️ Implementation Details
<details>
<summary><b>Core Components</b></summary><br>
<p>The Pipex program consists of these main components:</p>

| Component | Description |
|---------|-------------|
| 📂 File Handling | Opening input/output files with proper permissions |
| 🔄 Pipe Creation | Creating pipes for inter-process communication |
| 🐣 Process Forking | Creating child processes with fork() |
| ⚙️ Command Execution | Parsing and executing commands with execve() |
| 🔍 Path Resolution | Finding the correct binary path for commands |
| 🧹 Resource Cleanup | Proper closing of file descriptors and memory management |

</details>

> [!NOTE]
> "Connecting processes like plumbing - one pipe at a time"

<div align="center">
  <img src="https://media.tenor.com/3grNO2sOwBgAAAAM/flood-pipe.gif" width="400" alt="Pipe System">
  <br>
  <i>A journey into Unix process communication</i><br><br><br>
</div>

---
<div align="center">
  <p>Made with ❤️ and lots of 📊</p>
</div>
