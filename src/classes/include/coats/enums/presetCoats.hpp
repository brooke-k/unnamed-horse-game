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
};

enum PresetDilutions
{
  singleCream = 0x02000000,
  doubleCream = 0x03000000,
  champagne = 0x00800000,
  doubleChampagne
};

enum PresetFades
{

};

enum PresetMarkings
{

};