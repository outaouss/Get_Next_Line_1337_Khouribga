## get_next_line — 42 Project

💡 **The Goal**

The goal of this project is to write a function that returns a line read from a file descriptor. Whether the input comes from a standard file, a redirect, or even stdin, the function must return the line ending with a newline character (\n) if it exists.

This project introduces the concept of Static Variables in C and provides a deep dive into how the Operating System manages files through File Descriptors, File Tables, and Inodes.

🏗️ **The Architecture (Under the Hood)**

To succeed in this project, I had to understand how the Linux Kernel tracks file positions. When get_next_line is called, it interacts with three system layers:

Per-Process FD Table: A private table for my program where the File Descriptor (FD) is used as an index.

Global Open File Table: A system-wide table that stores the File Offset (the "cursor"). This offset is automatically updated by the kernel every time read() is called.

Inode Table: Contains the metadata and the physical location of the data blocks on the hard drive.

🧠 **The Algorithm**

The logic is split into three main phases to ensure memory efficiency and handle "leftover" data (the Stash):

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
1. *The Reading Phase (ft_read_line)*
We read from the file in chunks of BUFFER_SIZE. We keep appending these chunks to our Static Stash until we find a \n or reach the end of the file (EOF).
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2. *The Extraction Phase (ft_get_line)*
Once the stash contains a newline, we locate its Memory Offset (the distance from the base address to the \n). We extract everything up to that point to return as the current line.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3. *The Cleanup Phase (ft_new_line)*
This is the most critical part for memory management. We take the remaining data in the stash (everything after the \n), save it into a new memory block, and free the old stash to prevent leaks.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

🛠️ **Features & Technical Details**

Static Variables: Used to preserve the "Stash" between function calls.

Memory Management: Fully checked with AddressSanitizer (ASan) and LeakSanitizer (LSan) to ensure 0 leaks and 0 memory corruption (no double-frees or buffer overflows).

Buffer Size Flexibility: Works with any BUFFER_SIZE (from 1 to 10,000,000).

Bonus Support: Handles multiple file descriptors simultaneously using an array of static variables.
