
<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Chapter 5. Probabilistic Analysis and Randomized Algorithms</summary>

**Parking Problem**:

37% Rule, 1 / Euler's Number = ~0.3697, which is the "Optimal Stopping" point for an Algorithm where you don't know the next entry, but you're trying to Optimize your chances of picking the "Best" *(Highest Ranking)* Thing. In the case of the Hiring Problem, it's the highest ranking candidate for employement.

![DSA C61](../static/DSA_5_1.png)

**BIAS**
For the Hiring Problem, <br><br/>
If we consider the sequence in which candidates arrive for the interview, a **"BIASED"** sequence would be one in which the likelihood of encountering a better candidate is not equal at each step of the interview process. In other words, if some candidates have a higher chance of showing up earlier or later in the interview process, then the sequence would be biased.

However, the hiring problem assumes a uniform random permutation of applicants, which means that each candidate is equally likely to be interviewed at any point in the process. This implies that there is no bias in the order of interviews.

The hiring algorithm itself doesn't involve a biased random process; it's a deterministic procedure that assumes a fair comparison of candidates based on their qualifications. The discussion of **BIASED-RANDOM** is more about understanding the nature of probabilistic processes and how they can be manipulated to achieve desired outcomes, which is a common theme in the study of randomized algorithms and probabilistic analysis.

## **Question(s)**
   ![DSA 51](../static/DSA_5_2.png)
</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Chapter 6. HeapSort</summary>

# Build Max Heap


![DSA C61](../static/DSA_c61.png)

![DSA C62](../static/DSA_c62.png)

Here we're dividing `A.length/2` As we don't need to check the Leaf Nodes, only the nodes with children, 
As in 1 iteration, for a node **i** in the tree, we can access **Left** and **Right** child in O(1).

Left: `2 * i` | Right: `2 * i + 1`
---

# Pop Max 

![DSA C63](../static/DSA_c63.png)

---

# Max Heapify

![DSA C65](../static/DSA_c65.png)

![DSA C64](../static/DSA_c64.png)



---

# Heap Sort Algorithm
- Using the building blocks

![DSA C66](../static/DSA_c66.png)
![DSA C67](../static/DSA_c67.png)

**Note:**
- Pop Max does the `MaxHeapify()`, so calling PopMax is sufficient, whereas the sudo-code does it directly in the Algo


---

# Time Complexity Analysis

### Max Heapify

Worst Case Scenario: Root is violating with Max-Heap Property *(Needs to access left side)*

![DSA HS](../static/DSA_hs_rt.png)

**a** : 1 , **b** : 3/2 , **F(n)** : O(1)

In a B-Tree (Max/Min Heap Tree) with **n** elements:

*Nodes above last layer N#*: n/2
*Leaf Nodes N#*: n/2

*T(n) = T(2n/3) + C*

n^log base (3/2) 1 ~= n^1

**Therefore, Heapsort Complexity** T(n) = n * lg(n)

It takes time *O(n lg n)*, since the call to *BUILD-MAX-HEAP* takes time **O(n)**
and each of the **n-1** calls to *MAX-HEAPIFY* takes time **O(lg n)**.


![DSA HS](../static/DSA_hs_rt2.png)

Usually we're only checking quadrant **I** & **II**, and section **IV** is usually empty as we start filling in Leaf-Nodes from the left, so in general it's *2/3*, sometimes *2/4* tho
---

### Priority Queue
- Application of Max Heap 
- Actually `Heapsort` is **SLOWER** than `Quicksort`, so it isn't used...

Max Heap has more applications tho...

- Used in Heuristics *(Priority of Best-First Strategy)*, Discrete Event Simulations
- Shortest Path Algorithms *(What is the current best path, at iteration)*

#### Insert:
  - Insert a new Task, with a Priority
  - **Boss** gives me a Low Priority Task, **Boss #2** gives me a High Priority Task

##### Extract Max:
  - Extracts Max, Ruins the Priority Queue, so we gotta `MaxHeapify` again

##### Increase Key
  - Increase value *(priority)* of a Node, so you need to `MaxHeapify` again aswell



---


</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Chapter 7. QuickSort</summary>

  ## Abdul Bari Video Notes & Quicksort Steps
  ![DSA 7](../static/DSA_7_1.png)

  # Book Notes:

  General notes:
  ![DSA 7](../static/DSA_7_2.png)

  ## Loop Invariant:
  ![DSA 7](../static/DSA_7_3.png)
  ![dsa 77](../static/DSA_7_LI.png)

  ## Scenarios:
  ![DSA 7](../static/DSA_7_4.png)

  **QuickSorts WORST CASE**: 1 Parition has `n-1` Elements in it, and the other has `0` Elements in it. *(last parition is the Pivot Set, of 1 element)*

  ![DSA Case Scenarios](../static/DSA_7_5.png)

  **NOTE**: Average case is very close to best case, that's why QuickSort is known as quite "Practical" as the Worst Case is very rare, and the Average Case usually falls near the best case.

  ## **Recursion Tree Analysis**
  ![DSA RTA](../static/DSA_7_6.png)
  ![DSA RTA2](../static/DSA_7_7.png)
   ![DSA RTA2](../static/DSA_7_8.png)
![DSA RTA2](../static/DSA_7_wc.png)

   ## Randomized QuickSort
   ![DSA RTA3](../static/DSA_7_9.png)
  - Random Pivot is Picked

   ![DSA RTA3](../static/DSA_7_10.png)

  ---
   ## QuickSort Pseudo-Code:
  ![DSA HS](../static/DSA_6_tb.png)

</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">8. Sorting in Linear Time *| Counting, Radix, Bucket Sorts*</summary>

  ## Counting Sort
   ![DSA RTA2](../static/DSA_8_1.png)
  
  ## Radix Sort & Bucket Sort
   ![DSA RTA3](../static/DSA_8_2.png)
  
  ## Analysis:
   ![DSA RTA3](../static/DSA_8_3.png)

  ## bucket vs. radix

  **common ground** <br>
  Bucket Sort and Radix Sort are both non-comparison based sorting algorithms, which means they can achieve a better time complexity than comparison-based algorithms (like quicksort or mergesort) under certain conditions. However, their performance heavily depends on the specific characteristics of the data and the implementation details.

  #### Bucket Sort Advantages
  - Fast for data that is uniformly distributed across the range.
  - Can be more efficient than Radix Sort when the dataset is large and the key values are very spread out. *(Ignores some ranges for example)*
  - The size and number of buckets can be dynamically determined to fit the data distribution.
  - **Best Case:** O(n + k) (when elements are distributed uniformly across buckets) >> this is also avg. case


  #### Bucket Disadvantages
  - Performance depends on a uniform distribution of data.
  - Overhead of using additional space for buckets.
  - Needs an additional sorting algorithm for sorting individual buckets, unless the elements fall into buckets in a sorted manner. *(Space complex)*

  - **Worst Case:** O(n^2) (when all elements are distributed into a single bucket)

---

#### Radix Sort Advantages
- Very fast for fixed-length integer sorting.
- Not influenced by the distribution of the key values.
- Consistent performance since it depends on the number of digits in the longest number. *(Best and Worst case is O(n) )*

#### Radix Sort Disadvantages
- Less flexible, as it's primarily suited for integers or strings of the same length.
- Can have large constants hidden in the time complexity due to the use of counting sort or other stable sorts.
- The need for stable intermediate sorting can create overhead.


The choice between Bucket Sort and Radix Sort should be made based on the known characteristics of the data to be sorted. If the distribution of the data can be leveraged, Bucket Sort may offer superior performance; otherwise, Radix Sort provides consistent performance regardless of data distribution.


---

#  **More on Stability**:

Example array [1, 5, 2, 5], a stable sort would ensure that the first '5' in the input array remains the first '5' in the sorted array. After sorting, a stable algorithm would give you [1, 2, 5, 5] where the position of the two '5's relative to each other hasn't changed.

Stability matters when each element in the array contains more than just the key. Suppose each '5' is actually a complex object or a record that has several other fields.

**Consider:**

```json
[ { "name": "Alice", "grade": "B" },  { "name": "Bob", "grade": "A" },  { "name": "Charlie", "grade": "B" } ]
```

If we sort this array by the grade field using a **stable** sort, then after sorting by grade in ascending order, we will have:

```json
[ { "name": "Bob", "grade": "A" },  { "name": "Alice", "grade": "B" },  { "name": "Charlie", "grade": "B" } ]
```
^ Sorted by Highest Grade

<br>
Notice that Alice and Charlie both have a grade of 'B', and in the sorted array, Alice comes before Charlie because she was listed first in the original array.

*If this was an un-stable, Charlie might have been listed before Alice, even tho in the OG, Alice can first*

**Why Stability Might Matter:**

**Maintaining original sequence:** In many cases, the original sequence of records is meaningful. For example, if records are timestamped, using a stable sort ensures that records with the same key value *(but different timestamps)* remain in the order they occurred *(sorted by timestamp already)*.

**Subsequent sorting steps:** Stability is also important when performing multiple rounds of sorting, known as "sort by multiple keys". Suppose you first sort by grade, and then you sort by name within each grade. A stable sort guarantees that the sorting by name does not disturb the relative order of records that have the same name but different grades.

**Data integrity:** When elements are otherwise indistinguishable by their key (like the two '5's), you may not care about stability. However, if there is additional context or data associated with those keys, stability ensures that the data's integrity is maintained through the sorting process.


good video for this chapter: [CLICK](https://youtu.be/pJ1IQD5rv4o)
</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Midterm Study #2</summary>

  ## Q1.
   ![DSA RTA2](../static/DSA_M2_1.png)

   **Extracted info**
   A.) Avg case: Theta(N) , Worst case: Theta(N^2)
  - Smaller hidden constants, and easier implementation

   B.) Avg case & Worst case is Theta(N * lg n)
  - Larger constants, More complex implementation

  **A** & **B** Solve the same problem P.

  **The inputs are fairly small.**
  - Algorithm A would be the better choice. Since the inputs are small, the quadratic worst-case time complexity of A is less of a concern. Moreover, the smaller constants hidden by the Θ-notation and the ease of implementation make A more suitable for this scenario.
  - TL:DR, if A does end up with Quadric time, it's fine because of small input, I'd rather reduce the hidden constants cost!

  **For large and uniformly chosen inputs, processing in bulk:** 
  - Algorithm B should be preferred because its average-case and worst-case running times are both Θ(n lg n), which is better than A’s quadratic worst-case running time. When processing a large number of inputs, the lower worst-case time complexity of B will likely lead to better overall performance, despite the larger hidden constants.

  **For large inputs skewed towards A’s worst case:** 
  - Ofcourse, Algorithm B is the better option. Given that the inputs are heavily skewed towards A’s worst-case scenario, the Θ(n^2) running time of A would become a significant problem. B’s consistent Θ(n lg n) performance, in both average and worst cases, would result in a more predictable and generally lower total processing time.

  **For moderate-sized inputs, processed one at a time in real-time:**
  - Algorithm A could be more desirable due to its linear average-case time complexity and the fact that it is easier to implement, which might be important in an interactive tool that is being used to explore data. Since we care about the response time on each individual input, A’s faster average-case, given the smaller constants, would likely provide a more responsive experience for the user.

</details>