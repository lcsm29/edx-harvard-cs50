## Environments
* OS: Ubuntu 21.04
* CPU: Intel Core i5-1135G7
* Command: `time (for i in {1..100}; ./sort_binary target.txt ; done)`

## Total time taken for 100 iterations
* **NOTE**: The results shown in the tables below are sorted from the fastest to the slowest based on their user times

### random5000.txt
|  binary  |   real   |   user   |   sys    |
| :------: | :------: | :------: | :------: |
|  /sort2  |  6.909s  |  0.240s  |  0.490s  |
|  /sort3  |  7.386s  |  1.890s  |  0.511s  |
|  /sort1  |  7.619s  |  3.538s  |  0.543s  |

### random10000.txt
|  binary  |   real   |   user   |   sys    |
| :------: | :------: | :------: | :------: |
|  /sort2  |  15.051s |   0.410s |  0.982s  |
|  /sort3  |  15.561s |   7.282s |  0.955s  |
|  /sort1  |  16.747s |  15.630s |  1.016s  |

### random50000.txt
|  binary  |    real    |    user    |   sys    |
| :------: | :--------: | :--------: | :------: |
|  /sort2  |   73.668s  |    2.203s  |  4.703s  |
|  /sort3  |  196.158s  |  143.011s  |  4.714s  |
|  /sort1  |  587.722s  |  529.516s  |  4.712s  |

### reversed5000.txt
|  binary  |   real   |   user   |   sys    |
| :------: | :------: | :------: | :------: |
|  /sort2  |  7.458s  |  0.154s  |  0.551s  |
|  /sort3  |  8.166s  |  1.977s  |  0.550s  |
|  /sort1  |  7.982s  |  4.624s  |  0.560s  |

### reversed10000.txt
|  binary  |   real   |   user   |   sys    |
| :------: | :------: | :------: | :------: |
|  /sort2  |  15.790s |   0.322s |  1.047s  |
|  /sort3  |  14.532s |   7.553s |  1.116s  |
|  /sort1  |  19.769s |  18.324s |  1.009s  |

### reversed50000.txt
|  binary  |    real    |    user    |   sys    |
| :------: | :--------: | :--------: | :------: |
|  /sort2  |   77.487s  |    1.770s  |  4.817s  |
|  /sort3  |  214.816s  |  153.880s  |  4.739s  |
|  /sort1  |  534.392s  |  471.324s  |  4.765s  |

### sorted5000.txt
|  binary  |   real   |   user   |   sys    |
| :------: | :------: | :------: | :------: |
|  /sort1  |  7.493s  |  0.176s  |  0.510s  |
|  /sort2  |  7.442s  |  0.194s  |  0.514s  |
|  /sort3  |  8.240s  |  1.937s  |  0.586s  |

### sorted10000.txt
|  binary  |   real   |   user   |   sys    |
| :------: | :------: | :------: | :------: |
|  /sort1  |  15.720s |  0.241s  |  1.036s  |
|  /sort2  |  14.729s |  0.339s  |  1.016s  |
|  /sort3  |  16.084s |  7.132s  |  0.970s  |

### sorted50000.txt
|  binary  |    real    |    user    |   sys    |
| :------: | :--------: | :--------: | :------: |
|  /sort1  |   77.241s  |    1.314s  |  4.858s  |
|  /sort2  |   78.597s  |    1.645s  |  5.045s  |
|  /sort3  |  208.822s  |  145.998s  |  4.587s  |

## Analysis
### sort1: Bubble sort
* sort1 was faster than any other algorithms on the already sorted datasets, but it was also substantially slower than any other algorithms on every other datasets.
* It took significantly longer time as the size of datasets grows. When the size of dataset doubles (i.e. 5k -> 10k), it took 301% more time to sort on average (4.41x, 3.96x, 3.68x, respectively). When the size of datasets grows 10 times (i.e. 5k -> 50k), it took 149.66x times on the random datasets and 101.92x times on the reversed datasets, but only 7.46x times on the already sorted datasets. This suggests `O(n**2)` time complexity on non-sorted datasets, but `O(n)` time complexity on the already sorted datasets(i.e. the best case).
* It was substantially faster on the already sorted datasets, compare to the non-sorted datasets, but only exhibits marginal differences between the random and reversed datasets.

### sort2: Merge sort
* sort2 was substantially faster than any other algorithms on the random and reversed datasets, but it was slightly slower than sort1 on the already sorted datasets.
* The durations were almost directly proportional to the dataset sizes, which suggests either `O(n)` or `O(n * log(n))` time complexity.
* It was consistently slower on the random datasets than reversed datasets. Likewise, it was substantially slower on the reversed datasets than already sorted datasets.

### sort3: Selection sort
* sort3 was the middle of the pack on the random and reversed datasets, but it was the slowest algorithm on the already sorted dataset.
* The durations were more or less proportional to the square of the dataset sizes, which suggest `O(n**2)` time complexity.
* Regardless of how the data is sorted, It took more or less the same time to sort.
