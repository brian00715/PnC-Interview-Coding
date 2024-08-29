#!/usr/bin/python3
"""Recursively clean all files and folders without the enxtension .cpp or .hpp"""

import os
import shutil

ignore_exts = [
    "cpp",
    "cc",
    "hpp",
    "py",
    "c",
    "h",
    "txt",
    "md",
    "json",
    "sh",
    "code-snippets",
    "gitignore",
    "clang-format",
    ".git",
]
igore_dirs = [".vscode", ".git", "./.git"]
dir_keywords = [".dSYM", "build", "test", "__pycache__"]


def clean(path):
    """Recursively clean all files and folders without the enxtension .cpp or .hpp"""
    for root, dirs, files in os.walk(path):
        dirs[:] = [d for d in dirs if d not in ignore_exts]

        for file in files:
            if file.split(".")[-1] not in ignore_exts:
                os.remove(os.path.join(root, file))
                print(f"remove {os.path.join(root, file)}")
                pass
        for dir in dirs:
            if dir in igore_dirs:
                continue
            if any(keyword in dir for keyword in dir_keywords):
                shutil.rmtree(os.path.join(root, dir))
                print(f"remove dir {os.path.join(root, dir)}")


if __name__ == "__main__":
    clean(".")
