# Script Language --Shell

- 绝大多数短选项可以组合，长选项则不可以组合

## 基础命令

### cd
- **功能**：切换目录
- **语法**：
  ```bash
  cd [目录路径]
  ```
- **示例**：
  ```bash
  cd Documents      # 进入用户主目录下的Documents文件夹
  cd ..             # 返回上一级目录
  cd ~              # 返回用户主目录。其中，~ 表示我的主目录，即 /Users/konfer
  cd -              # 返回上次所在的目录
  .                 # 表示 当前目录
  ./                # 开头的路径表示 从当前目录开始的相对路径。./foo 就是当前目录下的 foo
  ```

### ls
- **功能**：列出目录内容
- **语法**：
  ```bash
  ls [选项] [目录路径]
  ```
- **常用选项**：
  - `-l`：以长格式列出文件和目录详情
  - `-a`：显示包括隐藏文件在内的所有文件
  - `-h`：以人类可读的格式显示文件大小（与`-l`一起使用）
- **示例**：
  ```bash
  ls               # 列出当前目录下的文件和文件夹
  ls -l            # 以长格式列出当前目录下的文件和文件夹
  ls -a            # 列出包括隐藏文件在内的所有文件
  ls /Users        # 列出/Users目录下的内容
  ```

### pwd
- **功能**：显示当前工作目录
- **语法**：
  ```bash
  pwd
  ```
- **示例**：
  ```bash
  pwd              # 显示当前所在目录的完整路径
  ```

### touch
- **功能**：创建空文件或更改文件时间戳
- **语法**：
  ```bash
  touch [文件名]
  ```
- **示例**：
  ```bash
  touch newFile.txt    # 在当前目录下创建一个名为newFile.txt的空文件
  ```

### mkdir
- **功能**：创建新目录
- **语法**：
  ```bash
  mkdir [目录名]
  ```
- **示例**：
  ```bash
  mkdir newFolder      # 在当前目录下创建一个名为newFolder的新目录
  ```

### cp
- **功能**：复制文件或目录。把源文件完整地读取一遍，然后完整地写入到目标位置。如果目标文件已经存在，它会直接用新文件覆盖掉旧文件。
- **语法**：
  ```bash
  cp [源文件/目录] [目标文件/目录]
  ```
- **示例**：
  ```bash
  cp file.txt copy.txt         # 复制file.txt为copy.txt
  cp -r directory1 directory2  # 复制目录directory1到directory2
  ```

### rsync
- **功能**：一个功能强大的远程同步和备份工具。它通过“增量传输算法”来智能地复制文件和目录。它会比较源和目标的文件差异，只传输被修改过的部分，因此在重复执行时速度极快，尤其适合网络传输和备份。
    - **语法**：
    ```bash
    # 本地同步
    rsync [选项] [源文件/目录] [目标目录]

    # 推送到远程服务器
    rsync [选项] [本地源] [用户名@远程主机:远程目标路径]

    # 从远程服务器拉取
    rsync [选项] [用户名@远程主机:远程源路径] [本地目标]
    ```
- **常用选项**:
  * `-a` (archive): 归档模式，相当于 `-rlptgoD` 的集合，会保留几乎所有文件属性（权限、时间戳、所有者等）。**通常是必加选项**。
  * `-v` (verbose): 详细模式，显示传输过程中的文件列表。
  * `-h` (human-readable): 以人类可读的格式显示输出（例如 1K, 2M）。
  * `-z` (compress): 在传输过程中压缩文件数据，可以提高网络传输速度。
  * `--delete`: 删除目标目录中源目录不存在的文件，实现真正的“同步”。
  * `-n` 或 `--dry-run`: 模拟运行。显示会执行哪些操作，但**不实际执行**，用于测试。
- **示例**：
```bash
# 本地同步，-avh是常用组合
# 注意：source/ 表示同步目录里的内容，而 source 表示同步目录本身
rsync -avh source/ destination

# 推送本地项目到远程服务器
rsync -avh ./my-project/ user@123.45.67.89:/home/user/www/

# 同步备份，并删除目标目录多余的文件
rsync -avh --delete source/ user@123.45.67.89:/home/user/backup/

# 测试一下同步操作会发生什么，但不实际执行
rsync -avhn --delete source/ destination
```
### mv
- **功能**：移动或重命名文件或目录
- **语法**：
  ```bash
  mv [源文件/目录] [目标文件/目录]
  ```
- **示例**：
  ```bash
  mv file.txt Documents/       # 将file.txt移动到Documents目录下
  mv oldname.txt newname.txt   # 将oldname.txt重命名为newname.txt
  ```

### rm
- **功能**：删除文件或目录
- **语法**：
  ```bash
  rm [选项] [文件/目录]
  ```
- **常用选项**：
  - `-r`：递归删除目录及其内容
  - `-f`：强制删除，不提示确认
- **示例**：
  ```bash
  rm file.txt          # 删除file.txt文件
  rm -r directory/     # 删除directory目录及其内容
  ```

### cat
- **功能**：查看文件内容、连接文件或创建新文件
- **语法**：
  ```bash
  cat [选项] [文件名]
  ```
- **常用选项**：
  - `-n`：显示行号
- **示例**：
  ```bash
  cat file.txt         # 在终端中显示file.txt的内容
  cat file1.txt file2.txt > combined.txt  # 将file1.txt和file2.txt的内容合并到combined.txt
  ```

### less
- **功能**：分页查看文件内容
- **语法**：
  ```bash
  less [文件名]
  ```
- **示例**：
  ```bash
  less largefile.txt   # 分页查看largefile.txt的内容，按空格键翻页，按q键退出
  ```

### grep
- **功能**：在文件中搜索特定模式的文本行
- **语法**：
  ```bash
  grep [选项] "模式" [文件名]
  ```
- **常用选项**：
  - `-i`：忽略大小写
  - `-v`：反向选择，显示不匹配的行
- **示例**：
  ```bash
  grep "error" log.txt         # 在log.txt中搜索包含"error"的行
  grep -i "warning" log.txt    # 忽略大小写搜索包含"warning"的行
  ```

### echo
- **功能**：输出字符串或变量值
- **语法**：
  ```bash
  echo [字符串]
  ```
- **示例**：
  ```bash
  echo "Hello, World!"         # 输出Hello, World!
  echo $PATH                   # 输出PATH环境变量的值
  ```
### source
- **功能**：在当前 shell session 终端会话内，读取并执行指定文件中的命令。常用于让配置文件（如 .zshrc）的修改立即生效，或加载函数、变量到当前环境中。
- **语法**：
  ```bash
  source [文件名]
  . [文件名]           # . 是 source 的简写形式，功能完全相同
  ```
- **示例**：
  ```bash
  source ~/.zshrc     # 让对 .zshrc 文件的修改立即在当前终端生效
  . ~/.zshrc          # 使用简写形式 . = source
  # 假设有一个名为 functions.sh 的文件，里面定义了一些自定义函数
  # 执行后，就可以在当前终端里直接使用这些函数了
  source ./functions.sh
  ~/.zshrc.           # 直接运行脚本，在新的 Sub-Shell 中运行，不影响当前环境
  ```

## 文件和目录操作

### 查看文件内容
- **cat**：适用于较小的文件，可一次性显示整个文件内容
- **less**：适用于较大的文件，可分页查看文件内容
- **head**：显示文件的前几行（默认10行）
  ```bash
  head [文件名]
  ```
- **tail**：显示文件的后几行（默认10行），常用于查看日志文件的最新内容
  ```bash
  tail [文件名]
  ```

### 文件压缩与解压
- **zip**：压缩文件或目录
  ```bash
  zip [压缩文件名].zip [文件/目录名]
  ```
- **unzip**：解压.zip文件
  ```bash
  unzip [压缩文件名].zip
  ```
- **tar**：用于创建和提取.tar归档文件，常与gzip或bzip2一起使用来创建压缩的归档文件
  ```bash
  tar -cvf [归档文件名].tar [文件/目录名]      # 创建tar归档文件
  tar -xvf [归档文件名].tar                    # 提取tar归档文件
  tar -czvf [归档文件名].tar.gz [文件/目录名]  # 创建gzip压缩的tar归档文件
  tar -xzvf [归档文件名].tar.gz               # 提取gzip压缩的tar归档文件
  ```

## 系统信息和管理

### uname
- **功能**：显示系统信息
- **语法**：
  ```bash
  uname [选项]
  ```
- **常用选项**：
  - `-a`：显示所有系统信息
  - `-s`：显示操作系统名称
  - `-r`：显示操作系统版本
- **示例**：
  ```bash
  uname -a           # 显示所有系统信息
  ```

### df
- **功能**：显示磁盘空间使用情况
- **语法**：
  ```bash
  df [选项]
  ```
- **常用选项**：
  - `-h`：以人类可读的格式显示（如GB、MB）
- **示例**：
  ```bash
  df -h              # 显示磁盘空间使用情况
  ```

### du
- **功能**：显示目录或文件的磁盘使用空间
- **语法**：
  ```bash
  du [选项] [文件/目录名]
  ```
- **常用选项**：
  - `-h`：以人类可读的格式显示
  - `-s`：显示总计
- **示例**：
  ```bash
  du -sh directory/  # 显示directory目录的总大小
  ```

### top
- **功能**：显示系统进程和资源使用情况
- **语法**：
  ```bash
  top
  ```
- **说明**：按`q`键退出

### ps
- **功能**：显示当前系统的进程状态
- **语法**：
  ```bash
  ps [选项]
  ```
- **常用选项**：
  - `aux`：显示所有进程
- **示例**：
  ```bash
  ps aux            # 显示所有进程
  ```

### kill
- **功能**：终止进程
- **语法**：
  ```bash
  kill [选项] [进程ID]
  ```
- **常用选项**：
  - `-9`：强制终止进程
- **示例**：
  ```bash
  kill 1234         # 终止进程ID为1234的进程
  kill -9 1234      # 强制终止进程ID为1234的进程
  ```

## 文本处理

### sed
- **功能**：流编辑器，用于解析和转换文本
- **语法**：
  ```bash
  sed [选项] '命令' [文件名]
  ```
- **示例**：
  ```bash
  sed 's/oldtext/newtext/g' file.txt  # 将file.txt中的oldtext替换为newtext
  ```

### awk
- **功能**：文本处理工具，用于格式化文本、进行计算等
- **语法**：
  ```bash
  awk [选项] '模式 {动作}' [文件名]
  ```
- **示例**：
  ```bash
  awk '{print $1}' file.txt  # 打印file.txt中每行的第一个字段
  ```

## 网络相关

### ping
- **功能**：测试网络连通性
- **语法**：
  ```bash
  ping [主机名或IP地址]
  ```
- **示例**：
  ```bash
  ping google.com  # 测试与google.com的连通性
  ```

### curl
- **功能**：从服务器传输数据（下载文件、与API交互等）
- **语法**：
  ```bash
  curl [选项] [URL]
  ```
- **常用选项**：
  - `-O`：将远程文件保存到本地，文件名与远程相同
  - `-o`：将远程文件保存到本地，指定文件名
  - `-X`：指定请求方法（如GET、POST）
- **示例**：
  ```bash
  curl -O https://example.com/file.zip  # 下载文件并保存为file.zip
  ```

### wget
- **功能**：从网络下载文件
- **语法**：
  ```bash
  wget [选项] [URL]
  ```
- **示例**：
  ```bash
  wget https://example.com/file.zip    # 下载文件
  ```

## 权限和用户

### chmod
- **功能**：更改文件或目录的权限
- **语法**：
  ```bash
  chmod [选项] [权限模式] [文件/目录名]
  ```
- **权限模式**：
  - `u`：用户
  - `g`：组
  - `o`：其他
  - `a`：所有
  - `+`：添加权限
  - `-`：删除权限
  - `=`：设置权限
  - `r`：读权限
  - `w`：写权限
  - `x`：执行权限
- **示例**：
  ```bash
  chmod u+x script.sh  # 给script.sh添加用户执行权限
  ```

### chown
- **功能**：更改文件或目录的所有者
- **语法**：
  ```bash
  chown [选项] [所有者]:[组] [文件/目录名]
  ```
- **示例**：
  ```bash
  chown user:group file.txt  # 将file.txt的所有者改为user，组改为group
  ```

### sudo
- **功能**：以超级用户权限执行命令
- **语法**：
  ```bash
  sudo [命令]
  ```
- **示例**：
  ```bash
  sudo apt-get update  # 以超级用户权限更新软件包列表（适用于Debian/Ubuntu系统）
  ```

## 其他实用命令

### man
- **功能**：显示命令的手册页，提供命令的详细说明和用法
- **语法**：
  ```bash
  man [命令名]
  ```
- **示例**：
  ```bash
  man ls            # 查看ls命令的手册页
  ```

### history
- **功能**：显示当前会话中执行过的命令历史记录
- **语法**：
  ```bash
  history
  ```
- **示例**：
  ```bash
  history           # 显示命令历史记录
  ```

### clear
- **功能**：清除终端屏幕上的内容
- **语法**：
  ```bash
  clear
  ```
- **示例**：
  ```bash
  clear             # 清除终端屏幕上的内容
  ```

### exit
- **功能**：退出当前终端会话或关闭终端
- **语法**：
  ```bash
  exit
  ```
- **示例**：
  ```bash
  exit              # 退出当前终端会话
  ```

###

## Mac专属命令

- 我是 Mac 用户，平时在 Mac 上的 zsh 上常用命令也列在此。

### open
- **功能**：在Mac上打开文件、目录或应用程序
- **语法**：
  ```bash
  open [文件/目录/应用名]
  ```
- **示例**：
  ```bash
  open /Applications/Utilities/Terminal.app  # 打开终端应用
  open .                                    # 在Finder中打开当前目录
  open ~/.ssh                   # 便捷打开密钥目录，自动配合访达
  ```

### code
- **功能**：如果安装了Visual Studio Code编辑器，可以在命令行中用`code`命令打开文件或文件夹
- **语法**：
  ```bash
  code [文件/文件夹名]
  ```
- **示例**：
  ```bash
  code .             # 在当前目录下打开VS Code
  code file.txt      # 在VS Code中打开file.txt文件
  ```
