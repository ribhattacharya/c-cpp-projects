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

    Before sorting,
        210      82     656     994     306
        644     618     313     995     819
        82     103     181     612     327
        352     804       7     468     782
        302     374     580     627      26
        430     308     661     399     906
        208     446     651     720     851
        413     490      70     980     545
        930     832     427     760     807
        666     945     324     576     533
        994     865     770      96     478
        462     437     923     396     451
        906     732     609      36     866
        222    1000     887     747     995
        37     835     263     302     530
        484     833     893     128     276
        80     539     232     812     450
        711     540     686     179     515
        350     318     284     818     750
        978     304    1000      80     845


    After sorting,
        7      26      36      37      70
        80      80      82      82      96
        103     128     179     181     208
        210     222     232     263     276
        284     302     302     304     306
        308     313     318     324     327
        350     352     374     396     399
        413     427     430     437     446
        450     451     462     468     478
        484     490     515     530     533
        539     540     545     576     580
        609     612     618     627     644
        651     656     661     666     686
        711     720     732     747     750
        760     770     782     804     807
        812     818     819     832     833
        835     845     851     865     866
        887     893     906     906     923
        930     945     978     980     994
        994     995     995    1000    1000


    Sorted!