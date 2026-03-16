#!/bin/bash
# Shebang line specifies that the script should be executed using bash shell

echo "========================================="
echo "        OPERATING SYSTEM DETAILS         "
echo "========================================="

# uname -o displays the operating system name
echo "Operating System Name:"
uname -o

# uname -r displays the kernel release number
echo "Kernel Release:"
uname -r

# uname -v displays the kernel version
echo "Kernel Version:"
uname -v

echo ""
echo "========================================="
echo "     TOP 10 CPU CONSUMING PROCESSES      "
echo "========================================="

# ps command displays process information
# -e selects all running processes
# -o specifies output format
# --sort=-%cpu sorts processes in descending order of CPU usage
# head -n 11 displays top 10 processes along with header
ps -eo pid,ppid,cmd,%cpu --sort=-%cpu | head -n 11

echo ""
echo "========================================="
echo "    TOP 10 MEMORY CONSUMING PROCESSES    "
echo "========================================="

# %mem shows memory usage of processes
ps -eo pid,ppid,cmd,%mem --sort=-%mem | head -n 11

echo ""
echo "========================================="
echo "        USER LOGIN INFORMATION           "
echo "========================================="

# whoami displays current effective user
echo "Current Logged-in User:"
whoami

# logname displays login name of the user
echo "Login Name:"
logname

echo "========================================="
echo "        SCRIPT EXECUTION COMPLETED       "
echo "========================================="