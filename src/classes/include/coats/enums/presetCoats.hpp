/**
 * @file presetCoats.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 11/Aug/2022
 *
 */

enum PresetBases
{
  recCamWhite = 0x00000000, // All reccessive Camarillo white
  hetCamWhite = 0x80000000, // Heterozygous Camarillo white
  domCamWhite = 0xc0000000, // All dominant Camarillo white

  recRedFact = 0x00000000, // All recessive Red Factor
  hetRedFact = 0x20000000, // Heterozygous Red Factor
  domRedFact = 0x30000000, // All dominant Red Factor

  recAgouti = 0x00000000, // All recessive Agouti
  hetAgouti = 0x08000000, // Heterozygous Agouti
  domAgouti = 0x0c000000, // All dominant Agouti

  black = 0x20000000,
  bay = 0x28000000,
  chestnut = 0x0,
  white = 0x80000000
};

enum PresetDilutions
{
  singleCream = 0x02000000,
  doubleCream = 0x03000000,
  champagne = 0x00800000,
  doubleChampagne = 0x00c00000,
  heterPearl = 0x00200000,
  homoPearl = 0x00300000,
  pseudoPearl = 0x02200000,
  heterSilver = 0x00080000,
  homoSilver = 0x000c0000,
  wildDun = 0x00020000,
  wild = 0x00010000
};

enum PresetFades
{
  heterGrey = 0x00002000,
  homoGrey = 0x00003000,
  heterRoan = 0x00000800,
  homoRoan = 0x00000c00
};

enum PresetMarkings
{
  heterAppaloosa = 0x00000200,
  homoAppaloosa = 0x00000300,
  heterSplashWhite = 0x00000080,
  homoSplashWhite = 0x000000c0,
  overo = 0x00000020,
  fatalOvero = 0x00000030,
  sabino = 0x00000008,
  sabinoWhite = 0x0000000c,
  heterTobiano = 0x00000002,
  homoTobiano = 0x00000003

};