/**
 * @file pipe.cpp
 * @author SimonKenneth (smkk00715@gmail.com)
 * @brief Introduce the application of pipe communication
 * @version 0.1
 * @date 2024-01-26
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char message[] = "Hello, named pipe!";
    const char *fifo_path = "/tmp/my_fifo"; // 有名管道的路径

    // 创建有名管道
    if (mkfifo(fifo_path, 0666) == -1)
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    { // 子进程
        int fifo_fd = open(fifo_path, O_RDONLY);
        if (fifo_fd == -1)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        ssize_t read_bytes = read(fifo_fd, buffer, sizeof(buffer));
        close(fifo_fd);

        if (read_bytes > 0)
        {
            buffer[read_bytes] = '\0';
            printf("子进程收到消息：'%s'\n", buffer);
        }
        else
        {
            printf("无法读取消息。\n");
        }

        exit(EXIT_SUCCESS);
    }
    else
    { 
        // 父进程
        int fifo_fd = open(fifo_path, O_WRONLY);
        if (fifo_fd == -1)
        {
            perror("open");
            exit(EXIT_FAILURE);
        }

        ssize_t written_bytes = write(fifo_fd, message, strlen(message));
        close(fifo_fd);

        if (written_bytes == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        wait(NULL); // 等待子进程结束
        exit(EXIT_SUCCESS);
    }
}
