## Linux下常用指令

* `df` 以磁盘分区为单位查看文件系统，获取各硬盘空间占用情况、空间余量等信息

  * 

* `mv` (move file) 为文件或目录改名, 或将文件或目录移入其他位置.

  语法:

  `mv [options] source dest`

  参数说明:

  * `-b`: 当目标文件或目录存在时, 覆盖前生成一个备份.

  * `-i`: 源目录或文件与目标目录或文件重名, 询问是否覆盖旧文件.

  * `-f`: 源目录或文件与目标目录或文件重名, 不询问直接覆盖.

  * `-n`: 不覆盖任何已存在的文件或目录.

  * `-u`: 当源文件比目标文件新, 或者目标文件不存在时, 才执行操作.

  用法:

  * `mv source_file dest_file` 文件改名

  * `mv source_file dest_directory` 文件移动

  * `mv source_directory dest_directory` 文件夹移动(目标路径存在)或改名(目标路径不存在)