# easy_captcha
一个简单验证码的识别程序。可以识别某个固定网站上的验证码。

## 使用

tools目录包含一个拆分bmp图片，产生模版文件的程序。编译方法：

+ autoconf
+ autoheader
+ aclocal
+ automake --add-missing
+ ./configure
+ make
+ ./tools 1517.bmp

运行结果会产生one.dat, two.dat, three.dat, four.dat四个文件，是将1571.bmp文件中
四个数字拆分到了不同文件中。

	mv one.dat 1.dat
	mv two.dat 5.dat
	mv four.dat 7.dat

生成模版文件。

src目录下的main.c是识别图片程序。编译方法：

+ cc main.c
+ ./a.out ./tools/1571.dat

会输出识别出来的四个数字。
