# CompilerHomeWorkI
北京航空航天大学软件学院

编译原理第一次上机作业

### 如果我的作业对你有帮助的话，麻烦给个star吧：D

# 词法分析作业

## 相关地址

测试服公测贴

http://forum.loheagn.com/d/124

测试OJ Rurikawa

[https://oj.karenia.cc](https://oj.karenia.cc/)

SystemProgramming 论坛

http://forum.loheagn.com

评测机开源仓库

https://github.com/BUAA-SE-Compiling/rurikawa

评测机使用说明

 https://github.com/BUAA-SE-Compiling/rurikawa/blob/master/docs/manual/submit.md

## 作业要求

编写一个词法分析的程序，从文件读入目标代码，并将识别到的 token 按每行一个输出到标准输出流（stdout）中。

要求能够识别的 token 类型以及输出格式如下：

| Token         | 输出格式       | 备注                                      |
| :------------ | :------------- | :---------------------------------------- |
| `BEGIN`       | `Begin`        |                                           |
| `END`         | `End`          |                                           |
| `FOR`         | `For`          |                                           |
| `IF`          | `If`           |                                           |
| `THEN`        | `Then`         |                                           |
| `ELSE`        | `Else`         |                                           |
| 标识符        | `Ident($name)` | 把 `$name` 替换成标识符的字符串，不带引号 |
| 无符号整常数  | `Int($value)`  | 把 `$value` 替换成整常数的值，不带前导零  |
| `:` 冒号      | `Colon`        |                                           |
| `+` 加号      | `Plus`         |                                           |
| `*` 乘号      | `Star`         |                                           |
| `,` 逗号      | `Comma`        |                                           |
| `(` 左括号    | `LParenthesis` |                                           |
| `)` 右括号    | `RParenthesis` |                                           |
| `:=` 赋值符号 | `Assign`       |                                           |
| 不能识别的    | `Unknown`      | 程序终止，不继续向下分析                  |

为了简化程序，我们做出以下约定：

- **关键字区分大小写**，且我们保证不会有与关键字相同的非全大写的标识符
- **整常数不会超过 32 位有符号整数 (int32) 的最大值**
- 数字后面紧跟着字母的情况，识别为**两个 token**（如 `1a` 识别成 `Int(1)` `Ident(a)`）

Token 中的 *标识符* 和 *无符号整常数* 的定义如下：

Token 中的 *标识符* 和 *无符号整常数* 的定义如下：

```none
// 数字
NonZeroDigit -> '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

// 字母
Alpha -> 
    | 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k'
    | 'l' | 'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v'
    | 'w' | 'x' | 'y' | 'z' 
    | 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K'
    | 'L' | 'M' | 'N' | 'O' | 'P' | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V'
    | 'W' | 'X' | 'Y' | 'Z' 

Letter -> Alpha | Digit

// 标识符
Ident -> Alpha { Letter }
// 如果有人更习惯正则表达式的格式的话, `NonDigit Letter*`

// 无符号整常数
Int -> Digit { Digit }
// 同样的, `Digit+`
```

## 读入与配置格式

本次评测的标识符是 `pascal_lex`。

运行你的程序的命令必须是 `run` 数组的最后一项，并使用 `$input` 替代你的程序命令中输入文件路径的地方。

一个配置文件的示例如下：

```dockerfile
# -- Dockerfile --
# 这个文件负责构建包含你的程序的 Docker 容器

# 使用 Java 12
FROM openjdk:12-alpine
# 向容器内复制文件
COPY ./* /app/
# 编译程序
WORKDIR /app/
RUN javac -d ./output ./my/path/MyClass.java
# 将当前目录设为输出目录
WORKDIR /app/output
# -- judge.toml --
# 这个文件负责告诉评测姬你需要怎么评测你的程序

# 我们的评测标识符是 pascal_lex
[jobs.pascal_lex]
# 使用 Dockerfile 来源，路径就是当前文件夹，镜像名称是 my-pascal-lexer
image = { source = "dockerfile", path = ".", tag = "my-pascal-lexer" }

# 假如你用的是 Java
run = [
  # 运行程序
  "java my.path.MyClass $input",
]
```

## 评测记录

2020-10-07 16:43

5/5

1fqtzwqc9mfrz

master

2020-10-07 16:35

4/5

1fqtzf2c7rb7r

master

2020-10-06 16:23

OtherError

1fqracpbca9kv

master

没了
