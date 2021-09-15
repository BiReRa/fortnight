## markdown常用语法

<h2>目录</h2>

* [标题](#title)

* [代码](#code)

* [链接](#link)

---

* <span id="title">标题</span>

  连续的n个'#'表示n级标题.

  代码示例:

  ```markdown
  # 一级标题
  ## 二级标题
  ### 三级标题
  #### 四级标题
  ##### 五级标题
  ###### 六级标题
  ```

  我们可以使用html语法实现标题.

  代码示例:

  ```markdown
  <h1>一级标题</h1>
  <h2>二级标题</h2>
  <h3>三级标题</h3>
  <h4>四级标题</h4>
  <h5>五级标题</h5>
  <h6>六级标题</h6>
  ```

  效果:

  ***

  # 一级标题
  ## 二级标题
  ### 三级标题
  #### 四级标题
  ##### 五级标题
  ###### 六级标题

  ***

* <span id="code">代码</span>

  代码有两种表示方式.

  * 代码块

    用两个反引号' ` '包裹, 或者用两个" `` "串包裹的内容构成代码块.
    
    代码示例:

    ```markdown
    c语言中使用`printf()`进行打印.

    然而python中使用``print()``进行打印.
    ```

    效果:

    ***

    c语言中使用`printf()`进行打印.
    
    然而python中使用``print()``进行打印.

    ***

  * 代码段

    用两行**连续三个或多于三个**反引号包裹的内容构成代码段.第一行反引号之后可以附有代码语言来指定期待显示的语言类型.

    代码示例:

    ````markdown
    让我们来创建第一个HelloWorld程序:

    ```python
    name = "BiReRa"
    print("Hello world! I'm {}!".format(name))
    ```

    它将会打印"Hello world! I'm BiReRa!"
    ````

    效果:

    ***

    让我们来创建第一个HelloWorld程序:

    ```python
    name = "BiReRa"
    print("Hello world! I'm {}".format(name))
    ```

    它将会打印"Hello world! I'm BiReRa!"

    ***

* <span id="link">链接</span>
    