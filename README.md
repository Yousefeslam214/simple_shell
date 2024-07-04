<h1>Simple Shell Project</h1>
  <p>This project is a simple implementation of a shell program in C. A shell is a command-line interface that allows users to interact with the operating system by executing commands.</p>
  <h2>Features</h2>
  <ul>
    <li>Execute commands like <code>ls</code>, <code>pwd</code>, and <code>env</code>.</li>
    <li>Handle built-in commands such as <code>exit</code>, <code>cd</code>, and <code>setenv</code>.</li>
    <li>Support for custom commands defined within the shell.</li>
  </ul>
  <h2>Files</h2>
  <ul>
    <li><code>shell.c</code> - The main file that contains the core functionality of the shell.</li>
    <li><code>commands.c</code> - Contains the built-in command functions.</li>
    <li><code>free.c</code> - Functions to free allocated memory.</li>
    <li><code>getPath.c</code> - Functions to handle the PATH environment variable.</li>
    <li><code>helpFun.c</code> - Helper functions.</li>
    <li><code>runFun.c</code> - Functions to run commands.</li>
    <li><code>shell.h</code> - Header file with function declarations and struct definitions.</li>
    <li><code>str.c</code> - String utility functions.</li>
    <li><code>README.md</code> - Project documentation.</li>
    <li><code>AUTHORS</code> - List of project contributors.</li>
  </ul>
  <h2>Compilation</h2>
  <p>To compile the shell program, use the following command:</p>
  <pre><code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh</code></pre>
  <h2>Usage</h2>
  <p>After compilation, you can run the shell with:</p>
  <pre><code>./hsh</code></pre>
  <p>Then you can type commands like:</p>
  <pre><code>/bin/ls</code></pre>
  <p>To list files in the current directory.</p>
  <h2>Handling Errors</h2>
  <p>If you encounter errors such as "malloc_consolidate(): unaligned fastbin chunk detected", ensure that memory allocation and deallocation are handled correctly in the code.</p>
  <h2>Built-in Commands</h2>
  <p>The shell supports several built-in commands:</p>
  <ul>
    <li><code>exit</code> - Exit the shell.</li>
    <li><code>cd</code> - Change the current directory.</li>
    <li><code>setenv</code> - Set an environment variable.</li>
    <li><code>unsetenv</code> - Unset an environment variable.</li>
    <li><code>env</code> - Print the environment variables.</li>
  </ul>
  <h2>External Commands</h2>
  <p>The shell can also execute external commands by searching for the executable in the directories specified in the PATH environment variable.</p>
