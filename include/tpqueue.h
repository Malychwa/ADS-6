// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T arr[size];
  int first, last;

 public:
  TPQueue() : first(0), last(0) {};
  void push (T x) {
    int prl = last;
    while ((--prl >= first) && (x.prior > arr[prl % size].prior)) {
        arr[(prl + 1) % size] = arr[prl % size];
    }
    arr[(prl + 1) % size] = x;
    last++;
  };
  T pop() {
   if (first < last)
    return arr[(first++) % size];
   return 0;
  };
  int getSize() {
    return (last - first);
    };
  
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
