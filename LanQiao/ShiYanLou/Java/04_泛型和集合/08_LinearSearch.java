public class LinearSearch {
    public static void main(String[] args) {
        int[] ints = {5, 3, 4, 1, 2};
        System.out.println(search(ints, 4));
    }

    public static int search(int[] arr, int key) {
        //循环
        for (int i = 0; i < arr.length; i++) {
            //比较是否等于key
            if (arr[i] == key) {
                return arr[i];
            }
        }
        //找不到就返回-1
        return -1;
    }
}