//
// Created by 。 on 2024/5/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9
#define UNASSIGNED 0

// 函数原型声明
int isSafe(int grid[N][N], int row, int col, int num);
int findUnassignedLocation(int grid[N][N], int *row, int *col);
int solveSudoku(int grid[N][N]);
void printGrid(int grid[N][N]);

// 主函数
//int main() {
//    // 初始化数独游戏板
//    int grid[N][N] = {0};
//
//    // 设置随机种子
//    srand(time(NULL));
//
//    // 尝试解决数独
//    if (solveSudoku(grid)) {
//        printf("生成的数独：\n");
//        printGrid(grid);
//    } else {
//        printf("无法生成数独\n");
//    }
//    return 0;
//}

// 解数独的主要函数
int solveSudoku(int grid[N][N]) {
    int row, col;

    // 如果没有未分配的位置，我们已经完成了
    if (!findUnassignedLocation(grid, &row, &col))
        return 1; // 成功

    // 考虑数字 1 到 9
    for (int num = 1; num <= N; num++ ) {
        // 如果放置没有冲突
        if (isSafe(grid, row, col, num)) {
            // 使分配的数字暂时生效
            grid[row][col] = num;

            // 递归调用
            if (solveSudoku(grid))
                return 1;

            // 失败时撤销 & 尝试
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0; // 触发回溯
}

// 检查放置数字 num 是否安全
int isSafe(int grid[N][N], int row, int col, int num) {
    // 检查行和列
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return 0;

    // 检查小宫格
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i+startRow][j+startCol] == num)
                return 0;

    return 1;
}

// 在数独中找到未分配的位置
int findUnassignedLocation(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

// 打印数独板
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}
//这个任务包含两个主要部分：首先是使用 C 语言编写一个数独生成器，其次是熟悉 GCC 的编译流程以及使用 GDB 进行调试。以下是初步引导帮助你开始这个实验。
//
//### 一、数独生成器
//
//        **数独简介**：
//数独是一个经典的逻辑填数字游戏，通常是一个9×9的格子，分为9个3×3的子格。游戏的目标是在每一行、每一列以及每一个小的3×3宫格内填上1到9的数字，且同一个数字在每行、每列及每个小宫格中只能出现一次。
//
//**实现步骤概述**：
//1. **数据结构**：首先，你需要设计一个适合的数据结构来代表数独的游戏板。一种简单的方式是使用一个二维数组 `int board[9][9];`。
//2. **生成完全解**：可以通过递归回溯算法填充数独板来生成一个有效的完全解。
//3. **生成数独题**：从完全解的数独板中随机挖去一些数字，保留足够的数字以便有一个唯一的解。难易程度可通过挖去数字的数量来调整。
//4. **展示函数**：编写函数输出数独板的当前状态，方便调试和展示结果。
//
//### 二、GCC 编译
//
//1. **编写代码**：假设你的源代码保存在 `sudoku_generator.c` 文件中。
//2. **编译**：打开终端或命令行，进入源代码文件所在的目录，执行下面的命令来编译源代码：
//```bash
//        gcc -g sudoku_generator.c -o sudoku_generator
//```
//这里，`-g` 选项是为了生成调试信息。
//
//### 三、GDB 调试
//
//1. **启动 GDB**：在命令行中输入 `gdb sudoku_generator` 启动 GDB。
//2. **设置断点**：使用 `break` 命令在特定的函数或行号设置断点，例如：`break main`。
//3. **开始执行**：使用 `run` 命令开始执行程序。
//4. **单步执行**：使用 `step` （进入函数）和 `next` （不进入函数）命令查看程序的执行流程。
//5. **打印变量**：使用 `print` 命令查看特定变量的值，例如：`print board`。
//6. **继续执行**：当程序在断点处暂停时，使用 `continue` 命令继续执行。
//
//实现一个完整的数独生成器涉及到算法的设计和调试，这是一个相对复杂的任务。以上给出的步骤和概念仅仅是一个起点。根据实验要求，你可能需要深入学习相关的算法和调试技巧来完成这个任务。