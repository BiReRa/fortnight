## markdown常用语法

* 标题

  连续的n个'#'表示n级标题。

  代码示例：

  ```markdown
  # markdown
  ## markdown
  ### markdown
  #### markdown
  ##### markdown
  ###### markdown
  ```

  效果：

  ***

  # markdown
  ## markdown
  ### markdown
  #### markdown
  ##### markdown
  ###### markdown

  ***

* 代码

  代码有两种表示方式。

  * 代码块

    用两个反引号' ` '包裹，或者用两个" `` "串包裹的内容构成代码块。
    
    代码示例：

    ```markdown
    c语言中使用`printf()`进行打印。

    然而python中使用``print()``进行打印。
    ```

    效果：

    ***

    c语言中使用`printf()`进行打印。
    
    然而python中使用``print()``进行打印。

    ***

  * 代码段

    用两行**连续三个或多于三个**反引号包裹的内容构成代码段。第一行反引号之后可以附有代码语言来指定期待显示的语言类型。

    代码示例：

    ````markdown
    让我们来创建第一个HelloWorld程序：

    ```python
    name = "BiReRa"
    print("Hello world! I'm {}!".format(name))
    ```

    它将会打印"Hello world! I'm BiReRa!"
    ````

    效果：

    ***

    让我们来创建第一个HelloWorld程序：

    ```python
    name = "BiReRa"
    print("Hello world! I'm {}".format(name))
    ```

    它将会打印"Hello world! I'm BiReRa!"

    ***

    