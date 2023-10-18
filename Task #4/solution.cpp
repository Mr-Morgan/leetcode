/* O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = nums1.size()-1, j = nums2.size()-1, k = nums1.size() + nums2.size()-1;
        nums1.resize(nums1.size() + nums2.size());
        while (i>=0 && j>=0) {
            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }//while (i>=0 && j>=0)
        while (j>=0) nums1[k--] = nums2[j--];

        if (nums1.size()%2) return static_cast<double>(nums1[nums1.size()/2]);
        else return static_cast<double>((nums1[nums1.size()/2-1]+nums1[nums1.size()/2]))/2.0;
    }//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
};
*/

// O(log(m+n))
#define INT_MIN numeric_limits<int>::min()
#define INT_MAX numeric_limits<int>::max()

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b)
    {
        // Цикл создается для передачи меньшего массива, поэтому первый в списке аргументов заменяется вторым, если размер второго меньше
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);

        // ] n - массив размера «a», m - массив размера «b», median_index - медианный индекс в массиве, отсортированном слиянием
        const int n = a.size(), m = b.size();

        // Если «n» или «m» равны нулю, то медиана слитого массива будет медианой непустого массива
	// Оставлена только одна проверка, проверка массива меньшего размера (a.size < = b.size), т.к оба не могут быть пустыми по условию задания
        if (!n) { // if (a.size() == 0)
            if (m%2) return static_cast<double>(b[m/2]);
            else return static_cast<double>(b[m/2]+b[m/2-1])/2.0;
        }//if ()

	// Границы массива для двоичного поиска в массиве меньшего размера
        int left = 0, right = n;
        // Цикл выполняется до схождения границ массива
        while (left <= right) {
            //медиана в массиве «a» и «b»
            int median_a = (left + right)/2;
            int median_b = (m+n+1)/2 - median_a;
            // массив a = [ , , , , ,max_left_a,min_right_a, , , , , ]
            int max_left_a  = (median_a)?   a[median_a -1] : INT_MIN;         // Во избежание выхода из массива присваиваются значения
            int min_right_a = (median_a == n)? INT_MAX : a[median_a];         // минимальное или максимальное целое число,
            // массив b = [ , , , , ,max_left_b,min_right_b, , , , , ]        // при достижении граничного элемента массива.
            int max_left_b  = (median_b)?   b[median_b -1] : INT_MIN;         // Минимальные и максимальные значения назначаются таким образом, 
            int min_right_b = (median_b == m)? INT_MAX : b[median_b];         // чтобы эти значения не влияли на функции min () и max ()

	    // Условие для локализации медианы  
            if (max_left_a <= min_right_b && max_left_b <= min_right_a ) {
                if ((m+n)%2) { // Медиана для нечетного количества элементов
                    return static_cast<double>(max(max_left_a,max_left_b)); 
                } else { // Для четного
                    return static_cast<double>(max(max_left_a,max_left_b) + min(min_right_a,min_right_b))/2.0;
                }//if ()
            } else if (max_left_a > min_right_b) {
                right = median_a-1;
            } else {
                left = median_a+1;
            }//if ()
        }//while ()
        return 0.0;
    }//double findMedianSortedArrays()
};// Solution
