//太平洋时区的 ID 为 PST
TimeZone tz0 = TimeZone.getTimeZone("PST")
//getDefault()可以获取主机所处时区的对象
TimeZone tz1 = TimeZone.getDefault()

//调用Locale类的构造方法
Locale l0 = new Locale(String language)
Locale l1 = new Locale(String language, String country)
Locale l2 = new Locale(String languge, String country, String variant)

//调用Locale类中定义的常量
Locale l1 = Locale.CHINA;