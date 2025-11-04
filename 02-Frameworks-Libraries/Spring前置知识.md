# Spring 前置知识

#### **一：项目构建与依赖管理 (Maven)**

*  在 JavaSE 手动 import 类，或者手动添加 JAR 包。在真实项目中，一个项目可能依赖几十上百个 JAR 包。Maven 是一个专业的项目管家，它能**自动下载和管理所有依赖的 JAR 包**。 
  
    > JAR 包是 Java 世界里分发和使用代码的基本单位。它是一个包含了预编译好的 Java 类和其他资源的压缩文件(.zip)，通过组合各种现成的功能模块（JAR 包）来高效地构建自己的应用程序。
    >
    > 思想就是打包。把别人打包的东西（别人的 jar 包）称为依赖，从外部拉取 jar 包叫做*声明依赖*。
    >
    > 自己的项目打包成 jar 包，叫做*打包项目*。

* 所有的 Spring Boot 项目都基于 Maven (或 Gradle) 来构建。这是创建项目的起点。下面介绍如何从 maven 注入依赖。
* maven 是一个中央仓库，里面有各种各样的 jar 包，是 java 生态的官方中央仓库，收录的内容由全世界的开源组织和个人开发者共享和贡献，受到严格审核与管理规则。里面的内容对全世界的开发者开源，所有人都能导入。maven 之于 Java，类似 App Store 之于 Apple。
* **掌握如下知识**  
  1. 理解 pom.xml 文件的功能。
   ```xml
  <?xml version="1.0" encoding="UTF-8"?>
  <project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>com.cuit</groupId>
    <artifactId>LearningJDBC</artifactId>
    <version>1.0-SNAPSHOT</version>

    <properties>
        <maven.compiler.source>25</maven.compiler.source>
        <maven.compiler.target>25</maven.compiler.target>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
    </properties>

    <dependencyManagement>
        <dependencies>
            <dependency>
                <groupId>com.google.protobuf</groupId>
                <artifactId>protobuf-java</artifactId>
                <version>3.25.3</version> </dependency>
        </dependencies>
    </dependencyManagement>

    <dependencies>
        <dependency>
            <groupId>com.mysql</groupId>
            <artifactId>mysql-connector-j</artifactId>
            <version>8.4.0</version>
            <scope>runtime</scope> </dependency>
    </dependencies>

  </project>
   ```

   * `groupId`提供项目组ID，一般为公司域名的反写，我使用自己的学校名反写。
   * `artifactId`是项目ID，使用项目、模块的名称，我的代码中写的项目是学习JDBC。
   * `version`是版本号，分为 3 级。第一级是主版本号。当做了不兼容的 API 修改时才增加这个版本号。比如，一个函数被删除了，或者参数变了，导致旧的代码无法直接在新版本上运行。向下兼容地添加了新功能时，增加第二个版本号。做了向下兼容的问题修正时，增加第三个版本号，例如一个不增加新功能的小修 bug。
   * `SNAPSHOT`是快照的意思，表明这个版本是一个不稳定的、正在开发中的版本。此版本下，每当把最新的代码发布到 Maven 仓库时，Maven 会为这个快照版本生成一个带时间戳的唯一版本（例如 1.0-20251025.160000-1）。当同事构建他的项目B时，Maven 会自动检查仓库里有没有比他本地更新的 1.0-SNAPSHOT 版本。如果有，就会自动下载最新的快照，无需他手动修改 pom.xml。觉得这个项目的功能已经发完成、测试通过、可以稳定使用时，执行 release 操作，去掉 -SNAPSHOT 后缀，正式发布 1.0 版本。然后，下一个开发周期将从 1.1-SNAPSHOT 或 2.0-SNAPSHOT 开始。
  2. 知道 \<dependencies\> 和 \<dependency\> 标签的作用。
   * `<dependencies>`我要开始列举我需要的所有 JAR 包了。
   * `<dependency>`我需要一个什么样的 JAR 包。
  3. 学会从 [Maven中央仓库](https://mvnrepository.com/) 查找需要的依赖，并把它粘贴到 pom.xml 里。粘的位置正是上一点写的`<dependency>`里面。例如我需要连接 JDBC 和 MySQL 数据库，就在上面的代码写了相关的依赖。
  4. 掌握如何将自己的 Spring Boot 项目打包成 jar。
   * 使用 Spring Boot 构建项目时，在 pom.xml 里面加上一个插件，这个插件创建一个可执行 JAR（也叫 Fat JAR）。它不仅包含了自己的 .class 文件，还把所有依赖的库 JAR 包也一起打包了进去。
   * 只需要 `java -jar my-app.jar` 就能运行整个 Spring Boot 应用，因为它已经是一个自包含的完整包了。

  ```xml
  <build>
    <plugins>
        <plugin>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-maven-plugin</artifactId>
        </plugin>
    </plugins>
  </build>
  ```

#### **二：Web 前置知识**

*  Spring Boot 主要用来开发 Web 应用（后端API）。所有 Web 应用都建立在 HTTP 协议之上。而 Servlet 是 Java 官方提供的、用于处理 HTTP 请求和响应的一套最最基础的 API 规范。 Servlet 容器中，最出名的是 Tomcat。
*  Spring Boot 中的所有网络相关注解，**其最底层就是 Servlet**。Servlet（Server Applet，服务器小程序）是运行在 Web 服务器内部的 Java 程序。
     * 以前，Web 服务器只能处理静态资源（HTML 文件、图片）。为了让服务器能处理动态的、需要 Java 逻辑的请求（比如从数据库查数据、进行计算），Sun 公司定义了一套标准的 Java API 接口，这就是 Servlet API。Servlet 容器来完成底层的网络通信、HTTP 协议解析等复杂工作。
* Java对象存在于JVM的内存中，是一种结构化的数据实体； **JSON** 是一个纯文本的、有特定格式的字符串，用于在不同系统（比如前端浏览器和后端服务器）之间传输数据。映射遵循一套固定的规则，将Java对象的属性（Fields）和值（Values）映射成JSON对象的键（Keys）和值（Values）。
    * 序列化 (Serialization)：把 Java对象 转换为 JSON字符串。
    * 反序列化 (Deserialization)：把 JSON字符串 转换为 Java对象。
  
  对这样一个 Java 类示例：
  ```java
  // 为了简化，下面的代码省略构造函数和toString()方法
  public class Address {
    private String city;
    private String street;

    // Getters and Setters...
  }

  public class User {
    private long id;
    private String name;
    private int age;
    private boolean isVip;
    private List<String> hobbies;
    private Address address; // 嵌套对象
    private String password; // 一个我们不想公开的字段

    // Getters and Setters...
  }
  ```
  我们有这样的操作：
  ```java
  User user = new User();
  user.setId(1001L);
  user.setName("张三");
  user.setAge(25);
  user.setVip(true);
  user.setHobbies(Arrays.asList("篮球", "编码", "音乐"));

  Address addr = new Address();
  addr.setCity("北京");
  addr.setStreet("中关村大街");
  user.setAddress(addr);

  user.setPassword("a_secret_password"); // 不希望这个字段被序列化
  ```
  序列化后得：
  ```json
  {
    "id": 1001,
    "name": "张三",
    "age": 25,
    "vip": true,
    "hobbies": [
      "篮球",
     "编码",
     "音乐"
    ],
   "address": {
      "city": "北京",
      "street": "中关村大街"
    }
  }
  ```
  * password 字段没有出现在 JSON 里。这是通过特定配置（比如注解）实现的，是 Spring 的知识了，后面了解。

  反序列化直接使用 Maven 添加依赖帮我们完成。Jackson 功能强大，性能也很好，是 Spring Boot 默认的 JSON 处理库。

  ```xml
  <dependency>
    <groupId>com.fasterxml.jackson.core</groupId>
    <artifactId>jackson-databind</artifactId>
    <version>2.15.2</version> </dependency>
  ```
* **掌握如下知识**  
  1. 前端三剑客大致了解就行：HTML，CSS，JS（当然是只知道 DOM 操作和事件监听就行了）。
   
  > 这里**回顾** JS 操作
  > 1. 加载页面：HTML 结构被浏览器解析成 DOM 对象树。
  > 2. JS 执行：app.js 开始执行。
  > 3. 查找元素：JS 使用 querySelector 找到了输入框、按钮和段落这三个 DOM 对象。
  > 4. 设置监听：JS 给按钮对象添加了一个监听器 click。
  > 5. 用户交互：用户在输入框里输入文字，然后点击了按钮。
  > 6. 触发事件：按钮感觉到了 click，于是立刻执行了我们之前绑定的那个函数。
  > 7. 函数执行：函数内部的代码开始运行，它从输入框读取值，然后修改了段落的文本内容和样式。

  2. 计算机网络的知识，了解 HTTP (浏览器和服务器之间的通信规则) 的基本概念
  * 请求-响应循环
  <blockquote>
   <ol style="list-style-type: decimal;">
     <li>客户端与服务器建立连接。</li>
     <li>客户端发送一条 HTTP 请求 (Request) 报文。</li>
     <li>服务器处理该请求。</li>
     <li>服务器返回一条 HTTP 响应 (Response) 报文</li>
     <li>连接通常会被关闭（现代 HTTP 版本为了效率可以复用连接）。</li>
   </ol>
  </blockquote>
  
  * 了解 HTTP 请求报文的一些方法，请求报文和响应报文的结构。
  * 识别常见的 HTTP 状态码。
   
  3. 了解 HttpServletRequest 和 HttpServletResponse 这两个核心对象的作用是：一个用来拿前端发来的数据，一个用来向前端发回数据。

#### **三：数据库连接基础**

* 程序要和数据库打交道。JDBC (Java Database Connectivity) 是 Java 连接所有关系型数据库（MySQL, Oracle等）的标准 API。熟练编写 SQL 的增删改查（CRUD）语句。
* Spring Boot 中流行的持久化框架如 Mybatis、JPA，它们本质上都是对繁琐的 JDBC 操作进行的优雅封装。
