public class BinarySearch {
    public static int search(int[] arr, int key) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int middle = (high + low) / 2;
            //如果相等 返回值
            if (key == arr[middle]) {
                return key;
            } else if (key < arr[middle]) {
                //如果key小于中间值，那么改变high，值可能在左边部（比较小的部分）
                high = middle - 1;
            }else {
                //如果key大于中间值，那么改变low，值可能在右边部（比较大的部分）
                low = middle + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] ints = {1, 2, 3, 4, 5};
        System.out.println(search(ints, 4));
    }
}