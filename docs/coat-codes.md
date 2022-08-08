# CoatCode Guide

## Basics

Horse coats are coded for using a 32-bit long int. Each bit represents the dominance of a specific allele, where 0 represents a recessive allele occurance and 1 represents a dominant occurance. Each gene used to encode equine coats is represented by 2 bits (2 alleles). All coats have encoding for all coat genes, but not all genes may be active in a single coat and thus, are not represented in the holistic coat colour.

## Bit Assignment

Each gene is encoded in a 2-bit sequence (representing 2 alleles), where 0 is a recessive allele and 1 is a dominant allele. Bit-position assignemnts are outlined below.

| Bit Range   | Gene                | Alleles (Dom/Rec)  | Group            |
|-------------|---------------------|--------------------|------------------|
| `31-30`     | Camarillo White     | CW/N               | Base             |
| `29-28`     | Red Factor          | E/e                | Base             |
| `27-26`     | Agouti              | A/a                | Base             |
| `25-24`     | Cream               | Cr/N               | Dilution         |
| `23-22`     | Champagne           | Ch/N               | Dilution         |
| `21-20`     | Pearl               | Prl/N              | Dilution         |
| `19-18`     | Silver              | Z/N                | Dilution         |
| `17-16`     | Dun allele 1        | D/nd1/nd2          | Dilution/Pattern |
| `15-14`     | Dun2                | D/nd1/nd2          | Dilution/Pattern |
| `13-12`     | Grey                | G/N                | Fade             |
| `11-10`     | Roan                | Rn/N               | Fade             |
| `9-8  `     | Leopard Complex     | LP/N               | Marking          |
| `7-6  `     | Appaloosa Pattern-1 | PATN1/N            | Marking          |
| `5-4  `     | Lethal White Overo  | O/N                | Marking          |
| `3-2  `     | Sabino1             | SB1/N              | Marking          |
| `1-0  `     | Tobiano             | TO/N               | Marking          |


## Base Coats

Base coats serve to define the entire coat of the horse, with most dilutions (and some patterns) being affected by the base colour. It is possible for an equine to not express any patterning, in which case the base coat will serve as the only visible colour on the horse.

Base coats in real horses are defined by 2 genes. These genes are the Red Factor, which controls the possibility of the horse being able to produce black pigmentation for its coat, and Agouti factor, which controls to what degree black pigment is produced.

If Red factor (defined with dominant allele E and recessive allele e) is recessive, that is, the Red Factor is 'e/e', then no black pigment will be produced on the horse's coat. In this case, it does not matter what the alleles are for the Agouti factor in regards to visible expression, as it will not be visible at all. A fully recessive allele pair for Red factor will only produce a red-pigment base coat, commonly called "Chestnut".

Otherwise, if at least one Red Factor allele is domanent, 'E/e' or 'E/E', then black pigment will be visible and the Agouti factor will be used.

Agouti (defined with dominant allele A and recessive allele a) that is fully recessive, that is 'a/a', will cause the entire coat to produce black pigment instead of red. This complete production of black will produce the "Black" coat colour.
Otherwise, there is at least one dominant Agouti allele, 'A/a' or 'A/A', black pigment will only replace red pigment on the nose, legs, mane, and tail. This coat pattern is commonly called "Bay".

Although not a base coat, Camarillo white (recognized in real-world equine genetics as a white spotting pattern), is a dominant gene and will be expressed if at least one of its alleles is dominant. This expression causes the entire coat, including the mane and tail, to be completely white, thus concealing the other base coat colours. Since all other equine coat genes rely on lightening or diluting the base coat, they will not affect the visual appearance of Camarillo white. Because of this unique property, Camarillo white has been included in the list of encoded base coats, as it provides a coat colour that will affect every other gene's visual expression, but other genes will not affect it.

Simplified encoding for base coats (using bits 0-5) is outlined below.

| Simplified `bit-31 to bit-28`          | Simplfied expressed alleles | Expressed Base Coat |
|----------------------------------------|-----------------------------|---------------------|
| `1xxxxx, 01xxxx`                       | CW/x-x/x-x/x                | White               |
| `0000xx`                               | N/N-e/e-x/x                 | Chestnut            |
| `001x10`, `00x110`, `00x111`, `001x11` | N/N-E/x-A/x                 | Bay                 |
| `001x00, 00x100`                       | N/N-E/x-a/a                 | Black               |

## Dilutions

Not all dilutions affect all coats, and not all dilutions affect coat colours with equal intensity. Most coats have a continues heterogyny that provides them the ability to produce a variety of coats.

The expression of all dilutions, except dun, on different base coats is show below.

| Base Coat | Dilution  | Experession    | Coat Colour                      |
|-----------|-----------|----------------|----------------------------------|
| Red       | Cream     | N/N            | Red (no effect)                  |
| Red       | Cream     | Cr/N           | Palomino                         |
| Red       | Cream     | Cr/Cr          | Cremello                         |
| Red       | Cream     | Cr/N and Prl/N | Pseudo Cremello                  |
| Red       | Champagne | N/N            | Red (no effect)                  |
| Red       | Champagne | Ch/N           | Gold                             |
| Red       | Champagne | Ch/Ch          | Gold                             |
| Red       | Pearl     | N/N            | Red (no effect)                  |
| Red       | Pearl     | Prl/N          | Red (no effect)                  |
| Red       | Pearl     | Prl/Prl        | Uniform apricot                  |
| Red       | Silver    | N/N            | Red (no effect)                  |
| Red       | Silver    | Z/N            | Red (no effect)                  |
| Red       | Silver    | Z/Z            | Red (no effect)                  |
| Bay       | Cream     | N/N            | Bay (no effect)                  |
| Bay       | Cream     | Cr/N           | Buckskin                         |
| Bay       | Cream     | Cr/Cr          | Perlino                          |
| Bay       | Cream     | Cr/N and Prl/N | Pseudo-perlino                   |
| Bay       | Champagne | N/N            | Bay (no effect)                  |
| Bay       | Champagne | Ch/N           | Amber                            |
| Bay       | Champagne | Ch/Ch          | Amber                            |
| Bay       | Pearl     | N/N            | Bay (no effect)                  |
| Bay       | Pearl     | Prl/N          | Bay (no effect)                  |
| Bay       | Pearl     | Prl/Prl        | Uniform apricot                  |
| Bay       | Silver    | N/N            | Bay (no effect)                  |
| Bay       | Silver    | Z/N            | Brown points, flaxen mane/tail   |
| Bay       | Silver    | Z/Z            | Brown points, flaxen mane/tail   |
| Black     | Cream     | N/N            | Black (no effect)                |
| Black     | Cream     | Cr/N           | Smokey black                     |
| Black     | Cream     | Cr/Cr          | Smokey cream                     |
| Black     | Cream     | Cr/N and Prl/N | Pseudo-smokey cream              |
| Black     | Champagne | N/N            | Black (no effect)                |
| Black     | Champagne | Ch/N           | Classic                          |
| Black     | Champagne | Ch/Ch          | Classic                          |
| Black     | Pearl     | N/N            | Black (no effect)                |
| Black     | Pearl     | Prl/N          | Black (no effect)                |
| Black     | Pearl     | Prl/Prl        | Uniform apricot                  |
| Black     | Silver    | N/N            | Black (no effect)                |
| Black     | Silver    | Z/N            | Chocolate coat, silver mane/tail |
| Black     | Silver    | Z/Z            | Chocolate coat, silver mane/tail |

Because the expression of dun relies on the continuous dominance of 3 alleles - D, nd1, and nd2 - they are encoded within 4 bits (`17-14`), instead of two. Bits `17-16` encode for the first dun allele, and represent the presence of D, nd1, or nd2. Bits `15-14` encode for the second dun allele, and also represent the presence of D, nd1, or nd2.

The specifications of these encodings is listed below.

| Bit number | Allele represented |
|------------|--------------------|
| `17`       | D/`bit 16`         |
| `16`       | nd1/nd2            |
| `15`       | D/`bit 14`         |
| `14`       | nd1/nd2            |

The dominance of dun alleles is continous, instead of following the binary pattern all other, so expression is based on a heriarchy of dominance. For dun alleles, that heirarchy follows D>nd1>nd2.

A comparison of real equine genes and the equivalent 4-bit pattern used by `unnamed-horse-game` can be found below.

| Real Equine Genes  (D/nd1/nd2) | Simplified `bit-17 to bit-14`     | Dilution expression*               |
|--------------------------------|-----------------------------------|------------------------------------|
| D/D                            | `1x1x`                            | Dilution, primative markings       |
| D/nd1                          | `1x01`, `011x`                    | Dilution, primative markings       |
| D/nd2                          | `1x00`, `001x`                    | Dilution, primative markings       |
| nd1/nd1                        | `0101`                            | No dilution, primative markings    |
| nd1/nd2                        | `0100`                            | No dilution, primative markings    |
| nd2/nd2                        | `0000`                            | No dilution, no primative markings |

**Dun dilution affects both red and black hair follicles, so all base coats (except white) are affected. This dilution behaves most similarly to cream dilution with Cr/Cr dominance.*

Because the official names for coats affected by dun dilution (both with and without primative markings) vary from breed to breed, `unnamed-horse-game` will refer to this dilution as the base coat name, followed by 'dun', then the presence (or lack-there-of) of primative markings.

| Dilutions Heirarchy (Most Dominant to Most Recessive) |
|----------------|
| Silver (Black/bay coats)        |
| Champagne, Dun |
| Cream          |
| Pearl          |

**This dominance heirachy is not fully realistic, and has been adapted subjectively to better fit a digital format.*
