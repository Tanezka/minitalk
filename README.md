# Minitalk 🚀

**Minitalk** is a UNIX signal-based communication program where a **client** sends messages to a **server** using `SIGUSR1` and `SIGUSR2`. The server decodes and prints the messages in real-time. Built in C with strict error handling and zero memory leaks.

---

## 📝 Table of Functions

| **Function**               | **File**      | **Description**                                                                 |
|----------------------------|---------------|---------------------------------------------------------------------------------|
| `server_main`              | `server.c`    | Initializes the server, prints PID, and listens for incoming signals.           |
| `client_main`              | `client.c`    | Validates input and sends the message bit-by-bit to the server.                 |
| `send_bit`                 | `client_utils.c` | Encodes a character into bits and sends `SIGUSR1` (0) or `SIGUSR2` (1).        |
| `sig_handler`              | `server.c`    | Decodes received bits into characters and reconstructs the full message.        |
| `print_pid`                | `server_utils.c` | Prints the server’s PID to stdout.                                             |
| `validate_pid_and_message` | `client_utils.c` | Checks if the PID is valid and the message is non-empty.                       |
| `error_exit`               | `utils.c`     | Handles fatal errors (e.g., invalid PID, signal failure) and exits gracefully.  |
| `ft_itoa`                  | `libft`       | Custom integer-to-ASCII converter (for PID printing).                          |

---

## 🛠️ Installation & Usage

### Requirements
- **libft**
- **Unix-based OS** (Linux/macOS)
- **GCC** compiler

### Steps
1. Clone the repo:
   ```bash
   git clone https://github.com/your-username/minitalk.git && cd minitalk
2. Compile:
   ```
   make # Compiles both server and client
3. Run the server (it will print its PID):
   ```
   ./server
4. Send a message using the client:
   ```
   ./client <SERVER_PID> "Hello, World! 🌍"

## 🚨 Features
- **Real-time message decoding** with signal queuing workaround.
- **Robust error handling**: Invalid PID, empty messages, and signal errors are caught.
- **No memory leaks**: All heap memory is properly freed.
- **Single global variable** per program (server and client) for state management.
