# C and C++ projects
Coursera [Coding for Everyone: C and C++ Specialization](https://www.coursera.org/specializations/coding-for-everyone?) projects.

## Probabilities of poker hands using Monte Carlo method
[File: card_shuffle.c](/C%20projects/card_shuffle.c)

Shuffle a deck of 52 cards _NCALLS=100,000,000_ times, and then pick out a 7 card hand. Compute the probabilities of a pattern appearing over all the trials (Monte Carlo method). Verify using combinatorial mathematics.

    SAMPLES RUN: 0%
    SAMPLES RUN: 10%
    SAMPLES RUN: 20%
    SAMPLES RUN: 30%
    SAMPLES RUN: 40%
    SAMPLES RUN: 50%
    SAMPLES RUN: 60%
    SAMPLES RUN: 70%
    SAMPLES RUN: 80%
    SAMPLES RUN: 90%

    ------SUMMARY---------
    NCALLS: 100000000

    Pattern          Appearances     Probability

    Four of a kind : 168281          (0.001683)
    Full house     : 2553838         (0.025538)
    Three of a kind: 4964910         (0.049649)
    Two pair       : 23999193        (0.239992)
    One pair       : 47286379        (0.472864)
    No pair        : 21027399        (0.210274)

## Remove duplicates from a doubly linked list
[File: remove_duplicates_LL.c](/C%20projects/remove_duplicates_LL.c)

Create a doubly linked list using random elements. Use bubble sort to sort the list and remove duplicate elements.

    Before removing duplicates,
      36       3      13      48      32      39      45      27      42      48
      28       7       1      18      20       7      40       3      10       5
       0      12       0      38      44      26      21      25      31      31
       0      39      49      11      42      19       2      40       2      27
      49      41      27      22      40      15      36       8      49      14
      24      40      32      46      23      37      23      42      32      25
      40      36       6      30      37       7       2      35      41      14
      42       9      24      11       0      27      47      25      25      29
      44      32      36      18      17      47      30       9      39      46
      21       2      24      33      14      25      22      49      17      34
      24      24      46      21      32       6      48       6      23      17
      27       1       0       0      28      20      34      43      18      45
      37      49      19      10      10      33      18      11       2       0
      10      36       7      45       3      23       8      41      30      13
       5       9      34       5       3      44       6      43      38      41
      29      42      44       1      25      30      41      27      43      15
      19      34      27      27      40      15       2      34      17      37
      28      44      39      25      16      37      24       2      43      31
      12      15      22      19      11       7       5      33      46       2
      19      37      11      10      31       9      10      18      40      31


    After removing duplicates,
       0       1       2       3       5       6       7       8       9      10
      11      12      13      14      15      16      17      18      19      20
      21      22      23      24      25      26      27      28      29      30
      31      32      33      34      35      36      37      38      39      40
      41      42      43      44      45      46      47      48      49


    Sorted and unique!

## Sort a linked list
[File: sort_LL.c](/C%20projects/sort_LL.c)

Create a linked list using random elements. Use bubble sort to sort the list.

## Convert array to binary tree
[File: array_2_BT.c](/C%20projects/array_2_BT.c)

Read a file of intergers and store it as a binary tree. Print the inorder traversal of the tree.

    Input array:            90 34 67 21 33 71 
    Inorder traversal:      21 34 33 90 71 67 

## Shortest path using Dijkstra's algorithm
[File: dijkstra.cpp](/C++%20projects/Shortest%20path%20(dijkstra)/dijkstra.cpp)

Create a random graph from given parameters, and use Dijkstra's algorithm to compute average of all shortest paths.

    Initialized graph with
    -----------------------------------
    Nodes:             50
    Density:           0.2
    Min. distance:     1
    Max. distance:     10
    Conn. matrix size: 50 x 50
    Cost matrix size:  50 x 50

    --------------------Computed paths--------------------
    dist(1  ->  0) = 4         :  1 ->  0
    dist(1  ->  1) = 0         :  1
    dist(1  ->  2) = 6         :  1 -> 33 -> 24 -> 25 -> 27 ->  2
    dist(1  ->  3) = 5         :  1 -> 33 ->  7 ->  3
    dist(1  ->  4) = 9         :  1 -> 33 -> 24 -> 25 -> 27 ->  4
    dist(1  ->  5) = 6         :  1 -> 29 -> 41 ->  5
    dist(1  ->  6) = 7         :  1 -> 33 -> 24 -> 12 -> 48 ->  6
    dist(1  ->  7) = 3         :  1 -> 33 ->  7
    dist(1  ->  8) = 6         :  1 -> 33 -> 24 -> 40 ->  8
    dist(1  ->  9) = 8         :  1 -> 33 ->  7 -> 45 ->  9
    dist(1  -> 10) = 8         :  1 -> 33 -> 24 -> 12 -> 10
    dist(1  -> 11) = 9         :  1 -> 29 -> 11
    dist(1  -> 12) = 4         :  1 -> 33 -> 24 -> 12
    dist(1  -> 13) = 7         :  1 -> 33 ->  7 ->  3 -> 13
    dist(1  -> 14) = 8         :  1 -> 33 -> 24 -> 25 -> 14
    dist(1  -> 15) = 7         :  1 -> 33 -> 24 -> 40 -> 15
    dist(1  -> 16) = 8         :  1 -> 33 -> 24 -> 40 -> 34 -> 16
    dist(1  -> 17) = 9         :  1 -> 29 -> 35 -> 17
    dist(1  -> 18) = 6         :  1 -> 33 ->  7 -> 18
    dist(1  -> 19) = 8         :  1 -> 33 -> 39 -> 19
    dist(1  -> 20) = 7         :  1 -> 33 -> 24 -> 12 -> 20
    dist(1  -> 21) = 8         :  1 -> 33 -> 24 -> 12 -> 20 -> 21
    dist(1  -> 22) = 9         :  1 -> 33 ->  7 -> 18 -> 22
    dist(1  -> 23) = 6         :  1 -> 29 -> 23
    dist(1  -> 24) = 3         :  1 -> 33 -> 24
    dist(1  -> 25) = 4         :  1 -> 33 -> 24 -> 25
    dist(1  -> 26) = 7         :  1 -> 33 -> 24 -> 25 -> 27 -> 26
    dist(1  -> 27) = 5         :  1 -> 33 -> 24 -> 25 -> 27
    dist(1  -> 28) = 4         :  1 -> 33 -> 24 -> 28
    dist(1  -> 29) = 4         :  1 -> 29
    dist(1  -> 30) = 9         :  1 -> 29 -> 23 -> 30
    dist(1  -> 31) = 8         :  1 -> 33 -> 31
    dist(1  -> 32) = 6         :  1 -> 29 -> 32
    dist(1  -> 33) = 2         :  1 -> 33
    dist(1  -> 34) = 7         :  1 -> 33 -> 24 -> 40 -> 34
    dist(1  -> 35) = 7         :  1 -> 29 -> 35
    dist(1  -> 36) = 8         :  1 -> 29 -> 41 -> 36
    dist(1  -> 37) = 10        :  1 -> 29 -> 41 -> 36 -> 37
    dist(1  -> 38) = 9         :  1 -> 29 -> 38
    dist(1  -> 39) = 4         :  1 -> 33 -> 39
    dist(1  -> 40) = 5         :  1 -> 33 -> 24 -> 40
    dist(1  -> 41) = 5         :  1 -> 29 -> 41
    dist(1  -> 42) = 5         :  1 -> 33 -> 42
    dist(1  -> 43) = 6         :  1 ->  0 -> 43
    dist(1  -> 44) = 7         :  1 ->  0 -> 44
    dist(1  -> 45) = 7         :  1 -> 33 ->  7 -> 45
    dist(1  -> 46) = 6         :  1 -> 33 ->  7 -> 46
    dist(1  -> 47) = 9         :  1 ->  0 -> 43 -> 47
    dist(1  -> 48) = 6         :  1 -> 33 -> 24 -> 12 -> 48
    dist(1  -> 49) = 7         :  1 -> 33 -> 49

    Path found from 1 to 3: Yes. Average distance between two nodes is 6.4898.

## Minimum spanning tree using Prim's algorithm
[File: MST.cpp](/C++%20projects/Minimum%20Spanning%20Tree/MST.cpp)

Create a random graph/read graph from a file, and use Prim's algorithm to compute the minimum spanning tree and the corressponding path length. To pass a custom graph, use the following in the terminal after compiling.

    ./a.out "file_name.txt"

To create a random graph given parameters, uncomment line 48
    
    Graph graph(50, 0.2, 1, 10, false);     // Create random graph

and comment line 49

    Graph graph(file_name, false);          // Read graph

For the file `input.txt`, we have,

    Node expanded:  0 with cost:  0
    Node expanded:  2 with cost:  2
    Node expanded:  9 with cost:  1
    Node expanded: 13 with cost:  3
    Node expanded: 12 with cost:  3
    Node expanded: 17 with cost:  1
    Node expanded: 11 with cost:  1
    Node expanded: 14 with cost:  1
    Node expanded: 18 with cost:  1
    Node expanded:  5 with cost:  1
    Node expanded:  6 with cost:  1
    Node expanded:  3 with cost:  1
    Node expanded:  1 with cost:  1
    Node expanded: 16 with cost:  2
    Node expanded: 10 with cost:  3
    Node expanded: 15 with cost:  2
    Node expanded: 19 with cost:  2
    Node expanded:  7 with cost:  2
    Node expanded:  4 with cost:  1
    Node expanded:  8 with cost:  1


    Minimum Spanned Tree Cost: 30