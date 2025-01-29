#!/bin/python3

'''
Content created by Gemini2 with following prompt:

Please write a python file testing availability of following packages:

... list of packages ...

'''

import subprocess
import sys
import importlib

def check_command_availability(command):
    """Checks if a command is available in the system's PATH."""
    try:
        subprocess.run(
            ["which", command], check=True, capture_output=True, text=True
        )
        return True
    except subprocess.CalledProcessError:
        return False


def check_python_package_availability(package_name):
    """Checks if a Python package is available."""
    try:
        importlib.import_module(package_name)
        return True
    except ImportError:
        return False


def print_section_header(header_text):
    """Prints a formatted section header."""
    print(f"\n{'='*60}\n{header_text.upper()}\n{'='*60}")


def print_command_status(command, available):
    """Prints the status of a command check."""
    status = "[OK]" if available else "[FAIL]"
    print(f"  {command:<20} : {status}")


def print_package_status(package, available):
    """Prints the status of a python package check."""
    status = "[OK]" if available else "[FAIL]"
    print(f"  {package:<20} : {status}")

def run_test_and_print_status(test_name, test_func, test_items):
    """Runs a test on multiple items and prints results."""
    print_section_header(test_name)
    for item in test_items:
        is_available = test_func(item)
        if test_func == check_command_availability:
            print_command_status(item, is_available)
        elif test_func == check_python_package_availability:
            print_package_status(item, is_available)

if __name__ == "__main__":
    # Bash 1
    bash1_commands = [
        "hostnamectl",
        "gcp",  # Assuming 'gcp' command exists in the environment or is an alias
        "view",
        "nano",
        "gzip",
        "gunzip",
        "pigz",
        "wget",
        "scp",
        "rsync",
        "htop",
        "xkill",
        "pidof",
        "mc",
    ]
    run_test_and_print_status("Bash 1 Commands", check_command_availability, bash1_commands)
    

    # Bash 2
    bash2_commands = [
        "bc",
        "sort",
        "paste",
        "xargs",
        "tee",
        "readlink",
        "dirname",
        "basename",
        "awk",
        "sed",
        "make"
    ]
    run_test_and_print_status("Bash 2 Commands", check_command_availability, bash2_commands)


    # Pliki obiektowe i linkowanie
    object_linking_commands = [
        "g++",
        "make",
        "cmake",
        "ar",
        "c++filt",
        "nm",
        "objdump",
        "ldd",
        "patchelf",
    ]
    run_test_and_print_status("Object File and Linking", check_command_availability, object_linking_commands)

    # Python packages
    python_packages = [
        "numpy",
        "matplotlib",
        "pandas",
        "glob",
        "scipy",
        "jupyter",
        "ollama"
    ]
    run_test_and_print_status("Python Packages", check_python_package_availability, python_packages)


    # Git
    run_test_and_print_status("Git", check_command_availability, ["git"])
    
    print("\nTests completed.")
 