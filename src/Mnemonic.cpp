#include "Mnemonic.h"


MnemonicGenerator::MnemonicGenerator() 
{
}

String MnemonicGenerator::Generate(int no_of_words=12) 
{
  return generateMnemonic(no_of_words, entropy.y, ENTROPY_LEN);
}

void MnemonicGenerator::Add(float random_val) 
{
    if(cycles < MAX_CYCLES) 
    {
        entropy.x[index++] += random_val;
        index = index % (ENTROPY_LEN/4);
        if(index == 0) cycles++;
    }
}

float MnemonicGenerator::GetProgress()
{
    return ((float)cycles)/MAX_CYCLES;
}

void MnemonicGenerator::Reset()
{
    for(int i=0;i<ENTROPY_LEN/4;i++)
        entropy.x[i] = 0;
}