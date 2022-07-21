# Coat Codes Guide

## Base Coats
### Composition

Base coats are represented by a 4-bit binary number (d0:d1:d2:d3)

d0 => Red factor allele 1
d1 => Red factor allele 2
d2 => Agouti allele 1
d3 => Agouti allele 2

### Colours Table

| 4-Bit Binary Code | Visible Colour | Decimal Value |
|-------------------|----------------|---------------|
| 0000              | Red            | 0             |
| 0001              | Red            | 1             |
| 0010              | Red            | 2             |
| 0011              | Red            | 3             |
| 0100              | Black          | 4             |
| 0101              | Bay            | 5             |
| 0110              | Bay            | 6             |
| 0111              | Bay            | 7             |
| 1000              | Black          | 8             |
| 1001              | Bay            | 9             |
| 1010              | Bay            | 10            |
| 1011              | Bay            | 11            |
| 1100              | Black          | 12            |
| 1101              | Bay            | 13            |
| 1110              | Bay            | 14            |
| 1111              | Bay            | 15            |

## Dilutions

Dilutions are provided by 5 factors (cream, champagne, pearl, and silver), in addition to a dun allele and its respective primitive markings.

All four dilution factors exist on a scale of 0-2, with the factor value representing how many copies of that dilution gene are present. In general, the greater the dilution factor, the lighter the coat colour. Dilution factors will not affect coat colour, regardless of their values, it is not applicable to present base coat.


### Dilutions Codes

> Df *Decimal Dilution Factor*

| Dilution Factor (Present/Wildtype) | Levels, Lowest to Highest (Df/Alpha/Bin) |
|------------------------------------|---------------------------|
| Cream (Cr/N)     | (Df0/NN/00), (Df1/CrN/01), (Df2/CrCr/10)    |
| Champagne (Ch/N) | (Df0/NN/00), (Df1/ChN/01), (Df2/ChCh/10)    |
| Pearl (Prl/N)    | (Df0/NN/00), (Df1/PrlN/01), (Df2/PrlPrl/10) |
| Silver (Z/N)     | (Df0/NN/00), (Df1/ZN/01), (Df2/ZZ/10)       |

Dilution is represented in binary by an 8-bit value (d_0:d_1:...:d_6:d_7)
d_0: Cream1
d_1: Cream2
d_2: Champagne1
d_3: Champagne2
d_4: Pearl1
d_5: Pearl2
d_6: Silver1
d_7: Silver2

### Effects on Red Base Coats

> NA *No effect*

| Dilution Factor | Df0 Coat | Df1 Coat | Df2 Coat |
|-----------------|----------|----------|----------|
| Cream           | NA       | Palomino | Cremello |
| Champagne       | NA       | Gold     | Gold     |
| Pearl           | NA       | NA (Will cause pseudo-cremello in combination with Cr) | Gold |
| Silver          | NA       | NA       | NA       |


### Effects on Bay Base Coats

| Dilution Factor | Df0 Coat | Df1 Coat | Df2 Coat |
|-----------------|----------|----------|----------|
| Cream           | NA       | Buckskin | Perlino  |
| Champagne       | NA       | Amber*   | Amber*   |
| Pearl           | NA       | NA (Will cause pseudo-perlino in combination with Cr) | Amber* |
| Silver          | NA       | Black points become brown, flaxen mane | Black points become brown, flaxen mane |

**Amber is defined as having a tan body and brown points, instead of black*

### Effects on Black Base Coats

| Dilution Factor | Df0 Coat | Df1 Coat | Df2 Coat |
|-----------------|----------|----------|----------|
| Cream           | NA       | Smokey Black | Smokey Cream |
| Champagne       | NA       | Classic Champagne* | Classic Champagne* |
| Pearl           | NA       | NA (Will cause psuedo-smokey cream in combination with Cr) | Classic Champagne* |
| Silver          | NA       | Chocolate coat, silver/flaxen mane | Chocolate coat, silver/flaxen mane |



**Classic champagne is defined as having a darker tan body and brown points, instead of black*
