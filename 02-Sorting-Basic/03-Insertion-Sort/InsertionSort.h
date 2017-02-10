//
// Created by Queen on 2017/2/9.
//

#ifndef INC_03_INSERTION_SORT_INSERTIONSORT_H
#define INC_03_INSERTION_SORT_INSERTIONSORT_H

template <typename T>
void insertionSort(T arr[], int n)
{
//    // 写法1
//    for (int i = 1; i < n; ++i) {
//        // 寻找元素 arr[i] 合适的插入位置
//        for (int j = i; j > 0 ; --j) {
//            if (arr[j] < arr[j-1]) {// 如果当前元素按小于前一个元素，就交换两个数，因为按照升序排列
//                std::swap(arr[j], arr[j-1]);
//            } else {
//                break;
//            }
//        }
//    }

//    // 写法2
//    for (int k = 1; k < n; ++k) {
//        for (int j = k; j > 0 && arr[j] < arr[j-1]; --j) {
//                std::swap(arr[j], arr[j-1]);
//        }
//    }


    // 写法3
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;// j 表示元素e应在插入的位置
        for (j = i; j > 0 && arr[j-1] > e; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

/*
 *  解读：
 *  插入排序一开始的思路其实很简单：
 *      从第2个元素开始（因为第1个元素可以认为是一个已经排好序的数组），从当前位置往前比，如果比前一个元素小（假设默认都是升序排列），
 *      那么交换两个元素，就这么简单。
 *  上面的思路简单明了，但是也存在一个致命的问题：就是交换过于频繁（其实也是冒泡排序的问题），修改思路也是排序算法中一个经典又简单的做法：
 *      用赋值代替交换！
 *      当然这样做的代价就是，需要多占用一个变量来保存一份值，因为赋值的话，意味着有一个值被覆盖了，逻辑上也稍微复杂了一点点。
 *  所以将思路修改为：
 *      如果当前元素比前一个元素小，那么把当前元素赋值为前面的元素，也就是把前面的元素挪到了后面。
 *      举例说明：数组为 10， 2， 5， 7， 1，进行升序插入排序
 *      那么第一次排序的过程就是：
 *          2跟10比，2小，那么把2赋值为10，（因为2在之前已经保存了一份，所以不用担心覆盖问题），然后找到了2应该插入的位置，也就是0号位置，
 *          这时把10再赋值为2。
 *      第二次排序：此时数组变成：2，10，5，7，1，保存当前元素的值，也就是5被保存了一份，当前元素按位置下标为：2
 *          此时来到值为5的元素，此时5跟10比，5小，所以把5赋值为10（这样做的目地还是把大的元素按挪到后面去），此时数据变成了2，10，10，7，1，
 *          再看赋值的条件是：要么是已经是第一元素，前面没有元素可比较，要么就是当前元素比前面元素大（为什么不要继续向前面比较呢？因为插入排序每次
 *          拍好序时，当前位置之前已经是一个排好序的数组了）。
 *          当前的情况就是当前元素10，已经比前面元素2大，所以内层循环终止，但是j条件判断之前已经进行了--，所以当前下标为：1
 *          也就是该轮循环，说要查找的元素 5 的下标：1，
 *          所以数组变成了：2，5，10，7，1
 *      第三次排序跟第二次几乎一致，而且只是赋值了一次：
 *          还是需要记住一点，就是每次当前位置的元素都是跟这轮的关键值元素进行比较，因为要找的就是这个关键值元素按的位置
 *          该轮关键值元素为7
 *          过程为：2，5，10，7，1 ==》 7比10小，当前元素被赋值为前面的元素，2，5，10，10，1 ==》 7比5大，循环停止，10 赋值为 7 ==》 2，5，7，10，1
 *      第四次排序相对比较难：
 *          过程为：
 *          2，5，7，10，1 ==》
 *          1比10小，当前元素被赋值为前面的元素：2，5，7，10，10 ==》
 *          1比7小，当前元素10被赋值为前面的元素7： 2，5，7，7，10 ==》
 *          1比5小，当前元素7被赋值为前面的元素5： 2，5，5，7，10 ==》
 *          1比2小，当前元素5被赋值为前面的元素2： 2，2，5，7，10 ==》
 *          来到0号下标，那么内层循环停止，找到关键值元素的位置：0号下标位置，所以数组变成为：1，2，5，7，10
 * */



#endif //INC_03_INSERTION_SORT_INSERTIONSORT_H