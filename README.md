# Leetcode 刷题存档

## 准备

1. vscode 安装 leetcode 插件

2. 安装 [leetcode-cli](https://github.com/skygragon/leetcode-cli)

    `npm install -g leetcode-cli`

3. 修改 template

    `open /usr/local/lib/node_modules/leetcode-cli/templates/detailed.tpl`

    ``` js
    ${comment.start}
    ${comment.line} @lc app=${app} id=${fid} lang=${lang}
    ${comment.line}
    ${comment.line} [${fid}] ${name}
    ${comment.line}
    ${comment.line} Source : ${link}
    ${comment.line} Author : AFuture
    ${comment.line} Date   : ${(new Date()).toISOString().substring(0,16)}
    ${comment.line}
    ${comment.line} ${category}
    ${comment.line} ${level} (${percent}%)
    ${comment.line} Total Accepted:    ${totalAC}
    ${comment.line} Total Submissions: ${totalSubmit}
    ${comment.line} Testcase Example:  ${testcase}
    ${comment.line}
    ${comment.end}
    
    ${code}
    ```

4. 编写脚本

    见文件[`engine`](.engine)

## workflow

### cpp语言

0. 准备预编译文件

   ```bash
   g++ -c 0_pre.cpp -std=c++11
   ```

1. 生成题目对应文件

   ```bash
   > ./engine new [problem number]
   
   # 或者使用 leetcode-cli
   > leetcode show -gx -l cpp [problem number]
   ```

2. 编写代码

   - 添加 `#include "0_pre.h"`；

   - 编写 `main` 函数

3. 测试

   ```bash
   >./engine test [filename]
   
   # 实际执行代码
   > g++ $filename 0_pre.o -std=c++11 -o main; ./main
   ```

4. 提交

   ```bash
   > leetcode submit [filename]
   ```