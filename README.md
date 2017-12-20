# OpenCV-Learning
---
## Chapter 3 基于类的图像处理

### 3.1
在算法设计中使用策略(Strategy)模式  
创建了一个`ColorDetector`类

### 3.2
使用控制器(Controller)实现模块间的通信  
使用`ColorDetectorController`类

### 3.2
使用单间(Singleton)设计模式  
修改`ColorDetectorController`类  
注： 单件的实现并不是线程安全的。在多线程情况下不应该使用它。

### 3.4
使用模型-视图-控制器(Model-Vier-Controller)  
架构设计应用程序  
基于Qt的MVC，可以层次清晰的分离程序中的逻辑部分与用户交互部分。

---
## Chapter 5 基于形态学运算的图像变换

### 5.2 膨胀和腐蚀运算
**腐蚀**：将锚点位置的像素值替换为核中像素值**最小**的值，相当于白色部分**缩小**一圈。  

**膨胀**：将描点位置的像素值替换为核中像素值**最大**的值，相当于白色部分**放大**一圈。