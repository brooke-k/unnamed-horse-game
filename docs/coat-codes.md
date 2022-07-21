# CoatCode Guide

## Basics

Horse coats are coded for using a 32-bit long int. Each bit represents the dominance of a specific allele, where 0 represents a recessive allele occurance and 1 represents a dominant occurance. Each gene used to encode equine coats is represented by 2 bits (2 alleles). All coats have encoding for all coat genes, but not all genes may be active in a single coat and thus, are not represented in the holistic coat colour.

## Bit Assignment

Each gene is encoded in a 2-bit sequence (representing 2 alleles), where 0 is a recessive allele and 1 is a dominant allele. Bit-position assignemnts are outlined below.

| Bit Range | Gene                | Alleles (Dom/Rec) | Group            |
|-----------|---------------------|-------------------|------------------|
| `0-1  `     | Camarillo White     | CW/N              | Base             |
| `2-3  `     | Red Factor          | E/e               | Base             |
| `4-5  `     | Agouti              | A/a               | Base             |
| `6-7  `     | Cream               | Cr/N              | Dilution         |
| `8-9  `     | Champagne           | Ch/N              | Dilution         |
| `10-11`     | Pearl               | Prl/N             | Dilution         |
| `12-13`     | Silver              | Z/N               | Dilution         |
| `14-15`     | Dun1                | D/dn1             | Dilution/Pattern |
| `16-17`     | Dun2                | D/dn2             | Dilution/Pattern |
| `18-19`     | Grey                | G/N               | Fade             |
| `20-21`     | Roan                | Rn/N              | Fade             |
| `22-23`     | Leopard Complex     | LP/N              | Marking          |
| `24-24`     | Appaloosa Pattern-1 | PATN1/N           | Marking          |
| `25-26`     | Lethal White Overo  | O/N               | Marking          |
| `27-28`     | Sabino1             | SB1/N             | Marking          |
| `29-30`     | Splashed White      | SW/N              | Marking          |
| `31-32`     | Tobiano             | TO/N              | Marking          |

## Base Coats

Base coats serve to define the entire coat of the horse, with most dilutions (and some patterns) being affected by the base colour. It is possible for an equine to not express any patterning, in which case the base coat will serve as the only visible colour on the horse.

Simplified encoding for base coats (using bits 0-5) is outlined below.

| Simplified bits 0-5 | Expressed Base Coat |
|---------------------|---------------------|
| `1xxxxx, 01xxxx`      | White |
| `0000xx` | Red |
| `001x10, 00x110` | Bay |
| `001x11, 00x111` | Black |