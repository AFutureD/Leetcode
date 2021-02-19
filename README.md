# Leetcode 刷题存档

## 准备

1. vscode 安装 leetcode 插件

2. 添加 `leetcode` 到 `bin`

   `ln -s ~/.vscode/extensions/leetcode.vscode-leetcode-0.17.0/node_modules/vsc-leetcode-cli/bin/leetcode /usr/local/bin/leetcode`

3. 修改 template

    `open ~/.vscode/extensions/leetcode.vscode-leetcode-0.17.0/node_modules/vsc-leetcode-cli/templates/codeonly.tpl`
    
   `open ~/.vscode/extensions/leetcode.vscode-leetcode-0.17.0/node_modules/vsc-leetcode-cli/templates/detailed.tpl`

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

4. 修改配置文件

   vscode 配置文件 `open ~/Library/Application Support/Code/User/settings.json`

   ```
   "leetcode.filePath": {
        "default": {
            "folder": "",
            "filename": "${id}.${ext}"
        }
   }
   ```

   leetcode-cli 配置文件 `open ~/.lc/config.json`

   ```
   {
      "file": {
         "show": "${fid}"
      }
   }
   ```

5. 编写脚本

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
   > ./engine test [filename]
   
   # 实际执行代码
   > g++ $filename 0_pre.o -std=c++11 -o main; ./main
   ```

4. 提交

   ```bash
   > leetcode submit [filename]
   ```