#ifndef _MNEMONIC_H_
#define _MNEMONIC_H_

#include <Bitcoin.h>

#define ENTROPY_LEN 512
#define MAX_CYCLES 100

union Entropy {
  float x[ENTROPY_LEN/4];
  uint8_t y[ENTROPY_LEN];
};

class MnemonicGenerator {
  Entropy entropy;
  int index=0;
  int cycles=0;
public:
  MnemonicGenerator();
  float GetProgress();
  void Add(float random_val);
  String Generate(int no_of_words);
  void Reset();
};

#endif