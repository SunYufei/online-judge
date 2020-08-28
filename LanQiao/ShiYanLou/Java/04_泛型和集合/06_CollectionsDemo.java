import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CollectionsDemo {
    public static void main(String[] args) {
        // 创建一个空List
        List<Integer> list = new ArrayList<Integer>();
        // 赋值
        list.add(3);
        list.add(5);
        list.add(7);
        list.add(9);
        list.add(12);
        System.out.print("初始顺序：");
        list.forEach(v -> System.out.print(v + "\t"));


        // 打乱顺序
        Collections.shuffle(list);
        System.out.print("\n打乱顺序：");
        list.forEach(v -> System.out.print(v + "\t"));

        // 反转
        Collections.reverse(list);
        System.out.print("\n反转集合：");
        list.forEach(v -> System.out.print(v + "\t"));

        // 第一个位和最后一位交换
        Collections.swap(list, 0, list.size() - 1);
        System.out.print("\n交换第一位和最后一位：");
        list.forEach(v -> System.out.print(v + "\t"));

        // 按自然升序排序
        Collections.sort(list);
        System.out.print("\nSort排序后：");
        list.forEach(v -> System.out.print(v + "\t"));

        // 二分查找 必须排序后
        System.out.print("\n二分查找数值7的位置：" + Collections.binarySearch(list, 7));

        // 返回线程安全的list
        List<Integer> synchronizedList = Collections.synchronizedList(list);
    }
}