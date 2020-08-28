//从指定的源数组中复制一个数组，从源数组指定的位置开始，到目标数组指定的位置
public static void arraycopy(Object src,int srcPos, Object dest,int desPos,int length)
//返回以毫秒为单位的当前时间(从1970年到现在的毫秒数)
public static long currentTimeMillis()
//终止当前正在运行的Java虚拟机，status为 0时退出
public static void exit(int status)
//  运行垃圾收集器
public static void gc()
// 取得当前系统的全部属性
public static Properties getProperties()
//获取指定键的系统属性
public static String  getProperty(String key)

import java.util.Arrays;

public class SystemDemo {
    public static void main(String[] args) {
        int[] a = {7, 8, 9, 10, 11};
        int[] b = {1, 2, 3, 4, 5, 6};
        //从数组a的第二个元素开始，复制到b数组的第三个位置 复制的元素长度为3
        System.arraycopy(a, 1, b, 2, 3);
        //输出结果
        System.out.println(Arrays.toString(b));
        System.out.println("当前时间：" + System.currentTimeMillis());
        System.out.println("java版本信息：" + System.getProperty("java.version"));
        //运行垃圾收集器
        System.gc();
        //退出
        System.exit(0);
    }
}